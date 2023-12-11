/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:39:19 by mlongo            #+#    #+#             */
/*   Updated: 2023/12/11 12:49:22 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	init_pos(t_cube *cube, int y, int x, int type_door)
{
	cube->map_door_start_t[y][x].start_t = get_time();
	cube->map_door_start_t[y][x].start_v
		= cube->map_door_timer[y][x];
	cube->map_door_status[y][x] = type_door;
}

void	inc_dec_door(t_cube *cube, int y, int x)
{
	double	elapsed_time;

	elapsed_time = cube->time - cube->map_door_start_t[y][x].start_t;
	if (cube->map_door_status[y][x] == OPENING)
		cube->map_door_timer[y][x] = (cube->map_door_start_t[y][x].start_v
				- elapsed_time / 1000);
	else if (cube->map_door_status[y][x] == CLOSING)
		cube->map_door_timer[y][x] = (cube->map_door_start_t[y][x].start_v
				+ elapsed_time / 1000);
}
