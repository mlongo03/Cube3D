/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuele <manuele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:06:47 by mlongo            #+#    #+#             */
/*   Updated: 2023/12/10 15:37:22 by manuele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	init_direction(t_cube *cube)
{
	if (cube->player->direction == 'W')
	{
		cube->player->dirx = -1;
		cube->player->planey = 0.66;
	}
	if (cube->player->direction == 'E')
	{
		cube->player->dirx = 1;
		cube->player->planey = -0.66;
	}
	if (cube->player->direction == 'N')
	{
		cube->player->diry = -1;
		cube->player->planex = -0.66;
	}
	if (cube->player->direction == 'S')
	{
		cube->player->diry = 1;
		cube->player->planex = 0.66;
	}
}

u_int64_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (u_int64_t)1000) + (tv.tv_usec / 1000));
}

int	main(int argc, char **argv)
{
	t_cube	*game;

	if (argc != 2)
	{
		ft_printf("Too few/many arguments\n");
		exit(1);
	}
	game = ft_calloc(1, sizeof(t_cube));
	struct_init(game);
	is_cub(argv, game);
	read_and_build(game, argv);
	game->mlx = mlx_init();
	load_imgs(game);
	load_textures(game);
	mlx_hooks(game);
	init_direction(game);
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_loop(game->mlx);
}
