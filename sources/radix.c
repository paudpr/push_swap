#include <push_swap.h>

int binary_check(int data,  int bit)
{
	if(!data)
		return(0);
	printf("antes de: \n");
	printf("dta -> %d\n", data);
	printf("bit -> %d\n", bit);
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

	len = ft_lstsize(*stack_a);
	mapping(stack_a);
	if (check_sort(stack_a, main) == 1)
		return ;
	bit = 0;
	while((len - 1) >> bit != 0)
		bit++;
	printf("bit --> %d\n", bit);
	i = 0;
	while (i < bit && i < 1)
	{
		j = 0;
		while(j < len)
		{
			if(check_sort(stack_a, main) == 1) //si si está ordenado
				break;
			printf("dentro de radix \n");
			printf("%d\n", (stack_a[0]->index >> i));
			printf("%d\n", ((stack_a[0]->index >> i) & 1));
			if(((stack_a[0]->index >> i) & 1) == 1) //>> takes two numbers, right shifts the bits of the first operand, the second operand decides the number of places to shift
			{
				ft_rev_rotate(stack_a);
				printf("hago rev_rotate\n");
			}
			else
			{
				ft_push(stack_a, stack_b);
				printf("hago push a b\n");
			}
			j++;
	// printf("is sorted -> %d\n", check_sort(stack_a, main));	
	// printf("i --> %d\n", i);
	// printf("j --> %d\n", j);
	// show_list(*stack_a, 20);
	// show_list(*stack_b, 20);

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