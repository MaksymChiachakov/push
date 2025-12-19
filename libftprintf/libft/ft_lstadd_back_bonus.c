/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andelalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:10:26 by andelalo          #+#    #+#             */
/*   Updated: 2025/11/13 15:53:59 by andelalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (new)
	{
		if (!*lst)
			*lst = new;
		else
		{
			last = ft_lstlast(*lst);
			last->next = new;
		}
	}
}

/*
int	main(void)
{
	t_list	*lst;
	t_list	*cur;

	lst = NULL;
	ft_lstadd_back(&lst, ft_lstnew("test1"));
	ft_lstadd_back(&lst, ft_lstnew("test2"));
	ft_lstadd_back(&lst, ft_lstnew("test3"));
	ft_lstadd_back(&lst, NULL);
	cur = lst
	while (cur)
	{
		ft_putendl_fd(cur->content, 1);
		cur = cur->next;
	}
	return (0);
}
*/
