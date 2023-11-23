/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 23:04:18 by lnicoter          #+#    #+#             */
/*   Updated: 2023/11/23 01:21:56 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	main(int ac, char **av)
{

	t_cube	*game;

	if (ac != 2)
	{
		printf("Too few/many arguments\n");
		exit(1);
	}
	game = ft_calloc(1, sizeof(t_cube));
//	game->mlx = mlx_init();
	struct_init(game);
	is_cub(av, game);
	read_and_build(game, av);
	free_struct(game);
	//mlx_loop(game->mlx);
}