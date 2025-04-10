#include "libft.h"


static int	in_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*result;

	if (!s1 || !set)
		return (NULL);

	start = 0;
	while (s1[start] && in_set(s1[start], set))
		start++;

	end = ft_strlen(s1);
	while (end > start && in_set(s1[end - 1], set))
		end--;

	result = (char *)malloc((end - start + 1) * sizeof(char));
	if (!result)
		return (NULL);

	i = 0;
	while (start < end)
		result[i++] = s1[start++];

	result[i] = '\0';
	return (result);
}
/*
int	main(void)
{
	char const *s1 = "Why hello there";
	char const *s2 = "Why";
	char *res = ft_strtrim(s1,s2);
	printf("the final string is : %s\n", res);
	return (0);
}*/
