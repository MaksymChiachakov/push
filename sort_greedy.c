/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_greedy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 12:46:10 by mchiacha          #+#    #+#             */
/*   Updated: 2025/12/19 12:46:16 by mchiacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(t_stack stack, int value)
{
	int	i;

	i = 0;
	while (stack.count)
	{
		if (pop(&stack) == value)
			return (i);
		i++;
	}
	return (0);
}

static int	get_target(t_stack a, int value)
{
	int		target;
	int		min;
	int		top;
	bool	target_found;

	target = INT32_MAX;
	min = INT32_MAX;
	target_found = false;
	while (a.count)
	{
		top = pop(&a);
		if (value < top && top <= target)
		{
			target = top;
			target_found = true;
		}
		if (top < min)
			min = top;
	}
	if (target_found)
		return (target);
	return (min);
}

int	get_cost(t_stack a, t_stack b, int value, t_rotations *r)
{
	int	cost;
	int	target;
	int	pos_value;
	int	pos_target;

	target = get_target(a, value);
	pos_value = get_index(b, value);
	pos_target = get_index(a, target);
	cost = ft_max(pos_target, pos_value);
	if (ft_max(a.count - pos_target, b.count - pos_value) < cost)
	{
		cost = ft_max(a.count - pos_target, b.count - pos_value);
		*r = DOWN_DOWN;
	}
	if (pos_target + b.count - pos_value < cost)
	{
		cost = pos_target + b.count - pos_value;
		*r = UP_DOWN;
	}
	if (pos_value + a.count - pos_target < cost)
	{
		cost = pos_value + a.count - pos_target;
		*r = DOWN_UP;
	}
	return (cost);
}

static void	push_value_to_a(t_stack *a, t_stack *b, int value, t_rotations r)
{
	int	target;
	int	pos_value;
	int	pos_target;

	target = get_target(*a, value);
	pos_value = get_index(*b, value);
	pos_target = get_index(*a, target);
	if (r == UP_UP)
		rotate_up_up(a, b, pos_target, pos_value);
	else if (r == DOWN_DOWN)
		rotate_down_down(a, b, pos_target, pos_value);
	else if (r == UP_DOWN)
		rotate_up_down(a, b, pos_target, pos_value);
	else
		rotate_down_up(a, b, pos_target, pos_value);
	pa(a, b);
}

void	greedy_sort(t_stack *a, t_stack *b)
{
	int			value;
	t_rotations	r_min;

	while (a->count > 3)
		pb(a, b);
	sort3(a);
	while (b->count)
	{
		r_min = UP_UP;
		value = find_value(*a, *b, &r_min);
		push_value_to_a(a, b, value, r_min);
	}
	rotate_ascending_order(a);
}
