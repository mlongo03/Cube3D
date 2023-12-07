/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:11:23 by mlongo            #+#    #+#             */
/*   Updated: 2023/12/07 17:04:05 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	load_imgs(t_cube *game)
{
	game->mlx_win = mlx_new_window(game->mlx, SCREENWIDTH,
			SCREENHEIGHT, "Cube3D");
	game->img->img = mlx_new_image(game->mlx, SCREENWIDTH, SCREENHEIGHT);
	game->img->addr = mlx_get_data_addr(game->img->img,
			&game->img->bpp, &game->img->line_length,
			&game->img->endian);
	game->mini = ft_calloc(1, sizeof(t_mini));
	game->mini->scale = SCREENWIDTH / 150;
}

void	load_door(t_cube *cube)
{
	cube->door->img = mlx_xpm_file_to_image(cube->mlx,
			"./textures/door.xpm",
			&cube->door->width, &cube->door->height);
	cube->door->addr = mlx_get_data_addr(cube->door->img,
			&cube->door->bpp, &cube->door->line_length,
			&cube->door->endian);
}

static void	load_north_south_text(t_cube *cube)
{
	cube->card->north_wall.img = mlx_xpm_file_to_image(cube->mlx,
			cube->card->north_path,
			&cube->card->north_wall.width, &cube->card->north_wall.height);
	if (!cube->card->north_wall.img)
		ft_error("The image wasn't loaded correctly\n", cube);
	cube->card->north_wall.addr = mlx_get_data_addr(cube->card->north_wall.img,
			&cube->card->north_wall.bpp, &cube->card->north_wall.line_length,
			&cube->card->north_wall.endian);
	cube->card->south_wall.img = mlx_xpm_file_to_image(cube->mlx,
			cube->card->south_path,
			&cube->card->south_wall.width, &cube->card->south_wall.height);
	if (!cube->card->north_wall.img)
		ft_error("The image wasn't loaded correctly\n", cube);
	cube->card->south_wall.addr = mlx_get_data_addr(cube->card->south_wall.img,
			&cube->card->south_wall.bpp, &cube->card->south_wall.line_length,
			&cube->card->south_wall.endian);
}

void	load_textures(t_cube *cube)
{
	load_north_south_text(cube);
	cube->card->east_wall.img = mlx_xpm_file_to_image(cube->mlx,
			cube->card->east_path,
			&cube->card->east_wall.width, &cube->card->east_wall.height);
	if (!cube->card->north_wall.img)
		ft_error("The image wasn't loaded correctly\n", cube);
	cube->card->east_wall.addr = mlx_get_data_addr(cube->card->east_wall.img,
			&cube->card->east_wall.bpp, &cube->card->east_wall.line_length,
			&cube->card->east_wall.endian);
	cube->card->west_wall.img = mlx_xpm_file_to_image(cube->mlx,
			cube->card->west_path,
			&cube->card->west_wall.width, &cube->card->west_wall.height);
	if (!cube->card->north_wall.img)
		ft_error("The image wasn't loaded correctly\n", cube);
	cube->card->west_wall.addr = mlx_get_data_addr(cube->card->west_wall.img,
			&cube->card->west_wall.bpp, &cube->card->west_wall.line_length,
			&cube->card->west_wall.endian);
	load_door(cube);
}
