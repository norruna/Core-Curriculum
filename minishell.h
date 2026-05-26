#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include<readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/types.h>
#include <dirent.h>
#include "libft/libft.h"
#include <signal.h>

void cd_path(char *line);
void execute_cd(char *path);
void	handle_sigint(int sig);
void	run_command(char *line, char **envp);
void    handle_env(char **path);
void    handle_input(char **path);
#endif
