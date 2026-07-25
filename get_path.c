/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 21:46:35 by mayahiao          #+#    #+#             */
/*   Updated: 2026/07/25 20:03:28 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


static char *get_env_path(char **envp)
{
    int i;

    i = 0;
    while(envp[i])
    {
        if (ft_strncmp(envp[i],"PATH=",5) == 0)
            return(envp[i] + 5);
        i++;
    }
    return (0);
}

static char *split_and_join(char *path,t_tools *tools)
{
	char	**split;
    char	*join;
	char	*temp;
    int		i;
	t_token *token;

	token = tools->token_list->content;
	if (!path)
		return (0);
    split = ft_split(path, ':');
    if (!split)
    {    
        ft_free(split);
        return (0);
    }
	i = 0;
	while (split[i])
	{
		join = "\0";
		temp = ft_strjoin(split[i], "/");
		join = ft_strjoin(temp,token->value);
		free(temp);
		if (access(join, X_OK) == 0)
		{
			ft_free(split);
			return (join);
		}
		i++;
	}
	ft_free(split);
	return (0);
}

char *get_path(char **envp,t_tools *tools)
{
    char *path;
    char *new_path;
    
    path = get_env_path(envp);
    new_path = split_and_join(path,tools);
    return (new_path);
}