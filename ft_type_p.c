#include "ft_printf.h"

static int	ft_p_nbrlen(unsigned long long nbr)
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

static char	*ft_p_itoa(t_printf *var, unsigned long long n)
{
	char	*str;
	int		i;
	int		type;

	i = ft_p_nbrlen(n);
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

void	ft_p_width(t_printf *var)
{
	if (var->width > 2 && var->flag_minus == 0)
	{
		while (var->width-- != 2)
			ft_putchar(var, ' ');
		ft_putstr(var, "0x");
	}
	else if (var->width > 2 && var->flag_minus == 1)
	{
		ft_putstr(var, "0x");
		while (var->width-- != 2)
			ft_putchar(var, ' ');
	}
	else if (var->width <= 2)
		ft_putstr(var, "0x");
}

void	ft_type_p(t_printf *var)
{
	unsigned long long	d;
	char				*digit;

	d = va_arg(var->ap, unsigned long long);
	while (1)
	{
		if (var->accuracy == 0 && d == 0)
		{
			ft_p_width(var);
			break ;
		}
		digit = ft_p_itoa(var, d);
		var->len = ft_strlen(digit) + 2;
		if (var->width > var->len && var->flag_minus == 0)
			while (var->width-- != var->len)
				ft_putchar(var, ' ');
		ft_putstr(var, "0x");
		ft_putstr(var, digit);
		if (var->width > var->len && var->flag_minus == 1)
			while (var->width-- != var->len)
				ft_putchar(var, ' ');
		free(digit);
		break ;
	}
}
