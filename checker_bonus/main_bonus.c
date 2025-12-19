/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 12:47:33 by mchiacha          #+#    #+#             */
/*   Updated: 2025/12/19 12:47:35 by mchiacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	free_args(t_args args)
{
	int	i;

	if (args.free_args)
	{
		i = 0;
		while (args.av[i])
		{
			free(args.av[i]);
			i++;
		}
		free(args.av);
	}
}

int	nb_param(char **av)
{
	int	n;

	n = 0;
	while (av[n])
		n++;
	return (n);
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	t_args	args;

	if (ac == 1)
		return (0);
	args.av = av + 1;
	args.free_args = false;
	if (ac == 2)
	{
		args.av = ft_split(av[1], ' ');
		if (!args.av)
			ft_put_error(NULL, NULL, args);
		args.free_args = true;
		if (nb_param(args.av) == 0)
			ft_put_error(NULL, NULL, args);
		stack_init(nb_param(args.av), args, &a, &b);
		free_args(args);
	}
	else
		stack_init(--ac, args, &a, &b);
	ft_checker(&a, &b);
	free_stacks(&a, &b);
	return (0);
}
