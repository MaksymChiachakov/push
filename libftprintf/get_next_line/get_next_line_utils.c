/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 12:50:07 by mchiacha          #+#    #+#             */
/*   Updated: 2025/12/19 12:50:09 by mchiacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	is_nl(char **stash, int fd, int *len)
{
	*len = 0;
	if (stash[fd])
	{
		while (stash[fd][*len])
		{
			if (stash[fd][*len] == '\n')
				return (1);
			(*len)++;
		}
	}
	return (0);
}
