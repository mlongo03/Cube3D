/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:04:26 by mlongo            #+#    #+#             */
/*   Updated: 2023/12/07 16:22:11 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

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

void	init_draw_vars(t_cube *cube)
{
	t_mini_draw_vars	mp;

	init_mp(&mp, cube);
	calculate_start_end_mini(&mp, cube);
	adjust_start_end(&mp, cube);
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
