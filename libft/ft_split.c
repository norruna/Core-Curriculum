/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nellys-simulation <nellys-simulation@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:16:42 by mayahiao          #+#    #+#             */
/*   Updated: 2026/04/18 18:25:04 by nellys-simu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static int	word_length(const char *str, char c)
{
	int	len;

	len = 0;
	if (!c)
		return (0);
	while (str[len] && (str[len] != c))
	{
		len++;
	}
	return (len);
}

static int	count_words(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!str || !c)
		return (0);
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			count++;
		i += word_length(&str[i], c);
		while (str[i] == c && str[i])
			i++;
		if (str[i])
		{
			count ++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*make_word(const char *str, char c)
{
	int		i;
	char	*word;

	i = 0;
	word = (char *)malloc((word_length(str, c) + 1)
			* sizeof(char));
	if (!word)
		return (NULL);
	while (i < (word_length(str, c)))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	**zero_case(const char *str)
{
	char	**result;

	if (!str || str[0] == '\0')
	{
		result = (char **)malloc(sizeof(char *));
		if (!result)
			return (NULL);
		result[0] = NULL;
		return (result);
	}
	result = (char **)malloc(2 * sizeof(char *));
	if (!result)
		return (NULL);
	result[0] = ft_strdup(str);
	result[1] = 0;
	return (result);
}

char	**ft_split(const char *str, char c)
{
	char	**result;
	int		i;
	int		j;

	if (c == 0)
		return (zero_case(str));
	result = (char **)malloc((count_words(str, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
		{
			result[j] = make_word(&str[i], c);
			if (!result[j])
			{
				ft_free(result);
				return (NULL);
			}
			i += word_length(&str[i], c);
			j++;
		}
	}
	result[j] = NULL;
	return (result);
}


/*#include <stdio.h>
int	main(void)
{
	const char *str = " h  a    rtd ttt drt yd";
	char charset = 'a';
	printf("count words is : %d\n",count_words(str,charset));
	char **result = ft_split(str, charset);
	int	i = 0;
	while (result[i])
	{
		printf("Word number %d is : %s\n", i, result[i]);
		i++;
	}
	ft_free(result);
	return (0);
}*/
