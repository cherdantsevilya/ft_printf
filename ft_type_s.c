#include "ft_printf.h"

void ft_print_type_s(t_printf *var, char *dst, int length)
{
    if (var->flag_minus == 1)
    {
        ft_putstr(var, dst);
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
        ft_putstr(var, dst);
    }
}

void ft_type_s(t_printf *var)
{
    char *src;
    char *dst;
    int length;

    src = va_arg(var->ap, char *);
    dst[0] = 0;
    if (src = NULL)
        src = "(null)";
    if (var->accuracy > 0)
        ft_strncpy(dst, src, var->accuracy);
    else if (var->accuracy == -1)
        ft_strcpy(dst, src);
    else if (var->accuracy == 0)
        (ft_strcpy(dst, NULL));
    length = var->width - ft_strlen(dst);
    if (length <= 0)
        length = 0;
    ft_print_type_s(var, dst, length);
}

