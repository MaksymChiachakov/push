/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andelalo <andelalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:02:56 by andelalo          #+#    #+#             */
/*   Updated: 2025/12/16 14:57:22 by andelalo         ###   ########.fr       */
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
