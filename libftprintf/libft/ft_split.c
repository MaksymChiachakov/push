/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andelalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:56:39 by andelalo          #+#    #+#             */
/*   Updated: 2025/11/11 15:49:10 by andelalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countwords(char const *s, char c)
{
	size_t	cnt;
	size_t	i;

	i = 0;
	cnt = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		cnt++;
		while (s[i] && s[i] != c)
			i++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (cnt);
}

static size_t	ft_wordlen(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static void	ft_free(char **res, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(res[i]);
		i++;
	}
	free(res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	j;

	res = (char **)malloc(sizeof(char *) * (ft_countwords(s, c) + 1));
	if (!res)
		return (NULL);
	while (*s && *s == c)
		s++;
	j = 0;
	while (*s)
	{
		res[j] = (char *)malloc(sizeof(char) * (ft_wordlen(s, c) + 1));
		if (!res[j])
		{
			ft_free(res, j);
			return (NULL);
		}
		ft_strlcpy(res[j], s, ft_wordlen(s, c) + 1);
		j++;
		s += ft_wordlen(s, c);
		while (*s && *s == c)
			s++;
	}
	res[j] = NULL;
	return (res);
}
