/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:06:56 by mlongo            #+#    #+#             */
/*   Updated: 2023/11/23 11:46:47 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
#define CUBE_H

typedef	struct s_cardinals
{
	void	*north_wall;
	void	*south_wall;
	void	*east_wall;
	void	*west_wall;
}	t_cardinals;

typedef	struct s_player
{
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	double	mov_dirX;
	double	mov_dirY;
	double	cam_dir;
}	t_player;

typedef	struct s_colors
{
	int				f_color_num;
	int				c_color_num;
	char			**floor_colors;
	char			**ceiling_colors;
	char			*f_hex_color;
	char			*c_hex_color;
}	t_colors;

typedef struct s_img
{
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_render_data
{
	int		mapX;
	int		mapY;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	int		color;
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
}	t_render_data;

typedef	struct s_cube
{
	void		*mlx;
	void		*mlx_win;
	char		**all_map; //la mappa con letteralmente tutto
	char		**real_map; //la mappa base
	t_cardinals	*card;
	t_colors	*colors;
	int			check_card[4];
	t_player	*player;
	int			*map_len; //può diventare permanente (per ora provvisiorio)
	double		time;
	double		oldTime;
	int			fps;
	double		frameTime;
	t_img		*img;
}	t_cube;

# include "libft/libft.h"
# include "mlx_linux/mlx.h"
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdbool.h>
# include <stdint.h>

int	close_window(t_cube *cube);

#endif
