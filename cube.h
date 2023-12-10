/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuele <manuele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:06:56 by mlongo            #+#    #+#             */
/*   Updated: 2023/12/10 13:56:24 by manuele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# define SCREENWIDTH 1000
# define SCREENHEIGHT 700
# define CLOSED 0
# define OPEN 3
# define OPENING 1
# define CLOSING 2
# include "libft/libft.h"
# include "mlx_linux/mlx.h"
# include "ft_printf/ft_printf.h"
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

typedef struct s_player
{
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	mov_dirx;
	double	mov_diry;
	double	cam_dir;
	double	rot_angle;
	char	direction;
}	t_player;

typedef struct s_colors
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
	int		bpp;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_xpm_img
{
	void	*img;
	void	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_xpm_img;

typedef struct s_render_data
{
	double				map_x;
	double				map_y;
	double				step_x;
	double				step_y;
	int					hit;
	int					side;
	int					line_height;
	int					draw_start;
	int					draw_end;
	int					tex_width;
	int					tex_height;
	int					tex_x;
	int					tex_y;
	unsigned int		color;
	double				camera_x;
	double				ray_dir_x;
	double				ray_dir_y;
	double				side_dist_x;
	double				side_dist_y;
	double				delta_dist_x;
	double				delta_dist_y;
	double				perp_wall_dist;
	double				wall_x;
	double				step;
	double				tex_pos;
}	t_render_data;

typedef struct s_cardinals
{
	t_xpm_img	north_wall;
	t_xpm_img	south_wall;
	t_xpm_img	east_wall;
	t_xpm_img	west_wall;
	char		*north_path;
	char		*south_path;
	char		*east_path;
	char		*west_path;
}	t_cardinals;

typedef struct s_mini_draw_vars
{
	int	offset;
	int	dist_width;
	int	dist_height;
	int	fix_y;
	int	fix_x;
	int	is_width_even;
	int	is_height_even;
}	t_mini_draw_vars;

typedef struct s_mini
{
	int		draw_start_height;
	int		draw_start_width;
	int		draw_end_height;
	int		draw_end_width;
	int		x;
	int		y;
	int		scale;
}	t_mini;

typedef struct s_cube
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
	double		old_time;
	double		frame_time;
	t_cardinals	*card;
	t_colors	*colors;
	t_mini		*mini;
	t_player	*player;
	t_img		*img;
	t_xpm_img	*door;
}	t_cube;

int			close_window(t_cube *cube);
void		struct_init(t_cube *game);
void		read_and_build(t_cube *game, char **av);
void		print_mat(char **mat);
void		free_struct(t_cube *game);
int			check_cardinals(t_cube *game);
void		take_real_map(t_cube *game);
void		ft_error(char *str_err, t_cube *game);
void		save_floor_colors(t_cube *game, char *f_color_str);
void		save_ceiling_colors(t_cube *game, char *c_color_str);
void		set_colors(t_cube *game, int i, int floor_flag, int ceiling_flag);
void		ft_rgb(int	*color, unsigned int rgb[3], int i, t_cube *game);
void		color_convertion_int(t_cube *game);
void		save_colors_in_str(t_cube *game);
void		free_matrix(char **mat);
void		free_matrix_double(double **mat);
void		free_matrix_int(int **mat);
void		check_existence(t_cube *game, int i);
void		main_check(t_cube *game);
int			count_rows(char **mat);
int			isplayer(char c);
int			inmap(char c);
int			ismap(char c);
int			final_map_check(t_cube *game, int *map_len);
int			fix_lenght_rows(char **map, int **map_len, t_cube *cube);
void		is_map_last(t_cube *game);
void		is_cub(char **av, t_cube *game);
void		save_cardinals_path(t_cube *game);
void		save_player_pos(t_cube *game);
void		free_cardinals(t_cube *game);
void		save_player_pos(t_cube *game);
int			count_tabs(char *str);
char		*replace_tabs(char *str, int count);
char		*replace_tab_with_spaces(char *str);
void		rotate_left(t_cube *cube, double rot_speed);
void		rotate_right(t_cube *cube, double rot_speed);
void		update_rotation(t_cube *cube);
void		move_forward(t_cube *cube, double moveSpeed);
void		move_backward(t_cube *cube, double moveSpeed);
void		move_left(t_cube *cube, double moveSpeed);
void		move_right(t_cube *cube, double moveSpeed);
void		update_movement(t_cube *cube);
int			handle_mouse(int x, int y, void	*cube);
void		mlx_hooks(t_cube *cube);
void		ft_sleep(u_int64_t time);
void		calculate_fps(t_cube *cube);
int			game_loop(t_cube *cube);
void		handle_door(t_cube *cube);
int			key_hook_press(int key, t_cube *cube);
int			key_hook_release(int key, t_cube *cube);
void		rotate_camera(float angle, t_cube *cube);
void		load_imgs(t_cube *game);
void		render_doors(t_cube *cube);
int			close_window(t_cube *cube);
void		set_positions_to_watch(t_cube *cube, int *pos);
void		render_map(t_cube *cube);
void		destroy_all(t_cube *cube);
void		draw_squares(t_cube *cube, int x, int y);
void		render_minimap(t_cube *cube);
void		update_door(int x, int y, t_cube *cube);
void		update_doors(t_cube *cube);
void		draw_square(int startX, int startY, t_cube *cube, int color);
void		player_close_to_so_limit(t_mini_draw_vars *mp, t_cube *cube);
void		player_close_to_ea_limit(t_mini_draw_vars *mp, t_cube *cube);
void		player_close_to_we_limit(t_mini_draw_vars *mp, t_cube *cube);
void		adjust_start_end(t_mini_draw_vars *mp, t_cube *cube);
void		init_draw_vars(t_cube *cube);
void		load_textures(t_cube *cube);
void		init_mp(t_mini_draw_vars *mp, t_cube *cube);
void		calculate_start_end_mini(t_mini_draw_vars *mp, t_cube *cube);
void		player_close_to_no_limit(t_mini_draw_vars *mp, t_cube *cube);
void		draw_tex_wall(t_render_data *data, t_cube *cube, int x);
int			set_wall_x(t_render_data *data, t_cube *cube);
int			wall_pos_ray_pos_on_wall(t_render_data *data, t_cube *cube);
void		draw_vertical_line(t_render_data *data, t_cube *cube, int x);
void		load_door(t_cube *cube);
int			perform_dda_doors(t_render_data *data, t_cube *cube);
void		set_color(t_render_data *data, t_cube *cube, int shift);
void		my_mlx_pixel_put(t_img *img, int x, int y, int color);
void		door_tex_init(t_render_data *data, t_cube *cube);
void		set_tex_width_height(t_render_data *data, t_cube *cube);
void		init_step_direction(t_render_data *data, t_cube *cube);
void		init_render_data(t_render_data *data, t_cube *cube, int x);
void		perform_dda(t_render_data *data, t_cube *cube);
void		detect_vertical_door(t_render_data *data, t_cube *cube);
void		detect_horizontal_door(t_render_data *data, t_cube *cube);
u_int64_t	get_time(void);

#endif
