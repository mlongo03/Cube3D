/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuele <manuele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:08:03 by lnicoter          #+#    #+#             */
/*   Updated: 2023/12/10 14:14:44 by manuele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"



void	struct_init(t_cube *game)
{
	game->colors = ft_calloc(1, sizeof(t_colors));
	game->player = ft_calloc(1, sizeof(t_player));
	game->img = ft_calloc(1, sizeof(t_img));
	game->card = ft_calloc(1, sizeof(t_cardinals));
	game->door = ft_calloc(1, sizeof(t_xpm_img));
	game->player->posx = 0;
	game->player->posy = 0;
	game->player->dirx = 0;
	game->player->diry = 0;
	game->player->planex = 0;
	game->player->planey = 0;
	game->player->mov_dirx = 0;
	game->player->mov_diry = 0;
	game->player->cam_dir = 0;
	game->player->rot_angle = 360;
	game->time = 0;
	game->old_time = 0;
	game->colors->c_color_num = 0;
	game->colors->f_color_num = 0;
	game->map_max_width = 0;
	game->map_max_height = 0;
}

void	print_mat(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
	{
		ft_printf("%s\n", mat[i]);
		i++;
	}
}

void	free_struct(t_cube *game)
{
	if (game->all_map)
		free_matrix(game->all_map);
	if (game->real_map)
		free_matrix(game->real_map);
	if (game->colors->ceiling_colors)
		free_matrix(game->colors->ceiling_colors);
	if (game->colors->floor_colors)
		free_matrix(game->colors->floor_colors);
	if (game->colors->f_hex_color)
		free(game->colors->f_hex_color);
	if (game->colors->c_hex_color)
		free(game->colors->c_hex_color);
	if (game->map_len)
		free(game->map_len);
	if (game->card)
		free_cardinals(game);
	free(game->colors);
	free(game->player);
	free(game);
	exit(0);
}

void	ft_error(char *str_err, t_cube *game)
{
	ft_printf("%s\n", str_err);
	free_struct(game);
}

void	ft_sleep(u_int64_t time)
{
	u_int64_t	start;

	start = 0;
	start = get_time();
	while ((get_time() - start) < time)
		usleep(time / 10);
}
