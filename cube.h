/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 22:55:48 by lnicoter          #+#    #+#             */
/*   Updated: 2023/11/27 16:50:52 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "./mlx_linux/mlx.h"
# include "./libft/libft.h" //fare modifiche per l'atoi???
# include <math.h>
# include <error.h>

typedef	struct s_cardinals
{
	void	*north_wall;
	void	*south_wall;
	void	*east_wall;
	void	*west_wall;
	char	*north_path;
	char	*south_path;
	char	*east_path;
	char	*west_path;
}	t_cardinals;

typedef	struct s_player
{
	int	posx;
	int	posy;
}	t_player;

typedef	struct s_colors
{
	int				f_color_num;
	int				c_color_num;
	char			**floor_colors; //temporanei per la conersione puoi liberarli subito dopo
	char			**ceiling_colors;
	char			*f_hex_color;
	char			*c_hex_color;
}	t_colors;

//snellire la struct principale per non averci troppa roba dentro
typedef	struct s_cube
{
	void			*mlx;
	void			*mlx_win;
	char			**all_map; //la mappa con letteralmente tutto
	char			**real_map; //la mappa base
	t_cardinals		*card;
	t_colors		*colors;
	int				check_card[4];
	t_player		*player;
	int				*map_len; //può diventare permanente (per ora provvisiorio)
}	t_cube;

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
void	check_existence(t_cube *game, int i);
void	main_check(t_cube *game);
int		count_rows(char **mat);
int		isplayer(char c);
int		inmap(char c);
int		ismap(char c);
int		final_map_check(t_cube *game, int *map_len);
int		fix_lenght_rows(char **map, int **map_len);
void	is_map_last(t_cube *game);
void	is_cub(char **av, t_cube *game);
void	fix_map(t_cube *game);
void	save_cardinals_path(t_cube *game);
void	save_player_pos(t_cube *game);
void	free_cardinals(t_cube *game);
#endif
