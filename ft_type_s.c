#include "ft_printf.h"

void	ft_s_width(t_printf *var)
{
	int	width;

	width = var->width;
	if (width > var->accuracy && var->accuracy < var->len && var->accuracy > 0)
		while (width-- != var->accuracy)
			ft_putchar(var, ' ');
	else if (width > var->len && (var->accuracy >= var->len
			|| var->accuracy < 0))
		while (width-- != var->len)
			ft_putchar(var, ' ');
	else if (width > 0 && var->accuracy == 0)
		while (width--)
			ft_putchar(var, ' ');
}

void	ft_type_s(t_printf *var)
{
	char	*str;
	int		dot;

	str = va_arg(var->ap, char *);
	dot = var->accuracy;
	while (1)
	{
		if (var->accuracy == 0 && var->width == 0)
			break ;
		if (str == NULL)
			str = "(null)";
		var->len = ft_strlen(str);
		if (var->flag_minus == 0)
			ft_s_width(var);
		if (var->accuracy >= var->len || var->accuracy < 0)
			ft_putstr(var, str);
		else if (var->accuracy < var->len && var->accuracy > 0)
			while (dot--)
				ft_putchar(var, *str++);
		if (var->flag_minus == 1)
			ft_s_width(var);
		break ;
	}
}
