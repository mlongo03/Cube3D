/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_card.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:08:04 by mlongo            #+#    #+#             */
/*   Updated: 2023/12/11 15:29:29 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	are_files_xpm(char *path, t_cube *game)
{
	char	file[25];
	int		fd;
	int		check;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_error("Error the read went wrong", game);
	check = read(fd, file, 25);
	if (check <= 0)
		ft_error("Error there's nothing in the file", game);
	file[check] = '\0';
	close(fd);
}
