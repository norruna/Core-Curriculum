/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:21:34 by mayahiao          #+#    #+#             */
/*   Updated: 2026/03/25 15:55:48 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void cleanup(t_game *game)
{
    if (!game)
        return;

    if (game->img)
        mlx_destroy_image(game->ptr, game->img);

    if (game->window)
        mlx_destroy_window(game->ptr, game->window);

    if (game->ptr)
    {
        mlx_destroy_display(game->ptr);
        free(game->ptr);
    }

    if (game->map)
        free_map(game->map, game->rows);
}

int	main(void)
{
	t_game	game;

	if (is_valid("map.ber") == 0)
		return (0);
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
