/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_map_checks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:52:37 by lnicoter          #+#    #+#             */
/*   Updated: 2023/11/17 17:33:44 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int	player_existence(t_cube *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->real_map[++i])
	{
		j = -1;
		while (game->real_map[i][++j])
		{
			if (game->real_map[i][j] == 'N' || game->real_map[i][j] == 'S'
				|| game->real_map[i][j] == 'E'
				|| game->real_map[i][j] == 'W')
			{
				game->player->posx = i;
				game->player->posy = j;
				return (1);
			}
		}
	}
	return (0);
}

static int	check_walls(t_cube *game)
{
	int	i;
	int	is_zero;

	is_zero = 0;
	i = -1;

	if (!ft_strncmp(game->real_map[0], "0",
		ft_strlen(game->real_map[0])))
		return (0);
	if (!ft_strncmp(game->real_map[count_rows(game->real_map) - 1], "0",
		ft_strlen(game->real_map[count_rows(game->real_map) - 1])))
		return (0);
	while (game->real_map[++i])
		if (ft_strchr(game->real_map[i], '0'))
			is_zero = 1;
	if (!is_zero)
		return (0);
	return (1);
}

void	main_check(t_cube *game)
{
	if (!player_existence(game))
		ft_error("Error player not found\n", game);
	if (!check_walls(game))
		ft_error("Error the map is not valid\n", game);
}
