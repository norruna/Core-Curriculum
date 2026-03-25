/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_valid_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 22:11:18 by nellys-simu       #+#    #+#             */
/*   Updated: 2026/03/25 18:08:04 by mayahiao         ###   ########.fr       */
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

int	valid_chars(char *file)
{
	int		i;
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	if (!line)
		return (close(fd), 0);
	while (line != NULL)
	{
		i = 0;
		while (line[i] && i < ft_strlen(line) - 1)
		{
			if (line[i] != 'P' && line[i] != 'C' 
				&& line[i] != 'E' && line[i] != '0' && line[i] != '1')
				return (free(line), close(fd), get_next_line(-1), 0);
			i++;
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}

int	is_valid(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		printf("Error: Could not open file\n");
		return (0);
	}
	if (!is_rectangular(file))
	{
		ft_printf("Map is not rectangular\n");
		return (0);
	}
	if (!is_surrounded_by_walls(file))
	{
		ft_printf("Map is not surrounded by walls\n");
		return (0);
	}
	if (!count_p_c_e(file))
	{
		return (ft_printf("Not enough exits, players or collectibles\n"), 0);
	}
	if (!valid_chars(file))
		return (ft_printf("invalid characters\n"), 0);
	return (1);
}
