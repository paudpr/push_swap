#include <push_swap.h>

void sort_2_3(t_list **stack, t_values *main)
{
	int i;

	if(!stack)
		return ;
	i = ft_lstsize(*stack);
	if(i < 3)
	{
		if(check_sort(stack, main) == 0)
			ft_swap(stack, 0, main);
		return ;
	}
	while(check_sort(stack, main) == 0)
	{
		if(*stack[0]->data > *stack[0]->next->data &&
			*stack[0]->data > *stack[0]->next->next->data &&
			*stack[0]->next->data < *stack[0]->next->next->data)
			ft_rotate(stack);
		else if (*stack[0]->data > *stack[0]->next->data ||
			*stack[0]->data < *stack[0]->next->next->data)
			ft_swap(stack, 0, main);
		else if(*stack[0]->data < *stack[0]->next->data &&
			*stack[0]->data > *stack[0]->next->next->data)
			ft_rev_rotate(stack);
	}
}


void sort_2_3_short(t_list **stack, t_values *main)
{
	int i;

	if(!stack)
		return ;
	i = ft_lstsize(*stack);
	if(i < 3)
	{
		if(check_sort(stack, main) == 1)
			ft_swap(stack, 0, main);
		return ;
	}
	printf("++++++++++++++++++++++\n");
	show_list(*stack, 5);
	printf("++++++++++++++++++++++\n");
	printf("orden -> %d\n", check_sort(stack, main));
	if(check_sort(stack, main) == 0)
	{
		show_list(*stack, 10);
		if (*stack[0]->data > *stack[0]->next->data ||
			*stack[0]->data < *stack[0]->next->next->data)
			ft_swap(stack, 0, main);
	}
	show_list(*stack, 10);
	// if(*stack[0]->data < *stack[0]->next->data)
	// 	ft_rev_rotate(stack);
}



void sort_4_5(t_list **stack_a, t_list **stack_b, t_values *main)
{
	int i;
	// t_list *aux;

	if(!stack_a)
		return ;
	i = ft_lstsize(*stack_a);
	printf("i ----> %d\n", i);
	if(i == 5)
		ft_push(stack_a, stack_b);
	ft_push(stack_a, stack_b);

	show_list(*stack_a, 5);
	printf("-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n\n");
	show_list(*stack_b, 5);


	sort_2_3_short(stack_a, main);
	show_list(*stack_a, 10);
	show_list(*stack_b, 10);
	printf("hasta aqui todo bien\n");

	printf("b ----> %d\n", *stack_b[0]->data);
	printf("a ----> %d\n", *stack_a[0]->data);
	i = ft_lstsize(*stack_b);
	// aux = *stack_b;
	while(i > 0)
	{
		printf("bucle\n");
		if(*stack_b[0]->data < *stack_a[0]->data)
		{
			printf("1\n");
			ft_push(stack_b, stack_a);
			i--;
			printf("i ----> %d\n", i);
		}
		else
		{
			printf("2\n");
			ft_rev_rotate(stack_a);
			ft_push(stack_b, stack_a);
			i--;
		}
		show_list(*stack_a, 10);
	}
	if (check_sort(stack_a, main) != 1)
	{
		printf("ahgo ft_rev_rotate\n");
		ft_rev_rotate(stack_a);
	}
	

	printf("\n\nterminado bucle\n\n");
	// if(check_sort(stack_b, main) == 1 && ft_lstsize(*stack_b) != 1)
	// {
	// 	printf("\n de aqui -----> \n\n");
	// 	ft_swap(stack_b, 1, main);
	// 	show_list(*stack_b, 10);
	// 	printf("\n hasta aqui -----> \n\n");
	// }
	
	// show_list(*stack_a, i);
	// printf("b\n\n");
	//show_list(*stack_b, i);
	// printf("size_b -> %d\n", main->size_b);
	// show_list(*stack_a, 7);
	
	printf("dfghjkhgfdsdfghjgfdxdcvbnmbvcxvbnbvcxcvbnbvcxcvbvc\n\n");

	// //poner bien la cuenta de movimientos o esto no sale :(   )
	// while(main->size_b != 0)
	// {
	// 	if(stack_a[0]->data < stack_b[0]->data)
	// 	{
	// 		printf("%d\n", *stack_a[0]->data);
	// 		printf("%d\n", *stack_b[0]->data);
	// 		printf("entro\n");
	// 		ft_rev_rotate(stack_a);
	// 	}
	// 	ft_push(stack_b, stack_a);
	// 	main->size_b--;
	// }


	show_list(*stack_a, 5);


	// show_list(*stack_a, main->size_a);



}