/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_drawing_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nellys-simulation <nellys-simulation@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 22:18:44 by nellys-simu       #+#    #+#             */
/*   Updated: 2026/03/24 22:30:28 by nellys-simu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_img_index(char c)
{
	if (c == '1')
		return (0);
	if (c == 'P')
		return (1);
	if (c == 'C')
		return (2);
	if (c == 'E')
		return (3);
	if (c == '0')
		return (4);
	return (-1);
}

/* draw_map: creates images for tiles and places them on window */
static int	load_images(t_game *game, void **imgs)
{
	int	h;
	int	w;

	h = TILE;
	w = TILE;
	imgs[0] = mlx_xpm_file_to_image(game->ptr, "images/Wall.xpm", &h, &w);
	imgs[1] = mlx_xpm_file_to_image(game->ptr, "images/Player.xpm", &h, &w);
	imgs[2] = mlx_xpm_file_to_image(game->ptr,
			"images/Collectible.xpm", &h, &w);
	imgs[3] = mlx_xpm_file_to_image(game->ptr, "images/Exit.xpm", &h, &w);
	imgs[4] = mlx_xpm_file_to_image(game->ptr, "images/Grass.xpm", &h, &w);
	return (imgs[0] && imgs[1] && imgs[2] && imgs[3] && imgs[4]);
}

static void	destroy_images(t_game *game, void **imgs)
{
	int	k;

	k = 0;
	while (k < 5)
	{
		if (imgs[k])
			mlx_destroy_image(game->ptr, imgs[k]);
		k++;
	}
}

static void	draw_tile(char c, t_game *game, void **imgs, t_pos pos)
{
	int	idx;

	idx = get_img_index(c);
	if (idx >= 0)
		mlx_put_image_to_window(game->ptr, game->window,
			imgs[idx], pos.x, pos.y);
}

void	draw_map(char **map, t_game *game)
{
	void	*imgs[5];
	int		i;
	int		j;

	if (!load_images(game, imgs))
		return (destroy_images(game, imgs));
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			draw_tile(map[i][j], game, imgs, (t_pos){j * TILE, i * TILE});
			j++;
		}
		i++;
	}
	destroy_images(game, imgs);
}
