/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_building.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:58:28 by lnicoter          #+#    #+#             */
/*   Updated: 2023/12/11 15:29:38 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	check_cardinals(t_cube *game)
{
	int	i;

	i = -1;
	while (++i < 4)
		game->check_card[i] = 0;
	i = -1;
	while (game->all_map[++i])
		check_existence(game, i);
	if (game->check_card[0] && game->check_card[1]
		&& game->check_card[2] && game->check_card[3])
	{
		i = -1;
		while (++i < 4)
			if (game->check_card[i] > 1)
				ft_error("Error double cardinal detected", game);
		return (1);
	}
	return (0);
}

void	take_colors(t_cube *game)
{
	int	i;
	int	floor_flag;
	int	ceiling_flag;

	floor_flag = 0;
	ceiling_flag = 0;
	i = -1;
	while (game->all_map[++i])
		set_colors(game, i, &floor_flag, &ceiling_flag);
	color_convertion_int(game);
	save_colors_in_str(game);
}

void	create_doors_start_time_map(t_cube *game)
{
	int	y;
	int	x;

	y = 0;
	game->map_door_start_t = ft_calloc(game->map_max_height + 1,
			sizeof(t_door *));
	while (y < game->map_max_height)
	{
		game->map_door_start_t[y] = ft_calloc(game->map_max_width + 1,
				sizeof(t_door));
		x = 0;
		while (x < game->map_max_width)
		{
			game->map_door_start_t[y][x].start_t = 0;
			game->map_door_start_t[y][x].start_v = 0;
			x++;
		}
		y++;
	}
}

void	fix_real_map(t_cube *cube)
{
	int		x;
	int		y;

	y = 0;
	while (cube->real_map[y])
	{
		if ((int)ft_strlen(cube->real_map[y]) < cube->map_max_width)
		{
			cube->real_map[y] = (char *)ft_realloc(cube->real_map[y],
					sizeof(char), ft_strlen(cube->real_map[y]),
					cube->map_max_width + 1);
			x = 0;
			while (cube->real_map[y][x])
				x++;
			while (x < cube->map_max_width)
				cube->real_map[y][x++] = '0';
			cube->real_map[y][x] = 0;
		}
		y++;
	}
}

void	read_and_build(t_cube *game, char **av)
{
	int		fd;
	char	*line;

	fd = open(av[1], O_RDONLY);
	line = get_next_line(fd);
	if (line == NULL)
		ft_error("The map is empty or doesn't exist", game);
	game->all_map = ft_split(line, '\n');
	close(fd);
	free(line);
	is_map_last(game);
	if (!check_cardinals(game))
		ft_error("There are not enough cardinal point", game);
	save_cardinals_path(game);
	take_real_map(game);
	take_colors(game);
	main_check(game);
	fix_real_map(game);
	create_doors_maps(game);
	create_doors_start_time_map(game);
}
