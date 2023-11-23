/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   before_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 01:19:29 by lnicoter          #+#    #+#             */
/*   Updated: 2023/11/23 01:25:14 by lnicoter         ###   ########.fr       */
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
