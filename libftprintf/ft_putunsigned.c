/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 12:48:50 by mchiacha          #+#    #+#             */
/*   Updated: 2025/12/19 12:48:53 by mchiacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_printn(unsigned long int n, char *base)
{
	if (n >= ft_strlen(base))
		ft_printn(n / ft_strlen(base), base);
	ft_putchar_fd(base[n % ft_strlen(base)], 1);
}

int	ft_putunsigned(unsigned long int n, char *base)
{
	ft_printn(n, base);
	return (ft_intlen(n, ft_strlen(base)));
}
