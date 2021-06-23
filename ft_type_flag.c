#include "ft_printf.h"

int	ft_is_type(int c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i')
		|| (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'));
}

int	ft_is_flag(int c)
{
	return ((c == '0') || (c == '-') || (c == '.') || (c == '*'));
}

void	ft_search_type(t_printf *var)
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
