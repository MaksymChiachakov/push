/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andelalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:06:08 by andelalo          #+#    #+#             */
/*   Updated: 2025/11/11 14:15:33 by andelalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = ft_strlen(str);
	while (i <= n)
	{
		if (str[i] == (char)c)
			return ((char *)(str + i));
		i++;
	}
	return (0);
}
