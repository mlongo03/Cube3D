/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuele <manuele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:12:16 by mlongo            #+#    #+#             */
/*   Updated: 2023/11/24 17:56:32 by manuele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sign(char c)
{
	return (c == '-' || c == '+');
}

static int	ft_spaces(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r'
		|| c == '\v' || c == '\f');
}

int	ft_atoi(const char *nptr)
{
	char	*p;
	int		s;
	int		r;

	p = (char *) nptr;
	s = 1;
	r = 0;
	while (ft_spaces(*p))
		p++;
	if (ft_sign(*p))
	{
		if (*p == '-')
			s = -1;
		p++;
	}
	while (ft_isdigit((int) *p))
	{
		r *= 10;
		r += *(p++) - 48;
	}
	return (r * s);
}

int	ft_atoi_colors(const char *str)
{
	int		i;
	int		res;
	int		sign;

	res = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == 32)
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
		return (-1);
	if (str[i] < '0' || str[i] > '9')
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (str[i] - 48) + (res * 10);
		i++;
	}
	return (res * sign);
}
