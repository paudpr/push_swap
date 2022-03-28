/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauladelpinoramirez <pauladelpinoramire    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:22:49 by pauladelpin       #+#    #+#             */
/*   Updated: 2022/03/28 17:07:37 by pauladelpin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

//counts number of items in list and creates a linked list node with each item
t_list	*init_list(int *nums, int len)
{
	t_list	*stack_a;
	int		i;

	stack_a = ft_lstnew_pw(&nums[0], 0);
	i = 1;
	while (i < len)
	{
		ft_lstadd_back(&stack_a, ft_lstnew_pw(&nums[i], 0));
		i++;
	}
	return (stack_a);
}
