/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andelalo <andelalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 10:09:01 by andelalo          #+#    #+#             */
/*   Updated: 2025/12/17 11:18:29 by andelalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort3(t_stack *stack_a)
{
	int	a;
	int	b;
	int	c;

	a = stack_a->tab[stack_a->bottom + 2];
	b = stack_a->tab[stack_a->bottom + 1];
	c = stack_a->tab[stack_a->bottom];
	if (a > b && b > c)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (b > a && a > c)
		rra(stack_a);
	else if (a > c && c > b)
		ra(stack_a);
	else if (c > a && a > b)
		sa(stack_a);
	else if (b > c && c > a)
	{
		sa(stack_a);
		ra(stack_a);
	}
}

static void	radix(t_stack *a, t_stack *b, int i_digit)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = a->count;
	while (i < cnt)
	{
		if ((peek(a) >> i_digit) & 1)
			ra(a);
		else
			pb(a, b);
		i++;
	}
}

static int	nb_digit_base2(int n)
{
	if (n == 0 || n == 1)
		return (1);
	return (1 + nb_digit_base2(n / 2));
}

static bool	is_ordered(t_stack a)
{
	int	prev;
	int	curr;

	prev = pop(&a);
	while (a.count)
	{
		curr = pop(&a);
		if (prev > curr)
			return (false);
		prev = curr;
	}
	return (true);
}

void	ft_push_swap(t_stack a, t_stack b)
{
	int	i_digit;

	if (is_ordered(a))
		return ;
	a.tab = normalize(a.tab, a.size);
	i_digit = nb_digit_base2(a.size) - 1;
	while (i_digit > 2)
		radix(&a, &b, i_digit--);
	greedy_sort(&a, &b);
}
