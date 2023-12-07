/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_game_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:48:22 by lnicoter          #+#    #+#             */
/*   Updated: 2023/12/07 16:24:49 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

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
