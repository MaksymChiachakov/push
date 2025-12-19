/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 12:49:36 by mchiacha          #+#    #+#             */
/*   Updated: 2025/12/19 12:49:39 by mchiacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_intlen(unsigned long int n, unsigned long int base_len)
{
	if (n < base_len)
		return (1);
	return (1 + ft_intlen(n / base_len, base_len));
}
