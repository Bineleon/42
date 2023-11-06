#include <stdio.h>

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

int	main(void)
{
	int	i;
	int	len;

	i = 0;
	int testChar[] = {'a', 'Z', 7, 127};
	len = sizeof(testChar) / sizeof(testChar[0]);
	while (i < len)
	{
		if (ft_isprint(testChar[i]))
			printf("%c (code %d) is printable\n", testChar[i], testChar[i]);
		else
			printf("%c (code %d) is not printable\n", testChar[i], testChar[i]);
		i++;
	}
	return (0);
}
