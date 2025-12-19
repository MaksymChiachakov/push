/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andelalo <andelalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:47:43 by andelalo          #+#    #+#             */
/*   Updated: 2025/11/25 11:27:07 by andelalo         ###   ########.fr       */
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
