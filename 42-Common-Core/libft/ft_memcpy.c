#include <stdio.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dest;
	const unsigned char	*s;

	dest = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dest[i] = s[i];
		i++;
	}
	return (dst);
}

int	main(void)
{
	char	dst[20];

	char src[100] = "Hello it's me";
	ft_memcpy(dst, src, 7);
	printf("%s\n", dst);
	return (0);
}
