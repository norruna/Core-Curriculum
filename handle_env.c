#include "minishell.h"



void handle_env(char *path)
{
    int fd;
    static char *buff;
    buff = malloc((sizeof(char) * 2) + 1);
    fd = open(path, O_RDONLY);
    if (fd < 0 || read(fd,0,0) < 1)
    {
        if (buff)
            free(buff);
        perror("/usr/bin/env");
        return ;
    }
    int bytes = read(fd,buff,1);
    while (bytes > 0)
    {
        write(1,&buff,1);
        bytes = read(fd,buff,1);
    }
    free(buff);
    close (fd);
}      
