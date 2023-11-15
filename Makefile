# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/01 14:36:32 by fcarlucc          #+#    #+#              #
#    Updated: 2023/11/15 11:54:37 by mlongo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = $(wildcard *.c) \
		# $(wildcard executor/*.c) \

OBJS = $(SRC:.c=.o)

FLAGS := -Wall -Wextra -Werror -g

LIBFT_PATH = ./libft

LIBFT = ${LIBFT_PATH}/libft.a

#COLORS
RED = \033[1;31m

GREEN = \033[1;32m

YELLOW = \033[1;33m

DEFAULT = \033[0m

all: $(NAME)

%.o : %.c
	@cc $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@make -C libft
	@make bonus -C libft
	@cc $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME) -lreadline
	@echo "$(GREEN)$(NAME) created!$(DEFAULT)"

clean:
	@make clean -C libft
	@rm -f $(OBJS)
	@echo "$(YELLOW)object files deleted!$(DEFAULT)"

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)
	@echo "$(RED)all deleted!$(DEFAULT)"

re: clean fclean all
