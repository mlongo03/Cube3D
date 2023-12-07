/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:06:56 by mlongo            #+#    #+#             */
/*   Updated: 2023/12/06 19:29:21 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
#define CUBE_H

# define screenWidth 1920
# define screenHeight 1080
// # define screenWidth 1000
// # define screenHeight 700
# define Closed 0
# define Open 3
# define Opening 1
# define Closing 2
# include "libft/libft.h"
# include "mlx_linux/mlx.h"
# include <math.h>
# include <error.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdbool.h>
# include <stdint.h>


typedef	struct s_player
{
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	double	mov_dirX;
	double	mov_dirY;
	double	cam_dir;
	double	rot_angle;
}	t_player;

typedef	struct s_colors
{
	int				f_color_num;
	int				c_color_num;
	char			**floor_colors;
	char			**ceiling_colors;
	char			*f_hex_color;
	char			*c_hex_color;
}	t_colors;

typedef struct s_img
{
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_xpm_img
{
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_xpm_img;

typedef struct s_render_data
{
	double				mapX;
	double				mapY;
	double				stepX;
	double				stepY;
	int					hit;
	int					side;
	int					lineHeight;
	int					drawStart;
	int					drawEnd;
	int					texWidth;
	int					texHeight;
	int					texX;
	int					texY;
	unsigned int		color;
	double				cameraX;
	double				rayDirX;
	double				rayDirY;
	double				sideDistX;
	double				sideDistY;
	double				deltaDistX;
	double				deltaDistY;
	double				perpWallDist;
	double				wallX;
	double				step;
	double				texPos;
}	t_render_data;

typedef	struct s_cardinals
{
	t_xpm_img	north_wall;
	t_xpm_img	south_wall;
	t_xpm_img	east_wall;
	t_xpm_img	west_wall;
	char	*north_path;
	char	*south_path;
	char	*east_path;
	char	*west_path;
}	t_cardinals;

typedef struct s_mini
{
	int		drawStartHeight;
	int		drawStartWidth;
	int		drawEndHeight;
	int		drawEndWidth;
	int		x;
	int		y;
	int		scale; //square sensibility
}	t_mini;

typedef	struct s_cube
{
	void		*mlx;
	void		*mlx_win;
	char		**all_map;
	char		**real_map;
	int			**map_door_status;
	double		**map_door_timer;
	int			check_card[4];
	int			*map_len;
	int			fps;
	int			map_max_width;
	int			map_max_height;
	double		time;
	double		oldTime;
	double		frameTime;
	t_cardinals	*card;
	t_colors	*colors;
	t_mini		*mini;
	t_player	*player;
	t_img		*img;
	t_xpm_img	*door;
}	t_cube;

int		close_window(t_cube *cube);
void	struct_init(t_cube *game);
void	read_and_build(t_cube *game, char **av);
void	print_mat(char **mat);
void	free_struct(t_cube *game);
int		check_cardinals(t_cube *game);
void	take_real_map(t_cube *game);
void	ft_error(char *str_err, t_cube *game);
void	save_floor_colors(t_cube *game, char *f_color_str);
void	save_ceiling_colors(t_cube *game, char *c_color_str);
void	set_colors(t_cube *game, int i, int floor_flag, int ceiling_flag);
void	ft_rgb(int	*color, unsigned int rgb[3], int i, t_cube *game);
void	color_convertion_int(t_cube *game);
void	save_colors_in_str(t_cube *game);
void	free_matrix(char **mat);
void	free_matrix_double(double **mat);
void	free_matrix_int(int **mat);
void	check_existence(t_cube *game, int i);
void	main_check(t_cube *game);
int		count_rows(char **mat);
int		isplayer(char c);
int		inmap(char c);
int		ismap(char c);
int		final_map_check(t_cube *game, int *map_len);
int		fix_lenght_rows(char **map, int **map_len, t_cube *cube);
void	is_map_last(t_cube *game);
void	is_cub(char **av, t_cube *game);
void	save_cardinals_path(t_cube *game);
void	save_player_pos(t_cube *game);
void	free_cardinals(t_cube *game);
void	save_player_pos(t_cube *game);
int		countTabs(char *str);
char	*replaceTabs(char *str, int count);
char	*replaceTabWithSpaces(char *str);

#endif
