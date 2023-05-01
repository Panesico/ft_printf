CFLAGS  = -Wall -Wextra -Werror
NAME    = libftprintf.a
AR		= ar -rcs
SRC		= ft_printf.c ft_printf_utils.c ft_printf_utils2.c
OBJ		= ${SRC:.c=.o}

all: $(NAME)

%.o: %.c
	@gcc $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@echo -- Compliling All

clean:
	@rm -rf *.o
	@echo -- Deleting All .o
fclean: clean
	@rm -f $(NAME)
	@echo -- Deleting .a

re: fclean all

.PHONY: all clean fclean re