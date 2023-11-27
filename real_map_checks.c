/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_map_checks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:52:37 by lnicoter          #+#    #+#             */
/*   Updated: 2023/11/27 15:50:53 by lnicoter         ###   ########.fr       */
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
	if (ft_strchr(game->real_map[count_rows(game->real_map) - 1], '0'))
		return (0);
	while (game->real_map[++i])
		if (ft_strchr(game->real_map[i], '0'))
			is_zero = 1;
	if (!is_zero)
		return (0);
	return (1);
}

static int	check_columns(t_cube *game)
{
	int	i;

	i = -1;
	while (game->real_map[++i])
	{
		if (game->real_map[i][0] != '1'
			|| game->real_map[i][ft_strlen(game->real_map[i]) - 1] != '1')
			return (0);
	}
	return (1);
}

int	final_map_check(t_cube *game, int *map_len)
{
	int	i;
	int	j;

	i = -1;
	while (game->real_map[++i])
	{
		j = -1;
		while (game->real_map[i][++j])
		{
			if (inmap(game->real_map[i][j]) && !(j && ismap(game->real_map[i][j - 1])
			&& game->real_map[i][j + 1] && ismap(game->real_map[i][j + 1])
			&& i && map_len[i - 1] >= j + 1 && ismap(game->real_map[i - 1][j - 1])
			&& ismap(game->real_map[i - 1][j]) && ismap(game->real_map[i - 1][j + 1])
			&& game->real_map[i + 1] && map_len[i + 1] >= j
			&& ismap(game->real_map[i + 1][j - 1])
			&& ismap(game->real_map[i + 1][j]) && ismap(game->real_map[i + 1][j + 1])))
				return (0);
			// if (isplayer(game->real_map[i][j]))
			// 	return (0);
		}
	}
	return (1);
}

void	main_check(t_cube *game)
{
	print_mat(game->real_map);
	printf("\n\n");
	save_player_pos(game);
	fix_map(game);
	if (!fix_lenght_rows(game->real_map, &game->map_len))
		ft_error("Error the map has an unknown tile\n",game);
	if (!player_existence(game))
		ft_error("Error player not found\n", game);
	// if (!check_walls(game))
	// 	ft_error("Error the map is not valid\n", game);
	if (!check_columns(game))
		ft_error("Error the map is not valid 2\n", game);
	if (!final_map_check(game, game->map_len))
		ft_error("Error the map is not closed\n", game);
}
