/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_colors_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:43:06 by lnicoter          #+#    #+#             */
/*   Updated: 2023/12/07 16:29:59 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

static char	*convert_to_hex(int decimal)
{
	int		i;
	int		temp;
	char	*hexa_number;

	i = 7;
	hexa_number = malloc(8 * sizeof(char) + 1);
	while (decimal != 0)
	{
		temp = decimal % 16;
		if (temp < 10)
			temp = temp + 48;
		else
			temp = temp + 55;
		hexa_number[i--] = temp;
		decimal = decimal / 16;
	}
	hexa_number[0] = '0';
	hexa_number[1] = 'x';
	hexa_number[7] = '\0';
	return (hexa_number);
}

void	save_colors_in_str(t_cube *game)
{
	game->colors->f_hex_color = convert_to_hex(game->colors->f_color_num);
	game->colors->c_hex_color = convert_to_hex(game->colors->c_color_num);
}
