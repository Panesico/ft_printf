#include "ft_printf.h"

unsigned int	ft_putchar_fd(int c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

unsigned int	ft_putstr_fd(char *s, int fd)
{
	unsigned int	print_len;
	unsigned int	i;

	print_len = 0;
	i = 0;
	while (s[i])
		print_len += ft_putchar_fd(s[i++], fd);
	return (print_len);
}

unsigned int	ft_print_itoa(int num)
{
	return (ft_putstr_fd(ft_itoa(num), 1));
}

unsigned int	ft_putunbr_fd(unsigned int n, int fd)
{
	unsigned int	len;

	len = 0;
	if (n >= 10)
	{
		len += ft_putunbr_fd(n / 10, fd);
		ft_putunbr_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
	len++;
	return (len);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
