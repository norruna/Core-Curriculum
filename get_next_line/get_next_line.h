/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:45:17 by mayahiao          #+#    #+#             */
/*   Updated: 2025/05/07 17:11:28 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
//# define BUFFER_SIZE 5 //comment when testing

# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> //for printf testing

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char    *ft_strcat(char *dest, const char *src);
int     ft_strlen(const char *str);
char	*read_buffer(int fd, char *line);
char	*extract_line(char *line);
char    *ft_strchr(const char *s, int c);
char	*ft_substr(char const *s1, int start, size_t len);
char	*ft_strdup(const char *s);
#endif
