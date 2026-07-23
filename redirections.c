/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 16:43:21 by mayahiao          #+#    #+#             */
/*   Updated: 2026/07/23 03:56:06 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "minishell.h"


 int check_output_redirections(t_tools *tools)
 {
    t_list *current;
    t_token *file;
    t_token *token;
    
    current = tools->token_list;
    while(current)
    {
        token = current->content;
        if (token->type == TOKEN_REDIR_OUT)
        {
            if(!current->next)
                return (-1);
            file = current->next->content;
            return(output_redirection(file->value));
        }
        current = current->next;
    }
    return (0);
 }

 int output_redirection(char *file)
 {
    int fd;

    fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
        return (-1);
    if (dup2(fd, STDOUT_FILENO) == -1)
    {
        close(fd);
        return(-1) ;
    }
    close(fd);
    return (0);
 }
 
/*  void input_redirection()
 {
    
 }

 void append_redirection()
 {
    
 }

 void heredoc_redirection()
 {
    
 } */