/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 18:49:25 by oait-si-          #+#    #+#             */
/*   Updated: 2024/11/16 19:15:47 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstmap_create_elem(t_list *lst, void *(*f)(void *),
												void (*del)(void *))
{
	t_list	*new_elem;
	void	*content;

	content = f(lst->content);
	if (!content)
		return (NULL);
	new_elem = ft_lstnew(content);
	if (!new_elem)
	{
		del(content);
		return (NULL);
	}
	return (new_elem);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_elem;

	if (!lst || !f)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_elem = ft_lstmap_create_elem(lst, f, del);
		if (!new_elem)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_elem);
		lst = lst->next;
	}
	return (new_list);
}
