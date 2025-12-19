/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andelalo <andelalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:09:44 by andelalo          #+#    #+#             */
/*   Updated: 2025/11/18 12:42:01 by andelalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putstr(char *str)
{
	int	len;

	if (!str)
		return (ft_putstr("(null)"));
	len = ft_strlen(str);
	write(1, str, len);
	return (len);
}
