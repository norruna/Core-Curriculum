/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_valid_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 22:13:18 by nellys-simu       #+#    #+#             */
/*   Updated: 2026/03/25 15:14:02 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* check that the map is surrounded by walls ('1') */
static int	is_all_walls(char *line)
{
	int	j;

	j = 0;
	while (line[j] && line[j] != '\n')
	{
		if (line[j] != '1')
			return (0);
		j++;
	}
	return (1);
}

static int	check_middle(int fd, int count)
{
	char	*line;
	int		len;
	int		i;

	i = 1;
	while (i < count - 1)
	{
		line = get_next_line(fd);
		if (!line)
			return (close(fd), 0);
		len = 0;
		while (line[len] && line[len] != '\n')
			len++;
		if (len == 0 || line[0] != '1' || line[len - 1] != '1')
			return (free(line), close(fd), get_next_line(-1), 0);
		free(line);
		i++;
	}
	return (1);
}

static int	check_first_last(int fd, int count)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (close(fd), 0);
	if (!is_all_walls(line))
		return (free(line), close(fd), 0);
	free(line);
	if (!check_middle(fd, count))
		return (0);
	if (count > 1)
	{
		line = get_next_line(fd);
		if (!line)
			return (close(fd), 0);
		if (!is_all_walls(line))
			return (free(line), close(fd), get_next_line(-1), 0);
		free(line);
	}
	return (1);
}

int	is_surrounded_by_walls(char *file)
{
	int		fd;
	int		count;

	count = count_map_lines(file);
	if (count == 0)
		return (0);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	if (!check_first_last(fd, count))
		return (0);
	close(fd);
	return (1);
}
