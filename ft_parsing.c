#include "ft_printf.h"

void	ft_search_accuracy(t_printf *var)
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

void	ft_search_width(t_printf *var)
{
	if (ft_isdigit(var->string[var->i]) == 1 && var->string[var->i + 1] != '*')
	{
		var->width = ft_atoi(&var->string[var->i]);
		while (ft_isdigit(var->string[var->i]) == 1)
			var->i++;
	}
	else if (var->string[var->i] == '*'
		&& ft_isdigit(var->string[var->i + 1]) != 1)
	{
		var->width = va_arg(var->ap, int);
		if (var->width < 0)
		{
			var->flag_minus = 1;
			var->flag_zero = 0;
			var->width *= -1;
		}
		var->i++;
	}
	else if (var->string[var->i] == '*'
		&& ft_isdigit(var->string[var->i + 1]) == 1)
	{
		var->width = va_arg(var->ap, int);
		var->width = ft_atoi(&var->string[var->i + 1]);
		var->i = var->i + 2;
	}
}

void	ft_search_flags(t_printf *var)
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

void	ft_parsing(t_printf *var)
{
	var->flag_minus = 0;
	var->flag_zero = 0;
	var->width = 0;
	var->accuracy = -1;
	var->type = 0;
	var->len = 0;
	var->sign = 0;
	while (var->string[var->i])
	{
		if (!ft_isdigit(var->string[var->i]) && !ft_is_type(var->string[var->i])
			&& !ft_is_flag(var->string[var->i]))
			break ;
		if (var->string[var->i] == '0' || var->string[var->i] == '-')
			ft_search_flags(var);
		if (ft_isdigit(var->string[var->i]) || var->string[var->i] == '*')
			ft_search_width(var);
		if (var->string[var->i] == '.')
			ft_search_accuracy(var);
		if (ft_is_type(var->string[var->i]))
		{
			var->type = var->string[var->i];
			break ;
		}
		var->i++;
	}
}
