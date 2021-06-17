#include "ft_printf.h"

void ft_search_type(t_printf *var)
{
    if (var->string[var->i] == 'c')
        ft_type_c(var);
    else if (var->string[var->i] == 's')
        ft_type_s(var);
    else if (var->string[var->i] == 'p')
        ft_type_p(var);
    else if (var->string[var->i] == 'd' || var->string[var->i] == 'i')
        ft_type_di(var);
    else if (var->string[var->i] == 'u')
        ft_type_u(var);
    else if (var->string[var->i] == 'x' || var->string[var->i] == 'X')
        ft_type_xX(var);
    else if (var->string[var->i] == '%')
        ft_type_percent(var);
}

void ft_search_accuracy(t_printf *var)
{
    if (var->string[var->i] == '.' && var->string[var->i + 1] == '*')
    {
        var->accuracy = va_arg(var->ap, int);
        var->i = var->i + 2;
        if (var->accuracy < 0)
            var->accuracy = -1;
    }
    else if (var->string[var->i] == '.' && ft_isdigit(var->string[var->i + 1]))
    {
        var->i++;
        var->accuracy = ft_atoi(&var->string[var->i]);
        while (ft_isdigit(var->string[var->i]))
            var->i++;
    }
    else if (var->string[var->i] == '.' && !ft_isdigit(var->string[var->i + 1]))
    {
        var->accuracy = 0;
        var->i++;
    }
}

void ft_search_width(t_printf *var)
{
    if (ft_isdigit(var->string[var->i]) && var->string[var->i + 1] != '*')
    {
        var->width = ft_atoi(&var->string[var->i]);
        while (ft_isdigit(var->string[var->i]) == 1)
            var->i++;
    }
    else if (var->string[var->i] == '*' && !ft_isdigit(var->string[var->i + 1]))
    {
        var->width = va_arg(var->ap, int);
        if (var->width < 0)
            var->width *= -1;
        var->i = var->i + 2;
    }
    else if ((var->string[var->i] == '*' && ft_isdigit(var->string[var->i + 1])) ||
            (ft_isdigit(var->string[var->i]) && var->string[var->i + 1] == '*'))
        var->i = var->i + 2;
}

void ft_search_flags(t_printf *var)
{
    while (var->string[var->i] == '-' || var->string[var->i] == '0')
    {
        if (var->string[var->i] == '-')
        {
            var->flag_minus = 1;
            var->flag_zero = 0;
        }
        if (var->string[var->i] == '0' && var->flag_minus == 0)
            var->flag_zero = 1;
        var->i++;
    }
}

void ft_parsing(t_printf *var)
{
    var->flag_minus = 0;
    var->flag_zero = 0;
    var->width = 0;
    var->accuracy = -1;
    var->type = 0;
    ft_search_flags(var);
    ft_search_width(var);
    ft_search_accuracy(var);
    ft_search_type(var);
}

