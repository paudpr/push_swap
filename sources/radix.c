#include <push_swap.h>

int binary_check(int data,  int bit)
{
	if(!data)
		return(0);
	// printf("antes de: \n");
	// printf("dta -> %d\n", data);
	// printf("bit -> %d\n", bit);
	data >>= bit;
	printf("\ndespues de: \n");
	printf("dta -> %d\n", data);
	printf("bit -> %d\n", bit);
	if(data & 1)
		return(1);
	else
		return(0);
}

// void radix(t_list **stack_a, t_list **stack_b, t_values *main)
// {
// 	int i;
// 	int bit;
// 	int len;

// 	len = ft_lstsize(*stack_a);
// 	mapping(stack_a);
// 	if (check_sort(stack_a, main) == 1)
// 		return ;
// 	bit = 0;

// }



void radix(t_list **stack_a, t_list **stack_b, t_values *main)
{
	int len;
	int bit;
	int i;
	int j;
	t_list *copy;

	copy = *stack_a;
	len = ft_lstsize(*stack_a);
	mapping(stack_a);
	if (check_sort(stack_a, main) == 1)
		return ;
	bit = 0;
	while((len - 1) >> bit != 0)
		bit++;
	printf("bit --> %d\n", bit);
	i = 0;
	while (i < bit)
	{
		j = 0;
		while(j < len)
		{
			if(check_sort(stack_a, main) == 1) //si si está ordenado
				break;
			if(((stack_a[0]->index >> i) & 1) == 1) //  >> takes two numbers, right shifts the bits of the first operand, the second operand decides the number of places to shift
			{
				ft_rotate(stack_a);
				printf("hago rev_rotate\n\n");
			}
			else
			{
				ft_push(stack_a, stack_b);
				printf("hago push a b\n\n");
			}
			printf("%d\n", len);
			j++;
		}
		while(ft_lstsize(*stack_b) != 0)
			ft_push(stack_b, stack_a);
		i++;
	printf("\nFIN DE CICLO\n\n");
	}
}





/*
	while(check_sort(stack_a, main != 1))
	{
		sort_radix(stack_a, stack_b, main, &bit);
		while(ft_lstsize(stack_b) != 0)
			ft_push(stack_b, stack_a);
		bit++;
	}
	ft_push(stack_b, stack_a);
}*/

/*
void sort_radix(t_list **stack_a, t_list **stack_b, t_values *main, int bit)
{
	t_list *copy;

	copy = *stack_a;
	if (binary(copy->data, bit) == 0)
	{
		copy = copy->next;
		ft_push(*stack_a, *stack_b);
	}
	else
		copy = copy->next;
		ft_rev_rotate(stack_a);
}*/













t_list	*ft_new_stack(void *content, size_t size)
{
	t_list	*stack;
	void	*aux;

	stack = malloc(sizeof(t_list));
	if (!stack)
		return (NULL);
	aux = malloc(size);
	if (!aux)
	{
		free(stack);
		stack = NULL;
	}
	ft_memcpy(aux, content, size);
	stack->data = aux;
	stack->next = NULL;
	return (stack);
}

void	delete_node(t_list **stack)
{
	t_list	*aux;

	aux = *stack;
	*stack = (*stack)->next;
	free(aux->data);
	free(aux);
}

/* If there's no list, creates it and adds the first value
if it already exists, adds it to the top */

void	push(t_list **stack, int n)
{
	if (!stack)
		*stack = ft_new_stack((void *) &n, sizeof(int));
	else
		ft_lstadd_front(stack, ft_new_stack((void *) &n, sizeof(int)));
}

/* Executes push_a or push_b depending on the parameter
passed in char, then deletes the node from the original
stack */

void	ft_durante_push(t_list **a, t_list **b, char c)
{
	int	n;

	if (c == 'a')
	{
		if (*b)
		{
			n = *(int *)(*b)->data;
			push(a, n);
			delete_node(b);
			write(1, "pa\n", 3);
		}
	}
	if (c == 'b')
	{
		if (*a)
		{
			n = *(int *)(*a)->data;
			push(b, n);
			delete_node(a);
			write(1, "pb\n", 3);
		}
	}
}

int	rotate(t_list **stack)
{
	t_list	*first;

	if (*stack == NULL || ft_lstsize(*stack) < 2)
		return (0);
	first = *stack;
	*stack = first->next;
	ft_lstlast(*stack)->next = first;
	first->next = NULL;
	return (1);
}

/* Calls rotate and executes ra, rb or rr 
depending on the char we passed as parameter
when we called it */

void	ft_durante_rotate(t_list **a, t_list **b, char c)
{
	if (c == 'a')
	{
		if (rotate(a))
			write(1, "ra\n", 3);
	}
	if (c == 'b')
	{
		if (rotate(b))
			write(1, "rb\n", 3);
	}
	if (c == 'r')
	{
		if (rotate(a) && rotate(b))
			write(1, "rr\n", 3);
	}
}

void	sort_big_stack(t_list **a, t_list **b, int length, t_values *main)
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
			if (check_sort(a, main))
				break ;
			n = (*a)->index;
			if (((n >> i) & 1) == 1)
				ft_durante_rotate(a, b, 'a');
			else
				ft_durante_push(a, b, 'b');
		}
		while (*b)
			ft_durante_push(a, b, 'a');
	}
}

