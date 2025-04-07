#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t len;
	size_t minus;
	char	*result;
	size_t	i;
	int	toggle = 0;
	minus = 0;
	i = 0;
	len = ft_strlen(set);
	if(ft_strncmp(s1, set, len) == 0)
	{
		minus += len;
		i += len;
	}
	if (ft_strncmp(&s1[ft_strlen(s1) - len], set, len) == 0)
	{
		minus += len;
		toggle = 1;
	}
	result = (char *)  malloc((ft_strlen(s1) - minus + 1) * sizeof(char));	
	if (!result)
		return (NULL);
	size_t j = 0;
	size_t end = 0;
	if (toggle == 1)
		end = ft_strlen(s1) - minus;
	else
		end = ft_strlen(s1);
	while (j < end )
	{
		result[j] = s1[i];	
		i++;
		j++;
	}
	result[j] = '\0';
	return (result);
}	

int	main(void)
{
	char const *s1 = "Why hello there";
	char const *s2 = "Why";
	char *res = ft_strtrim(s1,s2);
	printf("the final string is : %s\n", res);
	return (0);
}
