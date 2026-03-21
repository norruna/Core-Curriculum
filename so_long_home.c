/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_home.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:21:34 by mayahiao          #+#    #+#             */
/*   Updated: 2026/03/21 19:17:48 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* so_long_home_fixed.c */
#include "minilibx-linux/mlx.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>           // for printf (debug)
#include <X11/keysym.h>      // for key symbol constants
#include <fcntl.h>           // open, O_RDONLY
#include <unistd.h>          // close
#include <string.h>          // strlen
#include "get_next_line.h"

#define TILE 64

/* keep track of player position (unused for now) */
typedef struct s_position
{
    int     x;
    int     y;
}   t_position;

/* struct to handle both connection and window pointers */
typedef struct s_mlx_param
{
    void    *ptr;
    void    *window;
    void    *img;
}   t_mlx_param;

typedef struct s_game
{
    void    *ptr;
    void    *window;
    void    *img;
    char    **map;
    int     player_x;
    int     player_y;
    int     moves;
    int     collectibles;      // total on map
    int     collected;         // how many picked up
} t_game;
/*****************************/
/*--MAP----------MANAGEMENT--*/
/*****************************/
typedef struct s_flood
{
    int **visited;
    int rows;
    int cols;
} t_flood;

// recursive DFS flood fill
void flood_fill(char **map, t_flood *f, int y, int x)
{
    if (y < 0 || x < 0 || y >= f->rows || x >= f->cols)
        return;
    if (f->visited[y][x] || map[y][x] == '1')
        return;
    f->visited[y][x] = 1;
    flood_fill(map, f, y - 1, x);
    flood_fill(map, f, y + 1, x);
    flood_fill(map, f, y, x - 1);
    flood_fill(map, f, y, x + 1);
}

int is_reachable(char **map, int rows, int cols, int py, int px)
{
    t_flood f;
    int     i;
    int     found_e;
    int     found_c;

    // allocate visited grid
    f.visited = malloc(rows * sizeof(int *));
    if (!f.visited)
        return (0);
    i = 0;
    while (i < rows)
    {
        f.visited[i] = malloc(cols * sizeof(int));
        if (!f.visited[i])
        {
            while (--i >= 0)
                free(f.visited[i]);
            free(f.visited);
            return (0);
        }
        for (int j = 0; j < cols; j++)
            f.visited[i][j] = 0;
        i++;
    }
    f.rows = rows;
    f.cols = cols;

    // flood from player position
    flood_fill(map, &f, py, px);

    // check that E and at least one C were reached
    found_e = 0;
    found_c = 0;
    i = 0;
    while (i < rows)
    {
        int j = 0;
        while (j < cols)
        {
            if (f.visited[i][j])
            {
                if (map[i][j] == 'E')
                    found_e = 1;
                if (map[i][j] == 'C')
                    found_c = 1;
            }
            j++;
        }
        i++;
    }

    // free visited grid
    i = 0;
    while (i < rows)
        free(f.visited[i++]);
    free(f.visited);

    return (found_e && found_c);
}

void count_collectibles(t_game *game)
{
    int i = 0;
    game->collectibles = 0;
    while (game->map[i])
    {
        int j = 0;
        while (game->map[i][j])
        {
            if (game->map[i][j] == 'C')
                game->collectibles++;
            j++;
        }
        i++;
    }
}

int count_map_lines(char *file)
{
    int     count;
    char    *line;
    int     fd;

    fd = open(file, O_RDONLY);
    if (fd < 0)
        return (0);
    count = 0;
    line = get_next_line(fd);
    while (line != NULL)
    {
        count++;
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    return (count);
}

/*check that there is exactly one exit and one player and a minimum of one collectible*/
int count_P_C_E(char *file)
{
    int     exits;
    int     collectibles;
    int     player;
    char    *line;
    int     fd;
    int     i = 0;
    fd = open(file, O_RDONLY);
    if (fd < 0)
        return (0);
    exits = 0;
    collectibles = 0;
    player = 0;
    line = get_next_line(fd);
    while (line != NULL)
    {
        i = 0;
        while (line[i])
        {
            if (line[i] == 'P')
                player++;
            if (line[i] == 'C')
                collectibles++;
            if (line[i] == 'E')
                exits++;
            i++;
        }
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    if (player != 1 || exits != 1 || collectibles == 0)
        return (0);
    return (1);
}

/* check rectangular: all lines (excluding '\n') must have same length */
int is_rectangular(char *file)
{
    int     fd;
    int     count;
    char    *line;
    size_t  first_len;
    int     i;

    count = count_map_lines(file);
    if (count == 0)
        return (0);

    fd = open(file, O_RDONLY);
    if (fd < 0)
        return (0);

    line = get_next_line(fd);
    if (!line)
    {
        close(fd);
        return (0);
    }
    first_len = 0;
    while (line[first_len] && line[first_len] != '\n')
        first_len++;
    free(line);

    i = 1;
    while (i < count)
    {
        line = get_next_line(fd);
        if (!line)
        {
            close(fd);
            return (0);
        }
        {
            size_t len = 0;
            while (line[len] && line[len] != '\n')
                len++;
            if (len != first_len)
            {
                free(line);
                close(fd);
                return (0);
            }
        }
        free(line);
        i++;
    }
    close(fd);
    return (1);
}

/* check that the map is surrounded by walls ('1') */
int is_surrounded_by_walls(char *file)
{
    int     fd;
    int     count;
    char    *line;
    int     i;

    count = count_map_lines(file);
    if (count == 0)
        return (0);

    fd = open(file, O_RDONLY);
    if (fd < 0)
        return (0);

    /* top row */
    line = get_next_line(fd);
    if (!line)
    {
        close(fd);
        return (0);
    }
    {
        int j = 0;
        while (line[j] && line[j] != '\n')
        {
            if (line[j] != '1')
            {
                free(line);
                close(fd);
                return (0);
            }
            j++;
        }
    }
    free(line);

    /* middle rows: check first and last char are '1' */
    for (i = 1; i < count - 1; i++)
    {
        line = get_next_line(fd);
        if (!line)
        {
            close(fd);
            return (0);
        }
        {
            int len = 0;
            while (line[len] && line[len] != '\n')
                len++;
            if (len == 0 || line[0] != '1' || line[len - 1] != '1')
            {
                free(line);
                close(fd);
                return (0);
            }
        }
        free(line);
    }

    /* bottom row (if more than one row) */
    if (count > 1)
    {
        line = get_next_line(fd);
        if (!line)
        {
            close(fd);
            return (0);
        }
        {
            int j = 0;
            while (line[j] && line[j] != '\n')
            {
                if (line[j] != '1')
                {
                    free(line);
                    close(fd);
                    return (0);
                }
                j++;
            }
        }
        free(line);
    }

    close(fd);
    return (1);
}


int is_valid(char *file)
{
    if (!is_rectangular(file))
    {
        printf("Map is not rectangular\n");
        return (0);
    }
    if (!is_surrounded_by_walls(file))
    {
        printf("Map is not surrounded by walls\n");
        return (0);
    }
    if (!count_P_C_E(file))
    {
        printf("Map doesnt have the correct number of exits, players or collectibles\n");
        return (0);
    }
    return (1);
}

void free_map(char **map, int i)
{
    if (!map)
        return;
    while (i >= 0)
    {
        if (map[i])
            free(map[i]);
        i--;
    }
    free(map);
}

/* parse_map: returns NULL on error */
char **parse_map(char *file)
{
    char    **map;
    int     count;
    int     i;
    char    *line;
    int     fd;

    if (!is_valid(file))
        return (NULL);

    fd = open(file, O_RDONLY);
    if (fd < 0)
        return (NULL);

    count = count_map_lines(file);
    map = malloc((count + 1) * sizeof(char *));
    if (!map)
    {
        close(fd);
        return (NULL);
    }

    i = 0;
    while (i < count)
    {
        line = get_next_line(fd);
        if (!line)
        {
            free_map(map, i - 1);
            close(fd);
            return (NULL);
        }
        /* length excluding newline */
        int len = 0;
        while (line[len] && line[len] != '\n')
            len++;

        map[i] = malloc(len + 1);
        if (!map[i])
        {
            free(line);
            free_map(map, i - 1);
            close(fd);
            return (NULL);
        }
        for (int k = 0; k < len; k++)
            map[i][k] = line[k];
        map[i][len] = '\0';
        free(line);
        i++;
    }
    map[i] = NULL;
    close(fd);
    return (map);
}

/* draw_map: creates images for tiles and places them on window */
void draw_map(char **map, t_game *game)
{
    int i;
    int j;
    int height = TILE;
    int width = TILE;

    void *img_wall = mlx_xpm_file_to_image(game->ptr, "images/Wall.xpm", &height, &width);
    void *img_player = mlx_xpm_file_to_image(game->ptr, "images/Player.xpm", &height, &width);
    void *img_collectible = mlx_xpm_file_to_image(game->ptr, "images/Collectible.xpm", &height, &width);
    void *img_exit = mlx_xpm_file_to_image(game->ptr, "images/Exit.xpm", &height, &width);
    void *img_grass = mlx_xpm_file_to_image(game->ptr, "images/Grass.xpm", &height, &width);

    if (!img_exit || !img_collectible || !img_player || !img_wall || !img_grass)
    {
        printf("couldnt find image\n");
        /* destroy those that were created to avoid leaks */
        if (img_wall) mlx_destroy_image(game->ptr, img_wall);
        if (img_player) mlx_destroy_image(game->ptr, img_player);
        if (img_collectible) mlx_destroy_image(game->ptr, img_collectible);
        if (img_exit) mlx_destroy_image(game->ptr, img_exit);
        if (img_grass) mlx_destroy_image(game->ptr, img_grass);
        return;
    }

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == '1')
                mlx_put_image_to_window(game->ptr, game->window, img_wall, j * TILE, i * TILE);
            else if (map[i][j] == 'P')
                mlx_put_image_to_window(game->ptr, game->window, img_player, j * TILE, i * TILE);
            else if (map[i][j] == 'C')
                mlx_put_image_to_window(game->ptr, game->window, img_collectible, j * TILE, i * TILE);
            else if (map[i][j] == 'E')
                mlx_put_image_to_window(game->ptr, game->window, img_exit, j * TILE, i * TILE);
            else if (map[i][j] == '0')
                mlx_put_image_to_window(game->ptr, game->window, img_grass, j * TILE, i * TILE);
            j++;
        }
        i++;
    }

    /* destroy images created locally */
    mlx_destroy_image(game->ptr, img_wall);
    mlx_destroy_image(game->ptr, img_collectible);
    mlx_destroy_image(game->ptr, img_exit);
    mlx_destroy_image(game->ptr, img_player);
    mlx_destroy_image(game->ptr, img_grass);
}

void find_player(t_game *game)
{
    int i = 0;
    while (game->map[i])
    {
        int j = 0;
        while (game->map[i][j])
        {
            if (game->map[i][j] == 'P')
            {
                game->player_x = j;
                game->player_y = i;
            }
            j++;
        }
        i++;
    }
}

/*****************************/
/* WINDOW / EVENT MANAGEMENT */
/*****************************/

/* close window after pressing X button */
int close_after_x(void *param)
{
     t_game *game = (t_game *)param;
    if (game && game->ptr)
        mlx_loop_end(game->ptr);
    return (0);
}


void move_player(t_game *game, int dx, int dy)
{
    int new_x = game->player_x + dx;
    int new_y = game->player_y + dy;
    char target = game->map[new_y][new_x];

    if (target == '1')
        return;
    if (target == 'E' && game->collected < game->collectibles)
        return;  // exit blocked until all collected
    if (target == 'E' && game->collected == game->collectibles)
    {
        printf("You win! Moves: %d\n", game->moves + 1);
        mlx_loop_end(game->ptr);
        return;
    }
    if (target == 'C')
    {
        game->collected++;
        game->map[new_y][new_x] = '0';  // remove collectible from map
    }
    game->map[game->player_y][game->player_x] = '0';
    game->map[new_y][new_x] = 'P';
    game->player_x = new_x;
    game->player_y = new_y;
    game->moves++;
    printf("Moves: %d\n", game->moves);
    draw_map(game->map, game);
}

/* key press handler */
int key_presses(int keysym, void *param)
{
     t_game *game = (t_game *)param;

    if (keysym == XK_Escape)
        mlx_loop_end(game->ptr);
    else if (keysym == XK_w || keysym == XK_Up)
        move_player(game, 0, -1);
    else if (keysym == XK_s || keysym == XK_Down)
        move_player(game, 0, 1);
    else if (keysym == XK_a || keysym == XK_Left)
        move_player(game, -1, 0);
    else if (keysym == XK_d || keysym == XK_Right)
        move_player(game, 1, 0);
    return (0);
}

/* init and open window, register hooks once */

void init_and_open_window(t_game *game)
{
    int map_height;
    int map_width;
    int height;
    int width;

    game->map = parse_map("map1.ber");
    if (!game->map)
        return;
    find_player(game);
count_collectibles(game);

int rows = count_map_lines("map1.ber");
int cols = strlen(game->map[0]);

if (!is_reachable(game->map, rows, cols, game->player_y, game->player_x))
{
    printf("Map is not reachable: E or C is inaccessible\n");
    free_map(game->map, rows - 1);
    return;
    }
    map_height = count_map_lines("map1.ber");
    map_width = strlen(game->map[0]);
    height = map_height * TILE;
    width = map_width * TILE;

    game->ptr = mlx_init();
    if (!game->ptr) { free_map(game->map, map_height - 1); return; }

    game->window = mlx_new_window(game->ptr, width, height, "night_routine");
    if (!game->window) { free_map(game->map, map_height - 1); return; }

    game->img = mlx_xpm_file_to_image(game->ptr, "images/backgroundtest.xpm", &width, &height);
    if (!game->img)
    {
        mlx_destroy_window(game->ptr, game->window);
        free_map(game->map, map_height - 1);
        return;
    }

    find_player(game);
    find_player(game);
    count_collectibles(game);
    game->collected = 0;
    mlx_put_image_to_window(game->ptr, game->window, game->img, 0, 0);
    draw_map(game->map, game);

    mlx_key_hook(game->window, (int (*)())key_presses, game);
    mlx_hook(game->window, 17, 0L, (int (*)())close_after_x, game);
    mlx_loop(game->ptr);

    mlx_destroy_image(game->ptr, game->img);
    mlx_destroy_window(game->ptr, game->window);
    free_map(game->map, map_height - 1);
}

int main(void)
{
    if (is_valid("map1.ber") == 0)
        return (0);
    
    t_game game;

    game.ptr = NULL;
    game.window = NULL;
    game.img = NULL;
    game.map = NULL;
    game.player_x = 0;
    game.player_y = 0;
    game.moves = 0;

    init_and_open_window(&game);
    return (0);
}

