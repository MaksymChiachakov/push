/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andelalo <andelalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:02:56 by andelalo          #+#    #+#             */
/*   Updated: 2025/12/09 15:07:25 by andelalo         ###   ########.fr       */
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
