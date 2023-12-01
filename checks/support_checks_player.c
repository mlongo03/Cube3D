/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_checks_player.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuele <manuele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:13:57 by lnicoter          #+#    #+#             */
/*   Updated: 2023/12/01 16:05:44 by manuele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

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
				game->player->posX = i; //ad essere onesto non saprei dire quale fa più comodo
				game->player->posY = j;
				break ;
			}
		}
	}
}
