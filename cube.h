/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 22:55:48 by lnicoter          #+#    #+#             */
/*   Updated: 2023/11/17 12:04:46 by lnicoter         ###   ########.fr       */
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
}	t_cardinals;

//snellire la struct principale per non averci troppa roba dentro
typedef	struct s_cube
{
	void			*mlx;
	char			**all_map; //la mappa con letteralmente tutto
	char			**real_map; //la mappa base
	t_cardinals		*card;
	int	f_color_num;
	int	c_color_num;
	char			**floor_colors; //temporanei per la conersione puoi liberarli subito dopo
	char			**ceiling_colors;
	char			*f_hex_color;
	char			*c_hex_color;
	int				check_card[4];
}	t_cube;

void	struct_init(t_cube *game);
void	read_and_build(t_cube *game);
void	print_mat(char **mat);
void	free_struct(t_cube *game);
int		check_cardinals(t_cube *game);
void	take_real_map(t_cube *game);
void	ft_error(char *str_err, t_cube *game);
void	save_floor_colors(t_cube *game, char *f_color_str);
void	save_ceiling_colors(t_cube *game, char *c_color_str);
void	set_colors(t_cube *game, int i, int floor_flag, int ceiling_flag);
void	ft_rgb(int	*color, unsigned int rgb[3], int i);
void	color_convertion_int(t_cube *game);
void	save_colors_in_str(t_cube *game);
void	free_matrix(char **mat);
void	check_existence(t_cube *game, int i);

#endif
