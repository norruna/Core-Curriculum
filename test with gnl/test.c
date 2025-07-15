
#include "get_next_line.h"

int	count_map_lines(char *file)
{
	int		count;
	char	*line;
	int		fd;
	fd = open(file, O_RDONLY);
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

int	is_rectangular(char *file)
{
	int		count;
	int		i;
	int		fd;
	char	*line;
	char	*next_line;
	
	fd = open(file, O_RDONLY);
	i = 0;
	count = count_map_lines(file);
	line = get_next_line(fd);
	next_line = line;
	while (i < count) 
	{
		if (strlen(line) != strlen(next_line)) //change strlen to ft_strlen
		{
			free(line);
			close(fd);
			return (0);
		}
		free(line);
		line = get_next_line(fd);
		next_line = line;
		i++;
	}
	close (fd);
	return (1);
}
int	is_surrounded_by_walls(char *file)
{
	int		count;
	char	*line;
	int		fd;
	int		i;
	int		j;

	i = 0;
	fd = open("maps_examples/valid_maps/map1.ber", O_RDONLY);
	count = 0;
	line = get_next_line(fd);
	while (i < count)
	{
		j = 0;
		if (i == 0 || i == count - 1)
		{
			while (line[j])
			{
				if (line[j] != '1')
				{
					close(fd);
					return (0);
				}
				j++;
			}
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}

#include <stdio.h>
int	main(void)
{

	char *file = "map1.ber";
	int count = is_rectangular(file);
	if (count == 1)
		printf("map is rectangular :) \n");
	else
		printf("map is not rectangular :(\n");
	int	var;
	var = is_surrounded_by_walls(file);
	if (
	return (0);
}

