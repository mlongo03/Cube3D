/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:47:53 by lnicoter          #+#    #+#             */
/*   Updated: 2023/11/21 08:46:45 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

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

int	fix_lenght_rows(char **map, int **map_len)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (!(ismap(map[i][j]) || map[i][j] == 32 || map[i][j] == '\n'))
				return (0);
		}
		(*map_len)[i] = j;
	}
	return (1);
}
