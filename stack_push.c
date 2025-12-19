/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 12:46:27 by mchiacha          #+#    #+#             */
/*   Updated: 2025/12/19 12:46:30 by mchiacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	int	tmp;

	if (b->count == 0)
		return ;
	tmp = pop(b);
	push(a, tmp);
	ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	int	tmp;

	if (a->count == 0)
		return ;
	tmp = pop(a);
	push(b, tmp);
	ft_printf("pb\n");
}
