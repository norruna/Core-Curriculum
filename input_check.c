/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nellys-simulation <nellys-simulation@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 19:58:10 by nellys-simu       #+#    #+#             */
/*   Updated: 2025/11/09 20:21:51 by nellys-simu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*here i check if the arg string meets the requirements*/

int str_check(char *str)
{
   if (str[0] == '"' && str[ft_strlen(str)] == '"')

	return (1);
}