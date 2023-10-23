![Banner](https://github.com/byaliego/42-project-badges/blob/main/covers/cover-ft_printf-bonus.png)

## About

> A simple version of printf, a function that prints characters into standard output / terminal.

### How to include

> Inside your makefile include the following rule:

```
PRINTF_DIR = <ft_printf directory path>  example: ./includes/ft_printf

$(PRINTF):
	@ make -C $(PRINTF_DIR) all
  
```

Then, include the variable $(PRINTF) into the compiler line.

example: gcc main.c $(PRINTF)

## Usage

> ft_printf("string", variable(if any % is added in the string));
* example :
> ft_printf("Hello my name is %s and I have %d year of experience atm\n", "Jorge", 1);

## Contents

This minimalistic printf supports the following conversions:

* %c Prints a single character.
* %s Prints a string (as defined by the common C convention).
* %p The void * pointer argument has to be printed in hexadecimal format.
* %d Prints a decimal (base 10) number.
* %i Prints an integer in base 10.
* %u Prints an unsigned decimal (base 10) number.
* %x Prints a number in hexadecimal (base 16) lowercase format.
* %X Prints a number in hexadecimal (base 16) uppercase format.
* %% Prints a percent sign.
