/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_checks_player.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:13:57 by lnicoter          #+#    #+#             */
/*   Updated: 2023/11/27 16:39:45 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	save_player_pos(t_cube *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->real_map[++i])
	{
		j = -1;
		while (game->real_map[i][++j])
		{
			if (isplayer(game->real_map[i][j]))
			{
				game->player->posx = i; //ad essere onesto non saprei dire quale fa più comodo
				game->player->posy = j;
				break ;
			}
		}
	}
}
