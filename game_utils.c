/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:16:07 by lnicoter          #+#    #+#             */
/*   Updated: 2023/12/07 14:16:52 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

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

void	ft_sleep(u_int64_t time)
{
	u_int64_t	start;

	start = 0;
	start = get_time();
	while ((get_time() - start) < time)
		usleep(time / 10);
}

void	calculate_fps(t_cube *cube)
{
	char	*number;

	cube->old_time = cube->time;
	cube->time = get_time();
	cube->frame_time = (cube->time - cube->old_time) / 1000.0;
	cube->fps = (int)(1.0 / cube->frame_time);
	if (cube->fps > 60)
	{
		ft_sleep(((1.0 / 60) - cube->frame_time) * 1000);
		cube->time = get_time();
		cube->frame_time = (cube->time - cube->old_time) / 1000.0;
		cube->fps = (int)(1.0 / cube->frame_time);
	}
	number = ft_itoa(cube->fps);
	mlx_string_put(cube->mlx, cube->mlx_win,
		screenWidth - 50, 20, -1, number);
	free(number);
}

int	game_loop(t_cube *cube)
{
	render_map(cube);
	mlx_put_image_to_window(cube->mlx, cube->mlx_win, cube->img->img, 0, 0);
	calculate_fps(cube);
	update_movement(cube);
	update_rotation(cube);
	return (0);
}
