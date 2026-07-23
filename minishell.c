/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 19:33:20 by maleibig          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/07/23 05:11:08 by mayahiao         ###   ########.fr       */
=======
/*   Updated: 2026/07/08 15:07:25 by mayahiao         ###   ########.fr       */
>>>>>>> a1b6d03773e9202f60701ce895550bbf94b80b0f
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		printf("%s", env[i]);
		i++;
		printf("\n");
	}
}
void	free_token(void *content)
{
	t_token	*token;

	token = (t_token *)content;
	if (!token)
		return;
	free(token->value);
	free(token);
}

int	main(int argc, char **argv, char **env)
{
	char *line;
	t_tools tools;
	line = (char *)NULL;
	(void)argc;
	(void)argv;
    (void)env;
    
    tools.token_list = NULL;
	// print_env(env);
	while (1)
	{
		// write(1, "microshell > ", 13);
		line = readline("minishell > ");
		if (line == NULL)
		{
			write(1, "\n", 1);
			break ;
		}
		if (*line)
			add_history(line);
		tokenizer(line, &tools);
		run_command(env, &tools);	
		ft_lstclear(&tools.token_list, free_token);
		free(line);
	}
	clear_history();
	return (0);
}