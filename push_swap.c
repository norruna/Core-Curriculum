/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 19:58:10 by nellys-simu       #+#    #+#             */
/*   Updated: 2025/11/17 02:55:55 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	str_check(char *str)
{
	int	i;

	if (!str)
		return (0);
	if (ft_strlen(str) == 1)
	{
		if (str[0] < '0' || str[0] > '9')
			return (0);
	}
	else
	{
		i = 0;
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
		if (str[i] != 32 && str[i] != '\t')
			return (1);
		i++;
	}
	return (0);
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
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		i++;
	}
	return (1);
}

/*main test*/
/* void	print_stack(t_stack *stack, const char *name)
{
	ft_printf("Stack %s:\n", name);
	if (!stack)
	{
		ft_printf("  [empty]\n");
		return;
	}

	while (stack)
	{
		ft_printf("  value = %d | index = %d\n", stack->value, stack->index);
		stack = stack->next;
	}
} */

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
		if (argv[1][0] == '\0')
		{
			ft_putstr_fd("Error\n", 2);
			return (0);	
		}	
		
		if (too_many_spaces(argv[1]) == 0)
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		//res = arg_check(&argv[1]);
		char **result = ft_split((char *)argv[1], 32); //if leak might be split needing free
		if (!result)
			return (0);
		int i = 0;
		while (result[i])
		{
			if ((result[i][0] == '-' || result[i][0] == '+') && result[i][1] == '\0')
			{
				ft_putstr_fd("Error\n", 2);
				return (0);
			}
			i++;
		}
		res = arg_check(result);
		a = parse_stack(result);
		ft_free(result);
	}
	else
	{
		int	i = 1;
		while (argv[i])
		{	if(argv[i][0] == '\0')
			{	
				ft_putstr_fd("Error\n", 2);
				return (0);
			}	
			i++;
		}
		res = arg_check(argv + 1);
		if (res == 1)
			a = parse_stack(argv + 1);
	}
	indexing(a);
	sorting(&a, &b);
	//ft_print_output(a);
	ft_freestack(&a);
	ft_freestack(&b);
	return (0);
}
