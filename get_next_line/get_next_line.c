/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:45:26 by mayahiao          #+#    #+#             */
/*   Updated: 2025/05/07 17:15:11 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;
	i = 0;

	while (str[i])
		i++;
	return (i);
}


char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;
	i = 0;
	dest = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!dest)
		return (NULL);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*read_buffer(int fd, char *buffer, char *line, char *extracted_line)
{
	int		bytes;

	bytes = read (fd, buffer, BUFFER_SIZE);
	while (bytes > 0)
	{
		if (ft_strlen(line) == 0)
			line = ft_strdup(buffer);
		else
			line = ft_strjoin(line, buffer);
		if (ft_strchr(line, '\n') || ft_strchr(line, '\0'))
		{
			extracted_line = extract_line(line, extracted_line);
			free(line); //dont change  this one
			return (extracted_line);
		}
		bytes = read (fd, buffer, BUFFER_SIZE);
	}
	free(line);
	return (0);
}

char	*extract_line(char *line, char *extracted_line)
{
	int		i;
	i = 0;
	while (line[i] != '\n' && line[i] != '\0') //added '\0' but didnt make difference with valgrind
	{
		extracted_line[i] = line[i];
		i++;
	}
	extracted_line[i] = '\0';
	return (extracted_line);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	static char	*extracted_line;
	char	*line;
	
	fd = open("file.txt", O_RDONLY);
	if (fd < 0 || read (fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	line = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line)
	{
		free(buffer);
		return (0);
	}	
	extracted_line = (char *) malloc (sizeof(char) * BUFFER_SIZE + 1);
	if (!extracted_line)
	{
		free(buffer);
		return (NULL);
	}
	extracted_line = read_buffer(fd, buffer, line ,extracted_line);
	free(buffer);
	free(line);
	return (extracted_line);
}

int	main(void)

{
	char	*str;
	int fd = 1;
	str = get_next_line(fd);
	printf("the line is : %s\n",str);
	free(str);
	return (0);
}
