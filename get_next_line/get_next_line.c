/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:45:26 by mayahiao          #+#    #+#             */
/*   Updated: 2025/05/07 13:32:56 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_buffer(int fd)
{
	char	*buffer;
	int		bytes;

	buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	bytes = read (fd, buffer, BUFFER_SIZE);
	while (bytes > 0)
	{
		if (ft_strchr(buffer, '\n'))
			extract_line(buffer);

	}
	return (0);
}

char	*extract_line(char *buffer)
{
	char	*line;

	line = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line)
	{
		free(buffer);
		return (0);
	}
	return (line)
}

char	*get_next_line(int fd)
{

	return(0);
}

