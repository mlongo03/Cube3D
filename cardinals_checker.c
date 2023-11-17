/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cardinals_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:44:09 by lnicoter          #+#    #+#             */
/*   Updated: 2023/11/17 15:08:49 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/*
	implementerò delle funzioni
	per controllare se la sezione dei punti cardinali è ok
	come se ci sono doppioni o se non ci sono valori
	insomma per snellire il codice da 26 righe
	oltre al controllo generico devo controllare che non c'è ne
	sia più di uno penso che lo farò dopo pranzo :)
	piccola nota per dopo:
		se non c'è il primo cardinals va in segfault
*/


void	check_existence(t_cube *game, int i)
{
	if (!ft_strncmp(game->all_map[i], "NO", 2))
		game->check_card[0] += 1;
	if (!ft_strncmp(game->all_map[i], "SO", 2))
		game->check_card[1] += 1;
	if (!ft_strncmp(game->all_map[i], "EA", 2))
		game->check_card[2] += 1;
	if (!ft_strncmp(game->all_map[i], "WE", 2))
		game->check_card[3] += 1;
}
