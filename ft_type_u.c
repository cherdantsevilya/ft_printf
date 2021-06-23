#include "ft_printf.h"

static int	ft_u_nbrlen(unsigned int nbr)
{
	int	len;

	len = 1;
	if (nbr < 0)
	{
		len++;
		nbr = nbr * (-1);
	}
	while (nbr >= 10)
	{
		len++;
		nbr = nbr / 10;
	}
	return (len);
}

static char	*ft_u_itoa(unsigned int n)
{
	char	*str;
	int		i;

	i = ft_u_nbrlen(n);
	str = ((char *)malloc(sizeof(char) * (i + 1)));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = n * (-1);
	}
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[i] = (n % 10) + 48;
		n = (n / 10);
		i--;
	}
	return (str);
}

void	ft_u_dot(t_printf *var)
{
	int	dot;

	dot = var->accuracy;
	while (dot-- != var->len)
		ft_putchar(var, '0');
}

void	ft_u_width(t_printf *var)
{
	if (var->accuracy >= var->len && var->accuracy <= var->width)
		while (var->width-- != var->accuracy)
			ft_putchar(var, ' ');
	else
	{
		if (var->flag_zero == 1 && var->accuracy < 0)
			while (var->width-- != var->len)
				ft_putchar(var, '0');
		else if (var->accuracy < var->len)
			while (var->width-- != var->len)
				ft_putchar(var, ' ');
	}
}

void	ft_type_u(t_printf *var)
{
	unsigned int	d;
	char			*digit;

	d = va_arg(var->ap, unsigned int);
	while (1)
	{
		if (d == 0 && var->width == 0 && var->accuracy == 0)
			break ;
		digit = ft_u_itoa(d);
		var->len = ft_strlen(digit);
		if (var->width > var->len && var->flag_minus == 0)
			ft_u_width(var);
		if (var->accuracy >= var->len)
			ft_u_dot(var);
		if (*digit == '0' && var->accuracy == 0)
			ft_putchar(var, ' ');
		else
			ft_putstr(var, digit);
		if (var->width > var->len && var->flag_minus == 1)
			ft_u_width(var);
		free(digit);
		break ;
	}
}
