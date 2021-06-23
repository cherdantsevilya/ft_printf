#include "ft_printf.h"

void	ft_print_int(t_printf *var, char *digit)
{
	if (*digit == '-' && ((var->accuracy >= var->len) || (var->flag_zero == 1
				&& var->accuracy < 0 && var->width > var->len)))
	{
		digit++;
		ft_putstr(var, digit);
	}
	else if (*digit == '0' && var->accuracy == 0)
		ft_putchar(var, ' ');
	else
		ft_putstr(var, digit);
}

void	ft_int_dot(t_printf *var)
{
	int	dot;

	dot = var->accuracy;
	if (var->sign == 1)
	{
		ft_putchar(var, '-');
		while ((dot--) - (var->len - 1))
			ft_putchar(var, '0');
	}
	else
		while (dot-- != var->len)
			ft_putchar(var, '0');
}

void	ft_int_width(t_printf *var, int width)
{
	if (var->accuracy >= var->len && var->accuracy <= width && var->sign == 1)
		while (width-- != var->accuracy + 1)
			ft_putchar(var, ' ');
	else if (var->accuracy >= var->len && var->accuracy <= width
		&& var->sign == 0)
		while (width-- != var->accuracy)
			ft_putchar(var, ' ');
	else if (var->flag_zero == 1 && var->accuracy < 0)
	{
		if (var->sign == 1)
			ft_putchar(var, '-');
		while (width-- != var->len)
			ft_putchar(var, '0');
	}
	else if (var->accuracy < var->len)
		while (width-- != var->len)
			ft_putchar(var, ' ');
}

void	ft_type_di(t_printf *var)
{
	int		d;
	char	*digit;

	d = va_arg(var->ap, int);
	while (1)
	{
		if (d == 0 && var->width == 0 && var->accuracy == 0)
			break ;
		digit = ft_itoa(d);
		var->len = ft_strlen(digit);
		if (d < 0)
			var->sign = 1;
		if (var->width > var->len && var->flag_minus == 0
			&& var->accuracy != var->width)
			ft_int_width(var, var->width);
		if (var->accuracy >= var->len)
			ft_int_dot(var);
		ft_print_int(var, digit);
		if (var->width > var->len && var->flag_minus == 1
			&& var->accuracy != var->width)
			ft_int_width(var, var->width);
		free(digit);
		break ;
	}
}
