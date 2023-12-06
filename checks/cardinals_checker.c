/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cardinals_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:44:09 by lnicoter          #+#    #+#             */
/*   Updated: 2023/12/04 19:16:11 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	check_existence(t_cube *game, int i)
{
	if (!ft_strncmp(game->all_map[i], "NO", 2))
		game->check_card[0] += 1;
	if (!ft_strncmp(game->all_map[i], "SO", 2))
		game->check_card[1] += 1;
	if (!ft_strncmp(game->all_map[i], "EA", 2))
		game->check_card[2] += 1;
	if (!ft_strncmp(game->all_map[i], "WE", 2))
		game->check_card[3] += 1;
}

static void	save_cardinals_path_north_south(t_cube *game, int i)
{
	int	j;

	if (!ft_strncmp(game->all_map[i], "NO", 2))
	{
		j = -1;
		while (game->all_map[i][++j] != '.')
			;
		game->card->north_path = ft_strdup(&game->all_map[i][j]);
	}
	if (!ft_strncmp(game->all_map[i], "SO", 2))
	{
		j = -1;
		while (game->all_map[i][++j] != '.')
			;
		game->card->south_path = ft_strdup(&game->all_map[i][j]);
	}
}

static void	save_cardinals_path_east_west(t_cube *game, int i)
{
	int	j;

	if (!ft_strncmp(game->all_map[i], "EA", 2))
	{
		j = -1;
		while (game->all_map[i][++j] != '.')
			;
		game->card->east_path = ft_strdup(&game->all_map[i][j]);
	}
	if (!ft_strncmp(game->all_map[i], "WE", 2))
	{
		j = -1;
		while (game->all_map[i][++j] != '.')
			;
		game->card->west_path = ft_strdup(&game->all_map[i][j]);
	}
}

void	save_cardinals_path(t_cube *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->all_map[++i])
	{
		save_cardinals_path_north_south(game, i);
		save_cardinals_path_east_west(game, i);
	}
	printf("path %s\n",game->card->north_path);
	printf("path %s\n",game->card->south_path);
	printf("path %s\n",game->card->east_path);
	printf("path %s\n",game->card->west_path);
}
