/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 15:28:32 by mayahiao          #+#    #+#             */
/*   Updated: 2026/03/23 16:32:58 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* close window after pressing X button */
int	close_after_x(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (game && game->ptr)
		mlx_loop_end(game->ptr);
	return (0);
}

/* init and open window, register hooks once */
void	init_and_open_window(t_game *game)
{
	int	map_height;
	int	map_width;
	int	height;
	int	width;
	int	rows;
	int	cols;

	game->map = parse_map("map.ber");
	if (!game->map)
		return ;
	find_player(game);
	count_collectibles(game);
	rows = count_map_lines("map.ber");
	cols = strlen(game->map[0]);
	if (!is_reachable(game->map, rows, cols, game->player_y, game->player_x))
	{
		printf("Map is not reachable: E or C is inaccessible\n");
		free_map(game->map, rows - 1);
		return ;
	}
	map_height = count_map_lines("map.ber");
	map_width = strlen(game->map[0]);
	height = map_height * TILE;
	width = map_width * TILE;
	game->ptr = mlx_init();
	if (!game->ptr)
	{
		free_map(game->map, map_height - 1); 
		return ;
	}
	game->window = mlx_new_window(game->ptr, width, height, "night_routine");
	if (!game->window)
	{
		free_map(game->map, map_height - 1);
		return ;
	}
	game->img = mlx_xpm_file_to_image(game->ptr, 
			"images/backgroundtest.xpm", &width, &height);
	if (!game->img)
	{
		mlx_destroy_window(game->ptr, game->window);
		free_map(game->map, map_height - 1);
		return ;
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
