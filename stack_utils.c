/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 12:46:55 by mchiacha          #+#    #+#             */
/*   Updated: 2025/12/19 12:46:57 by mchiacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(int cnt, t_args args, t_stack *stack_a, t_stack *stack_b)
{
	stack_a->tab = malloc(sizeof(int) * cnt);
	if (!stack_a->tab)
		ft_put_error(NULL, NULL, args);
	stack_b->tab = malloc(sizeof(int) * cnt);
	if (!stack_b->tab)
		ft_put_error(stack_a, NULL, args);
	stack_a->count = 0;
	stack_a->size = cnt;
	stack_a->bottom = 0;
	stack_a->top = 0;
	stack_b->count = 0;
	stack_b->size = cnt;
	stack_b->bottom = 0;
	stack_b->top = 0;
	while (cnt)
	{
		cnt--;
		if (!is_valid_int(args.av[cnt]))
			ft_put_error(stack_a, stack_b, args);
		else if (is_in_stack(*stack_a, ft_atoi(args.av[cnt])))
			ft_put_error(stack_a, stack_b, args);
		push(stack_a, ft_atoi(args.av[cnt]));
	}
}

void	print_stacks(t_stack a, t_stack b)
{
	int	cnt;

	cnt = a.count;
	if (cnt < b.count)
		cnt = b.count;
	while (cnt > 0)
	{
		if (a.count >= cnt)
			ft_printf("%d", pop(&a));
		else
			ft_printf(" ");
		ft_printf(" ");
		if (b.count >= cnt)
		{
			ft_printf("%d", pop(&b));
		}
		ft_printf("\n");
		cnt--;
	}
	ft_printf("a b\n\n");
}

void	push(t_stack *stack, int x)
{
	stack->tab[stack->top] = x;
	stack->top = (stack->top + 1) % stack->size;
	stack->count++;
}

int	pop(t_stack *stack)
{
	stack->top--;
	if (stack->top < 0)
		stack->top = stack->size - 1;
	stack->count--;
	return (stack->tab[stack->top]);
}

int	peek(t_stack *stack)
{
	if (stack->top - 1 < 0)
		return (stack->tab[stack->size - 1]);
	return (stack->tab[stack->top - 1]);
}
