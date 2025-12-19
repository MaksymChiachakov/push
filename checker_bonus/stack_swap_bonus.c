/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 12:48:13 by mchiacha          #+#    #+#             */
/*   Updated: 2025/12/19 12:48:15 by mchiacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

void	sa_check(t_stack *a)
{
	if (a->count >= 2)
	{
		ft_swap(a);
	}
}

void	sb_check(t_stack *b)
{
	if (b->count >= 2)
	{
		ft_swap(b);
	}
}

void	ss_check(t_stack *a, t_stack *b)
{
	if (a->count >= 2 || b->count >= 2)
	{
		ft_swap(a);
		ft_swap(b);
	}
}
