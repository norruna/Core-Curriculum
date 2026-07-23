/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 16:59:39 by mayahiao          #+#    #+#             */
/*   Updated: 2026/07/23 04:49:46 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void handle_env(char **envp)
{
    int i = 0;
    while (envp[i])
    {
		write(STDOUT_FILENO, envp[i], ft_strlen(envp[i]));
        i++;
        write(STDOUT_FILENO, "\n", 1);
    }
}
void	handle_echo(t_tools *tools)
{
	t_list	*current;
	t_token	*token;
	t_token *next_token;
	current = tools->token_list;
	if (!current)
		return ;
	current = current->next;
	if (!current)
		return ;
	token = (t_token *)current->content;
	if (strcmp(token->value, "-n") != 0)
		return ;
	current = current->next;
	while (current)
	{
		token = (t_token *)current->content;
		if (token->type == TOKEN_REDIR_OUT)
			break ;
		write(STDOUT_FILENO, token->value, ft_strlen(token->value));
		if (current->next)
		{
			next_token = current->next->content;
			if (next_token->type != TOKEN_REDIR_OUT)
				write(STDOUT_FILENO, " ", 1);	
		}
		current = current->next;
	}
}

void	handle_cd(t_tools *tools)
{
	t_list	*current;
	t_token *token;

	current = tools->token_list;
	if (!current)
		return ;
	current = current->next;
	if (!current)
		return ;
	token = (t_token *)current->content;
	if (chdir(token->value) == -1)
		perror("path not found");
}

void	handle_pwd(void)
{
	char *str;
	str = getcwd(NULL,0);
	if (!str)
	{
		perror("pwd");
		return ;
	}
	write(STDOUT_FILENO, str, ft_strlen(str));
	write(STDOUT_FILENO, "\n", 1);
	free(str);
}
