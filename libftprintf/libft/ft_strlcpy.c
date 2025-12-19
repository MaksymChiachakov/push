/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andelalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 10:33:09 by andelalo          #+#    #+#             */
/*   Updated: 2025/11/11 14:24:42 by andelalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while ((i < size - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

/*
#include <bsd/string.h>
#include <stdio.h>
int	main(void)
{
	size_t	size = 10;
	char	dst1[size];
	char	dst2[size];

	printf("%zu\n",strlcpy(dst1, "hello", size));
	printf("%zu\n",ft_strlcpy(dst2, "hello", size));
	printf("%s\n", dst1);
	printf("%s\n", dst2);
	return (0);
}
*/
