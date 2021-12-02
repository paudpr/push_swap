/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-pin <pdel-pin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:01:34 by pdel-pin          #+#    #+#             */
/*   Updated: 2021/12/02 14:03:25 by pdel-pin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int *data)
{
	t_list	*a;

	a = malloc(sizeof(t_list));
	if (a == NULL)
		return (0);
	a -> data = data;
	a -> next = 0;
	return (a);
}
