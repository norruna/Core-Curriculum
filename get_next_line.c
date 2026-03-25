/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 18:31:45 by mayahiao          #+#    #+#             */
/*   Updated: 2026/03/25 15:03:54 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*next_line(char *s)
{
	int		i;
	int		j;
	char	*new_buffer;

	i = 0;
	j = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	i++;
	new_buffer = malloc(ft_strlen(s) - i + 1);
	if (!new_buffer)
		return (NULL);
	while (s[i])
		new_buffer[j++] = s[i++];
	new_buffer[j] = '\0';
	free(s);
	return (new_buffer);
}

char	*read_buffer(int fd, char *stash)
{
	char	*buf;
	int		bytes;

	bytes = 1;
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (!ft_strchr(stash, '\n') && bytes > 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(buf);
			if (stash)
				free(stash);
			return (NULL);
		}
		buf[bytes] = '\0';
		stash = ft_strjoin(stash, buf);
	}
	free(buf);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd == -1)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (buffer)
		{
			free(buffer);
			buffer = NULL;
		}
		return (NULL);
	}
	buffer = read_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	line = extract_line(buffer);
	buffer = next_line(buffer);
	return (line);
}

/*int	main(void)
{
	char	*str = NULL;
	int		fd = open("file.txt", O_RDONLY);

	if (fd < 0)
	{
		perror("open");
		return (1);
	}
	while (fd != -1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		printf("the line is : %s", str);
		free(str);
	}
	close(fd);
	return (0);
}*/
