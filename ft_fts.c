#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

static size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static int	*ft_abs(int nb)
{
	int	*result;

	result = malloc(sizeof(int) * 3);
	result[2] = '\0';
	if (nb >= 0)
	{
		result[0] = 1;
		result[1] = nb;
	}
	else
	{
		result[0] = 2;
		result[1] = ((nb) * (-1));
	}
	return (result);
}

int	ft_putstr(char	*s)
{
	if (!s)
		return (ft_putstr("(null)"));
	return (write(1, s, ft_strlen(s)));
}

static int	ft_power(int number, int power)
{
	int result;

	if (power == 0)
		return (1);
	else if (power == 1)
		return (number);
	result = 1;
	while (power--)
		result = result * number;
	return (result);
}

static char	*ft_converter(size_t nb)
{
	int		len;
	static char	*str;
	int		temp;
	size_t		i;

	i = 0;
	len = 0;
	temp = nb;
	while(temp)
	{
		len = len + 1;
		temp = temp / 10;
	}
	str = malloc(sizeof(char) * (len + 1));
	str[len + 1] = '\0';
	while (len)
	{
		str[i++] = ((nb / ft_power(10, len - 1)) % 10) + 48;
		len = len - 1;
	}
	return (str);
}

int	ft_putnbr(const int number)
{
	int		*nb;
	char	*string;

	nb = ft_abs(number);
	if (nb[0] == 2)
		write(1, "-", 1);
	string = ft_converter(nb[1]);
	free(nb);
	return (ft_putstr(string));
}

int	ft_convert(size_t data, char *base)
{
	size_t		len;
	static char	str[50];
	char		*ptr;

	len	=	ft_strlen(base);
	ptr	=	&str[49];
	*ptr	=	'\0';
	*--ptr	=	base[data % len];
	data	=	data / len;
	while (data)
	{
		*--ptr	=	base[data	%	len];
		data	=	data / len;
	}
	return	(ft_putstr(ptr));
}