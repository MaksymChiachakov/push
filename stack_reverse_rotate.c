/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andelalo <andelalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:12:30 by andelalo          #+#    #+#             */
/*   Updated: 2025/12/15 15:00:19 by andelalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_rotate_left(t_stack *stack)
{
	stack->tab[stack->top] = stack->tab[stack->bottom];
	stack->top = (stack->top + 1) % stack->size;
	stack->bottom = (stack->bottom + 1) % stack->size;
}

void	rra(t_stack *a)
{
	if (a->count > 1)
	{
		stack_rotate_left(a);
		ft_printf("rra\n");
	}
}

void	rrb(t_stack *b)
{
	if (b->count > 1)
	{
		stack_rotate_left(b);
		ft_printf("rrb\n");
	}
}

void	rrr(t_stack *a, t_stack *b)
{
	if (a->count > 1 || b->count > 1)
	{
		stack_rotate_left(a);
		stack_rotate_left(b);
		ft_printf("rrr\n");
	}
}
