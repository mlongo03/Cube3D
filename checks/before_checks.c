/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   before_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuele <manuele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 01:19:29 by lnicoter          #+#    #+#             */
/*   Updated: 2023/12/01 15:55:05 by manuele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	is_cub(char **av, t_cube *game)
{
	if (av[1][ft_strlen(av[1]) - 3] == 'c'
		&& av[1][ft_strlen(av[1]) - 2] == 'u'
		&& av[1][ft_strlen(av[1]) - 1] == 'b'
		&& av[1][ft_strlen(av[1])] == '\0'
		&& av[1][ft_strlen(av[1] - 4) == '.'])
		;
	else
		ft_error("The map must be of .cub type\n", game);
}

/*void	fix_map(t_cube *game) //funzione per sostituire gli spazi
{
	int		i;
	int		j;
	// char	**second_map;
	i = -1;
	// second_map = ft_calloc(count_rows(game->real_mapD), sizeof(char *));
	while (game->real_map[++i])
	{
		j = -1;
		while (game->real_map[i][++j] )
		{
			if (game->real_map[i][j] == ' '
				|| game->real_map[i][j] == '\t')
				game->real_map[i][j] = '1';
		}
	}
}*/


/*
Old check per la mappa provo a optare per altro
	if (game->real_map[i][j] == ' '
				&& (game->real_map[i][j - 1]
				&& (game->real_map[i][j - 1] == '0')
				|| game->real_map[i][j - 1] == '1'))
*/
