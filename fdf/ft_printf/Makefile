# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luis-fif <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/26 13:18:43 by luis-fif          #+#    #+#              #
#    Updated: 2024/03/26 13:19:01 by luis-fif         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFTNAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFTDIR = ../libft

SRCS = 	ft_printf.c \
	ft_char.c \
	ft_string.c \
	ft_number.c \
	ft_pnthex.c \
	ft_unsigned.c \
	ft_hexa.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

makelibft:
	@make -C $(LIBFTDIR)
	@cp $(LIBFTDIR)/$(LIBFTNAME) .

$(NAME): makelibft $(OBJS)
	@ar -rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@ar -rc $(NAME) $(LIBFTDIR)/*.o

clean:
	@rm -f $(OBJS)
	@cd $(LIBFTDIR) && make clean

fclean: clean
	@rm -f $(NAME)
	@cd $(LIBFTDIR) && make fclean

re: fclean all

