/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:45:20 by lnicoter          #+#    #+#             */
/*   Updated: 2023/12/07 14:45:27 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	draw_tex_wall(t_render_data *data, t_cube *cube, int x)
{
	int	y;

	data->step = 1.0 * data->tex_height / data->line_height;
	data->tex_pos = (data->draw_start - screenHeight / 2
			+ data->line_height / 2) * data->step;
	y = data->draw_start;
	while (y < data->draw_end)
	{
		data->tex_y = (int)data->tex_pos % data->tex_height;
		data->tex_pos += data->step;
		set_color(data, cube, 4
			* (int)(data->tex_height * data->tex_y + data->tex_x));
		my_mlx_pixel_put(cube->img, x, y++, data->color);
	}
}

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

void	draw_vertical_line(t_render_data *data, t_cube *cube, int x)
{
	int	i;

	i = 0;
	if (wall_pos_ray_pos_on_wall(data, cube))
		return ;
	while (i < data->draw_start)
		my_mlx_pixel_put(cube->img, x, i++, cube->colors->f_color_num);
	draw_tex_wall(data, cube, x);
	i = data->draw_end;
	while (i < screenHeight)
		my_mlx_pixel_put(cube->img, x, i++, cube->colors->c_color_num);
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
