#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// int	main(int ac, char **av)
// {
// 	if (ac == 2)
// 	{
// 		printf("String len is : %zu\n", ft_strlen(av[1]));
// 	}
// 	return (0);
// }
