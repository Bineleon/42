#include <stdio.h>

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

int	main(void)
{
	int	i;
	int	len;

	i = 0;
	int testChar[] = {'a', 'Z', -1, 128};
	len = sizeof(testChar) / sizeof(testChar[0]);
	while (i < len)
	{
		if (ft_isascii(testChar[i]))
			printf("%c is part of the ascii table\n", testChar[i]);
		else
			printf("%c is not part of the ascii table\n", testChar[i]);
		i++;
	}
	return (0);
}
