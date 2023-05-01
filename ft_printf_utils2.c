#include "ft_printf.h"

unsigned int	ft_digit_count(long nb)
{
	unsigned int	count;

	count = 0;
	if (!nb)
		count = 1;
	if (nb < 0)
	{
		nb = -nb;
		count++;
	}
	while (nb > 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int nb)
{
	unsigned int	i;
	long			num;
	char			*str;

	num = nb;
	str = (char *)malloc((ft_digit_count(num) + 1) * sizeof(char));
	if (!str)
		return (0);
	str[ft_digit_count(num)] = '\0';
	if (num == 0)
		str[0] = '0';
	i = ft_digit_count(num) - 1;
	if (num < 0)
	{
		num = -num;
		str[0] = '-';
	}
	while (num > 0)
	{
		str[i--] = (num % 10) + 48;
		num /= 10;
	}
	return (str);
}

unsigned int	ft_putbase(unsigned long long num, char *base)
{
	unsigned int	len;
	unsigned int	base_len;

	base_len = ft_strlen(base);
	len = 0;
	if (num >= base_len)
		len += ft_putbase(num / base_len, base);
	ft_putchar_fd(base[num % base_len], 1);
	len++;
	return (len);
}

unsigned int	ft_putptr(unsigned long long num, char *base)
{
	unsigned int	len;

	len = 0;
	len += ft_putstr_fd("0x", 1);
	len += ft_putbase(num, base);
	return (len);
}

unsigned int	ft_convert(char c, va_list arglist)
{
	unsigned int		len;

	len = 0;
	if (c == 's')
		len += ft_putstr_fd(va_arg(arglist, char *), 1);
	else if (c == 'c')
		len += ft_putchar_fd(va_arg(arglist, int), 1);
	else if (c == 'x')
		len += ft_putbase(va_arg(arglist, unsigned long long),
				"0123456789abcdef");
	else if (c == 'X')
		len += ft_putbase(va_arg(arglist, unsigned long long),
				"0123456789ABCDEF");
	else if (c == 'p')
		len += ft_putptr(va_arg(arglist, unsigned long long),
				"0123456789abcdef");
	else if (c == 'd' || c == 'i')
		len += ft_print_itoa(va_arg(arglist, int));
	else if (c == 'u')
		len += ft_putunbr_fd(va_arg(arglist, unsigned int), 1);
	else if (c == '%')
		len += ft_putchar_fd('%', 1);
	return (len);
}
