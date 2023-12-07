/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_door.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:02:58 by mlongo            #+#    #+#             */
/*   Updated: 2023/12/07 16:23:42 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

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

int	perform_dda_doors(t_render_data *data, t_cube *cube)
{
	while (data->hit == 0)
	{
		if (data->side_dist_x < data->side_dist_y)
		{
			data->map_x += data->step_x;
			data->side = 0;
			if (cube->real_map[(int)data->map_y][(int)data->map_x] == '2')
				detect_vertical_door(data, cube);
			else
				data->side_dist_x += data->delta_dist_x;
		}
		else
		{
			data->map_y += data->step_y;
			data->side = 1;
			if (cube->real_map[(int)data->map_y][(int)data->map_x] == '2')
				detect_horizontal_door(data, cube);
			else
				data->side_dist_y += data->delta_dist_y;
		}
		if (cube->real_map[(int)data->map_y][(int)data->map_x] == '1')
			return (1);
	}
	return (0);
}
