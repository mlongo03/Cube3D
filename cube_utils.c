/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:08:03 by lnicoter          #+#    #+#             */
/*   Updated: 2023/11/25 15:16:28 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	struct_init(t_cube *game)
{
	//non serve per ora
	game->colors = ft_calloc(1, sizeof(t_colors));
	game->player = ft_calloc(1, sizeof(t_player));
	game->colors->c_color_num = 0;
	game->colors->f_color_num = 0;
	game->player->posx = 0;
	game->player->posy = 0;
}

void	print_mat(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
	{
		printf("%s\n", mat[i]);
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
