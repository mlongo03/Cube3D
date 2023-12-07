/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:09:39 by mlongo            #+#    #+#             */
/*   Updated: 2023/12/07 16:22:15 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

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
