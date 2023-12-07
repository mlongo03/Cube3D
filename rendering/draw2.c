/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:45:20 by lnicoter          #+#    #+#             */
/*   Updated: 2023/12/07 16:23:14 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	set_wall_x(t_render_data *data, t_cube *cube)
{
	if (data->side == 0)
		data->wall_x = cube->player->posy + data->perp_wall_dist
			* data->ray_dir_y;
	else
		data->wall_x = cube->player->posx + data->perp_wall_dist
			* data->ray_dir_x;
	data->wall_x -= (int)(data->wall_x);
	if (data->hit == 2)
	{
		if (data->wall_x
			> cube->map_door_timer[(int)data->map_y][(int)data->map_x])
			return (1);
		data->wall_x = 1
			- (cube->map_door_timer[(int)data->map_y][(int)data->map_x]
				- data->wall_x);
	}
	return (0);
}

int	wall_pos_ray_pos_on_wall(t_render_data *data, t_cube *cube)
{
	if (data->side == 0)
		data->perp_wall_dist = (data->side_dist_x - data->delta_dist_x);
	else
		data->perp_wall_dist = (data->side_dist_y - data->delta_dist_y);
	data->line_height = (int)(screenHeight / data->perp_wall_dist);
	data->draw_start = -data->line_height / 2 + screenHeight / 2;
	if (data->draw_start < 0)
		data->draw_start = 0;
	data->draw_end = data->line_height / 2 + screenHeight / 2;
	if (data->draw_end >= screenHeight)
		data->draw_end = screenHeight - 1;
	if (set_wall_x(data, cube))
		return (1);
	set_tex_width_height(data, cube);
	data->tex_x = (int)(data->wall_x * (double)data->tex_width);
	if (data->hit != 2 && data->side == 0 && data->ray_dir_x > 0)
		data->tex_x = data->tex_width - data->tex_x - 1;
	if (data->side == 1 && data->ray_dir_y < 0)
		data->tex_x = data->tex_width - data->tex_x - 1;
	return (0);
}
