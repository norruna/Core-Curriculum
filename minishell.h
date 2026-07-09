/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 19:37:52 by maleibig          #+#    #+#             */
/*   Updated: 2026/07/08 14:05:33 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/types.h>
#include <dirent.h>
#include "libft/libft.h"
#include <signal.h>
// # ifndef BUFFER_SIZE
// #  define BUFFER_SIZE 256
// # endif

typedef enum e_token_type
{
	TOKEN_WORD,
	TOKEN_PIPE,
	TOKEN_REDIR_IN,
	TOKEN_REDIR_OUT,
	TOKEN_APPEND,
	TOKEN_HEREDOC,
}					t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*value;
}					t_token;

typedef struct s_tools
{
	t_list			*token_list;
	char			**env;
}					t_tools;

typedef struct s_redirect
{
	t_token_type	type;
	char			*target;
}					t_redirect;

typedef struct s_command
{
	char			**argv;
	t_redirect		*redirects;
	int				redir_count;
}					t_command;

typedef struct s_pipeline
{
	t_command		*commands;
	int				command_count;
}					t_pipeline;

////***tokenizer.c***////

t_list				*tokenizer(char *line, t_tools *tools);

////***parser.c***////

void				parser(t_tools *tools);

////***cleanup.c***////
int					error_tokenizer_exit(char *msg, t_tools *tools);


//run_command

void	run_command(char **envp, t_tools *tools);
#endif