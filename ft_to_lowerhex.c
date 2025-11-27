#include<stdio.h>
#include "libft.h"

void    ft_to_lowerhex(int n)
{
        char *hex;
        hex = "0123456789abcdef";
        if (n < 0)
        {
            write(1, "-", 1);
            n = -n;   
        }
        if (n >= 16)
            ft_to_lowerhex(n / 16);
        ft_putchar_fd(hex[n % 16], 1);
}

int main()
{
    ft_to_lowerhex(16);
}