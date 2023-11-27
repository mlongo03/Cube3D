/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:08:12 by lnicoter          #+#    #+#             */
/*   Updated: 2023/11/27 16:50:26 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	free_matrix(char **mat)
{
	int	i;

	i = -1;
	while (mat[++i])
		free(mat[i]);
	free(mat);
}

int	count_rows(char **mat)
{
	int	i;

	i = -1;
	while (mat[++i])
		;
	return (i);
}

void	free_cardinals(t_cube *game)
{
	if (game->card->north_path)
		free(game->card->north_path);
	if (game->card->south_path)
		free(game->card->south_path);
	if (game->card->east_path)
		free(game->card->east_path);
	if (game->card->west_path)
		free(game->card->west_path);
}
