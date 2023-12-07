/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doorsmap_render_destroy_all.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:23:37 by lnicoter          #+#    #+#             */
/*   Updated: 2023/12/07 14:23:44 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	render_doors(t_cube *cube)
{
	t_render_data	data;
	int				x;

	x = 0;
	update_doors(cube);
	while (x < screenWidth)
	{
		init_render_data(&data, cube, x);
		if (perform_dda_doors(&data, cube))
		{
			x++;
			continue ;
		}
		draw_vertical_line(&data, cube, x);
		x++;
	}
}

void	render_map(t_cube *cube)
{
	t_render_data	data;
	int				x;

	x = 0;
	while (x < screenWidth)
	{
		init_render_data(&data, cube, x);
		perform_dda(&data, cube);
		draw_vertical_line(&data, cube, x);
		x++;
	}
	render_doors(cube);
	render_minimap(cube);
}

void	destroy_all(t_cube *cube)
{
	mlx_destroy_window(cube->mlx, cube->mlx_win);
	mlx_destroy_image(cube->mlx, cube->img->img);
	mlx_destroy_image(cube->mlx, cube->card->east_wall.img);
	mlx_destroy_image(cube->mlx, cube->card->west_wall.img);
	mlx_destroy_image(cube->mlx, cube->card->north_wall.img);
	mlx_destroy_image(cube->mlx, cube->card->south_wall.img);
	mlx_destroy_image(cube->mlx, cube->door->img);
}

int	close_window(t_cube *cube)
{
	destroy_all(cube);
	free(cube->card->north_path);
	free(cube->card->south_path);
	free(cube->card->east_path);
	free(cube->card->west_path);
	free(cube->colors->f_hex_color);
	free(cube->colors->c_hex_color);
	free_matrix(cube->colors->ceiling_colors);
	free_matrix(cube->colors->floor_colors);
	free(cube->card);
	free(cube->player);
	free(cube->img);
	free(cube->colors);
	free(cube->mini);
	free(cube->door);
	free(cube->mlx);
	free(cube->map_len);
	free_matrix(cube->all_map);
	free_matrix(cube->real_map);
	free_matrix_int(cube->map_door_status);
	free_matrix_double(cube->map_door_timer);
	free(cube);
	exit (1);
}

void	set_positions_to_watch(t_cube *cube, int *pos)
{
	int	i;

	i = 0;
	if (cube->player->dirx > 0)
	{
		pos[i++] = cube->player->posy;
		pos[i++] = cube->player->posx + 1;
	}
	if (cube->player->dirx < 0)
	{
		pos[i++] = cube->player->posy;
		pos[i++] = cube->player->posx - 1;
	}
	if (cube->player->diry > 0)
	{
		pos[i++] = cube->player->posy + 1;
		pos[i++] = cube->player->posx;
	}
	if (cube->player->diry < 0)
	{
		pos[i++] = cube->player->posy - 1;
		pos[i++] = cube->player->posx;
	}
	pos[i] = 0;
}
