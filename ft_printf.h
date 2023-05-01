#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>

unsigned int		ft_convert(char c, va_list arglist);
char				*ft_itoa(int num);
size_t				ft_strlen(const char *str);
unsigned int		ft_putbase(unsigned long long num, char *base);
unsigned int		ft_putchar_fd(int c, int fd);
unsigned int		ft_printf(const char *str, ...);
unsigned int		ft_print_itoa(int num);
unsigned int		ft_putptr(unsigned long long num, char *base);
unsigned int		ft_putstr_fd(char *s, int fd);
unsigned int		ft_putunbr_fd(unsigned int n, int fd);

#endif