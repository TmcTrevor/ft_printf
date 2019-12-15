# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mokhames <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/21 17:22:59 by mokhames          #+#    #+#              #
#    Updated: 2019/12/04 21:28:09 by mokhames         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FT_PRINTF_SRC = ft_printf.c \
				ft_check_format.c ft_edit_flags.c \
				ft_new_decimal.c\
				ft_itoa_base.c \
				ft_num_of_digits.c \
				ft_putstr2.c \
				ft_ultoa_base.c \
				ft_print_string.c \
				ft_print_hexadecimal.c \
				ft_print_char.c \
				ft_print_percent.c \
				ft_print_pointer.c	\
				ft_print_unsigned_decimal.c \
				ft_uitoa_base.c \
				ft_hextoa_base.c

LIBFT_PATH = $(wildcard libft/*.c)

OBJ = $(wildcard *.o)

NAME = libftprintf.a

all: $(NAME)

$(NAME): 
	@gcc -Wall -Wextra -Werror -c $(FT_PRINTF_SRC) $(LIBFT_PATH)
	@ar rc $(NAME) *.o
	@ranlib $(NAME)

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

