/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_drawing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 15:25:48 by mayahiao          #+#    #+#             */
/*   Updated: 2026/03/23 16:20:10 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map, int i)
{
	if (!map)
		return ;
	while (i >= 0)
	{
		if (map[i])
			free(map[i]);
		i--;
	}
	free(map);
}

/* parse_map: returns NULL on error */
char	**parse_map(char *file)
{
	char	**map;
	int		count;
	int		i;
	char	*line;
	int		fd;
	int		len;

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
		len = 0;
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
void	draw_map(char **map, t_game *game)
{
	int		i;
	int		j;
	int		height;
	int		width;
	void	*img_wall;
	void	*img_player;
	void	*img_collectible;
	void	*img_exit;
	void	*img_grass;

	height = TILE;
	width = TILE;
	img_wall = mlx_xpm_file_to_image(game->ptr, 
			"images/Wall.xpm", &height, &width);
	img_player = mlx_xpm_file_to_image(game->ptr, 
			"images/Player.xpm", &height, &width);
	img_collectible = mlx_xpm_file_to_image(game->ptr, 
			"images/Collectible.xpm", &height, &width);
	img_exit = mlx_xpm_file_to_image(game->ptr, 
			"images/Exit.xpm", &height, &width);
	img_grass = mlx_xpm_file_to_image(game->ptr, 
			"images/Grass.xpm", &height, &width);
	if (!img_exit || !img_collectible || !img_player || !img_wall || !img_grass)
	{
		printf("couldnt find image\n");
		if (img_wall)
			mlx_destroy_image(game->ptr, img_wall);
		if (img_player)
			mlx_destroy_image(game->ptr, img_player);
		if (img_collectible)
			mlx_destroy_image(game->ptr, img_collectible);
		if (img_exit)
			mlx_destroy_image(game->ptr, img_exit);
		if (img_grass)
			mlx_destroy_image(game->ptr, img_grass);
		return ;
	}
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				mlx_put_image_to_window(game->ptr, 
					game->window, img_wall, j * TILE, i * TILE);
			else if (map[i][j] == 'P')
				mlx_put_image_to_window(game->ptr, 
					game->window, img_player, j * TILE, i * TILE);
			else if (map[i][j] == 'C')
				mlx_put_image_to_window(game->ptr, 
					game->window, img_collectible, j * TILE, i * TILE);
			else if (map[i][j] == 'E')
				mlx_put_image_to_window(game->ptr, 
					game->window, img_exit, j * TILE, i * TILE);
			else if (map[i][j] == '0')
				mlx_put_image_to_window(game->ptr, 
					game->window, img_grass, j * TILE, i * TILE);
			j++;
		}
		i++;
	}
	mlx_destroy_image(game->ptr, img_wall);
	mlx_destroy_image(game->ptr, img_collectible);
	mlx_destroy_image(game->ptr, img_exit);
	mlx_destroy_image(game->ptr, img_player);
	mlx_destroy_image(game->ptr, img_grass);
}
