/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andelalo <andelalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:52:51 by andelalo          #+#    #+#             */
/*   Updated: 2025/11/18 12:41:21 by andelalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_intlen(unsigned long int n, unsigned long int base_len)
{
	if (n < base_len)
		return (1);
	return (1 + ft_intlen(n / base_len, base_len));
}
