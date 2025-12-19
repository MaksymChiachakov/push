/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andelalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 15:21:32 by andelalo          #+#    #+#             */
/*   Updated: 2025/11/12 11:21:31 by andelalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *find, size_t n)
{
	size_t	i;
	size_t	j;

	if (find[0] == 0)
		return ((char *)src);
	j = 0;
	while (*src && j < n)
	{
		i = 0;
		while ((src[i] == find[i]) && (i + j < n) && src[i])
			i++;
		if (find[i] == '\0')
			return ((char *)src);
		src++;
		j++;
	}
	return (0);
}

/*
#include <string.h>
#include <stdio.h>
int	main(int ac, char **av)
{
	if (ac == 3)
		printf("%s\n", ft_strnstr(av[1], "\0", 2));
	return (0);
}
*/
