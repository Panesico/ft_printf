/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgfern <jorgfern@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:38:58 by jorgfern          #+#    #+#             */
/*   Updated: 2023/05/03 21:01:07 by jorgfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>

int				ft_convert(char c, va_list arglist);
char			*ft_itoa(int num);
size_t			ft_strlen(const char *str);
int				ft_putbase(unsigned int num, char *base);
int				ft_putbasel(unsigned long long num, char *base);
int				ft_putchar_fd(int c, int fd);
int				ft_printf(const char *str, ...);
int				ft_print_itoa(int num);
int				ft_putptr(unsigned long long num, char *base);
int				ft_putstr_fd(char *s, int fd);
unsigned int	ft_putunbr_fd(unsigned int n, int fd);

#endif
