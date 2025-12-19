/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 12:46:33 by mchiacha          #+#    #+#             */
/*   Updated: 2025/12/19 12:46:36 by mchiacha         ###   ########.fr       */
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
