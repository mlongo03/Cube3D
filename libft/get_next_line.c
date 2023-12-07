/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 20:01:42 by lnicoter          #+#    #+#             */
/*   Updated: 2023/12/07 16:44:45 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_readrest(int fd, char *res, int size)
{
	char	*temp;
	int		bytes;

	temp = malloc(sizeof(char) * (size + 1));
	if (!temp)
		return (NULL);
	bytes = 1;
	while (bytes != 0)
	{
		bytes = read(fd, temp, size);
		if (bytes == -1)
		{
			free (temp);
			return (NULL);
		}
		temp[bytes] = '\0';
		res = ft_strjoin_get(res, temp);
	}
	free(temp);
	return (res);
}

char	*ft_writing(char *res)
{
	char	*line;
	int		i;

	i = 0;
	if (!res[i])
		return (NULL);
	while (res[i] && res[i] != '\0')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (res[i] && res[i] != '\0')
	{
		line[i] = res[i];
		i++;
	}
	if (res[i] == '\0')
	{
		line[i] = res[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_new_static(char *res)
{
	char	*s;
	int		i;
	int		j;

	i = 0;
	while (res[i] && res[i] != '\0')
		i++;
	if (!res[i])
	{
		free(res);
		return (NULL);
	}
	s = malloc(sizeof(char) * (ft_strlen(res) - i + 1));
	if (!s)
		return (NULL);
	i++;
	j = 0;
	while (res[i])
	{
		s[j++] = res[i++];
	}
	s[j] = '\0';
	free(res);
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;

	if (fd < 0 || 50 <= 0)
		return (NULL);
	rest = ft_readrest(fd, rest, 50);
	if (!rest)
		return (NULL);
	line = ft_writing(rest);
	rest = ft_new_static(rest);
	return (line);
}
