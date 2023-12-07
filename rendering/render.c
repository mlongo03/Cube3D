/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:16:07 by lnicoter          #+#    #+#             */
/*   Updated: 2023/12/07 17:04:05 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	calculate_fps(t_cube *cube)
{
	char	*number;

	cube->old_time = cube->time;
	cube->time = get_time();
	cube->frame_time = (cube->time - cube->old_time) / 1000.0;
	cube->fps = (int)(1.0 / cube->frame_time);
	if (cube->fps > 60)
	{
		ft_sleep(((1.0 / 60) - cube->frame_time) * 1000);
		cube->time = get_time();
		cube->frame_time = (cube->time - cube->old_time) / 1000.0;
		cube->fps = (int)(1.0 / cube->frame_time);
	}
	number = ft_itoa(cube->fps);
	mlx_string_put(cube->mlx, cube->mlx_win,
		SCREENWIDTH - 50, 20, -1, number);
	free(number);
}

void	render_map(t_cube *cube)
{
	t_render_data	data;
	int				x;

	x = 0;
	while (x < SCREENWIDTH)
	{
		init_render_data(&data, cube, x);
		perform_dda(&data, cube);
		draw_vertical_line(&data, cube, x);
		x++;
	}
	render_doors(cube);
	render_minimap(cube);
}

int	game_loop(t_cube *cube)
{
	render_map(cube);
	mlx_put_image_to_window(cube->mlx, cube->mlx_win, cube->img->img, 0, 0);
	calculate_fps(cube);
	update_movement(cube);
	update_rotation(cube);
	return (0);
}
