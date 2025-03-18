/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:16:42 by mayahiao          #+#    #+#             */
/*   Updated: 2025/03/11 12:16:43 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_length(const char *str, char c)
{
	int	len;

	len = 0;
	if (!c)
		return (0);
	while (str[len] && str[len] != c)
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

char	**ft_split(const char *str, char c)
{
	char	**result;
	int		i;
	int		j;

	result = (char **)malloc((count_words(str, c) + 1) * sizeof(char *));
	if (!result || !c)
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
				return (NULL);
			i = i + word_length(&str[i], c);
			j++;
		}
	}
	result[j] = 0;
	return (result);
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

/*#include <stdio.h>
int	main(void)
{
	const char *str = "   a     a    aaaaaaa    aa aa     aaa  ";
	char charset = 'a';
	printf("count words is : %d\n",count_words(str,charset));
	char **result = ft_split(str, charset);
	int	i = 0;
	while (result[i])
	{
		printf("Word number : %d is : %s\n", i, result[i]);
		i++;
	}
	ft_free(result);
	return (0);
}*/
