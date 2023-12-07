/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:16:54 by mlongo            #+#    #+#             */
/*   Updated: 2023/12/07 16:17:19 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

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
