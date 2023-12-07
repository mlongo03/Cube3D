/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:48:22 by lnicoter          #+#    #+#             */
/*   Updated: 2023/12/07 14:48:31 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

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

void	set_color(t_render_data *data, t_cube *cube, int shift)
{
	if (data->hit == 2)
	{
		data->color = *(unsigned int *)(cube->door->addr + shift);
	}
	else if (data->side == 1)
	{
		if (data->ray_dir_y > 0)
			data->color = *(unsigned int *)(cube->card->north_wall.addr
					+ shift);
		else
			data->color = *(unsigned int *)(cube->card->south_wall.addr
					+ shift);
	}
	else
	{
		if (data->ray_dir_x > 0)
			data->color = *(unsigned int *)(cube->card->east_wall.addr
					+ shift);
		else
			data->color = *(unsigned int *)(cube->card->west_wall.addr
					+ shift);
	}
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	door_tex_init(t_render_data *data, t_cube *cube)
{
	data->tex_width = cube->door->width;
	data->tex_height = cube->door->height;
}

void	set_tex_width_height(t_render_data *data, t_cube *cube)
{
	if (data->hit == 2)
		door_tex_init(data, cube);
	else if (data->side == 1)
	{
		if (data->ray_dir_y > 0)
		{
			data->tex_width = cube->card->north_wall.width;
			data->tex_height = cube->card->north_wall.height;
			return ;
		}
		data->tex_width = cube->card->south_wall.width;
		data->tex_height = cube->card->south_wall.height;
	}
	else
	{
		if (data->ray_dir_x > 0)
		{
			data->tex_width = cube->card->east_wall.width;
			data->tex_height = cube->card->east_wall.height;
			return ;
		}
		data->tex_width = cube->card->west_wall.width;
		data->tex_height = cube->card->west_wall.height;
	}
}
