/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andelalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:00:22 by andelalo          #+#    #+#             */
/*   Updated: 2025/11/13 15:43:45 by andelalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;
	size_t	total_size;

	if (!nmemb || !size)
	{
		arr = malloc(0);
		return (arr);
	}
	if (SIZE_MAX / size < nmemb)
		return (0);
	total_size = nmemb * size;
	arr = malloc(total_size);
	if (!arr)
		return (0);
	ft_bzero(arr, total_size);
	return (arr);
}
