/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 21:55:44 by maleibig          #+#    #+#             */
/*   Updated: 2026/07/23 13:55:15 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	error_tokenizer_exit(char *msg, t_tools *tools)
{
	// TO DO cleanup before exit
    (void) tools;
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}
//from run_command.c to stop segfaulting after redirections
void	close_stdout(int save_stdout)
{
		dup2(save_stdout, STDOUT_FILENO);
		close (save_stdout);
}

void	close_stdin(int save_stdin)
{
		dup2(save_stdin, STDIN_FILENO);
		close (save_stdin);
}