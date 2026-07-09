/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 16:28:57 by mayahiao          #+#    #+#             */
/*   Updated: 2026/07/08 15:03:39 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_path(char *line)
{
        
	if (strcmp(line, "ls") == 0)
		return ("/bin/ls");
	if (strcmp(line, "pwd") == 0)
		return ("/bin/pwd");
	if (strcmp(line, "cat") == 0)
		return ("/bin/cat");
	if (strcmp(line, "env") == 0)
		return("/bin/env");
	return (NULL);
}
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

void	run_command(char **envp, t_tools *tools)
{
	pid_t	pid;
	int		status;
	char	*path;
	char	*args[2];
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
		return ;
	}
	args[0] = path;
	args[1] = NULL;
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return;
	}
	if (pid == 0)
	{
		execve(path, args, NULL);
		perror("execve");
		exit(1);
	}
	waitpid(pid, &status, 0);
}
