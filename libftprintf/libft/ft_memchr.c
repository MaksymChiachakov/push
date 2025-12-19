/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andelalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:03:11 by andelalo          #+#    #+#             */
/*   Updated: 2025/11/10 14:23:12 by andelalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int chr, size_t n)
{
	const unsigned char	*s;
	size_t				i;
	unsigned char		c;

	i = 0;
	s = (const unsigned char *)src;
	c = (unsigned char)chr;
	while (i < n)
	{
		if (s[i] == c)
			return ((void *)(src + i));
		i++;
	}
	return (0);
}
