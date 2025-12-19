/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 12:47:39 by mchiacha          #+#    #+#             */
/*   Updated: 2025/12/19 12:47:41 by mchiacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	pa_check(t_stack *a, t_stack *b)
{
	int	tmp;

	if (b->count == 0)
		return ;
	tmp = pop(b);
	push(a, tmp);
}

void	pb_check(t_stack *a, t_stack *b)
{
	int	tmp;

	if (a->count == 0)
		return ;
	tmp = pop(a);
	push(b, tmp);
}
