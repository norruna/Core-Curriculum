/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:45:17 by mayahiao          #+#    #+#             */
/*   Updated: 2025/05/07 12:45:20 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 50

#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h> //for printf testing


char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
static char	*ft_strcat(char *dest, const char *src);
int	ft_strlen(const char *str);
char	*read_line(int fd);
char	*update_line();
#endif
