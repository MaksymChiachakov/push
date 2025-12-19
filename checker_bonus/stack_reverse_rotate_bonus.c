/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_reverse_rotate_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 12:47:46 by mchiacha          #+#    #+#             */
/*   Updated: 2025/12/19 12:47:48 by mchiacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	stack_rotate_left(t_stack *stack)
{
	stack->tab[stack->top] = stack->tab[stack->bottom];
	stack->top = (stack->top + 1) % stack->size;
	stack->bottom = (stack->bottom + 1) % stack->size;
}

void	rra_check(t_stack *a)
{
	if (a->count > 1)
		stack_rotate_left(a);
}

void	rrb_check(t_stack *b)
{
	if (b->count > 1)
		stack_rotate_left(b);
}

void	rrr_check(t_stack *a, t_stack *b)
{
	if (a->count > 1 || b->count > 1)
	{
		stack_rotate_left(a);
		stack_rotate_left(b);
	}
}
