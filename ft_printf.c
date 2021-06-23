#include "ft_printf.h"

void	ft_putchar(t_printf *var, char c)
{
	write (1, &c, 1);
	var->count++;
}

void	ft_putstr(t_printf *var, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
		var->count++;
	}
}

int	ft_read_str(const char *str, va_list ap)
{
	t_printf	var;

	var.i = 0;
	var.count = 0;
	var.string = str;
	va_copy(var.ap, ap);
	while (1)
	{
		if (!var.string[var.i])
			break ;
		else if (var.string[var.i] != '%')
			ft_putchar(&var, var.string[var.i]);
		else if (var.string[var.i] == '%' && var.string[var.i + 1])
		{
			var.i++;
			ft_parsing(&var);
			if (ft_is_type(var.string[var.i]))
				ft_search_type(&var);
			else if (var.string[var.i])
				ft_putchar(&var, var.string[var.i]);
		}
		var.i++;
	}
	return (var.count);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			count;
	const char	*str;

	str = ft_strdup(format);
	if (str == NULL)
		return (-1);
	va_start(ap, format);
	count = ft_read_str(str, ap);
	va_end(ap);
	free((char *)str);
	return (count);
}
