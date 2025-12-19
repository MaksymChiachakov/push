/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andelalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:57:44 by andelalo          #+#    #+#             */
/*   Updated: 2025/11/11 16:51:39 by andelalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lenofn(long n)
{
	if (n < 10)
		return (1);
	return (1 + ft_lenofn(n / 10));
}

static void	ft_fillres(char *res, int l, int neg, long n)
{
	res[l--] = '\0';
	while (l >= neg)
	{
		res[l] = n % 10 + '0';
		n = n / 10;
		l--;
	}
	if (neg)
		res[0] = '-';
}

char	*ft_itoa(int n1)
{
	int		neg;
	long	n;
	char	*res;
	int		l;

	n = (long)n1;
	neg = 0;
	if (n < 0)
	{
		n = -n;
		neg = 1;
	}
	l = ft_lenofn(n) + neg;
	res = (char *)malloc(l + 1);
	if (!res)
		return (NULL);
	ft_fillres(res, l, neg, n);
	return (res);
}

/*
#include <stdio.h>
int	main(void)
{
	int	n = 0;

	printf("len of %d is %zu\n", n ,ft_lenofn(n));
	return (0);
}
*/
