/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuele <manuele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:47:53 by lnicoter          #+#    #+#             */
/*   Updated: 2023/12/01 15:55:54 by manuele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	isplayer(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	inmap(char c)
{
	if (c == '0' || isplayer(c))
		return (1);
	return (0);
}

int	ismap(char c)
{
	if (c == '1' || isplayer(c) || inmap(c))
		return (1);
	return (0);
}

int	fix_lenght_rows(char **map, int **map_len, t_cube *game)
{
	int	i;
	int	j;

	i = -1;
	//qui legge il \t e giustamente da errore
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (!(ismap(map[i][j]) || map[i][j] == 32 || map[i][j] == '\n'))
				return (0);
		}
		(*map_len)[i] = j;
		if (game->map_max_width < j)
			game->map_max_width = j;
	}
	return (1);
}

void	is_map_last(t_cube *game)
{
	int	card;
	int	flo_cei;
	int	i;

	i = -1;
	card = 0;
	flo_cei = 0;
	while (game->all_map[++i])
	{
		if (!ft_strncmp(game->all_map[i], "NO", 2)
			|| !ft_strncmp(game->all_map[i], "SO", 2)
			|| !ft_strncmp(game->all_map[i], "EA", 2)
			|| !ft_strncmp(game->all_map[i], "WE", 2))
			card++;
		else if (!ft_strncmp(game->all_map[i], "F", 1)
				|| !ft_strncmp(game->all_map[i], "C", 1))
			flo_cei++;
		else if (card == 4 && flo_cei == 2)
			break ;
		else
			ft_error("The map should be the last argument\n",game);
	}
}
