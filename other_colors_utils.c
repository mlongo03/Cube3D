/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_colors_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:43:06 by lnicoter          #+#    #+#             */
/*   Updated: 2023/11/17 11:42:30 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static char	*convert_to_hex(int decimal)
{
	int	i;
	int	temp;
	char	*hexa_Number;

	i = 7;
	hexa_Number = malloc(8 * sizeof(char) + 1);
	while (decimal != 0)
	{
		temp = decimal % 16;
		if (temp < 10)
			temp = temp + 48;
		else
			temp = temp + 55;
		hexa_Number[i--] = temp;
		decimal = decimal / 16;
	}
	hexa_Number[0] = '0';
	hexa_Number[1] = 'x';
	hexa_Number[7] = '\0';
	return (hexa_Number);
}

void	save_colors_in_str(t_cube *game)
{
	game->f_hex_color = convert_to_hex(game->f_color_num);
	game->c_hex_color = convert_to_hex(game->c_color_num);
}
