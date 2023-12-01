/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:15:53 by lnicoter          #+#    #+#             */
/*   Updated: 2023/11/17 10:30:24 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_valid(int c, int baselen)
{
	if (ft_isdigit(c))
		return (c - '0' < baselen);
	if (c >= 97 && c <= 122)
		return (c - 'a' + 10 < baselen);
	if (c >= 65 && c <= 90)
		return (c - 'A' + 10 < baselen);
	return (0);
}

static int	get_value(char c)
{
	if (ft_isdigit(c))
		return (c - '0');
	if (c >= 97 && c <= 122)
		return (c - 'a' + 10);
	return (c - 'A' + 10);
}

int			ft_atoi_base(const char *str, char *base)
{
	int sum;
	int i;
	int sign;
	int baselen;

	if (str == NULL || !*str || (baselen = ft_checkbase(base)) == 0)
		return (0);
	i = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	sum = 0;
	while (is_valid(str[i], baselen))
	{
		sum *= baselen;
		sum += get_value(str[i]);
		i++;
	}
	return (sign * sum);
}
