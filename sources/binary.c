#include <push_swap.h>

int	ft_binary(int content, int bit)
{
	if (!content)
		return (1);
	content >>= bit;
	if (content & 1)
		return (0);
	else
		return (1);
}

void	ft_check_binary(int num, int *pos, t_list **sa, t_list **sb)
{
	t_list	*temp;

	temp = *sa;
	if (ft_binary(temp->content, *pos) == 1)
	{
		temp = temp->next;
		ft_push(sa, sb, num, 1);
	}
	else
	{
		temp = temp->next;
		ft_rotate_up(sa, num, 0);
	}
}

static void	ft_6radix(t_list **stack_a, t_list **stack_b, int num)
{
	int		i;
	int		pos;

	i = 0;
	pos = 0;
	if (is_sorted(stack_a, num) == 0)
		exit(0);
	while (is_sorted(stack_a, num) != 0 || ft_lstsize(*stack_a) != num)
	{
		ft_check_binary(num, &pos, stack_a, stack_b);
		if (i == num - 1)
		{
			while (ft_lstsize(*stack_b) != 0)
				ft_push(stack_b, stack_a, num, 0);
			pos++;
			i = -1;
		}
		i++;
	}
}









#include "../includes/push_swap.h"

/* Executes the algorithm "Radix sort" using the bitwise operators
>> and &. We take multiples of two and pass them to b while rotating 
the others, then bring them back to a and right-shift the first bit
and start again. */

void	sort_big_stack(t_list **a, t_list **b, int length)
{
	int	bits;
	int	n;
	int	i;
	int	j;

	bits = 0;
	while ((length - 1) >> bits != 0)
		bits++;
	i = -1;
	while (++i < bits)
	{
		j = -1;
		while (++j < length)
		{
			if (is_sorted(a, ft_lstsize(*a)))
				break ;
			n = *(int *)(*a)->content;
			if (((n >> i) & 1) == 1)
				ft_rotate(a, b, 'a');
			else
				ft_push(a, b, 'b');
		}
		while (*b)
			ft_push(a, b, 'a');
	}
}