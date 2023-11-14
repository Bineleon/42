#include <stdio.h>

size_t ft_strlen(const char *src);

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
    size_t i;

    i = 0;
    if (dstsize == 0)
        return ft_strlen(src);
    while (src[i] && i < dstsize)
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (ft_strlen(src));
}

// int main() {
//     char source[] = "Hello, World!";
//     char destination[20];
//     size_t result;

//     result = ft_strlcpy(destination, source, sizeof(destination));
//     printf("Copied string: %s\n", destination);
//     printf("Returned value: %zu\n\n", result);

//     char dest2[8];
//     result = ft_strlcpy(dest2, source, sizeof(dest2));
//     printf("Copied string: %s\n", dest2);
//     printf("Returned value: %zu\n\n", result);

//     char dest3[1];
//     result = ft_strlcpy(dest3, source, sizeof(dest3));
//     printf("Copied string: %s\n", dest3);
//     printf("Returned value: %zu\n\n", result);

//     return 0;
// }
