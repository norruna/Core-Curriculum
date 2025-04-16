/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelly <nelly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 00:49:51 by nelly             #+#    #+#             */
/*   Updated: 2025/04/12 00:49:52 by nelly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd)
{
	char *buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE));
	if (!buffer)
		return (0);	
	bytes = read (fd, buffer, BUFFER_SIZE);
	if (bytes == -1 || bytes == 0)
    		return (0);
	line = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line)
	{
		free(buffer);
		return (0);
	}
	printf("%s",buffer);
	free(buffer);
	printf("\n");
	return (line);
}

char	*update_line()
{
}

char	*get_next_line(int fd)
{

	return(0);
}

