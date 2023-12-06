/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_map_checks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:52:37 by lnicoter          #+#    #+#             */
/*   Updated: 2023/12/06 13:58:44 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

/*
Idea per dopo da costruire:
Allora con manu abbiamo chiaccherato e bisogna costruire
un controllo relativo al bonus, della mappa nei confronti
della porta la quale deve SEMPRE essere circondata da ALMENO
due muri. i muri però se sono solo 2 devono SEMPRE essere uniformi
nel senso

questo va bene
    0
   121
    0

oppure
   1
  020
   1
   
e questo NON va bene:
   0
  120
   1
sono due muri si ma non sono sulla stessa riga o colonna
fatto questo
*/
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
				|| j == ft_strlen(game->real_map[i])))
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
				game->player->posX= i;
				game->player->posY = j;
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
	int	i;

	i = -1;
	while (game->real_map[++i])
		game->real_map[i] = replaceTabWithSpaces(game->real_map[i]);
	save_player_pos(game);
	if (!fix_lenght_rows(game->real_map, &game->map_len, game))
		ft_error("Error the map has an unknown tile\n",game);
	if (!player_existence(game))
		ft_error("Error player not found\n", game);
	if (!final_map_check(game, game->map_len))
		ft_error("Error the map is not closed\n", game);
	if (!check_doors_walls(game))
		ft_error("Error the doors of the map aren't setted correctly\n", game);
	game->map_max_height = count_rows(game->real_map);
	printf("MaxHeight %d, MaxWidth %d\n", game->map_max_height, game->map_max_width);
}
