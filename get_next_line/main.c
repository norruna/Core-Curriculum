/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42-berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 01:04:30 by nelly             #+#    #+#             */
/*   Updated: 2025/04/12 02:32:50 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(void)
{
    int     fd;
    size_t  count = 25;
    ssize_t bytes;
    char    buffer[BUFFER_SIZE + 1];
    fd = open("file.txt", O_RDONLY);
    if (fd == -1)
        return (0);
    else
        printf("file opened yiiy\n");
    static char *line = NULL;
	bytes = read (fd, buffer, count);
	printf("bytes read : %ld\n",bytes);
	if (bytes == -1)
    	return (0);
	char *line_read = (char *) malloc(sizeof(char) * (bytes + 1));
   if (!line_read)
		return (0);
    int	j = 0;
	while (j < bytes)
	{
		line_read[j] = buffer[j];
		printf("%c",line_read[j]);
		j++;
	}
	line_read[j] = '\0';
    printf("\n");
    free(line_read);
    return(0);
}