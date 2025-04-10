#include "libft.h"

static int	size_malloc(int n)
{
	int	size;

	if (n == 0)
		return (1);
	size = 0;
	if (n < 0)
	{
		size++; // for the minus sign
		n = -n;
	}
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}


char	*ft_itoa(int n)
{
	int		size;
	char	*result;
	int		sign;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));

	sign = (n < 0);
	size = size_malloc(n);
	result = (char *)malloc((size + 1) * sizeof(char));
	if (!result)
		return (NULL);

	result[size] = '\0';
	if (n == 0)
		result[0] = '0';
	if (sign)
	{
		result[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		result[--size] = (n % 10) + '0';
		n /= 10;
	}
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
