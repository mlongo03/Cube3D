/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:08:03 by lnicoter          #+#    #+#             */
/*   Updated: 2023/11/17 14:54:46 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	struct_init(t_cube *game)
{
	//non serve per ora
	game->c_color_num = 0;
	game->f_color_num = 0;
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
	if (game->ceiling_colors)
		free_matrix(game->ceiling_colors);
	if (game->floor_colors)
		free_matrix(game->floor_colors);
	if (game->f_hex_color)
		free(game->f_hex_color);
	if (game-> c_hex_color)
		free(game->c_hex_color);
	free(game);
	exit(0);
}

void	ft_error(char *str_err, t_cube *game)
{
	printf("%s\n", str_err);
	free_struct(game);
}
