#include "ft_printf.h"

void	ft_type_c(t_printf *var)
{
	char	c;
	int		length;

	length = var->len;
	c = va_arg(var->ap, int);
	if (var->width > 0)
		length = var->width - 1;
	if (var->flag_minus == 1)
	{
		ft_putchar(var, c);
		while (length--)
			ft_putchar(var, ' ');
	}
	else if (var->flag_minus == 0)
	{
		if (var->flag_zero == 1)
			while (length--)
				ft_putchar(var, ' ');
		else if (var->flag_zero == 0)
			while (length--)
				ft_putchar(var, ' ');
		ft_putchar(var, c);
	}
}
