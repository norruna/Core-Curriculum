

/*AI GENERATED FOR TESTING PURPOSES*/
#include "minishell.h"
char	**make_argv(t_list *tokens)
{
	int		count;
	int		i;
	char	**argv;
	t_list	*current;
	t_token	*token;

	count = 0;
	current = tokens;

	// count words
	while (current)
	{
		token = current->content;
		if (token->type == TOKEN_WORD)
			count++;
		current = current->next;
	}

	argv = malloc(sizeof(char *) * (count + 1));
	if (!argv)
		return (NULL);

	i = 0;
	current = tokens;

	while (current)
	{
		token = current->content;
		if (token->type == TOKEN_WORD)
		{
			argv[i] = token->value;
			i++;
		}
		current = current->next;
	}
	argv[i] = NULL;

	return (argv);
}


void	fill_argv(t_command *cmd, t_list *tokens)
{
	int		count;
	int		i;
	t_list	*current;
	t_token	*token;

	count = 0;
	current = tokens;

	while (current)
	{
		token = current->content;
		if (token->type == TOKEN_PIPE)
			break ;
		if (token->type == TOKEN_WORD)
			count++;
		current = current->next;
	}

	cmd->argv = malloc(sizeof(char *) * (count + 1));
	if (!cmd->argv)
		return ;

	i = 0;
	current = tokens;
	while (current)
	{
		token = current->content;
		if (token->type == TOKEN_PIPE)
			break ;
		if (token->type == TOKEN_WORD)
		{
			cmd->argv[i] = token->value;
			i++;
		}
		current = current->next;
	}
	cmd->argv[i] = NULL;
}
