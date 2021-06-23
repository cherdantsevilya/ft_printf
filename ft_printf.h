#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_printf
{
	int			i;
	const char	*string;
	va_list		ap;
	int			flag_zero;
	int			flag_minus;
	int			width;
	int			accuracy;
	int			type;
	int			count;
	int			len;
	int			sign;
}				t_printf;

int		ft_printf(const char *format, ...);
int		ft_read_str(const char *str, va_list ap);
void	ft_putstr(t_printf *var, char *str);
void	ft_putchar(t_printf *var, char c);
void	ft_parsing(t_printf *var);
void	ft_search_flags(t_printf *var);
void	ft_search_width(t_printf *var);
void	ft_search_accuracy(t_printf *var);
void	ft_search_type(t_printf *var);
int		ft_is_flag(int c);
int		ft_is_type(int c);
void	ft_type_c(t_printf *var);
void	ft_type_s(t_printf *var);
void	ft_s_width(t_printf *var);
void	ft_type_p(t_printf *var);
void	ft_p_width(t_printf *var);
void	ft_type_di(t_printf *var);
void	ft_int_width(t_printf *var, int width);
void	ft_int_dot(t_printf *var);
void	ft_print_int(t_printf *var, char *digit);
void	ft_type_u(t_printf *var);
void	ft_u_width(t_printf *var);
void	ft_u_dot(t_printf *var);
void	ft_type_xX(t_printf *var);
void	ft_xX_width(t_printf *var);
void	ft_xX_dot(t_printf *var);
void	ft_type_percent(t_printf *var);

#endif
