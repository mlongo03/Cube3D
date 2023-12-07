/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:06:47 by mlongo            #+#    #+#             */
/*   Updated: 2023/12/07 13:11:39 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

u_int64_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (u_int64_t)1000) + (tv.tv_usec / 1000));
}

void	init_step_direction(t_render_data *data, t_cube *cube)
{
	if (data->ray_dir_x < 0)
	{
		data->step_x = -1;
		data->side_dist_x = (cube->player->posx - (int)data->map_x)
			* data->delta_dist_x;
	}
	else
	{
		data->step_x = 1;
		data->side_dist_x = ((int)data->map_x + 1.0 - cube->player->posx)
			* data->delta_dist_x;
	}
	if (data->ray_dir_y < 0)
	{
		data->step_y = -1;
		data->side_dist_y = (cube->player->posy - (int)data->map_y)
			* data->delta_dist_y;
	}
	else
	{
		data->step_y = 1;
		data->side_dist_y = ((int)data->map_y + 1.0 - cube->player->posy)
			* data->delta_dist_y;
	}
}

void	init_render_data(t_render_data *data, t_cube *cube, int x)
{
	data->camera_x = 2 * x / (double)screenWidth - 1;
	data->ray_dir_x = cube->player->dirx + cube->player->planex
		* data->camera_x;
	data->ray_dir_y = cube->player->diry + cube->player->planey
		* data->camera_x;
	data->map_x = (int)cube->player->posx;
	data->map_y = (int)cube->player->posy;
	if (data->ray_dir_x == 0)
		data->delta_dist_x = 1e30;
	else
		data->delta_dist_x = fabs(1.0f / data->ray_dir_x);
	if (data->ray_dir_y == 0)
		data->delta_dist_y = 1e30;
	else
		data->delta_dist_y = fabs(1.0f / data->ray_dir_y);
	data->hit = 0;
	init_step_direction(data, cube);
}

void	perform_dda(t_render_data *data, t_cube *cube)
{
	while (data->hit == 0)
	{
		if (data->side_dist_x < data->side_dist_y)
		{
			data->side_dist_x += data->delta_dist_x;
			data->map_x += data->step_x;
			data->side = 0;
		}
		else
		{
			data->side_dist_y += data->delta_dist_y;
			data->map_y += data->step_y;
			data->side = 1;
		}
		if (cube->real_map[(int)data->map_y][(int)data->map_x] == '1')
			data->hit = 1;
	}
}

void	detect_vertical_door(t_render_data *data, t_cube *cube)
{
	if (cube->real_map[(int)data->map_y + 1]
		[(int)data->map_x] == '1'
		&& cube->real_map[(int)data->map_y - 1]
		[(int)data->map_x] == '1')
	{
		data->side_dist_x += data->delta_dist_x
			+ (data->delta_dist_x / 2);
		data->perp_wall_dist = (data->side_dist_x
				- data->delta_dist_x);
		data->wall_x = cube->player->posy + data->perp_wall_dist
			* data->ray_dir_y;
		data->wall_x = data->wall_x - (int)(data->map_y);
		if (data->wall_x >= 0 && data->wall_x <= 1)
		{
			if (data->wall_x
				<= cube->map_door_timer[(int)data->map_y]
				[(int)data->map_x])
				data->hit = 2;
			else
				data->side_dist_x -= (data->delta_dist_x / 2);
		}
		else
			data->side_dist_x -= (data->delta_dist_x / 2);
	}
}

void	detect_horizontal_door(t_render_data *data, t_cube *cube)
{
	if (cube->real_map[(int)data->map_y]
		[(int)data->map_x + 1] == '1'
		&& cube->real_map[(int)data->map_y]
		[(int)data->map_x - 1] == '1')
	{
		data->side_dist_y += data->delta_dist_y
			+ (data->delta_dist_y / 2);
		data->perp_wall_dist = (data->side_dist_y
				- data->delta_dist_y);
		data->wall_x = cube->player->posx + data->perp_wall_dist
			* data->ray_dir_x;
		data->wall_x = data->wall_x - (int)(data->map_x);
		if (data->wall_x >= 0 && data->wall_x <= 1)
		{
			if (data->wall_x
				<= cube->map_door_timer[(int)data->map_y]
				[(int)data->map_x])
				data->hit = 2;
			else
				data->side_dist_y -= (data->delta_dist_y / 2);
		}
		else
			data->side_dist_y -= (data->delta_dist_y / 2);
	}
}

int	perform_dda_doors(t_render_data *data, t_cube *cube)
{
	while (data->hit == 0)
	{
		if (data->side_dist_x < data->side_dist_y)
		{
			data->map_x += data->step_x;
			data->side = 0;
			if (cube->real_map[(int)data->map_y][(int)data->map_x] == '2')
				detect_vertical_door(data, cube);
			else
				data->side_dist_x += data->delta_dist_x;
		}
		else
		{
			data->map_y += data->step_y;
			data->side = 1;
			if (cube->real_map[(int)data->map_y][(int)data->map_x] == '2')
				detect_horizontal_door(data, cube);
			else
				data->side_dist_y += data->delta_dist_y;
		}
		if (cube->real_map[(int)data->map_y][(int)data->map_x] == '1')
			return (1);
	}
	return (0);
}

void	set_color(t_render_data *data, t_cube *cube, int shift)
{
	if (data->hit == 2)
	{
		data->color = *(unsigned int *)(cube->door->addr + shift);
	}
	else if (data->side == 1)
	{
		if (data->ray_dir_y > 0)
			data->color = *(unsigned int *)(cube->card->north_wall.addr
					+ shift);
		else
			data->color = *(unsigned int *)(cube->card->south_wall.addr
					+ shift);
	}
	else
	{
		if (data->ray_dir_x > 0)
			data->color = *(unsigned int *)(cube->card->east_wall.addr
					+ shift);
		else
			data->color = *(unsigned int *)(cube->card->west_wall.addr
					+ shift);
	}
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

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

void	draw_tex_wall(t_render_data *data, t_cube *cube, int x)
{
	int	y;

	data->step = 1.0 * data->tex_height / data->line_height;
	data->tex_pos = (data->draw_start - screenHeight / 2
			+ data->line_height / 2) * data->step;
	y = data->draw_start;
	while (y < data->draw_end)
	{
		data->tex_y = (int)data->tex_pos % data->tex_height;
		data->tex_pos += data->step;
		set_color(data, cube, 4
			* (int)(data->tex_height * data->tex_y + data->tex_x));
		my_mlx_pixel_put(cube->img, x, y++, data->color);
	}
}

int	set_wall_x(t_render_data *data, t_cube *cube)
{
	if (data->side == 0)
		data->wall_x = cube->player->posy + data->perp_wall_dist
			* data->ray_dir_y;
	else
		data->wall_x = cube->player->posx + data->perp_wall_dist
			* data->ray_dir_x;
	data->wall_x -= (int)(data->wall_x);
	if (data->hit == 2)
	{
		if (data->wall_x
			> cube->map_door_timer[(int)data->map_y][(int)data->map_x])
			return (1);
		data->wall_x = 1
			- (cube->map_door_timer[(int)data->map_y][(int)data->map_x]
				- data->wall_x);
	}
	return (0);
}

int	wall_pos_ray_pos_on_wall(t_render_data *data, t_cube *cube)
{
	if (data->side == 0)
		data->perp_wall_dist = (data->side_dist_x - data->delta_dist_x);
	else
		data->perp_wall_dist = (data->side_dist_y - data->delta_dist_y);
	data->line_height = (int)(screenHeight / data->perp_wall_dist);
	data->draw_start = -data->line_height / 2 + screenHeight / 2;
	if (data->draw_start < 0)
		data->draw_start = 0;
	data->draw_end = data->line_height / 2 + screenHeight / 2;
	if (data->draw_end >= screenHeight)
		data->draw_end = screenHeight - 1;
	if (set_wall_x(data, cube))
		return (1);
	set_tex_width_height(data, cube);
	data->tex_x = (int)(data->wall_x * (double)data->tex_width);
	if (data->hit != 2 && data->side == 0 && data->ray_dir_x > 0)
		data->tex_x = data->tex_width - data->tex_x - 1;
	if (data->side == 1 && data->ray_dir_y < 0)
		data->tex_x = data->tex_width - data->tex_x - 1;
	return (0);
}

void	draw_vertical_line(t_render_data *data, t_cube *cube, int x)
{
	int	i;

	i = 0;
	if (wall_pos_ray_pos_on_wall(data, cube))
		return ;
	while (i < data->draw_start)
		my_mlx_pixel_put(cube->img, x, i++, cube->colors->f_color_num);
	draw_tex_wall(data, cube, x);
	i = data->draw_end;
	while (i < screenHeight)
		my_mlx_pixel_put(cube->img, x, i++, cube->colors->c_color_num);
}

void	load_door(t_cube *cube)
{
	cube->door->img = mlx_xpm_file_to_image(cube->mlx,
			"./textures/door.xpm",
			&cube->door->width, &cube->door->height);
	cube->door->addr = mlx_get_data_addr(cube->door->img,
			&cube->door->bpp, &cube->door->line_length,
			&cube->door->endian);
}

void	load_textures(t_cube *cube)
{
	cube->card->north_wall.img = mlx_xpm_file_to_image(cube->mlx,
			cube->card->north_path,
			&cube->card->north_wall.width, &cube->card->north_wall.height);
	cube->card->north_wall.addr = mlx_get_data_addr(cube->card->north_wall.img,
			&cube->card->north_wall.bpp, &cube->card->north_wall.line_length,
			&cube->card->north_wall.endian);
	cube->card->south_wall.img = mlx_xpm_file_to_image(cube->mlx,
			cube->card->south_path,
			&cube->card->south_wall.width, &cube->card->south_wall.height);
	cube->card->south_wall.addr = mlx_get_data_addr(cube->card->south_wall.img,
			&cube->card->south_wall.bpp, &cube->card->south_wall.line_length,
			&cube->card->south_wall.endian);
	cube->card->east_wall.img = mlx_xpm_file_to_image(cube->mlx,
			cube->card->east_path,
			&cube->card->east_wall.width, &cube->card->east_wall.height);
	cube->card->east_wall.addr = mlx_get_data_addr(cube->card->east_wall.img,
			&cube->card->east_wall.bpp, &cube->card->east_wall.line_length,
			&cube->card->east_wall.endian);
	cube->card->west_wall.img = mlx_xpm_file_to_image(cube->mlx,
			cube->card->west_path,
			&cube->card->west_wall.width, &cube->card->west_wall.height);
	cube->card->west_wall.addr = mlx_get_data_addr(cube->card->west_wall.img,
			&cube->card->west_wall.bpp, &cube->card->west_wall.line_length,
			&cube->card->west_wall.endian);
	load_door(cube);
}

void	init_mp(t_mini_draw_vars *mp, t_cube *cube)
{
	mp->fix_y = 0;
	mp->fix_x = 0;
	mp->offset = 0;
	mp->dist_width = 15;
	mp->dist_height = 8;
	mp->is_width_even = 0;
	mp->is_height_even = 1;
	if (cube->map_max_width < 30)
	{
		if (cube->map_max_width % 2 != 0)
			mp->is_width_even++;
		mp->dist_width = cube->map_max_width / 2;
	}
	if (cube->map_max_height < 17)
	{
		if (cube->map_max_height % 2 == 0)
			mp->is_height_even--;
		mp->dist_height = cube->map_max_height / 2;
	}
}

void	calculate_start_end_mini(t_mini_draw_vars *mp, t_cube *cube)
{
	while ((cube->mini->y + mp->offset) < (cube->map_max_height - 1)
		&& mp->offset < mp->dist_height)
		mp->offset++;
	cube->mini->draw_end_height = cube->mini->y + mp->offset;
	mp->offset = 0;
	while ((cube->mini->y - mp->offset) > 0 && mp->offset < mp->dist_height)
		mp->offset++;
	cube->mini->draw_start_height = cube->mini->y - mp->offset;
	mp->offset = 0;
	while ((cube->mini->x + mp->offset) < (cube->map_max_width - 1)
		&& mp->offset < mp->dist_width)
		mp->offset++;
	cube->mini->draw_end_width = cube->mini->x + mp->offset;
	mp->offset = 0;
	while (cube->mini->x - mp->offset > 0 && mp->offset < mp->dist_width)
		mp->offset++;
	cube->mini->draw_start_width = cube->mini->x - mp->offset;
}

void	player_close_to_no_limit(t_mini_draw_vars *mp, t_cube *cube)
{
	mp->fix_y++;
	cube->mini->draw_start_height -= (mp->dist_height
			- (cube->mini->draw_end_height - cube->mini->y));
	if (!mp->is_height_even)
		cube->mini->draw_start_height++;
}

void	player_close_to_so_limit(t_mini_draw_vars *mp, t_cube *cube)
{
	mp->fix_y++;
	cube->mini->draw_end_height += (mp->dist_height
			- (cube->mini->y - cube->mini->draw_start_height));
	if (!mp->is_height_even)
		cube->mini->draw_end_height--;
}

void	player_close_to_ea_limit(t_mini_draw_vars *mp, t_cube *cube)
{
	mp->fix_x++;
	cube->mini->draw_start_width -= (mp->dist_width
			- (cube->mini->draw_end_width - cube->mini->x));
	if (!mp->is_width_even)
		cube->mini->draw_start_width++;
}

void	player_close_to_we_limit(t_mini_draw_vars *mp, t_cube *cube)
{
	mp->fix_x++;
	cube->mini->draw_end_width += (mp->dist_width
			- (cube->mini->x - cube->mini->draw_start_width));
	if (!mp->is_width_even)
		cube->mini->draw_end_width--;
}

void	adjust_start_end(t_mini_draw_vars *mp, t_cube *cube)
{
	if (!mp->fix_y && cube->mini->draw_end_height
		- cube->mini->y < mp->dist_height)
	{
		player_close_to_no_limit(mp, cube);
	}
	if (!mp->fix_y && cube->mini->y
		- cube->mini->draw_start_height < mp->dist_height)
	{
		player_close_to_so_limit(mp, cube);
	}
	if (!mp->fix_x && cube->mini->draw_end_width
		- cube->mini->x < mp->dist_width)
	{
		player_close_to_ea_limit(mp, cube);
	}
	if (!mp->fix_x && cube->mini->x
		- cube->mini->draw_start_width < mp->dist_width)
	{
		player_close_to_we_limit(mp, cube);
	}
}

void	init_draw_vars(t_cube *cube)
{
	t_mini_draw_vars	mp;

	init_mp(&mp, cube);
	calculate_start_end_mini(&mp, cube);
	adjust_start_end(&mp, cube);
}

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

void	render_map(t_cube *cube)
{
	t_render_data	data;
	int				x;

	x = 0;
	while (x < screenWidth)
	{
		init_render_data(&data, cube, x);
		perform_dda(&data, cube);
		draw_vertical_line(&data, cube, x);
		x++;
	}
	render_doors(cube);
	render_minimap(cube);
}

void	destroy_all(t_cube *cube)
{
	mlx_destroy_window(cube->mlx, cube->mlx_win);
	mlx_destroy_image(cube->mlx, cube->img->img);
	mlx_destroy_image(cube->mlx, cube->card->east_wall.img);
	mlx_destroy_image(cube->mlx, cube->card->west_wall.img);
	mlx_destroy_image(cube->mlx, cube->card->north_wall.img);
	mlx_destroy_image(cube->mlx, cube->card->south_wall.img);
	mlx_destroy_image(cube->mlx, cube->door->img);
}

int	close_window(t_cube *cube)
{
	destroy_all(cube);
	free(cube->card->north_path);
	free(cube->card->south_path);
	free(cube->card->east_path);
	free(cube->card->west_path);
	free(cube->colors->f_hex_color);
	free(cube->colors->c_hex_color);
	free_matrix(cube->colors->ceiling_colors);
	free_matrix(cube->colors->floor_colors);
	free(cube->card);
	free(cube->player);
	free(cube->img);
	free(cube->colors);
	free(cube->mini);
	free(cube->door);
	free(cube->mlx);
	free(cube->map_len);
	free_matrix(cube->all_map);
	free_matrix(cube->real_map);
	free_matrix_int(cube->map_door_status);
	free_matrix_double(cube->map_door_timer);
	free(cube);
	exit (1);
}

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

int	game_loop(t_cube *cube)
{
	render_map(cube);
	mlx_put_image_to_window(cube->mlx, cube->mlx_win, cube->img->img, 0, 0);
	calculate_fps(cube);
	update_movement(cube);
	update_rotation(cube);
	return (0);
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

int	main(int argc, char **argv)
{
	t_cube	*game;

	if (argc != 2)
	{
		printf("Too few/many arguments\n");
		exit(1);
	}
	game = ft_calloc(1, sizeof(t_cube));
	struct_init(game);
	is_cub(argv, game);
	read_and_build(game, argv);
	game->mlx = mlx_init();
	load_imgs(game);
	load_textures(game);
	mlx_hooks(game);
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_loop(game->mlx);
}
