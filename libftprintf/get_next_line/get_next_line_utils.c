/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andelalo <andelalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 10:51:27 by andelalo          #+#    #+#             */
/*   Updated: 2025/12/18 12:00:34 by andelalo         ###   ########.fr       */
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
