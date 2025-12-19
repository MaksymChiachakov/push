/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andelalo <andelalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:39:07 by andelalo          #+#    #+#             */
/*   Updated: 2025/11/18 12:39:53 by andelalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putint(int n)
{
	ft_putnbr_fd(n, 1);
	if (n < 0)
		return (1 + ft_intlen(-(long)n, 10));
	return (ft_intlen(n, 10));
}
