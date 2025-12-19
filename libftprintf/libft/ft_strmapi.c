/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andelalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:15:12 by andelalo          #+#    #+#             */
/*   Updated: 2025/11/11 17:32:16 by andelalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;

	res = (char *)malloc(ft_strlen(s) + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}

/*
#include <stdio.h>
char	ft_capitalize(unsigned int i, char c)
{
	if (i == 0)
		return (ft_toupper(c));
	return (ft_tolower(c));
}

int	main(void)
{
	char	*str;

	str = ft_strmapi("bonJOUR", &ft_capitalize);
	if (str)
	{
		printf("ft_strmapi : %s\n", str);
		free(str);
	}
	return (0);
}
*/
