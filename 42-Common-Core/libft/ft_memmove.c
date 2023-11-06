#include <stdio.h>

void *ft_memmove(void *dst, const void *src, size_t len)
{
    size_t i;
    unsigned char *d;
    const unsigned char *s;

    d = (unsigned char *) dst;
    s = (const unsigned char *) src;
    if (d < s)
    {
        i = 0;
        while (i < len)
        {
            d[i] = s[i];
            i++;
        }
    }
    else if (s < d)
    {
        i = len;
        while (i != 0)
        {
            d[i - 1] = s[i - 1];
            i--;
        }
    }
    return (dst);
}

int	main(void)
{
    char dst[20];
	char src[100] = "Hello it's me";
	ft_memmove(dst, src, 7);
	printf("%s\n", dst);
	return (0);
}
