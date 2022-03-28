/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauladelpinoramirez <pauladelpinoramire    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:22:56 by pauladelpin       #+#    #+#             */
/*   Updated: 2022/03/28 17:09:37 by pauladelpin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

//gives each node an index of position in the list
void	mapping(t_list **stack)
{
	int		i;
	int		count;
	t_list	*copy;
	t_list	*aux;

	i = 0;
	copy = *stack;
	while (copy)
	{
		aux = *stack;
		i = *copy->data;
		count = 0;
		while (aux)
		{
			if (*aux->data < i)
				count++;
			aux = aux->next;
		}
		free(aux);
		copy->index = count;
		copy = copy->next;
	}
}
