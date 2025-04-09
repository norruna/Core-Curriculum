#include "libft.h"

static int	size_malloc(int n)
{
	int	size;

	size = 0;
	if (n < 0)
	{
		size++;
		n = -n;
	}
	if (n < 10)
		return (1);
	while ((n / 10) != 0)
	{
		n = n / 10;
		size++;
		if (n / 10 == 0 && n % 10 != 0)
			size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{	
	int	size;
	char	*result;
	char	*rev_result;
	int	sign;
	int	i;

	i = 0;
	sign = 0;
	size = size_malloc(n);
	rev_result = (char *) malloc ((size + 1) * sizeof(char));
	result = (char *) malloc ((size + 1) * sizeof(char));
	if (!result || !rev_result)
		return (0);
	if (n < 0)
	{	
		sign = 1;
		n = -n;
	}
	while (n / 10 != 0)
	{
		rev_result[i] = (n % 10) + '0';
		n = n / 10;
		i++;
	}
	rev_result[i] = n + '0';
	if (sign == 1)
	{
		i ++;
		rev_result[i] = '-';
		i++;
	}
	rev_result[i + 1] = '\0';
	
	i = 0;
	int j = size - 1;
	while (j >= 0)
	{
		result[i] = rev_result[j];
		i++;
		j--;
	}
	result[i] = '\0';
	return (result);
}


/*int	main(void)
{
	int	n  = 564450;
	char	*result = ft_itoa(n);
	if (!result)
		return (0);
	printf("the string is  : %s\n",result);
//	printf("main size is : %d\n",size);
	free(result);
	return (0);
}*/
