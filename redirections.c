/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 16:43:21 by mayahiao          #+#    #+#             */
/*   Updated: 2026/07/24 21:22:52 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
int check_redirections(t_tools *tools)
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
           if(output_redirection(file->value))
               return (-1);
       }
       if (token->type == TOKEN_REDIR_IN)
       {
           if(!current->next)
               return (-1);
           file = current->next->content;
           if(input_redirection(file->value))
               return (-1);
       }
       if (token->type == TOKEN_APPEND)
       {
           if(!current->next)
               return (-1);
           file = current->next->content;
           if(append_redirection(file->value))
               return (-1);
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
int input_redirection(char *file)
{
   int fd;
   fd = open(file, O_RDONLY);
   if (fd == -1)
       return (-1);
   if (dup2(fd, STDIN_FILENO) == -1)
   {
       close(fd);
       return(-1) ;
   }
   close(fd);
   return (0);
}
int append_redirection(char *file)
{
     int fd;
   fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
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

void heredoc_redirection(char *delimiter)
{
   int pipe_fd[2];
   char    *line;
   
   if(pipe(pipe_fd) == -1)
       return ;
   while(1)
   {
       line = readline("> ");
       if(!line)
           return ;
       if(strcmp(line, delimiter) == 0)
       {
           free(line);
           break;
       }
       write(pipe_fd[1], line, ft_strlen(line));
       write(pipe_fd[1], "\n", 1);
       free(line);
   }
   close(pipe_fd[1]);
   if(dup2(pipe_fd[0], STDIN_FILENO) == -1)
   {
       close(pipe_fd[0]); return ;
   }
   close(pipe_fd[0]); return ;
}
