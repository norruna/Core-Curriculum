/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 21:28:43 by mayahiao          #+#    #+#             */
/*   Updated: 2026/07/26 00:39:07 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* typedef struct s_command
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

typedef struct s_redirect
{
	t_token_type	type;
	char			*target;
}					t_redirect; */



t_command   *init_commands(int	command_count, int redirect_count)
{
	t_command *commands;
	t_redirect	*redirects;
	int			i;
	int			j;

	i = 0;
	commands = (t_command *)malloc((sizeof(t_command) * command_count));
	if (!commands)
		return (0);
	while (i < command_count)
	{
		commands[i].argv = NULL;
		commands[i].redir_count = 0;
		redirects = (t_redirect *)malloc((sizeof(t_redirect) * redirect_count));
		if (!redirects)
			return (0);
		j = 0;
		while (j < redirect_count)
		{
			commands[i].redirects[j].target = NULL;
			commands[i].redirects[j].type = 0;
			j++;
		}
		i++;
	}
	return (commands);
}
void	free_commands(t_command *commands, int command_count, int redirect_count)
{
	int	i;
	int	j;

	i = 0;
	while (i < command_count)
	{
		free(commands[i].argv);
		j = 0;
		while (j < redirect_count)
		{
			free(commands[i].redirects[j].target);
			j++;	
		}
		i++;
	}
	free(commands);
}
t_list	*skip_command(t_list *current)
{
	t_token *token;
	while (current)
	{
		token = current->content;
		if (token->type == TOKEN_PIPE)
			return(current->next);
		current = current->next;
	}
	return (NULL);
}

/* t_command   *fill_commands(t_tools *tools)
{
    t_command	*commands;
    t_list		*current;
	t_token		*token;
	int			i;

	i = 0;
	current = tools->token_list;
	if (!current)
		return (0);
	while (current)
	{
		token = current->content;
		if (token->type == TOKEN_APPEND || token->type == TOKEN_HEREDOC || token->type == TOKEN_REDIR_IN || token->type == TOKEN_REDIR_IN)
		{
			//fill_redirects(token);
			i++;
		}
		else
		{
			//commands[i].argv = make_argv(token);	
			i++;
		}
		current = current->next;
	}
    return (commands);   
} */
