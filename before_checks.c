/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   before_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 01:19:29 by lnicoter          #+#    #+#             */
/*   Updated: 2023/11/25 17:22:32 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	is_cub(char **av, t_cube *game)
{
	if (av[1][ft_strlen(av[1]) - 3] == 'c'
		&& av[1][ft_strlen(av[1]) - 2] == 'u'
		&& av[1][ft_strlen(av[1]) - 1] == 'b'
		&& av[1][ft_strlen(av[1])] == '\0')
		;
	else
		ft_error("The map must be of .cub type\n", game);
}

void	fix_map(t_cube *game) //funzione per sostituire gli spazi
{
	int		i;
	int		j;
	// char	**second_map;
	i = -1;
	// second_map = ft_calloc(count_rows(game->real_map), sizeof(char *));
	while (game->real_map[++i])
	{
		j = -1;
		while (game->real_map[i][++j] )
		{
			if (game->real_map[i][j] == ' '
				&& (game->real_map[i][j - 1]
				&& (game->real_map[i][j - 1] == '0')
				|| game->real_map[i][j - 1] == '1'))
				game->real_map[i][j] = '1';
		}
	}
	print_mat(game->real_map);
}
