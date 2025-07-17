
#include "get_next_line.h"

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
//works with no leaks and no errors
int	is_rectangular(char *file)
{
	int		count;
	int		i;
	int		fd;
	char	*line;
	char	*next_line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
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
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	count = count_map_lines(file);
	line = get_next_line(fd);
	while (i < count)
	{
		if (i == 0 || i == count - 1)
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
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (1);
}
void	free_map(char	**map, int i)
{
	while (i >= 0)
	{
		free(map[i]);
		i--;
	}
	free(map);
}

char	**parse_map(char *file)
{
	char	**map;
	int		count;
	int		i;
	int		j;
	int		k;
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	count = count_map_lines(file);
	map = malloc ((count + 1) * sizeof(char *));
	if(!map)
	{ 
		close(fd);
		return (NULL);
	}
	i = 0;
	while (i < count)
	{
		line = get_next_line(fd);
		if (!line)
			{	
				free_map(map, i - 1);
				close(fd);
				return (NULL);
			}
		map[i] = malloc(sizeof(char) * (strlen(line) + 1));
			if (!map[i])
			{	
				free_map(map, i - 1);
				free(line);
				close(fd);
				return (NULL);
			}
		k = 0;
		j = 0;
		while (line[k])
		{
			map[i][j] = line[k];
			j++;
			k++;
		}
		map[i][j] = '\0';
		i++;
		free(line);
	}
	map[i] = 0;
	close(fd);
	return(map);
}

#include <stdio.h>
int	main(void)
{
	//THE LEAKS ARE COMING FROM MAIN FUNCTION IGNORING SINCE ITS FOR TESTING
	char	**map;
	char *file = "map1.ber";
	int count = is_rectangular(file);
	if (count == 1)
		printf("map is rectangular :) \n");
	else
		printf("map is not rectangular :(\n");
	int	index;
	index = is_surrounded_by_walls(file);
	if (index == 0)
		printf("the map is not surrounded by walls :(\n");
	else
		printf("the map is surrounded by walls :)\n");
	map = parse_map(file);
	int i =0;
	while (map[i])
	{
		int j = 0;
		while(map[i][j])
		{
			printf("%c,",map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	free_map(map, count);
	return (0);

}

