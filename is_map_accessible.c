/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_accessible.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 15:23:42 by mayahiao          #+#    #+#             */
/*   Updated: 2026/03/25 17:14:19 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
// recursive DFS flood fill
void	flood_fill(char **map, t_flood *f, int y, int x)
{
	if (y < 0 || x < 0 || y >= f->rows || x >= f->cols)
		return ;
	if (f->visited[y][x] || map[y][x] == '1')
		return ;
	if (map[y][x] == 'E')
	{
		f->visited[y][x] = 1;
		return ;
	}
	f->visited[y][x] = 1;
	flood_fill(map, f, y - 1, x);
	flood_fill(map, f, y + 1, x);
	flood_fill(map, f, y, x - 1);
	flood_fill(map, f, y, x + 1);
}

static int	**alloc_visited(int rows, int cols)
{
	int	**visited;
	int	i;

	visited = malloc(rows * sizeof(int *));
	if (!visited)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		visited[i] = calloc(cols, sizeof(int));
		if (!visited[i])
		{
			while (--i >= 0)
				free(visited[i]);
			free(visited);
			return (NULL);
		}
		i++;
	}
	return (visited);
}

static int	check_found(char **map, t_flood *f, t_game *game)
{
	int	i;
	int	j;
	int	found_e;
	int	found_c;

	found_e = 0;
	found_c = 0;
	i = 0;
	while (i < f->rows)
	{
		j = 0;
		while (j < f->cols)
		{
			if (f->visited[i][j] && map[i][j] == 'E')
				found_e = 1;
			if (f->visited[i][j] && map[i][j] == 'C')
				found_c++;
			j++;
		}
		i++;
	}
	if (found_c != game->collectibles)
		return (0);
	return (found_e && found_c);
}

int	is_reachable(char **map, t_flood *f, t_game *game)
{
	int	result;
	int	i;

	f->visited = alloc_visited(f->rows, f->cols);
	if (!f->visited)
		return (0);
	flood_fill(map, f, f->py, f->px);
	result = check_found(map, f, game);
	i = 0;
	while (i < f->rows)
		free(f->visited[i++]);
	free(f->visited);
	return (result);
}
