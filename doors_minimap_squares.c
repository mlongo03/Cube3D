/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_minimap_squares.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:32:03 by lnicoter          #+#    #+#             */
/*   Updated: 2023/12/07 14:34:53 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	draw_square(int startX, int startY, t_cube *cube, int color)
{
	int	x;
	int	y;
	int	scale;

	scale = cube->mini->scale;
	if (color == 0x00FF0000)
		scale = scale / 2;
	y = -1;
	while (++y < scale)
	{
		x = -1;
		while (++x < scale)
			my_mlx_pixel_put(cube->img, x + startX, y + startY, color);
	}
}

void	draw_squares(t_cube *cube, int x, int y)
{
	if (cube->real_map[y][x] == '1')
		draw_square((x - cube->mini->draw_start_width)
			* cube->mini->scale, (y - cube->mini->draw_start_height)
			* cube->mini->scale, cube, 0xFFFFFFFF);
	else if (cube->real_map[y][x] == '2')
		draw_square((x - cube->mini->draw_start_width)
			* cube->mini->scale, (y - cube->mini->draw_start_height)
			* cube->mini->scale, cube, 0x000000FF);
	else
		draw_square((x - cube->mini->draw_start_width)
			* cube->mini->scale, (y - cube->mini->draw_start_height)
			* cube->mini->scale, cube, 0x00000000);
}

void	render_minimap(t_cube *cube)
{
	int		x;
	int		y;
	double	mini_x;
	double	mini_y;

	cube->mini->x = (int)cube->player->posx;
	cube->mini->y = (int)cube->player->posy;
	init_draw_vars(cube);
	y = cube->mini->draw_start_height;
	while (y <= cube->mini->draw_end_height)
	{
		x = cube->mini->draw_start_width;
		while (x <= cube->mini->draw_end_width)
		{
			draw_squares(cube, x, y);
			x++;
		}
		y++;
	}
	mini_x = cube->player->posx - cube->mini->draw_start_width;
	mini_y = cube->player->posy - cube->mini->draw_start_height;
	draw_square(mini_x * cube->mini->scale, mini_y
		* cube->mini->scale, cube, 0x00FF0000);
}

void	update_door(int x, int y, t_cube *cube)
{
	if (cube->map_door_timer[y][x] >= 1
			&& cube->map_door_status[y][x] == Closing)
		cube->map_door_status[y][x] = Closed;
	else if (cube->map_door_timer[y][x] <= 0
			&& cube->map_door_status[y][x] == Opening)
		cube->map_door_status[y][x] = Open;
	else if (cube->map_door_status[y][x] == Opening)
		cube->map_door_timer[y][x] -= 0.01;
	else if (cube->map_door_status[y][x] == Closing)
		cube->map_door_timer[y][x] += 0.01;
}

void	update_doors(t_cube *cube)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	while (y < cube->map_max_height)
	{
		x = 0;
		while (x < cube->map_max_width)
		{
			if (cube->real_map[y][x] == '2')
				update_door(x, y, cube);
			x++;
		}
		y++;
	}
}
