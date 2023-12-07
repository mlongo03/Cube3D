/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:01:17 by mlongo            #+#    #+#             */
/*   Updated: 2023/12/07 16:50:10 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	set_positions_to_watch(t_cube *cube, int *pos)
{
	int	i;

	i = 0;
	if (cube->player->dirx > 0)
	{
		pos[i++] = cube->player->posy;
		pos[i++] = cube->player->posx + 1;
	}
	if (cube->player->dirx < 0)
	{
		pos[i++] = cube->player->posy;
		pos[i++] = cube->player->posx - 1;
	}
	if (cube->player->diry > 0)
	{
		pos[i++] = cube->player->posy + 1;
		pos[i++] = cube->player->posx;
	}
	if (cube->player->diry < 0)
	{
		pos[i++] = cube->player->posy - 1;
		pos[i++] = cube->player->posx;
	}
	pos[i] = 0;
}

void	handle_door(t_cube *cube)
{
	int	*pos;
	int	i;

	i = 0;
	pos = (int *)malloc(sizeof(int) * 7);
	set_positions_to_watch(cube, pos);
	while (pos[i] && pos[i + 1])
	{
		if (cube->real_map[pos[i]][pos[i + 1]] == '2')
		{
			if (cube->map_door_status[pos[i]][pos[i + 1]] == Closed
				|| cube->map_door_status[pos[i]][pos[i + 1]] == Closing)
				cube->map_door_status[pos[i]][pos[i + 1]] = Opening;
			else if (cube->map_door_status[pos[i]][pos[i + 1]] == Open
				|| cube->map_door_status[pos[i]][pos[i + 1]] == Opening)
				cube->map_door_status[pos[i]][pos[i + 1]] = Closing;
		}
		i += 2;
	}
	free(pos);
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

void	render_doors(t_cube *cube)
{
	t_render_data	data;
	int				x;

	x = 0;
	update_doors(cube);
	while (x < screenWidth)
	{
		init_render_data(&data, cube, x);
		if (perform_dda_doors(&data, cube))
		{
			x++;
			continue ;
		}
		draw_vertical_line(&data, cube, x);
		x++;
	}
}
