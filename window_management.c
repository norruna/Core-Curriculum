/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 15:28:32 by mayahiao          #+#    #+#             */
/*   Updated: 2026/03/25 16:36:25 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* close window after pressing X button */
int	close_after_x(t_game *game)
{
	cleanup(game);
	exit(0);
}

/* init and open window, register hooks once */
static int	init_map(t_game *game)
{
	game->map = parse_map("map.ber");
	if (!game->map)
		return (0);
	game->rows = count_map_lines("map.ber");
	game->cols = ft_strlen(game->map[0]);
	find_player(game);
	count_collectibles(game);
	game->collected = 0;
	return (1);
}

static int	check_map(t_game *game)
{
	t_flood	f;

	f.rows = game->rows;
	f.cols = game->cols;
	f.py = game->player_y;
	f.px = game->player_x;
	if (!is_reachable(game->map, &f))
	{
		free_map(game->map, game->rows);
		game->map = NULL;
		return (0);
	}
	return (1);
}

static int	init_mlx(t_game *game)
{
	game->ptr = mlx_init();
	if (!game->ptr)
		return (0);
	game->window = mlx_new_window(game->ptr,
			game->cols * TILE, game->rows * TILE, "night_routine");
	if (!game->window)
		return (0);
	game->img = mlx_xpm_file_to_image(game->ptr,
			"images/backgroundtest.xpm",
			&(int){game->cols * TILE}, &(int){game->rows * TILE});
	if (!game->img)
		return (0);
	return (1);
}

void	init_and_open_window(t_game *game)
{
	if (!init_map(game))
		return ;
	if (!check_map(game))
		return (cleanup(game));
	if (!init_mlx(game))
		return(cleanup(game));
	mlx_put_image_to_window(game->ptr, game->window, game->img, 0, 0);
	draw_map(game->map, game);
	mlx_key_hook(game->window, (int (*)())key_presses, game);
	mlx_hook(game->window, 17, 0L, (int (*)())close_after_x, game);
	mlx_loop(game->ptr);
	cleanup(game);
}
