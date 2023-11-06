#include <stdio.h>

int	ft_isdigit(int c)
{
	if (c >= '0' & c <= '9')
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	char	testChar;

	if (ac == 2)
	{
		testChar = av[1][0];
		if (ft_isdigit(testChar))
			printf("%c is a digit\n", testChar);
		else
			printf("%c is not a digit\n", testChar);
	}
	return (0);
}
