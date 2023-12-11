/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_map_checks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:52:37 by lnicoter          #+#    #+#             */
/*   Updated: 2023/12/11 15:29:57 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

static int	check_adjacent(t_cube *game, int i, int j)
{
	if ((game->real_map[i - 1][j] == '1'
		&& game->real_map[i + 1][j] == '1')
		|| (game->real_map[i][j - 1] == '1'
		&& game->real_map[i][j + 1] == '1'))
			;
	else
		return (0);
	return (1);
}

static int	check_doors_walls(t_cube *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->real_map[++i])
	{
		j = -1;
		while (game->real_map[i][++j])
		{
			if (game->real_map[i][j] == '2' && (i == 0
				|| i == count_rows(game->real_map)))
				return (0);
			if (game->real_map[i][j] == '2' && (j == 0
				|| j == (int)ft_strlen(game->real_map[i])))
				return (0);
			if (game->real_map[i][j] == '2')
			{
				if (!check_adjacent(game, i, j))
					return (0);
			}
		}
	}
	return (1);
}

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
				game->player->posy = i + 0.5;
				game->player->posx = j + 0.5;
				game->player->direction = game->real_map[i][j];
				game->real_map[i][j] = '0';
				return (1);
			}
		}
	}
	return (0);
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
			if (inmap(game->real_map[i][j])
				&& !(j && ismap(game->real_map[i][j - 1])
				&& game->real_map[i][j + 1]
				&& ismap(game->real_map[i][j + 1])
				&& i && map_len[i - 1] >= j + 1
				&& ismap(game->real_map[i - 1][j - 1])
				&& ismap(game->real_map[i - 1][j])
				&& ismap(game->real_map[i - 1][j + 1])
				&& game->real_map[i + 1] && map_len[i + 1] >= j
				&& ismap(game->real_map[i + 1][j - 1])
				&& ismap(game->real_map[i + 1][j])
				&& ismap(game->real_map[i + 1][j + 1])))
				return (0);
		}
	}
	return (1);
}

void	main_check(t_cube *game)
{
	int	i;

	i = -1;
	while (game->real_map[++i])
		game->real_map[i] = replace_tab_with_spaces(game->real_map[i]);
	save_player_pos(game);
	if (!fix_lenght_rows(game->real_map, &game->map_len, game))
		ft_error("Error the map has an unknown tile", game);
	if (!player_existence(game))
		ft_error("Error player not found", game);
	if (!final_map_check(game, game->map_len))
		ft_error("Error the map is not closed", game);
	if (!check_doors_walls(game))
		ft_error("Error the doors of the map aren't setted correctly", game);
	game->map_max_height = count_rows(game->real_map);
}
