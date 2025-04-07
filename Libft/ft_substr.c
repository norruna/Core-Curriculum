#include "libft.h"

static size_t malloc_size(char const *s1, unsigned int start, size_t len)
{
	size_t size = 0;

	while (s1[start] && size < len)
	{
		size++;
		start++;
	}
	return (size);	
}
char	*ft_substr(char const *s1, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;
	size_t size;

	if (start > ft_strlen(s1))
		return (NULL);
	size = malloc_size(s1,start,len);
	result = (char *) malloc((size + 1 ) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] =s1[start];
		i++;
		start++;
	}
	result[i] = '\0';
	return (result);
}

int	main(void)
{
	char const *s1 = "no no no start from here stop no no";
	unsigned int start = 90;
	size_t len = 17;
	char *res = ft_substr(s1,start,len);
	printf("the resulting substring is : %s\n",res);
	free(res);
}
