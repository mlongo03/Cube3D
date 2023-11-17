/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_map_building.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:55:07 by lnicoter          #+#    #+#             */
/*   Updated: 2023/11/14 23:18:39 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	take_real_map(t_cube *game)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (game->all_map[++i] && game->all_map[i][0] == '1')
		;
	--i;
	while (game->all_map[++i])
		j++;
	game->real_map = malloc(j * sizeof(char *) + 1);
	if (!game->real_map)
		free_struct(game);
	i = -1;
	j = 0;
	while (game->all_map[++i])
	{
		if (game->all_map[i][0] == '1')
		{
			i--;
			while (game->all_map[++i])
				game->real_map[j++] = ft_strdup(game->all_map[i]);
			game->real_map[j] = 0;
			break ;
		}
	}
}
