/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauladelpinoramirez <pauladelpinoramire    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:52:47 by pdel-pin          #+#    #+#             */
/*   Updated: 2022/03/17 14:14:53 by pauladelpin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_elem;

	if (!lst || !f)
		return (0);
	new_lst = 0;
	while (lst != 0)
	{
		new_elem = ft_lstnew(f(lst -> data));
		if (!new_elem)
		{
			ft_lstclear(&new_lst, del);
			return (0);
		}
		ft_lstadd_back(&new_lst, new_elem);
		lst = lst -> next;
	}
	return (new_lst);
}

t_list	*ft_lstmap_pw(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_elem;

	if (!lst || !f)
		return (0);
	new_lst = 0;
	while (lst != 0)
	{
		new_elem = ft_lstnew_pw(f(lst -> data));
		if (!new_elem)
		{
			ft_lstclear(&new_lst, del);
			return (0);
		}
		ft_lstadd_back(&new_lst, new_elem);
		lst = lst -> next;
	}
	return (new_lst);
}