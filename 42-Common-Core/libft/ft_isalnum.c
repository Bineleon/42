#include <stdio.h>

int	ft_isalnum(int c)
{
	if (((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) || (c >= '0'
			&& c <= '9'))
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	char	testChar;

	if (ac == 2)
	{
		testChar = av[1][0];
		if (ft_isalnum(testChar))
			printf("'%c' is an alphanumeric character\n", testChar);
		else
			printf("'%c' is not an alphanumeric character\n", testChar);
	}
	return (0);
}
