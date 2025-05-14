/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 18:31:45 by mayahiao          #+#    #+#             */
/*   Updated: 2025/05/14 18:38:26 by mayahiao         ###   ########.fr       */
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

char	*read_buffer(int fd, char *line)
{
	int		bytes;
	char	*buffer;
	char	*temp;

	buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes = read(fd, buffer, BUFFER_SIZE);
	while (bytes > 0)
	{
		buffer[bytes] = '\0';
		if (ft_strlen(line) == 0)
			temp = ft_strdup(buffer);
		else
			temp = ft_strjoin(line, buffer);
		free(line);
		line = temp;
		if (ft_strchr(line, '\n'))
			break ;
		bytes = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	if (bytes < 0 || (bytes == 0 && ft_strlen(line) == 0))
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*extract_line(char *line)
{
	int		i;
	char	*extracted_line;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	extracted_line = (char *)malloc(sizeof(char) * (i + (line[i] == '\n') + 1));
	if (!extracted_line)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		extracted_line[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		extracted_line[i] = '\n';
		i++;
	}
	extracted_line[i] = '\0';
	return (extracted_line);
}

//extracted_line = NULL gives an error
char	*get_next_line(int fd)
{
	static char	*extracted_line;
	char		*line;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!extracted_line)
		extracted_line = ft_strdup("");
	extracted_line = read_buffer(fd, extracted_line);
	if (!extracted_line)
		return (NULL);
	line = extract_line(extracted_line);
	if (!line)
		return (NULL);
	temp = ft_strchr(extracted_line, '\n');
	if (temp)
	{
		temp = ft_strdup(temp + 1);
		free(extracted_line);
		extracted_line = temp;
	}
	else
	{
		free(extracted_line);
		extracted_line = NULL;
	}
	return (line);
}

/*int	main(void)
{
	char	*str;
	int		fd = open("file.txt", O_RDONLY);

	if (fd < 0)
	{
		perror("open");
		return (1);
	}
	while ((str = get_next_line(fd)))
	{
		printf("the line is : %s", str);
		free(str);
	}
	close(fd);
	return (0);
}*/
