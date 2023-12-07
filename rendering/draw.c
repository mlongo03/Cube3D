/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:56:48 by mlongo            #+#    #+#             */
/*   Updated: 2023/12/07 16:57:46 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
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

void	draw_tex_wall(t_render_data *data, t_cube *cube, int x)
{
	int	y;

	data->step = 1.0 * data->tex_height / data->line_height;
	data->tex_pos = (data->draw_start - SCREENHEIGHT / 2
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
	while (i < SCREENHEIGHT)
		my_mlx_pixel_put(cube->img, x, i++, cube->colors->c_color_num);
}
