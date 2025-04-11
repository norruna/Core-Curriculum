/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelly <nelly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 01:04:30 by nelly             #+#    #+#             */
/*   Updated: 2025/04/12 01:32:30 by nelly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
    FILE    *file;
    int     fd;
    size_t  count = 25;
    ssize_t bytes;

    fd = open("file.txt", O_RDONLY);
    if (fd == -1)
        return (0);
    else
        printf("file opened yiiy\n");
    static char *buffer;
    bytes = read (fd, buffer, count);
    printf("bytes read : %ld\n",bytes);
    char *line = (char *)malloc (sizeof(char) * (count + 1));
    if (!line)
        return NULL;
    if (bytes == -1)
    {
        free (buffer);
        return (0);
    }
    int i = 0;
    while (buffer[i])
    {
        printf("%c",buffer[i]);
        i++;
    }
    printf("\n");
    free(buffer);
    return(0);
}