/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 15:24:52 by mayahiao          #+#    #+#             */
/*   Updated: 2026/03/25 15:15:29 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*check that there is exactly 1 exit 1 player & at least 1 collectible*/
static void	count_chars(char *line, int *p, int *c, int *e)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'P')
			(*p)++;
		if (line[i] == 'C')
			(*c)++;
		if (line[i] == 'E')
			(*e)++;
		i++;
	}
}

int	count_p_c_e(char *file)
{
	int		exits;
	int		collectibles;
	int		player;
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	exits = 0;
	collectibles = 0;
	player = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		count_chars(line, &player, &collectibles, &exits);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (player != 1 || exits != 1 || collectibles == 0)
		return (0);
	return (1);
}

/* check rectangular: all lines (excluding '\n') must have same length */
static size_t	line_len(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	return (i);
}

static int	check_lines(int fd, size_t first_len, int count)
{
	char	*line;
	int		i;

	i = 1;
	while (i < count)
	{
		line = get_next_line(fd);
		if (!line)
			return (close(fd), 0);
		if (line_len(line) != first_len)
			return (free(line), close(fd), get_next_line(-1), 0);
		free(line);
		i++;
	}
	return (1);
}

int	is_rectangular(char *file)
{
	int		fd;
	int		count;
	char	*line;
	size_t	first_len;

	count = count_map_lines(file);
	if (count == 0)
		return (0);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	if (!line)
		return (close(fd), 0);
	first_len = line_len(line);
	free(line);
	if (!check_lines(fd, first_len, count))
		return (0);
	close(fd);
	return (1);
}
