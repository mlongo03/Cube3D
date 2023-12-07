# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/01 14:36:32 by fcarlucc          #+#    #+#              #
#    Updated: 2023/12/07 17:48:52 by lnicoter         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cube3d

SRC = $(wildcard *.c) \
		$(wildcard checks/*.c) \
		$(wildcard colors/*.c) \
		$(wildcard rendering/*.c) \
		$(wildcard minimap/*.c) \

OBJS = $(SRC:.c=.o)

FLAGS := -Wall -Werror -Wextra -g

LIBFT_PATH = ./libft

FT_PRINTF_PATH = ./ft_printf

MINILIBX_PATH = ./mlx_linux

LIBFT = ${LIBFT_PATH}/libft.a

FT_PRINTF = ${FT_PRINTF_PATH}/libftprintf.a

MINILIBX =${MINILIBX_PATH}/libmlx.a

MINILIBX_LINUX =${MINILIBX_PATH}/libmlx_Linux.a

#COLORS
RED = \033[1;31m

GREEN = \033[1;32m

YELLOW = \033[1;33m

DEFAULT = \033[0m

all: $(NAME)

%.o : %.c
	@cc $(FLAGS) -I/usr/includesude -Imlx_linux -c $< -o $@

$(NAME): $(OBJS)
	@make -C libft
	@make bonus -C libft
	@make -C ft_printf
	@make -C mlx_linux
	@cc $(FLAGS) $(OBJS) $(LIBFT) $(FT_PRINTF) ${MINILIBX} ${MINILIBX_LINUX} -Lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -D LIN=1 -o $(NAME)
	@echo "$(GREEN)$(NAME) created!$(DEFAULT)"

clean:
	@make clean -C libft
	@make clean -C ft_printf
	@make clean -C mlx_linux
	@rm -f $(OBJS)
	@echo "$(YELLOW)object files deleted!$(DEFAULT)"

fclean: clean
	@make fclean -C libft
	@make fclean -C ft_printf
	@rm -f $(NAME)
	@echo "$(RED)all deleted!$(DEFAULT)"

re: clean fclean all
