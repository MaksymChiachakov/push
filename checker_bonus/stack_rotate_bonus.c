/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andelalo <andelalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:29:31 by andelalo          #+#    #+#             */
/*   Updated: 2025/12/16 15:27:00 by andelalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	stack_rotate_right(t_stack *stack)
{
	stack->bottom--;
	if (stack->bottom < 0)
		stack->bottom = stack->size - 1;
	stack->top--;
	if (stack->top < 0)
		stack->top = stack->size - 1;
	stack->tab[stack->bottom] = stack->tab[stack->top];
}

void	ra_check(t_stack *a)
{
	if (a->count > 1)
		stack_rotate_right(a);
}

void	rb_check(t_stack *b)
{
	if (b->count > 1)
		stack_rotate_right(b);
}

void	rr_check(t_stack *a, t_stack *b)
{
	if (a->count > 1 || b->count > 1)
	{
		stack_rotate_right(a);
		stack_rotate_right(b);
	}
}
