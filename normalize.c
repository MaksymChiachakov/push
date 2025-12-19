/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andelalo <andelalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 10:52:59 by andelalo          #+#    #+#             */
/*   Updated: 2025/12/16 10:59:28 by andelalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_map(int *tab, int size, t_map *map)
{
	int	i;

	i = 0;
	while (i < size)
	{
		map[i].value = tab[i];
		map[i].pos = i;
		i++;
	}
}

static void	sort_by_value(t_map *map, int size)
{
	int		i;
	int		j;
	t_map	tmp;

	i = 0;
	while (i < size)
	{
		j = i;
		while (j < size)
		{
			if (map[j].value < map[i].value)
			{
				tmp = map[j];
				map[j] = map[i];
				map[i] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	*normalize(int *tab, int size)
{
	t_map	*map;
	int		i;

	map = malloc(sizeof(t_map) * size);
	if (!map)
		return (NULL);
	init_map(tab, size, map);
	sort_by_value(map, size);
	i = 0;
	while (i < size)
	{
		tab[map[i].pos] = i;
		i++;
	}
	free(map);
	return (tab);
}
