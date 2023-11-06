#include <stdio.h>

void ft_bzero(void *s, size_t n)
{
    size_t i;
    unsigned char *ptr;

    i = 0;
    ptr = (unsigned char *) s;
    while (i < n)
    {
        ptr[i] = 0;
        i++;
    }
}

int	main(void)
{
	char str[100] = "Hello it's me";
	ft_bzero(str, 5);
	printf("%s\n", str);
	return (0);
}
