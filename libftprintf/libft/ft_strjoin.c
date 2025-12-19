/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andelalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:58:39 by andelalo          #+#    #+#             */
/*   Updated: 2025/11/11 11:11:12 by andelalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	i;
	size_t	l1;
	size_t	l2;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	join = (char *)malloc(l1 + l2 + 1);
	if (!join)
		return (NULL);
	i = 0;
	while (i < l1)
	{
		join[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < l2)
	{
		join[l1 + i] = s2[i];
		i++;
	}
	join[l1 + i] = '\0';
	return (join);
}
