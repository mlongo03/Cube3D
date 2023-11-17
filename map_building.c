/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_building.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:58:28 by lnicoter          #+#    #+#             */
/*   Updated: 2023/11/17 15:07:42 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int		check_cardinals(t_cube *game)
{
	int	i;

	i = -1;
	while (++i < 4)
		game->check_card[i] = 0;
	i = -1;
	while(game->all_map[++i])
		check_existence(game, i);
	if (game->check_card[0] && game->check_card[1]
		&& game->check_card[2] && game->check_card[3])
	{
		i = -1;
		printf("checking\n");
		while (++i < 4)
		{
			printf("Value %d\n", game->check_card[i]);
			if (game->check_card[i] > 1)
				ft_error("Error double cardinal detected", game);
		}
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
		set_colors(game, i, floor_flag, ceiling_flag);
	color_convertion_int(game);
	save_colors_in_str(game);
}
/*
qui salverai con mlx_xpm_file_to_image appena
avrai gli sprite però prima finisci i check mappa
void	save_cardinals(t_cube *game)
{
	int	i;

	i = -1;
	while (game->all_map[++i])
	{
		if(!ft_strncmp(game->all_map[i], "NO", 2))
			game->card->north_wall = mlx_xpm_file_to_image()
		if(!ft_strncmp(game->all_map[i], "SO", 2))
			game->south_wall = mlx_xpm_file_to_image()
		if(!ft_strncmp(game->all_map[i], "EA", 2))
			game->east_wall = mlx_xpm_file_to_image()
		if(!ft_strncmp(game->all_map[i], "WE", 2))
			game->west_wall = mlx_xpm_file_to_image()
	}
}
*/

void	read_and_build(t_cube *game)
{
	int		fd;
	char	*line;

	fd = open("./maps/map1.cub", O_RDONLY);
	line = get_next_line(fd);
	game->all_map = ft_split(line, '\n');
	close(fd);
	free(line);
	if (!check_cardinals(game))
		ft_error("There are not enough cardinal point", game);
	take_real_map(game);
	take_colors(game);
}
