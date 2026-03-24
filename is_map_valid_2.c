/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_valid_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nellys-simulation <nellys-simulation@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 22:11:18 by nellys-simu       #+#    #+#             */
/*   Updated: 2026/03/24 22:21:56 by nellys-simu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_collectibles(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->collectibles = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				game->collectibles++;
			j++;
		}
		i++;
	}
}

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

int	is_valid(char *file)
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
	if (!count_p_c_e(file))
	{
		printf("Map doesnt have enough exits, players or collectibles\n");
		return (0);
	}
	return (1);
}
