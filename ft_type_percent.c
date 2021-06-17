#include "ft_printf.h"

void ft_type_percent(t_printf *var)
{
    int length;

    length = 0;
    if (var->width > 0)
        length = var->width - 1;
    if (var->flag_minus == 1)
    {
        ft_putchar(var, var->string[var->i]);
        while (length--)
            ft_putchar(var, ' ');
    }
    else if (var->flag_minus == 0)
    {
        if (var->flag_zero == 1)
            while (length--)
                ft_putchar(var, '0');
        else if (var->flag_zero == 0)
            while (length--)
                ft_putchar(var, ' ');
        ft_putchar(var, var->string[var->i]);
    }
}

