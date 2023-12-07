/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:51:01 by mlongo            #+#    #+#             */
/*   Updated: 2023/12/07 16:21:14 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	rotate_camera(float angle, t_cube *cube)
{
	double	new_dir_x;
	double	new_dir_y;
	double	new_plane_x;
	double	new_plane_y;

	angle = angle * M_PI / 180.0f;
	new_dir_x = cube->player->dirx * cos(angle)
		- cube->player->diry * sin(angle);
	new_dir_y = cube->player->dirx * sin(angle)
		+ cube->player->diry * cos(angle);
	new_plane_x = cube->player->planex * cos(angle)
		- cube->player->planey * sin(angle);
	new_plane_y = cube->player->planex * sin(angle)
		+ cube->player->planey * cos(angle);
	cube->player->dirx = new_dir_x;
	cube->player->diry = new_dir_y;
	cube->player->planex = new_plane_x;
	cube->player->planey = new_plane_y;
}

int	key_hook_press(int key, t_cube *cube)
{
	if (key == 0 || key == 'a')
		cube->player->mov_dirx = -1;
	else if (key == 1 || key == 's')
		cube->player->mov_dirY = -1;
	else if (key == 2 || key == 'd')
		cube->player->mov_dirx = 1;
	else if (key == 13 || key == 'w')
		cube->player->mov_dirY = 1;
	else if (key == 65361)
		cube->player->cam_dir = -1;
	else if (key == 65363)
		cube->player->cam_dir = 1;
	else if (key == 32)
		handle_door(cube);
	else if (key == 65307)
		close_window(cube);
	return (0);
}

int	key_hook_release(int key, t_cube *cube)
{
	if (key == 'w' || key == 's')
		cube->player->mov_dirY = 0;
	else if (key == 'a' || key == 'd')
		cube->player->mov_dirx = 0;
	else if (key == 65363 || key == 65361)
		cube->player->cam_dir = 0;
	return (0);
}

int	handle_mouse(int x, int y, void	*cube)
{
	double	normalized_x;
	double	max_rotation_angle;
	double	rotation_angle;
	double	new_rotation_angle;

	(void)y;
	mlx_mouse_hide(((t_cube *)cube)->mlx, ((t_cube *)cube)->mlx_win);
	normalized_x = (2.0f * x) / screenWidth - 1.0f;
	max_rotation_angle = 180.0f;
	rotation_angle = max_rotation_angle * normalized_x;
	new_rotation_angle = rotation_angle;
	if (((t_cube *)cube)->player->rot_angle != 360)
		new_rotation_angle = ((t_cube *)cube)->player->rot_angle
			- rotation_angle;
	((t_cube *)cube)->player->rot_angle = rotation_angle;
	rotate_camera(new_rotation_angle, (t_cube *)cube);
	return (0);
}

void	mlx_hooks(t_cube *cube)
{
	mlx_hook(cube->mlx_win, 17, 0, close_window, cube);
	mlx_hook(cube->mlx_win, 2, 1L << 0, key_hook_press, (void *)cube);
	mlx_hook(cube->mlx_win, 3, 1L << 1, key_hook_release, (void *)cube);
	mlx_hook(cube->mlx_win, 6, 1L << 6, handle_mouse, (void *)cube);
}
