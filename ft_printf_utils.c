/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgfern <jorgfern@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:38:38 by jorgfern          #+#    #+#             */
/*   Updated: 2023/05/04 01:23:26 by jorgfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(int c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putstr_fd(char *s, int fd)
{
	int	print_len;
	int	i;

	print_len = 0;
	i = 0;
	if (!s)
		s = "(null)";
	while (s[i])
		print_len += ft_putchar_fd(s[i++], fd);
	return (print_len);
}

int	ft_print_itoa(int num)
{
	char	*str;
	int		len;

	str = ft_itoa(num);
	len = ft_putstr_fd(str, 1);
	free(str);
	return (len);
}

unsigned int	ft_putunbr_fd(unsigned int n, int fd)
{
	int	len;

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
