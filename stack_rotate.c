/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 12:46:41 by mchiacha          #+#    #+#             */
/*   Updated: 2025/12/19 12:46:44 by mchiacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ra(t_stack *a)
{
	if (a->count > 1)
	{
		stack_rotate_right(a);
		ft_printf("ra\n");
	}
}

void	rb(t_stack *b)
{
	if (b->count > 1)
	{
		stack_rotate_right(b);
		ft_printf("rb\n");
	}
}

void	rr(t_stack *a, t_stack *b)
{
	if (a->count > 1 || b->count > 1)
	{
		stack_rotate_right(a);
		stack_rotate_right(b);
		ft_printf("rr\n");
	}
}
