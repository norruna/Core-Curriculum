/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_accessible.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 15:23:42 by mayahiao          #+#    #+#             */
/*   Updated: 2026/03/23 16:59:13 by mayahiao         ###   ########.fr       */
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
	f->visited[y][x] = 1;
	flood_fill(map, f, y - 1, x);
	flood_fill(map, f, y + 1, x);
	flood_fill(map, f, y, x - 1);
	flood_fill(map, f, y, x + 1);
}
int	is_visited(char **map, int rows, int cols)
{
	
}

int	is_reachable(char **map, int rows, int cols, int py, int px)
{
	t_flood	f;
	int		i;
	int		j;
	int		found_e;
	int		found_c;

	f.visited = malloc(rows * sizeof(int *));
	if (!f.visited)
		return (0);
	i = 0;
	while (i < rows)
	{
		f.visited[i] = malloc(cols * sizeof(int));
		if (!f.visited[i])
		{
			while (--i >= 0)
				free(f.visited[i]);
			free(f.visited);
			return (0);
		}
		while (j < cols)
		{
			f.visited[i][j] = 0;
			j++;
		}
		i++;
	}
	f.rows = rows;
	f.cols = cols;
	flood_fill(map, &f, py, px);
	found_e = 0;
	found_c = 0;
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (f.visited[i][j])
			{
				if (map[i][j] == 'E')
					found_e = 1;
				if (map[i][j] == 'C')
					found_c = 1;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (i < rows)
		free(f.visited[i++]);
	free(f.visited);
	return (found_e && found_c);
}
