/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_positions_hook.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:19:56 by lnicoter          #+#    #+#             */
/*   Updated: 2023/12/07 14:20:03 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

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

void	load_imgs(t_cube *game)
{
	game->mlx_win = mlx_new_window(game->mlx, screenWidth,
			screenHeight, "Cube3D");
	game->img->img = mlx_new_image(game->mlx, screenWidth, screenHeight);
	game->img->addr = mlx_get_data_addr(game->img->img,
			&game->img->bpp, &game->img->line_length,
			&game->img->endian);
	game->mini = ft_calloc(1, sizeof(t_mini));
	game->mini->scale = screenWidth / 150;
}
