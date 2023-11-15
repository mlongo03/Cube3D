/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:16:11 by mlongo            #+#    #+#             */
/*   Updated: 2023/11/10 17:15:49 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_word(const char *s, char c)
{
	size_t	words;

	words = 0;
	while (*s)
	{
		if (*s != c && !(*s >= '\t' && c <= '\r'))
		{
			++words;
			while (*s && *s != c)
				++s;
		}
		else
			s++;
	}
	return (words);
}

void	skip_quotes(char **s, size_t *len)
{
	if (**s == '"')
	{
		(*s)++;
		(*len)++;
		while (**s && **s != '"')
		{
			(*len)++;
			(*s)++;
		}
	}
	else if (**s == '\'')
	{
		(*s)++;
		(*len)++;
		while (**s && **s != '\'')
		{
			(*len)++;
			(*s)++;
		}
	}
	++(*s);
}

char	**ft_split(char *s, char c)
{
	char	**str;
	size_t	i;
	size_t	len;

	if (!s)
		return (0);
	i = 0;
	str = malloc(sizeof(char *) * (get_word(s, c) + 1));
	if (!str)
		return (0);
	while (*s)
	{
		if (*s != c && !(*s >= '\t' && c <= '\r'))
		{
			len = 0;
			while (*s && *s != c && !(*s >= '\t' && c <= '\r') && ++len)
				skip_quotes(&s, &len);
			str[i++] = ft_substr(s - len, 0, len);
		}
		else
			s++;
	}
	str[i] = 0;
	return (str);
}
