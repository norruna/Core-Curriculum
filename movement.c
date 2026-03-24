/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 15:27:40 by mayahiao          #+#    #+#             */
/*   Updated: 2026/03/23 16:25:55 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
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

void	move_player(t_game *game, int dx, int dy)
{
	int		new_x;
	int		new_y;
	char	target;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	target = game->map[new_y][new_x];
	if (target == '1')
		return ;
	if (target == 'E' && game->collected < game->collectibles)
		return ;
	if (target == 'E' && game->collected == game->collectibles)
	{
		printf("You win! Moves: %d\n", game->moves + 1);
		mlx_loop_end(game->ptr);
		return ;
	}
	if (target == 'C')
	{
		game->collected++;
		game->map[new_y][new_x] = '0';
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
int	key_presses(int keysym, void *param)
{
	t_game	*game;

	game = (t_game *)param;
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
