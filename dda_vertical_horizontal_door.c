/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_vertical_horizontal_door.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:50:41 by lnicoter          #+#    #+#             */
/*   Updated: 2023/12/07 14:50:48 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

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
	data->camera_x = 2 * x / (double)screenWidth - 1;
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

void	detect_vertical_door(t_render_data *data, t_cube *cube)
{
	if (cube->real_map[(int)data->map_y + 1]
		[(int)data->map_x] == '1'
		&& cube->real_map[(int)data->map_y - 1]
		[(int)data->map_x] == '1')
	{
		data->side_dist_x += data->delta_dist_x
			+ (data->delta_dist_x / 2);
		data->perp_wall_dist = (data->side_dist_x
				- data->delta_dist_x);
		data->wall_x = cube->player->posy + data->perp_wall_dist
			* data->ray_dir_y;
		data->wall_x = data->wall_x - (int)(data->map_y);
		if (data->wall_x >= 0 && data->wall_x <= 1)
		{
			if (data->wall_x
				<= cube->map_door_timer[(int)data->map_y]
				[(int)data->map_x])
				data->hit = 2;
			else
				data->side_dist_x -= (data->delta_dist_x / 2);
		}
		else
			data->side_dist_x -= (data->delta_dist_x / 2);
	}
}

void	detect_horizontal_door(t_render_data *data, t_cube *cube)
{
	if (cube->real_map[(int)data->map_y]
		[(int)data->map_x + 1] == '1'
		&& cube->real_map[(int)data->map_y]
		[(int)data->map_x - 1] == '1')
	{
		data->side_dist_y += data->delta_dist_y
			+ (data->delta_dist_y / 2);
		data->perp_wall_dist = (data->side_dist_y
				- data->delta_dist_y);
		data->wall_x = cube->player->posx + data->perp_wall_dist
			* data->ray_dir_x;
		data->wall_x = data->wall_x - (int)(data->map_x);
		if (data->wall_x >= 0 && data->wall_x <= 1)
		{
			if (data->wall_x
				<= cube->map_door_timer[(int)data->map_y]
				[(int)data->map_x])
				data->hit = 2;
			else
				data->side_dist_y -= (data->delta_dist_y / 2);
		}
		else
			data->side_dist_y -= (data->delta_dist_y / 2);
	}
}
