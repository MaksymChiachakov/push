/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andelalo <andelalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 13:05:41 by andelalo          #+#    #+#             */
/*   Updated: 2025/12/15 15:00:57 by andelalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_up_up(t_stack *a, t_stack *b, int pos_target, int pos_value)
{
	while (pos_target && pos_value)
	{
		rr(a, b);
		pos_value--;
		pos_target--;
	}
	while (pos_target)
	{
		ra(a);
		pos_target--;
	}
	while (pos_value)
	{
		rb(b);
		pos_value--;
	}
}

void	rotate_down_down(t_stack *a, t_stack *b, int pos_target, int pos_value)
{
	while (pos_target < a->count && pos_value < b->count)
	{
		rrr(a, b);
		pos_target++;
		pos_value++;
	}
	while (pos_target < a->count)
	{
		rra(a);
		pos_target++;
	}
	while (pos_value < b->count)
	{
		rrb(b);
		pos_value++;
	}
}

void	rotate_up_down(t_stack *a, t_stack *b, int pos_target, int pos_value)
{
	while (pos_target)
	{
		ra(a);
		pos_target--;
	}
	while (pos_value < b->count)
	{
		rrb(b);
		pos_value++;
	}
}

void	rotate_down_up(t_stack *a, t_stack *b, int pos_target, int pos_value)
{
	while (pos_target < a->count)
	{
		rra(a);
		pos_target++;
	}
	while (pos_value)
	{
		rb(b);
		pos_value--;
	}
}
