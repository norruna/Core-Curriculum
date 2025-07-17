/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_home.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:21:34 by mayahiao          #+#    #+#             */
/*   Updated: 2025/07/17 20:54:56 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h> //for printf just testing
#include <X11/keysym.h> //for events
#include "get_next_line.h"

# define TILE 128

//keep track of player position
typedef struct s_position
{
	int		x;
	int		y;
}	t_position;

//struct to handle both connection and window pointers
//more for mlx key hook
typedef struct s_mlx_param
{
	void	*ptr;
	void	*window;
	void	*img;
}	t_mlx_param;


/*****************************/
/*---------------------------*/
/*--MAP----------MANAGEMENT--*/
/*---------------------------*/
/*****************************/

int	count_map_lines(char *file)
{
	int		count;
	char	*line;
	int		fd;
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
//works with no leaks and no errors
int	is_rectangular(char *file)
{
	int		count;
	int		i;
	int		fd;
	char	*line;
	char	*next_line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	i = 0;
	count = count_map_lines(file);
	line = get_next_line(fd);
	if (count == 0)
    {
        if (line)
            free(line);
        close(fd);
        return (0);
    }
	next_line = line;
	while (i < count) 
	{
		if (strlen(line) != strlen(next_line)) //change strlen to ft_strlen
		{
			free(line);
			free(next_line);
			close(fd);
			return (0);
		}
		free(line);
		line = get_next_line(fd);
		next_line = line;
		i++;
	}
	if (next_line)
		free(next_line);
	close (fd);
	return (1);
}

int	is_surrounded_by_walls(char *file)
{
	int		count;
	char	*line;
	int		fd;
	int		i;
	int		j;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	count = count_map_lines(file);
	line = get_next_line(fd);
	if (count == 0)
    {
        if (line)
            free(line);
        close(fd);
        return (0);
    }
	while (i < count)
	{
		if (i == 0 || i == count - 1)
		{
			j = 0;
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
		line = get_next_line(fd);
		i++;
	}
	if (line)
		free(line);
	close(fd);
	return (1);
}
int	is_valid(char *file)
{
	if(is_surrounded_by_walls(file) == 0 || is_rectangular(file) == 0)
	{
		printf("THE MAP ISNT VALID, CANT PARSE"); //change to ft_printf
		return (0);
	}
	return (1);
}
void	free_map(char	**map, int i)
{
	while (i >= 0)
	{
		free(map[i]);
		i--;
	}
	free(map);
}

char	**parse_map(char *file)
{
	char	**map;
	int		count;
	int		i;
	int		j;
	int		k;
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	count = count_map_lines(file);
	map = malloc ((count + 1) * sizeof(char *));
	if(!map)
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
		map[i] = malloc(sizeof(char) * (strlen(line) + 1));
			if (!map[i])
			{	
				free_map(map, i - 1);
				free(line);
				close(fd);
				return (NULL);
			}
		k = 0;
		j = 0;
		while (line[k] && line[k] != '\n')
		{
			if (line[k] == '\n')
			{
				break;
			}	
			map[i][j] = line[k];
			j++;
			k++;
		}
		map[i][j] = '\0';
		i++;
		free(line);
	}
	map[i] = 0;
	close(fd);
	return(map);
}



void	draw_map(char **map, t_mlx_param *param)
{
	int	i;
	int	j;
	int	height = TILE;
	int	width = TILE;
	void *img_wall = mlx_xpm_file_to_image(param->ptr, "../images/Wall.xpm", &height, &width);
    void *img_player = mlx_xpm_file_to_image(param->ptr, "../images/Player.xpm", &height, &width);
    void *img_dad = mlx_xpm_file_to_image(param->ptr, "../images/Dad.xpm", &height, &width);
    void *img_bed = mlx_xpm_file_to_image(param->ptr, "../images/Bed.xpm", &height, &width);
	//void *img_grass = mlx_xpm_file_to_image(param->ptr, "../images/Grass.xpm", &height, &width);

	if (!img_bed || !img_dad || !img_player || !img_wall)
	{
		printf ("couldnt find image\n"); //replace later with ftprintf
		return ;
	}
	i =0;
	while (map[i])
	{
		int j = 0;
		while(map[i][j])
		{
			if (map[i][j] == '1')
				mlx_put_image_to_window(param->ptr, param->window, img_wall, j * TILE,i * TILE);
			else if (map[i][j] == 'P')
				mlx_put_image_to_window(param->ptr, param->window, img_player, j * TILE,i * TILE);
			else if (map[i][j] == 'C')
				mlx_put_image_to_window(param->ptr, param->window, img_dad, j * TILE,i * TILE);
			else if (map[i][j] == 'E')
				mlx_put_image_to_window(param->ptr, param->window, img_bed, j * TILE,i * TILE);
		//	else if (map[i][j] == '0')
			//	mlx_put_image_to_window(param->ptr, param->window, img_grass, j * TILE,i * TILE);
			j++;
		}
		i++;
	}
	mlx_destroy_image(param->ptr, img_wall);
    mlx_destroy_image(param->ptr, img_dad);
    mlx_destroy_image(param->ptr, img_bed);
    mlx_destroy_image(param->ptr, img_player);
	//mlx_destroy_image(param->ptr, img_grass);
}
/*****************************/
/*---------------------------*/
/*--MOVEMENT-----MANAGEMENT--*/
/*---------------------------*/
/*****************************/

/* int key_presses_player(int keysym, t_mlx_param *param)
{
	//change printf to ft_printf later
	if (keysym == XK_w || keysym == XK_W)
		
	{
		printf("You pressed the ESC key, exiting ...\n");
		mlx_loop_end(param->ptr); //doesnt segfault and also doesnt leak like exit(0)
	}
	printf("Thanks for pressing the %d key, nothing happened yet ..\n", keysym);
	return (0);
} */

/*****************************/
/*---------------------------*/
/* WINDOW -------- MANAGEMENT*/
/*---------------------------*/
/*****************************/

int key_presses(int keysym, t_mlx_param *param)
{
	//change printf to ft_printf later
	if (keysym == XK_Escape)
	{
		printf("You pressed the ESC key, exiting ...\n");
		mlx_loop_end(param->ptr); //doesnt segfault and also doesnt leak like exit(0)
	}
	printf("Thanks for pressing the %d key, nothing happened yet ..\n", keysym);
	return (0);
}

void init_and_open_window(t_mlx_param *param)
{
	
	char **map;
	int	map_height;
	int	map_width;
	int height ;
	int	width ;
	if (is_valid("map1.ber") == 0)
		return ;
	map = parse_map("map1.ber"); //var for map
	map_height = count_map_lines("map1.ber");
	map_width = ft_strlen(map[0]); // assuming rectangular map
	height = map_height * TILE;
	width = map_width * TILE;
	param->ptr = mlx_init(); //connect to server
	if (param->ptr == NULL)
	{ 
		free_map(map, map_height - 1);
		return ; //error since xvar use malloc
	}
	param->window = mlx_new_window(param->ptr, width, height, "night_routine");
	if (param->window == NULL)
	{
		free_map(map, map_height - 1);
		free(param->ptr); //close connection
		return ;
	}
	param->img = mlx_xpm_file_to_image(param->ptr , "../images/backgroundtest.xpm" , &width, &height); //putting backgroun image
	if (!param->img)
	{
		mlx_destroy_window(param->ptr, param->window); //close window
		free_map(map, map_height - 1);
		free(param->ptr); //close connection
		return ; //error loading the image
	}
	mlx_put_image_to_window(param->ptr, param->window, param->img, 0,0);
	draw_map(map, param);
	mlx_key_hook(param->window,key_presses,param); //handle key presses
	mlx_loop(param->ptr);
	mlx_destroy_image(param->ptr, param->img);
	mlx_destroy_window(param->ptr, param->window);
	mlx_destroy_display(param->ptr); //destroy the display
	free_map(map, map_height - 1);
	free(param->ptr); //free xvar struct
}

int	main(void)
{
	t_mlx_param	param;

	//for window management section
	init_and_open_window(&param);
	return (0);
}
