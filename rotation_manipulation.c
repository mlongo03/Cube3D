/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_manipulation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:10:23 by lnicoter          #+#    #+#             */
/*   Updated: 2023/12/07 14:11:22 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	rotate_left(t_cube *cube, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cube->player->dirx;
	cube->player->dirx = cube->player->dirx * cos(rot_speed)
		- cube->player->diry * sin(rot_speed);
	cube->player->diry = old_dir_x * sin(rot_speed)
		+ cube->player->diry * cos(rot_speed);
	old_plane_x = cube->player->planex;
	cube->player->planex = cube->player->planex * cos(rot_speed)
		- cube->player->planey * sin(rot_speed);
	cube->player->planey = old_plane_x * sin(rot_speed)
		+ cube->player->planey * cos(rot_speed);
}

void	rotate_right(t_cube *cube, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cube->player->dirx;
	cube->player->dirx = cube->player->dirx * cos(-rot_speed)
		- cube->player->diry * sin(-rot_speed);
	cube->player->diry = old_dir_x * sin(-rot_speed)
		+ cube->player->diry * cos(-rot_speed);
	old_plane_x = cube->player->planex;
	cube->player->planex = cube->player->planex * cos(-rot_speed)
		- cube->player->planey * sin(-rot_speed);
	cube->player->planey = old_plane_x * sin(-rot_speed)
		+ cube->player->planey * cos(-rot_speed);
}

void	update_rotation(t_cube *cube)
{
	double	rot_speed;

	rot_speed = cube->frame_time * 3.0;
	if (cube->player->cam_dir == 1)
		rotate_right(cube, rot_speed);
	if (cube->player->cam_dir == -1)
		rotate_left(cube, rot_speed);
}
