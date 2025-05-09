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

char	*read_buffer(int fd, char *extracted_line)
{
	char	*buffer;
	int		bytes;
	char	*line;

	buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	line = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line)
	{
		free(buffer);
		return (0);
	}
	bytes = read (fd, buffer, BUFFER_SIZE);
	while (bytes > 0)
	{
		ft_strjoin(line, buffer);
		if (ft_strchr(line, '\n'))
		{
			extracted_line = extract_line(line, extracted_line);
			return (extracted_line);
		}
		bytes = read (fd, buffer, BUFFER_SIZE);
	}
	return (0);
}

char	*extract_line(char *line, char *extracted_line)
{
	int		i;

	i = 0;
	while (line[i] != '\n')
	{
		extracted_line[i] = line[i];
		i++;
	}
	extracted_line[i] = '\0';
	return (extracted_line);
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

char	*get_next_line(int fd)
{
	static char	*extracted_line;
	fd = open("file.txt", O_RDONLY);
	if (fd == -1 )
		return (0);
	else
		printf("file opened yiiy\n");
	extracted_line = (char *) malloc (sizeof(char) * BUFFER_SIZE + 1);
	if (!extracted_line)
		return (NULL);
	extracted_line = read_buffer(fd, extracted_line);
	return (0);
}

int	main(void)
{
	char	*str;
	int fd = 1;
	str = get_next_line(fd);
	printf("the line is : %s\n",str);
	return (0);
}
