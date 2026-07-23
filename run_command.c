/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 16:28:57 by mayahiao          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/07/23 05:17:53 by mayahiao         ###   ########.fr       */
=======
/*   Updated: 2026/07/08 15:03:39 by mayahiao         ###   ########.fr       */
>>>>>>> a1b6d03773e9202f60701ce895550bbf94b80b0f
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

<<<<<<< HEAD
static char	*get_path(t_token *token)
=======
static char	*get_path(char *line)
>>>>>>> a1b6d03773e9202f60701ce895550bbf94b80b0f
{
        
	if (strcmp(token->value, "ls") == 0)
		return ("/bin/ls");
	return (NULL);
}
<<<<<<< HEAD
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
=======
void handle_env(char **envp)
{
    int i = 0;
    while (envp[i])
    {
        printf("%s",envp[i]);
        i++;
        printf("\n");
    }
}
void	handle_echo(t_tools *tools)
{
	t_list	*current;
	t_token	*token;

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
		printf("%s", token->value);	
		if (current->next)
			printf(" ");	
		current = current->next;
	}
}

void	handle_cd(t_tools *tools)
{
	printf("we re handling cd here\n");
	t_list *current;
	t_token *token;
	
	current = tools->token_list;
	if (!current)
		return ;
	current = current->next;
	if (!current)
		return ;
	token = (t_token *)current->content;
	chdir(token->value);
}

>>>>>>> a1b6d03773e9202f60701ce895550bbf94b80b0f
void	run_command(char **envp, t_tools *tools)
{
	pid_t	pid;
	int		status;
	char	*path;
	char	*args[2];
<<<<<<< HEAD
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
=======
	t_token	*token;
	
	token = (t_token *)tools->token_list->content;
	if (strcmp(token->value,"exit") == 0)
		exit(0);
	if (ft_strncmp(token->value, "echo", 4) == 0)
	{	
		handle_echo(tools);
		return ;
	}
	if (ft_strncmp(token->value, "cd", 2) == 0)
	{
		handle_cd(tools);
		return ;
	}
	path = get_path(token->value);
	if (!path)
	{
		printf("command not found: %s\n", token->value);
		return ;
	}

	if (strcmp(path ,"/bin/env") == 0)
	{
		handle_env(envp);
>>>>>>> a1b6d03773e9202f60701ce895550bbf94b80b0f
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
<<<<<<< HEAD
	close_stdout(save_stdout);

=======
>>>>>>> a1b6d03773e9202f60701ce895550bbf94b80b0f
}
