/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putarg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andelalo <andelalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:05:27 by andelalo          #+#    #+#             */
/*   Updated: 2025/11/26 10:08:03 by andelalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putarg(va_list ap, char c)
{
	if (c == 'd' || c == 'i')
		return (ft_putint(va_arg(ap, int)));
	if (c == 's')
		return (ft_putstr(va_arg(ap, char *)));
	if (c == 'u')
		return (ft_putunsigned(va_arg(ap, unsigned int), "0123456789"));
	if (c == 'x')
		return (ft_putunsigned(va_arg(ap, unsigned int), "0123456789abcdef"));
	if (c == 'X')
		return (ft_putunsigned(va_arg(ap, unsigned int), "0123456789ABCDEF"));
	if (c == 'p')
		return (ft_putptr(va_arg(ap, void *)));
	if (c == '%')
		return (ft_putstr("%"));
	if (c == 'c')
	{
		ft_putchar_fd((unsigned char)va_arg(ap, int), 1);
		return (1);
	}
	ft_putchar_fd('%', 1);
	ft_putchar_fd(c, 1);
	return (2);
}
