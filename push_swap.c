/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 19:58:10 by nellys-simu       #+#    #+#             */
/*   Updated: 2025/11/16 23:58:48 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*here i check if the individual strings meet the requirements*/
int	str_check(char *str)
{
	if (!str) //if empty, return 0
		return (0);
	if (ft_strlen(str)  == 1) //if single digit
	{
		if (str[0] < '0' || str[0] > '9')
			return (0);
	}
	else
	{
		int i = 0;
		if (str[0] == '+' || str[0] == '-')
		{
			if (!str[1] || (str[1] < '0' || str[1] > '9'))
				return (0);
			i++;
		}
		while (str[i] && (i < ((int)ft_strlen(str))))
		{
			if (str[i] < '0' || str[i] > '9')
				return (0);
			i++;
		}
	}
	return (1);
}
/*check if the string has more than a space in between or before the string starts*/
int	too_many_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == 32 || str[i] == '\t') && str[i + 1] 
			&& (str[i + 1] == 32 || str[i + 1] == '\t'))
			return (0);
		else if (i == 0 && (str[i] == 32 || str[i] == '\t'))
			return (0);
		else if (((size_t)i == ft_strlen(str) - 1) && (str[i] == 32 || str[i] == '\t'))
			return (0);
		i++;
	}
	return (1);
}
/*so only parse if argcheck = 1*/
int arg_check(char **str)
{
	int i = 0;
	while (str[i])
	{
		int r = str_check(str[i]);
		if (r == 0)
		{				
			printf("Error\n");
			return (0);
		}
		i++;
	}
	return (1);
}

/*main test*/


void	print_stack(t_stack *stack, const char *name)
{
	printf("Stack %s:\n", name);
	if (!stack)
	{
		printf("  [empty]\n");
		return;
	}

	while (stack)
	{
		printf("  value = %d | index = %d\n", stack->value, stack->index);
		stack = stack->next;
	}
}

void	ft_free(char **result)
{
	int	i = 0;
	while (result[i] != NULL)
	{
		free(result[i]);
		i++;
	}
	free(result);
}

int	main(int argc, char **argv)
{
	t_stack *a = NULL;
	t_stack *b = NULL;
	int	res = 0;
	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		if (too_many_spaces(argv[1]) == 0)
		{
			printf("Error\n");
			return (0);
		}
		char **result = ft_split((char *)argv[1], 32); //if leak might be split needing free
		res = arg_check(result);
		a = parse_stack(result);
		ft_free(result);
	}
	else
	{
		res = arg_check(argv + 1);
		if (res == 1)
			a = parse_stack(argv + 1);
	}
	indexing(a);
	sorting(&a, &b);
	ft_freestack(&a);
	ft_freestack(&b);
	return (0);
}
