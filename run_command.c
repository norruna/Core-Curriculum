/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 16:28:57 by mayahiao          #+#    #+#             */
/*   Updated: 2026/07/23 05:17:53 by mayahiao         ###   ########.fr       */
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

	token = (t_token *)tools->token_list->content;
	
	if (strcmp(token->value, "echo") != 0)
		return(0) ;
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

//to stop segfault hopefully
static void	close_stdout(int save_stdout)
{
		dup2(save_stdout, STDOUT_FILENO);
		close (save_stdout);
}
void	run_command(char **envp, t_tools *tools)
{
	pid_t	pid;
	int		status;
	char	*path;
	char	*args[2];
	int		save_stdout;
	t_token *token;
	
	save_stdout = dup(STDOUT_FILENO);
	if (check_output_redirections(tools) == -1)
	{
		close_stdout(save_stdout);
		return ;
	}
	check_exit(tools);
	if (check_echo(tools) || check_pwd(tools) || check_env(tools,envp))
	{
		close_stdout(save_stdout);
		return ;
	}
	check_cd(tools);
	token = (t_token *)tools->token_list->content;
	path = get_path(token);
	if (!path)
	{
		close_stdout(save_stdout);
		return ;
	}
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
	close_stdout(save_stdout);

}
