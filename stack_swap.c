/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andelalo <andelalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:46:50 by andelalo          #+#    #+#             */
/*   Updated: 2025/12/15 15:00:39 by andelalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(t_stack *stack)
{
	int	top;
	int	b;

	if (stack->count >= 2)
	{
		top = pop(stack);
		b = pop(stack);
		push(stack, top);
		push(stack, b);
	}
}

void	sa(t_stack *a)
{
	if (a->count >= 2)
	{
		ft_swap(a);
		ft_printf("sa\n");
	}
}

void	sb(t_stack *b)
{
	if (b->count >= 2)
	{
		ft_swap(b);
		ft_printf("sb\n");
	}
}

void	ss(t_stack *a, t_stack *b)
{
	if (a->count >= 2 || b->count >= 2)
	{
		ft_swap(a);
		ft_swap(b);
		ft_printf("ss\n");
	}
}
