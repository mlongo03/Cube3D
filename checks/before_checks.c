/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   before_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 01:19:29 by lnicoter          #+#    #+#             */
/*   Updated: 2023/12/11 15:29:25 by mlongo           ###   ########.fr       */
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
		ft_error("The map must be of .cub type", game);
}
