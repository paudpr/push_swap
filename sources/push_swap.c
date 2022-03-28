/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauladelpinoramirez <pauladelpinoramire    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:23:06 by pauladelpin       #+#    #+#             */
/*   Updated: 2022/03/28 14:23:07 by pauladelpin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	push_swap(t_list **stack_a, t_list **stack_b, t_values *main)
{
	unsigned int	i;

	i = ft_lstsize(*stack_a);
	mapping(stack_a);
	if (i != main->size_g || main->size_a != main->size_g)
		print_error();
	if (check_sort(stack_a, main) == 1)
		return ;
	if (main->size_a < 1)
		return ;
	else if (main->size_a == 2 && check_sort(stack_a, main) == 0)
		ft_swap(stack_a, 0);
	else if (main->size_a < 4 && main->size_a > 2)
		sort_2_3(stack_a, main);
	else if (main->size_a < 6 && main->size_a > 3)
		sort_4_5(stack_a, stack_b, main);
	else if (main->size_a > 5)
		radix(stack_a, stack_b, main);
}
