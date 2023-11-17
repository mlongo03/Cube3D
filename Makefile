NAME := Cube3D

CC := gcc

FILES = $(wildcard *.c) \


CFLAGS := -g #-Wall -Werror -Wextra

LIBFT := libft
LIBRARY := -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
MINILIBX := mlx_linux/

all:
	make -C $(LIBFT)
	make -C $(MINILIBX)
	$(CC) $(FILES) $(CFLAGS) $(LIBFT)/libft.a -L/$(LIBFT) $(LIBRARY) -o $(NAME)

clean: fclean

fclean: clean
		make re -C $(MINILIBX)
		make fclean -C $(LIBFT)
		rm -rf $(NAME)

re: fclean all
