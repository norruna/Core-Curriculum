/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 19:58:10 by nellys-simu       #+#    #+#             */
/*   Updated: 2025/11/17 04:44:06 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_empty_signs(char **result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		if ((result[i][0] == '-' || result[i][0] == '+')
			&& result[i][1] == '\0')
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		i++;
	}
	return (1);
}

int	handle_single_arg(char **argv, t_stack **a)
{
	char	**result;
	int		res;

	if (argv[1][0] == '\0' || only_spaces(argv[1]) == 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	result = ft_split((char *)argv[1], 32);
	if (!result)
		return (0);
	if (!check_empty_signs(result))
	{
		ft_free(result);
		return (0);
	}
	res = arg_check(result);
	*a = parse_stack(result);
	ft_free(result);
	return (res);
}

static int	check_empty_argv(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (argv[i][0] == '\0')
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		i++;
	}
	return (1);
}

int	handle_multi_arg(int argc, char **argv, t_stack **a)
{
	int	res;

	(void)argc;
	if (!check_empty_argv(argv))
		return (0);
	res = arg_check(argv + 1);
	if (res == 1)
		*a = parse_stack(argv + 1);
	return (res);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		res;

	a = NULL;
	b = NULL;
	res = 0;
	if (argc == 1)
		return (0);
	if (argc == 2)
		res = handle_single_arg(argv, &a);
	else
		res = handle_multi_arg(argc, argv, &a);
	if (res == 0)
		return (0);
	indexing(a);
	sorting(&a, &b);
	ft_freestack(&a);
	ft_freestack(&b);
	return (0);
}
