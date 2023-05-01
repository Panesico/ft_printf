#include "ft_printf.h"

unsigned int	ft_printf(const char *str, ...)
{
	va_list			arglist;
	unsigned int	print_len;
	unsigned int	i;

	va_start(arglist, str);
	print_len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			print_len += ft_convert(str[++i], arglist);
		else
			print_len += ft_putchar_fd(str[i], 1);
		i++;
	}
	va_end(arglist);
	return (print_len);
}
