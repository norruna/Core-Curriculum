void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *big;
	size_t	i;

	i = 0;
	j = 0;
	if (!*c)
		return (big);
	while (big[i] != '\0' && i < len)
	{
		if (c == big[i])
			return (&big[i]);
	}
		++i;
	}
	return (0);	
}
