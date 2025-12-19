/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 12:49:05 by mchiacha          #+#    #+#             */
/*   Updated: 2025/12/19 12:49:07 by mchiacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putptr(void *ptr)
{
	if (!ptr)
		return (ft_putstr("(nil)"));
	ft_putstr_fd("0x", 1);
	return (ft_putunsigned((unsigned long)ptr, "0123456789abcdef") + 2);
}
