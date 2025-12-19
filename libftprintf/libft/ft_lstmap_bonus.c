/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andelalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:16:39 by andelalo          #+#    #+#             */
/*   Updated: 2025/11/14 10:33:15 by andelalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*fm(t_list *l, t_list *m, void *(*f)(void *), void (*d)(void *))
{
	t_list	*current;
	void	*content;

	current = m;
	l = l->next;
	while (l)
	{
		content = f(l->content);
		if (!content)
		{
			ft_lstclear(&m, d);
			return (NULL);
		}
		current->next = ft_lstnew(content);
		current = current->next;
		if (!current)
		{
			d(content);
			ft_lstclear(&m, d);
			return (NULL);
		}
		l = l->next;
	}
	return (m);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;
	void	*content;

	if (!lst)
		return (NULL);
	content = f(lst->content);
	if (!content)
		return (NULL);
	map = ft_lstnew(content);
	if (!map)
	{
		del(content);
		return (NULL);
	}
	return (fm(lst, map, f, del));
}
