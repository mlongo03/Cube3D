/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuele <manuele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:06:47 by mlongo            #+#    #+#             */
/*   Updated: 2023/11/26 17:14:47 by manuele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#define mapWidth 24
#define mapHeight 24

int worldMap[mapWidth][mapHeight] =
	{
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

u_int64_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (u_int64_t)1000) + (tv.tv_usec / 1000));
}

void	init_step_direction(t_render_data *data, t_cube *cube)
{
	if (data->rayDirX < 0)
	{
		data->stepX = -1;
		data->sideDistX = (cube->player->posX - data->mapX) * data->deltaDistX;
	}
	else
	{
		data->stepX = 1;
		data->sideDistX = (data->mapX + 1.0 - cube->player->posX) * data->deltaDistX;
	}
	if (data->rayDirY < 0)
	{
		data->stepY = -1;
		data->sideDistY = (cube->player->posY - data->mapY) * data->deltaDistY;
	}
	else
	{
		data->stepY = 1;
		data->sideDistY = (data->mapY + 1.0 - cube->player->posY) * data->deltaDistY;
	}
}

void	init_render_data(t_render_data *data, t_cube *cube, int x)
{
	data->cameraX = 2 * x / (double)screenWidth - 1;
	data->rayDirX = cube->player->dirX + cube->player->planeX * data->cameraX;
	data->rayDirY = cube->player->dirY + cube->player->planeY * data->cameraX;
	data->mapX = (int)cube->player->posX;
	data->mapY = (int)cube->player->posY;
	if (data->rayDirX == 0)
		data->deltaDistX = 1e30;
	else
		data->deltaDistX = fabs(1.0f / data->rayDirX);
	if (data->rayDirY == 0)
		data->deltaDistY = 1e30;
	else
		data->deltaDistY = fabs(1.0f / data->rayDirY);
	data->hit = 0;
	init_step_direction(data, cube);
}

void	perform_dda(t_render_data *data)
{
	while (data->hit == 0)
	{
		if (data->sideDistX < data->sideDistY)
		{
			data->sideDistX += data->deltaDistX;
			data->mapX += data->stepX;
			data->side = 0;
		}
		else
		{
			data->sideDistY += data->deltaDistY;
			data->mapY += data->stepY;
			data->side = 1;
		}
		if (worldMap[data->mapX][data->mapY] == 1)
			data->hit = 1;
	}
}

void	set_color(t_render_data *data, t_cube *cube, int shift)
{
	if (data->side == 1)
	{
		//nord
		if (data->rayDirY > 0)
			data->color = *(unsigned int *)(cube->card->north_wall.addr + shift);
		//sud
		else
			data->color = *(unsigned int *)(cube->card->south_wall.addr + shift);
	}
	else
	{
		//est
		if (data->rayDirX > 0)
			data->color = *(unsigned int *)(cube->card->east_wall.addr + shift);
		//ovest
		else
			data->color = *(unsigned int *)(cube->card->west_wall.addr + shift);
	}

}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr	+ (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	set_tex_width_height(t_render_data *data, t_cube *cube)
{
	if (data->side == 1)
	{
		if (data->rayDirY > 0)
		{
			data->texWidth = cube->card->north_wall.width;
			data->texHeight = cube->card->north_wall.height;
			return ;
		}
		data->texWidth = cube->card->south_wall.width;
		data->texHeight = cube->card->south_wall.height;
	}
	else
	{
		if (data->rayDirX > 0)
		{
			data->texWidth = cube->card->east_wall.width;
			data->texHeight = cube->card->east_wall.height;
			return ;
		}
		data->texWidth = cube->card->west_wall.width;
		data->texHeight = cube->card->west_wall.height;
	}
}

void	draw_tex_wall(t_render_data *data, t_cube *cube, int x)
{
	int	y;
	data->step = 1.0 * data->texHeight / data->lineHeight;
	data->texPos = (data->drawStart - screenHeight / 2 + data->lineHeight / 2) * data->step;
	y = data->drawStart;
	while(y < data->drawEnd)
	{
		data->texY = (int)data->texPos % data->texHeight;
		data->texPos += data->step;
		set_color(data, cube, 4 * (int)(data->texHeight * data->texY + data->texX));
		my_mlx_pixel_put(cube->img, x, y++, data->color);
	}
}

void	wallPos_rayPosOnWall(t_render_data *data, t_cube *cube)
{
	if (data->side == 0)
		data->perpWallDist = (data->sideDistX - data->deltaDistX);
	else
		data->perpWallDist = (data->sideDistY - data->deltaDistY);
	data->lineHeight = (int)(screenHeight / data->perpWallDist);
	data->drawStart = -data->lineHeight / 2 + screenHeight / 2;
	if (data->drawStart < 0)
		data->drawStart = 0;
	data->drawEnd = data->lineHeight / 2 + screenHeight / 2;
	if (data->drawEnd >= screenHeight)
		data->drawEnd = screenHeight - 1;
	if (data->side == 0)
		data->wallX = cube->player->posY + data->perpWallDist * data->rayDirY;
	else
		data->wallX = cube->player->posX + data->perpWallDist * data->rayDirX;
	data->wallX -= (int)(data->wallX);
	set_tex_width_height(data, cube);
	data->texX = (int)(data->wallX * (double)data->texWidth);
	if(data->side == 0 && data->rayDirX > 0)
		data->texX = data->texWidth - data->texX - 1;
	if(data->side == 1 && data->rayDirY < 0)
		data->texX = data->texWidth - data->texX - 1;
}

void	draw_vertical_line(t_render_data *data, t_cube *cube, int x)
{
	int	i;

	i = 0;
	wallPos_rayPosOnWall(data, cube);
	while (i < data->drawStart)
		my_mlx_pixel_put(cube->img, x, i++, 0xFFFFFFFF);
	draw_tex_wall(data, cube, x);
	i = data->drawEnd;
	while (i < screenHeight)
		my_mlx_pixel_put(cube->img, x, i++, 0xFFFFFFFF);
}

void	load_textures(t_cube *cube)
{
	cube->card = ft_calloc(1, sizeof(t_cardinals));
	cube->card->north_wall.img = mlx_xpm_file_to_image(cube->mlx,
			"/home/manuele/Scrivania/darioCube/maps/bluestone.xpm",
			&cube->card->north_wall.width, &cube->card->north_wall.height);
	cube->card->north_wall.addr = mlx_get_data_addr(cube->card->north_wall.img,
		&cube->card->east_wall.bits_per_pixel, &cube->card->north_wall.line_length,
		&cube->card->north_wall.endian);
	cube->card->south_wall.img = mlx_xpm_file_to_image(cube->mlx,
			"/home/manuele/Scrivania/darioCube/maps/colorstone.xpm",
			&cube->card->south_wall.width, &cube->card->south_wall.height);
	cube->card->south_wall.addr = mlx_get_data_addr(cube->card->south_wall.img,
		&cube->card->south_wall.bits_per_pixel, &cube->card->south_wall.line_length,
		&cube->card->south_wall.endian);
	cube->card->east_wall.img = mlx_xpm_file_to_image(cube->mlx,
			"/home/manuele/Scrivania/darioCube/maps/pupone.xpm",
			&cube->card->east_wall.width, &cube->card->east_wall.height);
	cube->card->east_wall.addr = mlx_get_data_addr(cube->card->east_wall.img,
		&cube->card->east_wall.bits_per_pixel, &cube->card->east_wall.line_length,
		&cube->card->east_wall.endian);
	cube->card->west_wall.img = mlx_xpm_file_to_image(cube->mlx,
			"/home/manuele/Scrivania/darioCube/maps/colorstone.xpm",
			&cube->card->west_wall.width, &cube->card->west_wall.height);
	cube->card->west_wall.addr = mlx_get_data_addr(cube->card->west_wall.img,
		&cube->card->west_wall.bits_per_pixel, &cube->card->west_wall.line_length,
		&cube->card->west_wall.endian);
}

void	render_map(t_cube *cube)
{
	t_render_data	data;
	int				x;

	x = 0;
	load_textures(cube);
	while (x < screenWidth)
	{
		init_render_data(&data, cube, x);
		perform_dda(&data);
		draw_vertical_line(&data, cube, x);
		x++;
	}
}

int	close_window(t_cube *cube)
{
	mlx_destroy_window(cube->mlx, cube->mlx_win);
	mlx_destroy_image(cube->mlx, cube->img->img);
	// free_struct(cube);
	free(cube->mlx);
	exit (1);
}

int	key_hook_press(int key, t_cube *cube)
{
	if (key == 0 || key == 'a')
		cube->player->mov_dirX = -1;
	else if (key == 1 || key == 's')
		cube->player->mov_dirY = -1;
	else if (key == 2 || key == 'd')
		cube->player->mov_dirX = 1;
	else if (key == 13 || key == 'w')
		cube->player->mov_dirY = 1;
	else if (key == 65361)
		cube->player->cam_dir = -1;
	else if (key == 65363)
		cube->player->cam_dir = 1;
	// else if (key == 32)
	// 	door_mechanics(game);
	else if (key == 65307)
		close_window(cube);
	return (0);
}

int	key_hook_release(int key, t_cube *cube)
{
	if (key == 'w' || key == 's')
		cube->player->mov_dirY = 0;
	else if (key == 'a' || key == 'd')
		cube->player->mov_dirX = 0;
	else if (key == 65363 || key == 65361)
		cube->player->cam_dir = 0;
	return (0);	return (0);
}


void	mlx_hooks(t_cube *cube)
{
	mlx_hook(cube->mlx_win, 17, 0, close_window, cube);
	mlx_hook(cube->mlx_win, 2, 1L << 0, key_hook_press, (void *)cube);
	mlx_hook(cube->mlx_win, 3, 1L << 1, key_hook_release, (void *)cube);
	// mlx_hook(cube->mlx_win, 6, 1L << 6, ft_mouse, (void *)cube);
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
	char *number;

	cube->oldTime = cube->time;
	cube->time = get_time();
	cube->frameTime = (cube->time - cube->oldTime) / 1000.0;
	cube->fps = (int)(1.0 / cube->frameTime);
	if (cube->fps > 60)
	{
		ft_sleep(((1.0 / 60) - cube->frameTime) * 1000);
		cube->time = get_time();
		cube->frameTime = (cube->time - cube->oldTime) / 1000.0;
		cube->fps = (int)(1.0 / cube->frameTime);
	}
	number = ft_itoa(cube->fps);
	mlx_string_put(cube->mlx, cube->mlx_win,
		screenWidth - 50, 20, -1, number);
	free(number);
}

void	forward_backward(t_cube *cube, double moveSpeed)
{
	if (cube->player->mov_dirY == 1)
	{
		if (worldMap[(int)(cube->player->posX + cube->player->dirX * moveSpeed)][(int)cube->player->posY] == false)
			cube->player->posX += cube->player->dirX * moveSpeed;
		if (worldMap[(int)(cube->player->posX)][(int)(cube->player->posY + cube->player->dirY * moveSpeed)] == false)
			cube->player->posY += cube->player->dirY * moveSpeed;
	}
	if (cube->player->mov_dirY == -1)
	{
		if (worldMap[(int)(cube->player->posX - cube->player->dirX * moveSpeed)][(int)cube->player->posY] == false)
			cube->player->posX -= cube->player->dirX * moveSpeed;
		if (worldMap[(int)cube->player->posX][(int)(cube->player->posY - cube->player->dirY * moveSpeed)] == false)
			cube->player->posY -= cube->player->dirY * moveSpeed;
	}
}

void	left_right(t_cube *cube, double moveSpeed)
{
	if (cube->player->mov_dirX == -1)
	{
		if (worldMap[(int)(cube->player->posX - cube->player->dirY * moveSpeed)][(int)cube->player->posY] == false)
			cube->player->posX -= cube->player->dirY * moveSpeed;
		if (worldMap[(int)(cube->player->posX)][(int)(cube->player->posY + cube->player->dirX * moveSpeed)] == false)
			cube->player->posY += (cube->player->dirX) * moveSpeed;
	}
	if (cube->player->mov_dirX == 1)
	{
		if (worldMap[(int)(cube->player->posX + cube->player->dirY * moveSpeed)][(int)cube->player->posY] == false)
			cube->player->posX += cube->player->dirY * moveSpeed;
		if (worldMap[(int)cube->player->posX][(int)(cube->player->posY - cube->player->dirX * moveSpeed)] == false)
			cube->player->posY -= (cube->player->dirX) * moveSpeed;
	}
}

void	update_movement(t_cube *cube)
{
	double moveSpeed;

	moveSpeed = cube->frameTime * 5.0;
	forward_backward(cube, moveSpeed);
	left_right(cube, moveSpeed);
}

void	update_rotation(t_cube *cube)
{
	double rotSpeed;
	double oldDirX;
	double oldPlaneX;

	rotSpeed = cube->frameTime * 3.0;
	if (cube->player->cam_dir == 1)
	{
		oldDirX = cube->player->dirX;
		cube->player->dirX = cube->player->dirX * cos(-rotSpeed) - cube->player->dirY * sin(-rotSpeed);
		cube->player->dirY = oldDirX * sin(-rotSpeed) + cube->player->dirY * cos(-rotSpeed);
		oldPlaneX = cube->player->planeX;
		cube->player->planeX = cube->player->planeX * cos(-rotSpeed) - cube->player->planeY * sin(-rotSpeed);
		cube->player->planeY = oldPlaneX * sin(-rotSpeed) + cube->player->planeY * cos(-rotSpeed);
	}
	if (cube->player->cam_dir == -1)
	{
		oldDirX = cube->player->dirX;
		cube->player->dirX = cube->player->dirX * cos(rotSpeed) - cube->player->dirY * sin(rotSpeed);
		cube->player->dirY = oldDirX * sin(rotSpeed) + cube->player->dirY * cos(rotSpeed);
		oldPlaneX = cube->player->planeX;
		cube->player->planeX = cube->player->planeX * cos(rotSpeed) - cube->player->planeY * sin(rotSpeed);
		cube->player->planeY = oldPlaneX * sin(rotSpeed) + cube->player->planeY * cos(rotSpeed);
	}
}

int	game_loop(t_cube *cube)
{
	render_map(cube);
	mlx_put_image_to_window(cube->mlx, cube->mlx_win, cube->img->img, 0, 0);
	calculate_fps(cube);
	update_movement(cube);
	update_rotation(cube);
}

int main(int argc, char **argv)
{
	t_cube	*game;

	if (argc != 2)
	{
		printf("Too few/many arguments\n");
		exit(1);
	}
	game = ft_calloc(1, sizeof(t_cube));
	struct_init(game);
	// is_cub(argv, game);
	// read_and_build(game, argv);
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, screenWidth, screenHeight, "Hello world!");
	game->img->img = mlx_new_image(game->mlx, screenWidth, screenHeight);
	game->img->addr = mlx_get_data_addr(game->img->img,
		&game->img->bits_per_pixel, &game->img->line_length,
		&game->img->endian);
	mlx_hooks(game);
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_loop(game->mlx);
}
