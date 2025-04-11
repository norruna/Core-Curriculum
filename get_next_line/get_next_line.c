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

char	*fill_buffer(char *line)
{
	char	*buffer;
	size_t	i;
	ssize_t bytes;

	bytes = read(fd, 
	while (i < BUFFER_SIZE )
	{
		buffer[i] = line[i];
		i++;
	}
}

char	*fill_line()
{
&& line[i] != '\0' && line[i] != '\n'

}

char	*get_next_line(int fd)
{
	
}

