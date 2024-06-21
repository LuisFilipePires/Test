# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luis-fif <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/21 16:15:20 by luis-fif          #+#    #+#              #
#    Updated: 2024/06/15 14:08:30 by fil              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nome do executável
NAME = fdf

# Compilador
CC = gcc

# Diretórios
LIBFT_DIR = libft
MLX_DIR = minilibx-linux
FT_PRINTF_DIR = ft_printf
SRC_DIR = srcs
INC_DIR = includes

# Flags do compilador
CFLAGS = #-Wall -Wextra -Werror
INCLUDES = -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR) -I$(FT_PRINTF_DIR)

# Flags de linkagem
MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm
LIBFLAGS = -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf

# Arquivos
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:.c=.o)
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF_SRCS = $(wildcard $(FT_PRINTF_DIR)/*.c)
PRINTF_OBJS = $(PRINTF_SRCS:.c=.o)

# Regras
all: $(NAME)

$(LIBFT_DIR)/libft.a:
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_DIR)/libmlx.a:
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(LIBFT) $(MLX_DIR)/libmlx.a $(OBJS) $(PRINTF_OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF_OBJS) -o $(NAME) $(MLX_FLAGS) $(LIBFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(FT_PRINTF_DIR)/%.o: $(FT_PRINTF_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(OBJS) $(PRINTF_OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

