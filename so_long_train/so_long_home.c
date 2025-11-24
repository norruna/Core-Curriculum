/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_home.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:21:34 by mayahiao          #+#    #+#             */
/*   Updated: 2025/08/17 18:59:36 by mayahiao         ###   ########.fr       */
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

/*****************************/
/*--MAP----------MANAGEMENT--*/
/*****************************/

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
void draw_map(char **map, t_mlx_param *param)
{
    int i;
    int j;
    int height = TILE;
    int width = TILE;

    void *img_wall = mlx_xpm_file_to_image(param->ptr, "../images/Wall.xpm", &height, &width);
    void *img_player = mlx_xpm_file_to_image(param->ptr, "../images/Player.xpm", &height, &width);
    void *img_dad = mlx_xpm_file_to_image(param->ptr, "../images/Dad.xpm", &height, &width);
    void *img_bed = mlx_xpm_file_to_image(param->ptr, "../images/Bed.xpm", &height, &width);
    void *img_grass = mlx_xpm_file_to_image(param->ptr, "../images/Grass.xpm", &height, &width);

    if (!img_bed || !img_dad || !img_player || !img_wall || !img_grass)
    {
        printf("couldnt find image\n");
        /* destroy those that were created to avoid leaks */
        if (img_wall) mlx_destroy_image(param->ptr, img_wall);
        if (img_player) mlx_destroy_image(param->ptr, img_player);
        if (img_dad) mlx_destroy_image(param->ptr, img_dad);
        if (img_bed) mlx_destroy_image(param->ptr, img_bed);
        if (img_grass) mlx_destroy_image(param->ptr, img_grass);
        return;
    }

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == '1')
                mlx_put_image_to_window(param->ptr, param->window, img_wall, j * TILE, i * TILE);
            else if (map[i][j] == 'P')
                mlx_put_image_to_window(param->ptr, param->window, img_player, j * TILE, i * TILE);
            else if (map[i][j] == 'C')
                mlx_put_image_to_window(param->ptr, param->window, img_dad, j * TILE, i * TILE);
            else if (map[i][j] == 'E')
                mlx_put_image_to_window(param->ptr, param->window, img_bed, j * TILE, i * TILE);
            else if (map[i][j] == '0')
                mlx_put_image_to_window(param->ptr, param->window, img_grass, j * TILE, i * TILE);
            j++;
        }
        i++;
    }

    /* destroy images created locally */
    mlx_destroy_image(param->ptr, img_wall);
    mlx_destroy_image(param->ptr, img_dad);
    mlx_destroy_image(param->ptr, img_bed);
    mlx_destroy_image(param->ptr, img_player);
    mlx_destroy_image(param->ptr, img_grass);
}

/*****************************/
/* WINDOW / EVENT MANAGEMENT */
/*****************************/

/* close window after pressing X button */
int close_after_x(void *param)
{
    t_mlx_param *p = (t_mlx_param *)param;

    if (p && p->ptr)
    {
        printf("You clicked X. Exiting ....\n");
        mlx_loop_end(p->ptr);
    }
    return (0);
}

/* key press handler */
int key_presses(int keysym, void *param)
{
    t_mlx_param *p = (t_mlx_param *)param;

    if (keysym == XK_Escape)
    {
        if (p && p->ptr)
        {
            printf("You pressed the ESC key, exiting ...\n");
            mlx_loop_end(p->ptr);
        }
    }
    else
    {
        printf("Thanks for pressing the %d key, nothing happened yet ..\n", keysym);
    }
    /* DO NOT register hooks here */
    return (0);
}

/* init and open window, register hooks once */
void init_and_open_window(t_mlx_param *param)
{
    char    **map;
    int     map_height;
    int     map_width;
    int     height;
    int     width;

    if (is_valid("map1.ber") == 0)
        return;

    map = parse_map("map1.ber");
    if (!map)
        return;

    map_height = count_map_lines("map1.ber");
    if (map_height == 0)
    {
        free_map(map, 0);
        return;
    }

    map_width = strlen(map[0]); /* assuming rectangular map */
    height = map_height * TILE;
    width = map_width * TILE;

    param->ptr = mlx_init();
    if (param->ptr == NULL)
    {
        free_map(map, map_height - 1);
        return;
    }

    param->window = mlx_new_window(param->ptr, width, height, "night_routine");
    if (param->window == NULL)
    {
        free_map(map, map_height - 1);
        /* do not free param->ptr; mlx manages that */
        return;
    }

    param->img = mlx_xpm_file_to_image(param->ptr, "../images/backgroundtest.xpm", &width, &height);
    if (!param->img)
    {
        mlx_destroy_window(param->ptr, param->window);
        free_map(map, map_height - 1);
        return;
    }

    mlx_put_image_to_window(param->ptr, param->window, param->img, 0, 0);
    draw_map(map, param);

    /* register hooks once (cast to silence incompatible-pointer warnings) */
    mlx_key_hook(param->window, (int (*)())key_presses, param);
    mlx_hook(param->window, 17, 0L, (int (*)())close_after_x, param);

    mlx_loop(param->ptr);

    /* cleanup after loop ends */
    if (param->img)
        mlx_destroy_image(param->ptr, param->img);
    if (param->window)
        mlx_destroy_window(param->ptr, param->window);
#ifdef mlx_destroy_display
    mlx_destroy_display(param->ptr);
#endif
    free_map(map, map_height - 1);
    /* do not free(param->ptr) - mlx manages its internal memory */
}

int main(void)
{
    t_mlx_param param;

    /* initialize fields to NULL for safe cleanup */
    param.ptr = NULL;
    param.window = NULL;
    param.img = NULL;

    init_and_open_window(&param);
    return (0);
}

