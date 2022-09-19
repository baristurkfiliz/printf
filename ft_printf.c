#include "ft_printf.h"

static int	ft_data_type(char c, va_list arg)
{
	if (c == 's')
		return (ft_putstr(va_arg(arg, char *)));

}

int	ft_printf(const char *str, ...)
(
	va_list arg;
