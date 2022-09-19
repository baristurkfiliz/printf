#include "ft_printf.h"

static int	ft_print_it(char c, va_list arg)
{
	if (c == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (c == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (c == 'd' || c = 'i')
		return (ft_putnbr(va_arg(arg, int)));
	else if (c == 'p')
	{
		ft_
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list arg;
	int	i;
	int	j;

	va_start(arg, str);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i + 1] == '\0' && str[i] == '%')
			write(1, &str[i+1], 1);
		else if (str[i] == '%')
		{
			j += ft_print_it(str[i+1], arg);
			i++;
		}
		else
			j += write(1, &str[i], 1);
		i++;
	}
	va_end(arg);
	return (j);
}
