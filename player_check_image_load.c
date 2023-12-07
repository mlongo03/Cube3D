/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_check_image_load.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:42:01 by lnicoter          #+#    #+#             */
/*   Updated: 2023/12/07 14:42:09 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	load_north_south_text(t_cube *cube)
{
	cube->card->north_wall.img = mlx_xpm_file_to_image(cube->mlx,
			cube->card->north_path,
			&cube->card->north_wall.width, &cube->card->north_wall.height);
	if (!cube->card->north_wall.img)
		ft_error("The image wasn't loaded correctly\n", cube);
	cube->card->north_wall.addr = mlx_get_data_addr(cube->card->north_wall.img,
			&cube->card->north_wall.bpp, &cube->card->north_wall.line_length,
			&cube->card->north_wall.endian);
	cube->card->south_wall.img = mlx_xpm_file_to_image(cube->mlx,
			cube->card->south_path,
			&cube->card->south_wall.width, &cube->card->south_wall.height);
	if (!cube->card->north_wall.img)
		ft_error("The image wasn't loaded correctly\n", cube);
	cube->card->south_wall.addr = mlx_get_data_addr(cube->card->south_wall.img,
			&cube->card->south_wall.bpp, &cube->card->south_wall.line_length,
			&cube->card->south_wall.endian);
}

void	load_textures(t_cube *cube)
{
	load_north_south_text(cube);
	cube->card->east_wall.img = mlx_xpm_file_to_image(cube->mlx,
			cube->card->east_path,
			&cube->card->east_wall.width, &cube->card->east_wall.height);
	if (!cube->card->north_wall.img)
		ft_error("The image wasn't loaded correctly\n", cube);
	cube->card->east_wall.addr = mlx_get_data_addr(cube->card->east_wall.img,
			&cube->card->east_wall.bpp, &cube->card->east_wall.line_length,
			&cube->card->east_wall.endian);
	cube->card->west_wall.img = mlx_xpm_file_to_image(cube->mlx,
			cube->card->west_path,
			&cube->card->west_wall.width, &cube->card->west_wall.height);
	if (!cube->card->north_wall.img)
		ft_error("The image wasn't loaded correctly\n", cube);
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
