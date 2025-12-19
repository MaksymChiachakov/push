/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andelalo <andelalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:04:54 by andelalo          #+#    #+#             */
/*   Updated: 2025/11/18 12:43:06 by andelalo         ###   ########.fr       */
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
