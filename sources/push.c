/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauladelpinoramirez <pauladelpinoramire    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:23:09 by pauladelpin       #+#    #+#             */
/*   Updated: 2022/03/28 14:23:10 by pauladelpin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

//take the first element of one stack to the top of the other stack
void	ft_push(t_list **stack_orig, t_list **stack_dest)
{
	t_list	*copy;

	if (stack_orig == NULL)
		return ;
	copy = *stack_orig;
	if (*stack_dest == NULL)
	{
		*stack_dest = ft_lstnew_pw(stack_orig[0]->data, stack_orig[0]->index);
		*stack_orig = copy->next;
	}
	else
	{
		ft_lstadd_front(stack_dest, ft_lstnew_pw(stack_orig[0]->data,
				stack_orig[0]->index));
		*stack_orig = copy->next;
	}
	free(copy);
}

void	do_push(t_list **stack_a, t_list **stack_b, t_values *main, int type)
{
	if (!stack_a || !stack_b)
		return ;
	if (type == 0)
	{
		ft_push(stack_a, stack_b);
		write(1, "pb\n", 3);
		main->size_a -= 1;
		main->size_b += 1;
	}
	else if (type == 1)
	{
		ft_push(stack_b, stack_a);
		write(1, "pa\n", 3);
		main->size_b -= 1;
		main->size_a += 1;
	}
}
