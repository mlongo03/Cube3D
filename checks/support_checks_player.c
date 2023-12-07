/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_checks_player.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:13:57 by lnicoter          #+#    #+#             */
/*   Updated: 2023/12/07 16:36:45 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	save_player_pos(t_cube *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->real_map[++i])
	{
		j = -1;
		while (game->real_map[i][++j])
		{
			if (isplayer(game->real_map[i][j]))
			{
				game->player->posx = i;
				game->player->posy = j;
				break ;
			}
		}
	}
}

int	count_tabs(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '\t')
			count += 4;
		else
			count++;
		i++;
	}
	return (count);
}

char	*replace_tabs(char *str, int count)
{
	char	*result;
	int		j;
	int		i;

	result = (char *)malloc(count + 1);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\t')
		{
			result[j++] = ' ';
			result[j++] = ' ';
			result[j++] = ' ';
			result[j++] = ' ';
		}
		else
			result[j++] = str[i];
		i++;
	}
	result[j] = '\0';
	free(str);
	return (result);
}

char	*replace_tab_with_spaces(char *str)
{
	int		count;

	count = count_tabs(str);
	str = replace_tabs(str, count);
	return (str);
}
