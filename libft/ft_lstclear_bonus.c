/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-pin <pdel-pin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 14:37:51 by pdel-pin          #+#    #+#             */
/*   Updated: 2021/11/16 11:39:36 by pdel-pin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*p;

	if (lst && del && *lst)
	{
		while (*lst)
		{
			p = (*lst)-> next;
			ft_lstdelone(*lst, del);
			*lst = p;
		}
	}
}
