/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andelalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:29:33 by andelalo          #+#    #+#             */
/*   Updated: 2025/11/13 16:15:59 by andelalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (start >= ft_strlen(s))
	{
		substr = (char *)malloc(1);
		if (substr)
			substr[0] = '\0';
		return (substr);
	}
	if (len > ft_strlen(s) - start)
		substr = (char *)malloc(ft_strlen(s) - start + 1);
	else
		substr = (char *)malloc(len + 1);
	if (!substr)
		return (NULL);
	i = 0;
	while (s[i + start] && (i < len))
	{
		substr[i] = s[i + start];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
