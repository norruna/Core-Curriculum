#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 50

#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h> //for printf testing

char	*get_next_line(int fd);

#endif
