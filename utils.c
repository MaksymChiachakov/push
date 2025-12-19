/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andelalo <andelalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:59:06 by andelalo          #+#    #+#             */
/*   Updated: 2025/12/16 13:54:22 by andelalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stacks(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a)
		free(stack_a->tab);
	if (stack_b)
		free(stack_b->tab);
}

void	ft_put_error(t_stack *stack_a, t_stack *stack_b, t_args args)
{
	free_stacks(stack_a, stack_b);
	free_args(args);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

bool	is_valid_int(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (str[i] == '\0')
		return (false);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	if (str[0] == '-' && ft_strlen(str) >= 11)
	{
		if (ft_strlen(str) > 11 || ft_strncmp("-2147483648", str, 11) < 0)
			return (false);
	}
	if (str[0] != '-' && ft_strlen(str) >= 10)
	{
		if (ft_strlen(str) > 10 || ft_strncmp("2147483647", str, 10) < 0)
			return (false);
	}
	return (true);
}

bool	is_in_stack(t_stack stack, int x)
{
	while (stack.count)
	{
		if (pop(&stack) == x)
			return (true);
	}
	return (false);
}
