/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 16:28:57 by mayahiao          #+#    #+#             */
/*   Updated: 2026/07/23 17:08:31 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_path(t_token *token)
{
        
	if (strcmp(token->value, "ls") == 0)
		return ("/bin/ls");
	return (NULL);
}
static void check_exit(t_tools *tools)
{
	t_token	*token;
	
	token = (t_token *)tools->token_list->content;
	if (strcmp(token->value,"exit") == 0)
		exit(0);
}
 static int check_echo(t_tools *tools)
{
	t_token	*token;
	t_list	*current = tools->token_list;
	if (!current)
		return (0);
	token = current->content;
	
	if (strcmp(token->value, "echo") != 0)
		return(0) ;
	current = current->next;
	if(!current)
		return (0);
	token = current->content;
	if (strcmp(token->value, "-n") != 0)
		return (0);
	handle_echo(tools);
	return (1);
}
static int check_cd(t_tools *tools)
{
	t_token *token;
	
	token = (t_token *)tools->token_list->content;
	if (strcmp(token->value, "cd") != 0)
		return(0) ;
	handle_cd(tools);
	return (1);
}
static int check_env(t_tools *tools, char **envp)
{
	t_token *token;
	
	token = (t_token *)tools->token_list->content;
	if (strcmp(token->value, "env") != 0)
		return(0) ;
	handle_env(envp);
	return (1);

}
static int check_pwd(t_tools *tools)
{
	t_token *token;
	
	token = (t_token *)tools->token_list->content;
	if (strcmp(token->value, "pwd") != 0)
		return(0) ;
	handle_pwd();
	return (1);
}
static char *check_heredoc(t_tools *tools)
{
	t_token *token;
	t_list	*current;
	char	*delimiter;

	current = tools->token_list;
	if (!current)
		return (0);
	while (current)
	{
		token = current->content;
		if (token->type == TOKEN_HEREDOC)
		{
			current = current->next;
			if (!current)
				return (0);
			delimiter = (char *)malloc(sizeof(char) * (ft_strlen(token->value) + 1));
			if(!delimiter)
				return (0);
			token = current->content;
			//printf("current->content is %s\n",(char *)token->value);
			strcpy(delimiter, token->value);
			//printf("delimister is %s\n",delimiter);
			return (delimiter);
		}
		current = current->next;
	}
	return (0);
}
static void do_checks(t_tools *tools, int save_stdout, int save_stdin, char **envp)
{
	char	*delimiter;
	
	delimiter = check_heredoc(tools);
	if (delimiter)
	{
		heredoc_redirection(delimiter);
		free(delimiter);
	}
	if (check_redirections(tools) == -1)
	{
		close_stdout(save_stdout);
		close_stdin(save_stdin);
		return ;
	}
	check_exit(tools);
	if (check_echo(tools) || check_pwd(tools) || check_env(tools,envp))
	{
		close_stdout(save_stdout);
		close_stdin(save_stdin);
		return ;
	}
	check_cd(tools);
}
static void do_execve(char **envp, char *path)
{
	char	*args[2];
	
	pid_t	pid;
	
	int		status;
	
	args[0] = path;
	args[1] = NULL;
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return ;
	}
	if (pid == 0)
	{
		execve(path, args, envp);
		perror("execve");
		exit (1);
	}
	waitpid(pid, &status, 0);
}
void	run_command(char **envp, t_tools *tools)
{
	
	int		save_stdout;
	int		save_stdin;
	t_token *token;
	char	*path;

	save_stdout = dup(STDOUT_FILENO);
	save_stdin = dup(STDIN_FILENO);
	
	do_checks(tools,save_stdout, save_stdin, envp);
	token = (t_token *)tools->token_list->content;
	path = get_path(token);
	if (!path)
	{
		close_stdout(save_stdout);
		close_stdin(save_stdin);
		return ;
	}
	do_execve(envp, path);
	close_stdout(save_stdout);
	close_stdin(save_stdin);

}
