/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andelalo <andelalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:03:15 by andelalo          #+#    #+#             */
/*   Updated: 2025/12/16 16:56:44 by andelalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

int	ft_min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

int	find_value(t_stack a, t_stack b, t_rotations *r_min)
{
	int			i;
	int			min_cost;
	t_rotations	r;
	int			cost;
	int			value;

	i = 0;
	min_cost = INT32_MAX;
	while (i < b.count)
	{
		r = UP_UP;
		cost = get_cost(a, b, b.tab[(b.bottom + i) % b.size], &r);
		if (cost < min_cost)
		{
			min_cost = cost;
			*r_min = r;
			value = b.tab[(b.bottom + i) % b.size];
		}
		i++;
	}
	return (value);
}

void	rotate_ascending_order(t_stack *a)
{
	int	i;

	i = get_index(*a, 0);
	if (i <= a->count / 2)
	{
		while (i--)
			ra(a);
	}
	else
	{
		while (i++ < a->count)
			rra(a);
	}
}
