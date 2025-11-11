/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 19:58:10 by nellys-simu       #+#    #+#             */
/*   Updated: 2025/11/11 12:39:34 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*here i check if the individual strings meet the requirements*/
int str_check(char *str)
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

/*so only parse if argcheck = 1*/
int arg_check(char **str)
{
	int i = 0;
	while (str[i])
	{
		int r = str_check(str[i]);
		printf("the check is : %d \n", r);
		if (r == 0)
		{				
			printf("nope\n");
			return (0);
		}
		i++;
	}
	return (1);
}

/*main test*/
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
		char **result = ft_split((char *)argv[1], 32); //if leak might be split needing free
		res = arg_check(result);
		a = parse_stack(argv);
		ft_free(result);
	}
	else
	{
		res = arg_check(argv + 1);
		if (res == 1)
			a = parse_stack(argv + 1);
	}
	ft_freestack(&a);
	ft_freestack(&b);
	return (0);
}
