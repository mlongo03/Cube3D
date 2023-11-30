/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuele <manuele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:08:03 by lnicoter          #+#    #+#             */
/*   Updated: 2023/11/30 16:11:26 by manuele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	struct_init(t_cube *game)
{
	game->colors = ft_calloc(1, sizeof(t_colors));
	game->player = ft_calloc(1, sizeof(t_player));
	game->img = ft_calloc(1, sizeof(t_img));
	game->player->posX = 10;
	game->player->posY = 10;
	game->player->dirX = -1;
	game->player->dirY = 0;
	game->player->planeX = 0;
	game->player->planeY = 0.66;
	game->player->mov_dirX = 0;
	game->player->mov_dirY = 0;
	game->player->cam_dir = 0;
	game->time = 0;
	game->oldTime = 0;
	game->colors->c_color_num = 0;
	game->colors->f_color_num = 0;
}

void	print_mat(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
	{
		printf("mat value %s\n\n", mat[i]);
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
	free(game->colors);
	free(game->player);
	free(game);
	exit(0);
}

void	ft_error(char *str_err, t_cube *game)
{
	printf("%s\n", str_err);
	free_struct(game);
}
