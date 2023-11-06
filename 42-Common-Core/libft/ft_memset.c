#include <stdio.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = b;
	i = 0;
	while (i < len)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

int	main(void)
{
	char str[100] = "Hello it's me";
	ft_memset(str, '+', 5);
	printf("%s\n", str);
	return (0);
}
