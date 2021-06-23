#include "ft_printf.h"

static int	ft_xX_nbrlen(unsigned long nbr)
{
	int	len;

	len = 1;
	if (nbr < 0)
	{
		len++;
		nbr = nbr * (-1);
	}
	while (nbr >= 16)
	{
		len++;
		nbr = nbr / 16;
	}
	return (len);
}

static char	*ft_xX_itoa(t_printf *var, unsigned long n)
{
	char	*str;
	int		i;
	int		type;

	i = ft_xX_nbrlen(n);
	str = ((char *)malloc(sizeof(char) * (i + 1)));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (var->type == 'X')
		type = 55;
	else
		type = 87;
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		if ((n % 16) > 9)
			str[i] = type + (n % 16);
		else
			str[i] = (n % 16) + 48;
		n = (n / 16);
		i--;
	}
	return (str);
}

void	ft_xX_dot(t_printf *var)
{
	int	dot;

	dot = var->accuracy;
	while (dot-- != var->len)
		ft_putchar(var, '0');
}

void	ft_xX_width(t_printf *var)
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

void	ft_type_xX(t_printf *var)
{
	unsigned long	d;
	char			*digit;

	d = (unsigned long)va_arg(var->ap, unsigned int);
	while (1)
	{
		if (d == 0 && var->accuracy == 0 && var->width == 0)
			break ;
		digit = ft_xX_itoa(var, d);
		var->len = ft_strlen(digit);
		if (var->width > var->len && var->flag_minus == 0)
			ft_xX_width(var);
		if (var->accuracy >= var->len)
			ft_xX_dot(var);
		if (*digit == '0' && var->accuracy == 0)
			ft_putchar(var, ' ');
		else
			ft_putstr(var, digit);
		if (var->width > var->len && var->flag_minus == 1)
			ft_xX_width(var);
		free(digit);
		break ;
	}
}
