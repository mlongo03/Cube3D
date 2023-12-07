/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkbase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:26:38 by lnicoter          #+#    #+#             */
/*   Updated: 2023/12/07 16:47:13 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_checkbase(char *base)
{
	int	i;

	if (base == NULL || *base == 0 || !base[1])
		return (0);
	i = 1;
	while ((base[i]))
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] - base[i - 1] != 1)
			if (!(ft_isdigit(base[i - 1])
					&& (base[i] == 'a' || base[i] == 'A')))
				return (0);
		i++;
	}
	if (base[i])
		return (0);
	return (i);
}
