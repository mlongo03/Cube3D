/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:13:58 by lnicoter          #+#    #+#             */
/*   Updated: 2023/12/07 14:14:06 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	move_forward(t_cube *cube, double moveSpeed)
{
	if (cube->real_map[(int)cube->player->posy]
		[(int)(cube->player->posx + cube->player->dirx * moveSpeed)] == '0'
		|| cube->map_door_status [(int)cube->player->posy]
		[(int)(cube->player->posx + cube->player->dirx
		* moveSpeed)] == Open)
		cube->player->posx += cube->player->dirx * moveSpeed;
	if (cube->real_map[(int)(cube->player->posy + cube->player->diry
			* moveSpeed)]
		[(int)(cube->player->posx)] == '0'
		|| cube->map_door_status[(int)(cube->player->posy
		+ cube->player->diry
		* moveSpeed)]
		[(int)(cube->player->posx)] == Open)
		cube->player->posy += cube->player->diry
			* moveSpeed;
}

void	move_backward(t_cube *cube, double moveSpeed)
{
	if (cube->real_map[(int)cube->player->posy]
		[(int)(cube->player->posx - cube->player->dirx * moveSpeed)] == '0'
		|| cube->map_door_status[(int)cube->player->posy]
		[(int)(cube->player->posx - cube->player->dirx
			* moveSpeed)] == Open)
		cube->player->posx -= cube->player->dirx * moveSpeed;
	if (cube->real_map[(int)(cube->player->posy - cube->player->diry
			* moveSpeed)]
		[(int)cube->player->posx] == '0'
		|| cube->map_door_status[(int)(cube->player->posy -
		cube->player->diry * moveSpeed)]
		[(int)cube->player->posx] == Open)
		cube->player->posy -= cube->player->diry * moveSpeed;
}

void	move_left(t_cube *cube, double moveSpeed)
{
	if (cube->real_map[(int)cube->player->posy]
		[(int)(cube->player->posx - cube->player->diry * moveSpeed)] == '0'
		|| cube->map_door_status[(int)cube->player->posy]
		[(int)(cube->player->posx - cube->player->diry
		* moveSpeed)] == Open)
		cube->player->posx -= cube->player->diry * moveSpeed;
	if (cube->real_map[(int)(cube->player->posy
			+ cube->player->dirx * moveSpeed)]
		[(int)(cube->player->posx)] == '0' || cube->map_door_status
		[(int)(cube->player->posy + cube->player->dirx * moveSpeed)]
		[(int)(cube->player->posx)] == Open)
		cube->player->posy += (cube->player->dirx) * moveSpeed;
}

void	move_right(t_cube *cube, double moveSpeed)
{
	if (cube->real_map[(int)cube->player->posy]
		[(int)(cube->player->posx + cube->player->diry * moveSpeed)] == '0'
		|| cube->map_door_status[(int)cube->player->posy]
		[(int)(cube->player->posx + cube->player->diry
		* moveSpeed)] == Open)
		cube->player->posx += cube->player->diry * moveSpeed;
	if (cube->real_map[(int)(cube->player->posy
			- cube->player->dirx * moveSpeed)][(int)cube->player->posx] == '0'
		|| cube->map_door_status[(int)(cube->player->posy
		- cube->player->dirx * moveSpeed)][(int)cube->player->posx] == Open)
		cube->player->posy -= (cube->player->dirx) * moveSpeed;
}

void	update_movement(t_cube *cube)
{
	double	move_speed;

	move_speed = cube->frame_time * 5.0;
	if (cube->player->mov_dirY == 1)
		move_forward(cube, move_speed);
	if (cube->player->mov_dirY == -1)
		move_backward(cube, move_speed);
	if (cube->player->mov_dirx == -1)
		move_left(cube, move_speed);
	if (cube->player->mov_dirx == 1)
		move_right(cube, move_speed);
}
