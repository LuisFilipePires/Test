# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luis-fif <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/04 09:01:00 by luis-fif          #+#    #+#              #
#    Updated: 2024/03/11 16:06:42 by luis-fif         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 	ft_bzero.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_strlcpy.c \
	ft_memset.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_strnstr.c \
	ft_split.c
	
NAME	=	libft.a
OBJS	=	${SRC:.c=.o}
CC	=	cc
RM	=	rm -f

CFLAGS =	-Wall -Wextra -Werror

.c.o:
	@ ${CC}  ${CFLAGS} -g -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	@ ar rcs ${NAME} ${OBJS}

all:		${NAME}

clean:
		@ ${RM} ${OBJS}

fclean:	clean
				@ ${RM} ${NAME}

re:			fclean all
