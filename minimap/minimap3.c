/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:13:39 by mlongo            #+#    #+#             */
/*   Updated: 2023/12/07 16:49:56 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

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

void	player_close_to_no_limit(t_mini_draw_vars *mp, t_cube *cube)
{
	mp->fix_y++;
	cube->mini->draw_start_height -= (mp->dist_height
			- (cube->mini->draw_end_height - cube->mini->y));
	if (!mp->is_height_even)
		cube->mini->draw_start_height++;
}
