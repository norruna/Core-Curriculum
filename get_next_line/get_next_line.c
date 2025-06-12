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

char	*next_leftover(char *s)
{
	int		i = 0;
	int		j = 0;
	char	*new;

	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	i++;
	new = malloc(ft_strlen(s) - i + 1);
	if (!new)
		return (NULL);
	while (s[i])
	{
		new[j] = s[i];
		i++;
		j++;
	}
	new[j] = '\0';
	free(s);
	return (new);
}

char	*read_fd(int fd, char *stash)
{
	char	*buf;
	int		bytes = 1;

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
	static char	*leftover;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (leftover)
		{
			free(leftover);
			leftover = NULL;
		}
		return (NULL);
	}
	leftover = read_fd(fd, leftover);
	if (!leftover)
		return (NULL);
	line = extract_line(leftover);
	leftover = next_leftover(leftover);
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
