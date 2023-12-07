/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_and_player_utils2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:36:36 by lnicoter          #+#    #+#             */
/*   Updated: 2023/12/07 14:36:44 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

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
