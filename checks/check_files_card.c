/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files_card.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:25:09 by lnicoter          #+#    #+#             */
/*   Updated: 2023/12/06 18:20:03 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int		check_file_type(char *buffer)
{
	if (buffer[0] == 0x2f
		&& buffer[1] == 0x2a
		&& buffer[2] == 0x20
		&& buffer[3] == 0x58
		&& buffer[4] == 0x50
		&& buffer[5] == 0x4d
		&& buffer[6] == 0x20
		&& buffer[7] == 0x2a
		&& buffer[8] == 0x2f)
		return (1);
	return (0);
}

void	are_files_xpm(char *path, t_cube *game)
{
	char	file[25];
	int		fd;
	int		check;

	fd = open(path, O_RDONLY);
	if (check == -1)
		ft_error("Error the read went wrong\n", game);
	check = read(fd, file, 25);
	if (check < 0)
		ft_error("Error there's nothing in the file\n", game);
	file[check] = '\0';
	close(fd);
	if (!check_file_type(file))
		ft_error("Error the file is not valid\n", game);

}

void	set_cardinals_path(t_cube *game)
{
	char	**cardinals;
	int		i;
	cardinals = malloc(5 * sizeof(char *));
	cardinals[0] = ft_strdup(game->card->north_path);
	cardinals[1] = ft_strdup(game->card->south_path);
	cardinals[2] = ft_strdup(game->card->east_path);
	cardinals[3] = ft_strdup(game->card->west_path);
	cardinals[4] = 0;
	i = -1;
	while (cardinals[++i])
		are_files_xpm(cardinals[i], game);
}
