/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:10:18 by lnicoter          #+#    #+#             */
/*   Updated: 2023/11/17 11:20:55 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	save_floor_colors(t_cube *game, char *f_color_str)
{
	int		i;
	char	*test_str;

	while (*f_color_str == 'F' || *f_color_str == ' ')
		f_color_str++;
	test_str = ft_strdup(f_color_str);
	game->floor_colors = ft_split(test_str, ',');
	free(test_str);
}

void	save_ceiling_colors(t_cube *game, char *c_color_str)
{
	int		i;
	char	*test_str;

	while (*c_color_str == 'C' || *c_color_str == ' ')
		c_color_str++;
	test_str = ft_strdup(c_color_str);
	game->ceiling_colors = ft_split(test_str, ',');
	free(test_str);
}

void	set_colors(t_cube *game, int i, int floor_flag, int ceiling_flag)
{
	if (!ft_strncmp(game->all_map[i], "F", 1))
		{
			if (floor_flag == 1)
				ft_error("Error you put another floor color", game);
			save_floor_colors(game, game->all_map[i]);
			floor_flag = 1;
		}
		if (!ft_strncmp(game->all_map[i], "C", 1))
		{
			if (ceiling_flag == 1)
				ft_error("Error you put another ceiling color", game);
			save_ceiling_colors(game, game->all_map[i]);
			ceiling_flag = 1;
		}
}

void	ft_rgb(int	*color, unsigned int rgb[3], int i)
{
	if (rgb[i] > 255)
		exit(1);

	// Shifting bits e combinazione dei componenti di colore in un unico valore
	*color += (rgb[i] << (((i + 2) - (i * 2)) * 8));
}

void	color_convertion_int(t_cube *game)
{
	int				i;
	unsigned int	rgb_c[3];
	unsigned int	rgb_f[3];
	i = -1;
	//modificare per controllare se valore negativo
	while (game->ceiling_colors[++i] && i < 3)
		rgb_c[i] = ft_atoi(game->ceiling_colors[i]);
	i = -1;
	while (game->floor_colors[++i] && i < 3)
		rgb_f[i] = ft_atoi(game->floor_colors[i]);
	i = -1;
	while (++i < 3)
	{
		ft_rgb(&game->c_color_num, rgb_c, i);
		ft_rgb(&game->f_color_num, rgb_f, i);
	}
}
