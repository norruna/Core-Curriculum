/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:45:26 by mayahiao          #+#    #+#             */
/*   Updated: 2025/05/07 16:11:47 by mayahiao         ###   ########.fr       */
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

char	*read_buffer(int fd)
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
		if (ft_strchr(buffer, '\n'))
			extract_line(buffer, line);
		bytes = read (fd, buffer, BUFFER_SIZE);
	}
	return (0);
}

char	*extract_line(char *buffer, char *line)
{
	char	*extracted_line;
	int		i;

	extracted_line = (char *) malloc (sizeof(char) * BUFFER_SIZE + 1);
	if (!extract_line)
	{
		free (buffer);
		free (line);
		return (NULL);
	}
	i = 0;
	while (line[i] != '\n')
	{
		extracted_line[i] = line[i];
		i++;
	}
	extracted_line[i] = '\0';
	return (extracted_line);
}

/* char	*get_next_line(int fd)
{

	return(0);
}
 */
