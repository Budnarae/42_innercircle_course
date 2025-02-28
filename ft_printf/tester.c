#include <stdio.h>
#include "ft_printf_bonus.h"

int main()
{
    int ft_printf_returned;

    // test all converison
    ft_printf_returned = ft_printf("5c : %5c\n", 'c');
    printf("ft_printf returned : %d\n\n", ft_printf_returned);

    ft_printf_returned = ft_printf("10.3s : %10.3s\n", "string");
    printf("ft_printf returned : %d\n\n", ft_printf_returned);

    ft_printf_returned = ft_printf("020p : %020p\n", &ft_printf_returned);
    printf("ft_printf returned : %d\n\n", ft_printf_returned);

    ft_printf_returned = ft_printf(" d : % d\n", 42);
    printf("ft_printf returned : %d\n\n", ft_printf_returned);

    ft_printf_returned = ft_printf("+i : %+i\n", 42);
    printf("ft_printf returned : %d\n\n", ft_printf_returned);

    ft_printf_returned = ft_printf("010u : %010u\n", 42);
    printf("ft_printf returned : %d\n\n", ft_printf_returned);

    ft_printf_returned = ft_printf("x : %x\n", 42);
    printf("ft_printf returned : %d\n\n", ft_printf_returned);

    ft_printf_returned = ft_printf("#x : %#x\n", 42);
    printf("ft_printf returned : %d\n\n", ft_printf_returned);

    ft_printf_returned = ft_printf("X : %X\n", 42);
    printf("ft_printf returned : %d\n\n", ft_printf_returned);

    ft_printf_returned = ft_printf("percent : %%\n");
    printf("ft_printf returned : %d\n\n", ft_printf_returned);

    // test va_arg
    ft_printf_returned = ft_printf("c : %c, s : %s, d : %d\n", 'c', "string", 42);
    printf("ft_printf returned : %d\n", ft_printf_returned);
}