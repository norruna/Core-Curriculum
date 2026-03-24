/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nellys-simulation <nellys-simulation@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 15:27:40 by mayahiao          #+#    #+#             */
/*   Updated: 2026/03/24 22:26:46 by nellys-simu      ###   ########.fr       */
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

static int	handle_target(t_game *game, char target)
{
	if (target == '1')
		return (0);
	if (target == 'E' && game->collected < game->collectibles)
		return (0);
	if (target == 'E' && game->collected == game->collectibles)
	{
		printf("You win! Moves: %d\n", game->moves + 1);
		mlx_loop_end(game->ptr);
		return (0);
	}
	if (target == 'C')
	{
		game->collected++;
		game->map[game->player_y][game->player_x] = '0';
	}
	return (1);
}

void	move_player(t_game *game, int dx, int dy)
{
	int		new_x;
	int		new_y;
	char	target;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	target = game->map[new_y][new_x];
	if (!handle_target(game, target))
		return ;
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
