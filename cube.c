/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:06:47 by mlongo            #+#    #+#             */
/*   Updated: 2023/12/06 11:52:28 by mlongo           ###   ########.fr       */
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
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 2, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

int mapDoorsStatus[mapWidth][mapHeight] =
	{
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

double mapDoorsTimer[mapWidth][mapHeight] =
	{
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
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
		data->sideDistX = (cube->player->posX - (int)data->mapX) * data->deltaDistX;
	}
	else
	{
		data->stepX = 1;
		data->sideDistX = ((int)data->mapX + 1.0 - cube->player->posX) * data->deltaDistX;
	}
	if (data->rayDirY < 0)
	{
		data->stepY = -1;
		data->sideDistY = (cube->player->posY - (int)data->mapY) * data->deltaDistY;
	}
	else
	{
		data->stepY = 1;
		data->sideDistY = ((int)data->mapY + 1.0 - cube->player->posY) * data->deltaDistY;
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
		if (worldMap[(int)data->mapX][(int)data->mapY] == 1)
			data->hit = 1;
	}
}

int	perform_dda_doors(t_render_data *data, t_cube *cube)
{
	while (data->hit == 0)
	{
		if (data->sideDistX < data->sideDistY)
		{
			data->mapX += data->stepX;
			data->side = 0;

			if (worldMap[(int)data->mapX][(int)data->mapY] == 2)
			{
				if (worldMap[(int)data->mapX][(int)data->mapY + 1] == 1 && worldMap[(int)data->mapX][(int)data->mapY - 1] == 1)
				{
					//porta verticale
					data->sideDistX += data->deltaDistX + (data->deltaDistX / 2);
					data->perpWallDist = (data->sideDistX - data->deltaDistX);
					data->wallX = cube->player->posY + data->perpWallDist * data->rayDirY;
					data->wallX = data->wallX - (int)(data->mapY);
					if (data->wallX >= 0 && data->wallX <= 1)
					{
						if (data->wallX <= mapDoorsTimer[(int)data->mapX][(int)data->mapY])
							data->hit = 2;
						else
							data->sideDistX -= (data->deltaDistX / 2);
					}
					else
						data->sideDistX -= (data->deltaDistX / 2);
				}
			}
			else
				data->sideDistX += data->deltaDistX;

		}
		else
		{
			data->mapY += data->stepY;
			data->side = 1;

			if (worldMap[(int)data->mapX][(int)data->mapY] == 2)
			{
				if (worldMap[(int)data->mapX + 1][(int)data->mapY] == 1 && worldMap[(int)data->mapX - 1][(int)data->mapY] == 1)
				{
					//porta orizzonatale
					data->sideDistY += data->deltaDistY + (data->deltaDistY / 2);
					data->perpWallDist = (data->sideDistY - data->deltaDistY);
					data->wallX = cube->player->posX + data->perpWallDist * data->rayDirX;
					data->wallX = data->wallX - (int)(data->mapX);
					if (data->wallX >= 0 && data->wallX <= 1)
						data->hit = 2;
					else
						data->sideDistY -= (data->deltaDistY / 2);
				}
			}
			else
				data->sideDistY += data->deltaDistY;
		}
		if (worldMap[(int)data->mapX][(int)data->mapY] == 1)
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
		if (data->rayDirY > 0)
			data->color = *(unsigned int *)(cube->card->north_wall.addr + shift);
		else
			data->color = *(unsigned int *)(cube->card->south_wall.addr + shift);
	}
	else
	{
		if (data->rayDirX > 0)
			data->color = *(unsigned int *)(cube->card->east_wall.addr + shift);
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
	if (data->hit == 2)
	{
		data->texWidth = cube->door->width;
		data->texHeight = cube->door->height;
	}
	else if (data->side == 1)
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

double map_value(double x, double newMin, double newMax)
{
	double normalized_value;
	normalized_value = (x - newMin) / (newMax - newMin);
	return fmax(0, fmin(1, normalized_value));
}

int	wallPos_rayPosOnWall(t_render_data *data, t_cube *cube)
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
	if (data->hit == 2)
	{
		if (data->wallX > mapDoorsTimer[(int)data->mapX][(int)data->mapY])
			return (1);
		data->wallX = 1 - (mapDoorsTimer[(int)data->mapX][(int)data->mapY] - data->wallX);
	}
	set_tex_width_height(data, cube);
	data->texX = (int)(data->wallX * (double)data->texWidth);
	if(data->side == 0 && data->rayDirX > 0)
		data->texX = data->texWidth - data->texX - 1;
	if(data->side == 1 && data->rayDirY < 0)
		data->texX = data->texWidth - data->texX - 1;
	return (0);
}

void	draw_vertical_line(t_render_data *data, t_cube *cube, int x)
{
	int	i;

	i = 0;
	if (wallPos_rayPosOnWall(data, cube))
		return ;
	while (i < data->drawStart)
		my_mlx_pixel_put(cube->img, x, i++, 0x000000FF);
	draw_tex_wall(data, cube, x);
	i = data->drawEnd;
	while (i < screenHeight)
		my_mlx_pixel_put(cube->img, x, i++, 0xFFFFFFFF);
}

void	load_door(t_cube *cube)
{
	cube->door->img = mlx_xpm_file_to_image(cube->mlx,
			"./textures/door.xpm",
			&cube->door->width, &cube->door->height);
	cube->door->addr = mlx_get_data_addr(cube->door->img,
		&cube->door->bits_per_pixel, &cube->door->line_length,
		&cube->door->endian);
}

void	load_textures(t_cube *cube)
{
	cube->card->north_wall.img = mlx_xpm_file_to_image(cube->mlx,
			"./textures/magma.xpm",
			&cube->card->north_wall.width, &cube->card->north_wall.height);
	cube->card->north_wall.addr = mlx_get_data_addr(cube->card->north_wall.img,
		&cube->card->north_wall.bits_per_pixel, &cube->card->north_wall.line_length,
		&cube->card->north_wall.endian);
	cube->card->south_wall.img = mlx_xpm_file_to_image(cube->mlx,
			"./textures/wood.xpm",
			&cube->card->south_wall.width, &cube->card->south_wall.height);
	cube->card->south_wall.addr = mlx_get_data_addr(cube->card->south_wall.img,
		&cube->card->south_wall.bits_per_pixel, &cube->card->south_wall.line_length,
		&cube->card->south_wall.endian);
	cube->card->east_wall.img = mlx_xpm_file_to_image(cube->mlx,
			"./textures/magma.xpm",
			&cube->card->east_wall.width, &cube->card->east_wall.height);
	cube->card->east_wall.addr = mlx_get_data_addr(cube->card->east_wall.img,
		&cube->card->east_wall.bits_per_pixel, &cube->card->east_wall.line_length,
		&cube->card->east_wall.endian);
	cube->card->west_wall.img = mlx_xpm_file_to_image(cube->mlx,
			"./textures/wood.xpm",
			&cube->card->west_wall.width, &cube->card->west_wall.height);
	cube->card->west_wall.addr = mlx_get_data_addr(cube->card->west_wall.img,
		&cube->card->west_wall.bits_per_pixel, &cube->card->west_wall.line_length,
		&cube->card->west_wall.endian);
	load_door(cube);
}

void	init_draw_vars(t_cube *cube)
{
	//here we have to use our maxblocks variables
	int	offset;
	int	distWidth;
	int	distHeight;
	int	fixY;
	int	fixX;
	int	isWidthEven;
	int	isHeightEven;

	fixY = 0;
	fixX = 0;
	offset = 0;
	distWidth = 15;
	distHeight = 8;
	isWidthEven = 0;
	isHeightEven = 1;
	if (mapWidth < 30)
	{
		if (mapWidth % 2 != 0)
			isWidthEven++;
		distWidth = mapWidth / 2;
	}
	if (mapHeight < 17)
	{
		if (mapHeight % 2 == 0)
			isHeightEven--;
		distHeight = mapHeight / 2;
	}
	while ((cube->mini->y + offset) < (mapHeight - 1) && offset < distHeight)
		offset++;
	cube->mini->drawEndHeight = cube->mini->y + offset;
	offset = 0;
	while ((cube->mini->y - offset) > 0 && offset < distHeight)
		offset++;
	cube->mini->drawStartHeight = cube->mini->y - offset;
	offset = 0;
	while ((cube->mini->x + offset) < (mapWidth - 1) && offset < distWidth)
		offset++;
	cube->mini->drawEndWidth = cube->mini->x + offset;
	offset = 0;
	while (cube->mini->x - offset > 0 && offset < distWidth)
		offset++;
	cube->mini->drawStartWidth = cube->mini->x - offset;

	if (!fixY && cube->mini->drawEndHeight - cube->mini->y < distHeight)
	{
		fixY++;
		cube->mini->drawStartHeight -= (distHeight - (cube->mini->drawEndHeight - cube->mini->y));
		if (!isHeightEven)
			cube->mini->drawStartHeight++;
	}


	if (!fixY && cube->mini->y - cube->mini->drawStartHeight < distHeight)
	{
		fixY++;
		cube->mini->drawEndHeight += (distHeight - (cube->mini->y - cube->mini->drawStartHeight));
		if (!isHeightEven)
			cube->mini->drawEndHeight--;
	}


	if (!fixX && cube->mini->drawEndWidth - cube->mini->x < distWidth)
	{
		fixX++;
		cube->mini->drawStartWidth -= (distWidth - (cube->mini->drawEndWidth - cube->mini->x));
		if (!isWidthEven)
			cube->mini->drawStartWidth++;
	}

	if (!fixX && cube->mini->x - cube->mini->drawStartWidth < distWidth)
	{
		fixX++;
		cube->mini->drawEndWidth += (distWidth - (cube->mini->x - cube->mini->drawStartWidth));
		if (!isWidthEven)
			cube->mini->drawEndWidth--;
	}
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

void	render_minimap(t_cube *cube)
{
	int	x;
	int	y;
	double miniX;
	double miniY;

	cube->mini->x = (int)cube->player->posX;
	cube->mini->y = (int)cube->player->posY;
	init_draw_vars(cube);
	y = cube->mini->drawStartHeight;
	while (y <= cube->mini->drawEndHeight)
	{
		x = cube->mini->drawStartWidth;
		while (x <= cube->mini->drawEndWidth)
		{
			if (worldMap[x][y] == 1)
				draw_square((x - cube->mini->drawStartWidth) * cube->mini->scale, (y - cube->mini->drawStartHeight) * cube->mini->scale, cube, 0xFFFFFFFF);
			else if (worldMap[x][y] == 0)
				draw_square((x - cube->mini->drawStartWidth) * cube->mini->scale, (y - cube->mini->drawStartHeight) * cube->mini->scale, cube, 0x00000000);
			else if (worldMap[x][y] == 2)
				draw_square((x - cube->mini->drawStartWidth) * cube->mini->scale, (y - cube->mini->drawStartHeight) * cube->mini->scale, cube, 0x000000FF);
			x++;
		}
		y++;
	}
	miniX = cube->player->posX - cube->mini->drawStartWidth;
	miniY = cube->player->posY - cube->mini->drawStartHeight;
	draw_square(miniX * cube->mini->scale, miniY * cube->mini->scale, cube, 0x00FF0000);
}

void	update_door(int x, int y, t_cube *cube)
{
	if (mapDoorsTimer[x][y] >= 1 && mapDoorsStatus[x][y] == Closing)
		mapDoorsStatus[x][y] = Closed;
	else if (mapDoorsTimer[x][y] <= 0 && mapDoorsStatus[x][y] == Opening)
		mapDoorsStatus[x][y] = Open;
	else if (mapDoorsStatus[x][y] == Opening)
		mapDoorsTimer[x][y] -= 0.01;
	else if (mapDoorsStatus[x][y] == Closing)
		mapDoorsTimer[x][y] += 0.01;
}

void	update_doors(t_cube *cube)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	while (y < mapHeight)
	{
		x = 0;
		while (x < mapWidth)
		{
			if(worldMap[x][y] == 2)
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
		perform_dda(&data);
		draw_vertical_line(&data, cube, x);
		x++;
	}
	render_doors(cube);
	render_minimap(cube);
}

int	close_window(t_cube *cube)
{
	mlx_destroy_window(cube->mlx, cube->mlx_win);
	mlx_destroy_image(cube->mlx, cube->img->img);
	mlx_destroy_image(cube->mlx, cube->card->east_wall.img);
	mlx_destroy_image(cube->mlx, cube->card->west_wall.img);
	mlx_destroy_image(cube->mlx, cube->card->north_wall.img);
	mlx_destroy_image(cube->mlx, cube->card->south_wall.img);
	mlx_destroy_image(cube->mlx, cube->door->img);
	free(cube->card);
	free(cube->player);
	free(cube->img);
	free(cube->colors);
	free(cube->mini);
	free(cube->door);
	free(cube->mlx);
	// free_struct(cube);
	free(cube);
	exit (1);
}

void	handle_door(t_cube *cube)
{
	int	*positionstoWatch;
	int	posXtoWatch;
	int	posYtoWatch;
	int	i;

	i = 0;
	positionstoWatch = (int *)malloc(sizeof(int) * 7);
	posXtoWatch = cube->player->posX;
	posYtoWatch = cube->player->posY;
	if (cube->player->dirX > 0)
	{
		positionstoWatch[i++] = cube->player->posX + 1;
		positionstoWatch[i++] = cube->player->posY;
	}
	if (cube->player->dirX < 0)
	{
		positionstoWatch[i++] = cube->player->posX - 1;
		positionstoWatch[i++] = cube->player->posY;
	}
	if (cube->player->dirY > 0)
	{
		positionstoWatch[i++] = cube->player->posX;
		positionstoWatch[i++] = cube->player->posY + 1;
	}
	if (cube->player->dirY < 0)
	{
		positionstoWatch[i++] = cube->player->posX;
		positionstoWatch[i++] = cube->player->posY - 1;
	}
	positionstoWatch[i] = 0;
	// printf("worldMap[%d][%d] = %d\n", posXtoWatch, posYtoWatch, worldMap[posXtoWatch][posYtoWatch]);
	i = 0;
	while (positionstoWatch[i] && positionstoWatch[i + 1])
	{
		if (worldMap[positionstoWatch[i]][positionstoWatch[i + 1]] == 2)
		{
			// printf("map status[%d][%d] = %d\n", positionstoWatch[i], positionstoWatch[i + 1], mapDoorsStatus[positionstoWatch[i]][positionstoWatch[i + 1]]);
			if (mapDoorsStatus[positionstoWatch[i]][positionstoWatch[i + 1]] == Closed || mapDoorsStatus[positionstoWatch[i]][positionstoWatch[i + 1]] == Closing)
				mapDoorsStatus[positionstoWatch[i]][positionstoWatch[i + 1]] = Opening;
			else if (mapDoorsStatus[positionstoWatch[i]][positionstoWatch[i + 1]] == Open || mapDoorsStatus[positionstoWatch[i]][positionstoWatch[i + 1]] == Opening)
				mapDoorsStatus[positionstoWatch[i]][positionstoWatch[i + 1]] = Closing;
		}
		i += 2;
	}
	free(positionstoWatch);
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
		cube->player->mov_dirX = 0;
	else if (key == 65363 || key == 65361)
		cube->player->cam_dir = 0;
	return (0);	return (0);
}

void	rotateCamera(float angle, t_cube *cube)
{
	double	newDirX;
	double	newDirY;
	double	newPlaneX;
	double	newPlaneY;

	angle = angle * M_PI / 180.0f;

	newDirX = cube->player->dirX * cos(angle) - cube->player->dirY * sin(angle);
	newDirY = cube->player->dirX * sin(angle) + cube->player->dirY * cos(angle);
	newPlaneX = cube->player->planeX * cos(angle) - cube->player->planeY * sin(angle);
	newPlaneY = cube->player->planeX * sin(angle) + cube->player->planeY * cos(angle);

	cube->player->dirX = newDirX;
	cube->player->dirY = newDirY;
	cube->player->planeX = newPlaneX;
	cube->player->planeY = newPlaneY;
}

int	handle_mouse(int x, int y, void	*cube)
{
	double normalizedX;
	double maxRotationAngle;
	double rotationAngle;
	double newRotationAngle;

	(void)y;
	mlx_mouse_hide(((t_cube *)cube)->mlx, ((t_cube *)cube)->mlx_win);
	normalizedX = (2.0f * x) / screenWidth - 1.0f;
	maxRotationAngle = 180.0f;
	rotationAngle = maxRotationAngle * normalizedX;
	newRotationAngle = rotationAngle;
	if (((t_cube *)cube)->player->rot_angle != 360)
		newRotationAngle = ((t_cube *)cube)->player->rot_angle - rotationAngle;
	((t_cube *)cube)->player->rot_angle = rotationAngle;
	rotateCamera(newRotationAngle, (t_cube *)cube);
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
	char *number;

	cube->oldTime = cube->time;
	cube->time = get_time();
	cube->frameTime = (cube->time - cube->oldTime) / 1000.0;
	cube->fps = (int)(1.0 / cube->frameTime);
	// if (cube->fps > 60)
	// {
	// 	ft_sleep(((1.0 / 60) - cube->frameTime) * 1000);
	// 	cube->time = get_time();
	// 	cube->frameTime = (cube->time - cube->oldTime) / 1000.0;
	// 	cube->fps = (int)(1.0 / cube->frameTime);
	// }
	number = ft_itoa(cube->fps);
	mlx_string_put(cube->mlx, cube->mlx_win,
		screenWidth - 50, 20, -1, number);
	free(number);
}

void	forward_backward(t_cube *cube, double moveSpeed)
{
	if (cube->player->mov_dirY == 1)
	{
		if (worldMap[(int)(cube->player->posX + cube->player->dirX * moveSpeed)][(int)cube->player->posY] == 0
			|| mapDoorsStatus[(int)(cube->player->posX + cube->player->dirX * moveSpeed)][(int)cube->player->posY] == Open)
			cube->player->posX += cube->player->dirX * moveSpeed;
		if (worldMap[(int)(cube->player->posX)][(int)(cube->player->posY + cube->player->dirY * moveSpeed)] == 0
			|| mapDoorsStatus[(int)(cube->player->posX)][(int)(cube->player->posY + cube->player->dirY * moveSpeed)] == Open)
			cube->player->posY += cube->player->dirY * moveSpeed;
	}
	if (cube->player->mov_dirY == -1)
	{
		if (worldMap[(int)(cube->player->posX - cube->player->dirX * moveSpeed)][(int)cube->player->posY] == 0
			|| mapDoorsStatus[(int)(cube->player->posX - cube->player->dirX * moveSpeed)][(int)cube->player->posY] == Open)
			cube->player->posX -= cube->player->dirX * moveSpeed;
		if (worldMap[(int)cube->player->posX][(int)(cube->player->posY - cube->player->dirY * moveSpeed)] == 0
			|| mapDoorsStatus[(int)cube->player->posX][(int)(cube->player->posY - cube->player->dirY * moveSpeed)] == Open)
			cube->player->posY -= cube->player->dirY * moveSpeed;
	}
}

void	left_right(t_cube *cube, double moveSpeed)
{
	if (cube->player->mov_dirX == -1)
	{
		if (worldMap[(int)(cube->player->posX - cube->player->dirY * moveSpeed)][(int)cube->player->posY] == 0
			|| mapDoorsStatus[(int)(cube->player->posX - cube->player->dirY * moveSpeed)][(int)cube->player->posY] == Open)
			cube->player->posX -= cube->player->dirY * moveSpeed;
		if (worldMap[(int)(cube->player->posX)][(int)(cube->player->posY + cube->player->dirX * moveSpeed)] == 0
			|| mapDoorsStatus[(int)(cube->player->posX)][(int)(cube->player->posY + cube->player->dirX * moveSpeed)] == Open)
			cube->player->posY += (cube->player->dirX) * moveSpeed;
	}
	if (cube->player->mov_dirX == 1)
	{
		if (worldMap[(int)(cube->player->posX + cube->player->dirY * moveSpeed)][(int)cube->player->posY] == 0
			|| mapDoorsStatus[(int)(cube->player->posX + cube->player->dirY * moveSpeed)][(int)cube->player->posY] == Open)
			cube->player->posX += cube->player->dirY * moveSpeed;
		if (worldMap[(int)cube->player->posX][(int)(cube->player->posY - cube->player->dirX * moveSpeed)] == 0
			|| mapDoorsStatus[(int)cube->player->posX][(int)(cube->player->posY - cube->player->dirX * moveSpeed)] == Open)
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
	return (0);
}

void	load_imgs(t_cube *game)
{
	game->mlx_win = mlx_new_window(game->mlx, screenWidth, screenHeight, "Hello world!");
	game->img->img = mlx_new_image(game->mlx, screenWidth, screenHeight);
	game->img->addr = mlx_get_data_addr(game->img->img,
		&game->img->bits_per_pixel, &game->img->line_length,
		&game->img->endian);
	game->mini = ft_calloc(1, sizeof(t_mini));
	game->mini->scale = screenWidth / 150;
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
	load_imgs(game);
	load_textures(game);
	mlx_hooks(game);
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_loop(game->mlx);
}
