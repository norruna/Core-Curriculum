/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 19:33:34 by maleibig          #+#    #+#             */
/*   Updated: 2026/07/23 02:41:55 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_quotes(int *len, char *line, int *i, t_tools *tools)
{
	char	quote;

	quote = line[*i + *len];
	(*len)++;
	while (line[*i + *len] && line[*i + *len] != quote)
		(*len)++;
	if (line[*i + *len] == '\0')
		error_tokenizer_exit("no closing quote\n", tools);
	(*len)++;
}

void	add_token(t_token_type type, char *line, int len, t_tools *tools)
{
	t_token	*new_token;
	t_list	*token_node;

	new_token = malloc(sizeof(t_token));
	if (new_token == NULL)
		error_tokenizer_exit("malloc failed\n", tools);
	new_token->type = type;
	new_token->value = malloc(sizeof(char) * (len + 1));
	if (new_token->value == NULL)
	{
		free(new_token);
		error_tokenizer_exit("malloc failed\n", tools);
	}
	ft_strlcpy(new_token->value, line, len + 1);
	token_node = ft_lstnew(new_token);
	if (token_node == NULL)
		error_tokenizer_exit("error making list\n", tools);
	ft_lstadd_back(&tools->token_list, token_node);
	//printf("type: %d, value: %s\n", new_token->type, new_token->value);
}

void	handle_word(char *line, int *i, t_tools *tools)
{
	t_token_type	type;
	int				len;

	type = TOKEN_WORD;
	len = 0;
	while ((line[*i + len] && (!isspace(line[*i + len]))) && line[*i
		+ len] != '|' && line[*i + len] != '<' && line[*i + len] != '>')
	{
		if (line[*i + len] == '\"' || line[*i + len] == '\'')
			handle_quotes(&len, line, i, tools);
		else
			len++;
	}
	add_token(type, &line[*i], len, tools);
	(*i) += len;
}

void	handle_operator(char *line, int *i, t_tools *tools)
{
	t_token_type	type;
	int				len;

	if (line[*i] == '|')
		type = TOKEN_PIPE;
	else if (line[*i] == '<')
	{
		if (line[*i] == '<' && line[*i + 1] == '<')
			type = TOKEN_HEREDOC;
		else
			type = TOKEN_REDIR_IN;
	}
	else
	{
		if (line[*i] == '>' && line[*i + 1] == '>')
			type = TOKEN_APPEND;
		else
			type = TOKEN_REDIR_OUT;
	}
	if (type == TOKEN_PIPE || type == TOKEN_REDIR_IN || type == TOKEN_REDIR_OUT)
		len = 1;
	else
		len = 2;
	add_token(type, &line[*i], len, tools);
	(*i) += len;
}

t_list	*tokenizer(char *line, t_tools *tools)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (isspace(line[i]))
		{
			i++;
			continue ;
		}
		else if (line[i] == '|' || line[i] == '<' || line[i] == '>')
			handle_operator(line, &i, tools);
		else
			handle_word(line, &i, tools);
	}
	return (tools->token_list);
}
