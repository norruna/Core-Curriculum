/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 15:24:52 by mayahiao          #+#    #+#             */
/*   Updated: 2026/03/23 16:09:01 by mayahiao         ###   ########.fr       */
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

/*check that there is exactly 1 exit 1 player & at least 1 collectible*/
int	count_p_c_e(char *file)
{
	int		exits;
	int		collectibles;
	int		player;
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	exits = 0;
	collectibles = 0;
	player = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		i = 0;
		while (line[i])
		{
			if (line[i] == 'P')
				player++;
			if (line[i] == 'C')
				collectibles++;
			if (line[i] == 'E')
				exits++;
			i++;
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (player != 1 || exits != 1 || collectibles == 0)
		return (0);
	return (1);
}

/* check rectangular: all lines (excluding '\n') must have same length */
int	is_rectangular(char *file)
{
	int		fd;
	int		count;
	char	*line;
	size_t	first_len;
	int		i;
	size_t	len;

	count = count_map_lines(file);
	if (count == 0)
		return (0);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		return (0);
	}
	first_len = 0;
	while (line[first_len] && line[first_len] != '\n')
		first_len++;
	free(line);
	i = 1;
	while (i < count)
	{
		line = get_next_line(fd);
		if (!line)
		{
			close(fd);
			return (0);
		}
		{
			len = 0;
			while (line[len] && line[len] != '\n')
				len++;
			if (len != first_len)
			{
				free(line);
				close(fd);
				return (0);
			}
		}
		free(line);
		i++;
	}
	close(fd);
	return (1);
}

/* check that the map is surrounded by walls ('1') */
int	is_surrounded_by_walls(char *file)
{
	int		fd;
	int		count;
	char	*line;
	int		i;
	int		j;
	int		len;

	count = count_map_lines(file);
	if (count == 0)
		return (0);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		return (0);
	}
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
	for (i = 1; i < count - 1; i++)
	{
		line = get_next_line(fd);
		if (!line)
		{
			close(fd);
			return (0);
		}
		{
			len = 0;
			while (line[len] && line[len] != '\n')
				len++;
			if (len == 0 || line[0] != '1' || line[len - 1] != '1')
			{
				free(line);
				close(fd);
				return (0);
			}
		}
		free(line);
	}
	if (count > 1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			close(fd);
			return (0);
		}
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
	}
	close(fd);
	return (1);
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
	if (!count_P_C_E(file))
	{
		printf("Map doesnt have enough exits, players or collectibles\n");
		return (0);
	}
	return (1);
}
