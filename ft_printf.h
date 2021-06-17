#ifndef PKARI_FT_PRINTF_H
#define PKARI_FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_printf
{
    int i;
    const char *string;
    va_list ap;
    int flag_zero;
    int flag_minus;
    int width;
    int accuracy;
    int type;
    int count;
}   t_printf;

void ft_parsing(t_printf *var);
void	ft_putchar(t_printf *var, int c);
void ft_type_c(t_printf *var);
void	ft_putstr(t_printf *var, const char *s);

#endif //PKARI_FT_PRINTF_H
