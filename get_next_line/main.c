/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42-berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 01:04:30 by nelly             #+#    #+#             */
/*   Updated: 2025/04/12 02:47:49 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

#define BUFFER_SIZE 1024

int	ft_strlen(const char *str)
{
	int	i = 0;
	while (str[i])
		i++;
	return (i);

}
static char	*ft_strcat(char *dest, const char *src)
{
	int	i;
	int	j;

	j = 0;
	i = ft_strlen(dest);
	while (src[j])
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (0);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	ft_strcat(str, s2);
	return (str);
}

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
	bytes = read (fd, buffer, count);
	printf("bytes read : %ld\n",bytes);
	if (bytes == -1 || bytes == 0)
    	return (0);
	while (bytes > 0)
	{
		bytes = read (fd, buffer, count);
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
		//static char *line = NULL;
		//line = ft_strjoin(line, buffer);
    	printf("\n");
    	free(line_read);
	}
	return(0);
}