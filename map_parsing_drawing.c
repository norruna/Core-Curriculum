/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_drawing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 15:25:48 by mayahiao          #+#    #+#             */
/*   Updated: 2026/03/25 16:32:43 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map, int rows)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (i < rows)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

/* parse_map: returns NULL on error */
static char	*copy_line(char *line)
{
	int		len;
	char	*result;
	int		k;

	len = 0;
	while (line[len] && line[len] != '\n')
		len++;
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	k = 0;
	while (k < len)
	{
		result[k] = line[k];
		k++;
	}
	result[len] = '\0';
	return (result);
}

static char	**fill_map(int fd, char **map, int count)
{
	char	*line;
	int		i;

	i = 0;
	while (i < count)
	{
		line = get_next_line(fd);
		if (!line)
			return (free_map(map, i), close(fd), NULL);
		map[i] = copy_line(line);
		free(line);
		if (!map[i])
			return (free_map(map, i), close(fd), NULL);
		i++;
	}
	map[i] = NULL;
	return (map);
}

char	**parse_map(char *file)
{
	char	**map;
	int		count;
	int		fd;

	if (!is_valid(file))
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	count = count_map_lines(file);
	map = malloc((count + 1) * sizeof(char *));
	if (!map)
		return (close(fd), NULL);
	if (!fill_map(fd, map, count))
	{
		close(fd);
		return (NULL);
	}
	close (fd);
	return (map);
}
