/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_map_building.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:55:07 by lnicoter          #+#    #+#             */
/*   Updated: 2023/12/04 19:16:18 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

static int	is_one_of_them(t_cube *game, int i)
{
	if (!ft_strncmp(game->all_map[i], "NO", 2)
			|| !ft_strncmp(game->all_map[i], "SO", 2)
			|| !ft_strncmp(game->all_map[i], "EA", 2)
			|| !ft_strncmp(game->all_map[i], "WE", 2)
			|| !ft_strncmp(game->all_map[i], "F", 1)
			|| !ft_strncmp(game->all_map[i], "C", 1))
			return (1);
	return (0);
}

static void	take_real_map_phase_2(t_cube *game)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (game->all_map[++i])
	{
		if (ft_strchr(game->all_map[i], '1')
			&& ft_strncmp(game->all_map[i], "SO", 2)
			&& ft_strncmp(game->all_map[i], "EA", 2)
			&& ft_strncmp(game->all_map[i], "WE", 2)
			&& ft_strncmp(game->all_map[i], "F", 1)
			&& ft_strncmp(game->all_map[i], "C", 1))
		{
			i--;
			while (game->all_map[++i])
			{
				game->real_map[j] = ft_strdup(game->all_map[i]);
				j++;
			}
			game->real_map[j] = 0;
			break ;
		}
	}
}

void	take_real_map(t_cube *game)
{
	int	i;
	int	j;
	int	count_them;

	count_them = 0;
	i = -1;
	j = 0;

	while (game->all_map[++i] && count_them < 6)
	{
		if (is_one_of_them(game, i))
			count_them++;
	}
	while (game->all_map[++i] && !ft_strchr(game->all_map[i], '1'))
		;
	--i;
	while (game->all_map[++i])
		j++;
	//serviva un +2 alla j ho calcolato male lo spazio e uscivo con la matrice
	game->real_map = ft_calloc(j + 2, sizeof(char *));
	if (!game->real_map)
		free_struct(game);
	take_real_map_phase_2(game);
	game->map_len = malloc(sizeof(int) * count_rows(game->real_map));
	if (!game->map_len)
		ft_error("Malloc Error\n", game);
}
