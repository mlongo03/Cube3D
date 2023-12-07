/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:53:51 by mlongo            #+#    #+#             */
/*   Updated: 2023/12/07 17:04:05 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	init_step_direction(t_render_data *data, t_cube *cube)
{
	if (data->ray_dir_x < 0)
	{
		data->step_x = -1;
		data->side_dist_x = (cube->player->posx - (int)data->map_x)
			* data->delta_dist_x;
	}
	else
	{
		data->step_x = 1;
		data->side_dist_x = ((int)data->map_x + 1.0 - cube->player->posx)
			* data->delta_dist_x;
	}
	if (data->ray_dir_y < 0)
	{
		data->step_y = -1;
		data->side_dist_y = (cube->player->posy - (int)data->map_y)
			* data->delta_dist_y;
	}
	else
	{
		data->step_y = 1;
		data->side_dist_y = ((int)data->map_y + 1.0 - cube->player->posy)
			* data->delta_dist_y;
	}
}

void	init_render_data(t_render_data *data, t_cube *cube, int x)
{
	data->camera_x = 2 * x / (double)SCREENWIDTH - 1;
	data->ray_dir_x = cube->player->dirx + cube->player->planex
		* data->camera_x;
	data->ray_dir_y = cube->player->diry + cube->player->planey
		* data->camera_x;
	data->map_x = (int)cube->player->posx;
	data->map_y = (int)cube->player->posy;
	if (data->ray_dir_x == 0)
		data->delta_dist_x = 1e30;
	else
		data->delta_dist_x = fabs(1.0f / data->ray_dir_x);
	if (data->ray_dir_y == 0)
		data->delta_dist_y = 1e30;
	else
		data->delta_dist_y = fabs(1.0f / data->ray_dir_y);
	data->hit = 0;
	init_step_direction(data, cube);
}

void	perform_dda(t_render_data *data, t_cube *cube)
{
	while (data->hit == 0)
	{
		if (data->side_dist_x < data->side_dist_y)
		{
			data->side_dist_x += data->delta_dist_x;
			data->map_x += data->step_x;
			data->side = 0;
		}
		else
		{
			data->side_dist_y += data->delta_dist_y;
			data->map_y += data->step_y;
			data->side = 1;
		}
		if (cube->real_map[(int)data->map_y][(int)data->map_x] == '1')
			data->hit = 1;
	}
}
