#include "ft_printf.h"

void	ft_putstr(t_printf *var, const char *s)
{
    int	i;

    i = 0;
    while (s[i])
    {
        ft_putchar(var, s[i]);
        i++;
    }
}

void ft_putchar(t_printf *var, int c)
{
    write(1, &c, 1);
    var->count++;
}

int ft_read_str(const char *str, va_list ap)
{
    t_printf var;
    int count;

    var.i = 0;
    var.string = str;
    var.count = 0;
    va_copy(var.ap, ap);
    while (var.string[var.i])
    {
        if (!var.string[var.i])
            break;
        if (var.string[var.i] == '%' && var.string[var.i + 1])
        {
            var.i++;
            ft_parsing(&var);
            if (var.string[var.i + 1])
                ft_putchar(&var, var.string[var.i + 1]);
        }
        else if (var.string[var.i] != '%')
            ft_putchar(&var ,var.string[var.i]);
        var.i++;
    }
    va_end(ap);
    return (var.count);
}

int ft_printf(const char *format, ...)
{
    va_list ap;
    int count;
    const char *str;

    count = 0;
    str = ft_strdup(format);
    if (str == NULL)
        return (-1);
    va_start(ap, str);
    count = ft_read_str(str, ap);
    va_end(ap);
    free((char *)str);
    return (count);
}