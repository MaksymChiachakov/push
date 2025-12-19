/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 12:47:21 by mchiacha          #+#    #+#             */
/*   Updated: 2025/12/19 12:47:25 by mchiacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	print_error(t_stack *a, t_stack *b, t_list *lst)
{
	free_stacks(a, b);
	ft_lstclear(&lst, free);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

static t_list	*get_input(void)
{
	t_list	*head;
	t_list	*new;
	char	*line;
	int		fd;

	fd = 0;
	line = get_next_line(fd);
	if (!line)
		return (0);
	head = NULL;
	while (line)
	{
		new = ft_lstnew(line);
		if (!new)
		{
			free(line);
			ft_lstclear(&head, free);
			return (0);
		}
		ft_lstadd_back(&head, new);
		line = get_next_line(fd);
	}
	return (head);
}

static void	execute_input(t_stack *a, t_stack *b, t_list *lst, t_list *head)
{
	if (ft_strncmp(lst->content, "pa\n", 3) == 0)
		pa_check(a, b);
	else if (ft_strncmp(lst->content, "pb\n", 3) == 0)
		pb_check(a, b);
	else if (ft_strncmp(lst->content, "ra\n", 3) == 0)
		ra_check(a);
	else if (ft_strncmp(lst->content, "rb\n", 3) == 0)
		rb_check(b);
	else if (ft_strncmp(lst->content, "rr\n", 3) == 0)
		rr_check(a, b);
	else if (ft_strncmp(lst->content, "rra\n", 4) == 0)
		rra_check(a);
	else if (ft_strncmp(lst->content, "rrb\n", 4) == 0)
		rrb_check(b);
	else if (ft_strncmp(lst->content, "rrr\n", 4) == 0)
		rrr_check(a, b);
	else if (ft_strncmp(lst->content, "sa\n", 3) == 0)
		sa_check(a);
	else if (ft_strncmp(lst->content, "sb\n", 3) == 0)
		sb_check(b);
	else if (ft_strncmp(lst->content, "ss\n", 3) == 0)
		ss_check(a, b);
	else
		print_error(a, b, head);
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

void	ft_checker(t_stack *a, t_stack *b)
{
	t_list	*lst;
	t_list	*current;

	lst = get_input();
	current = lst;
	while (current)
	{
		execute_input(a, b, current, lst);
		current = current->next;
	}
	ft_lstclear(&lst, free);
	if (b->count)
	{
		ft_printf("KO\n");
		return ;
	}
	if (is_ordered(*a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
