#include <push_swap.h>

//take the first element of one stack to the top of the other stack
/*comprobación que el stack del que viene el elemento no es nulo. 
caso_1: si el stack que recibe está vacío, el stack es igual al nodo que movemos.
casp_2: si el stack que recibe no está vacío, */

void ft_push(t_list *stack_orig, t_list *stack_dest, t_values *main)
{
	t_list *copy;
	t_list *aux;

	if (stack_orig == NULL)
		return ;
	copy = stack_orig;
	if(stack_dest == NULL)
	{
		stack_dest = ft_lstnew(copy->data);
		aux = copy->next;
		stack_orig = aux;
		ft_free(&copy, *main, 2);
	}
	else
	{
		ft_lstadd_front(&stack_dest, ft_lstnew(stack_orig[0].data));
		aux = copy->next;
		stack_orig = aux;
		ft_free(&copy, *main, 2);

		// show_list(stack_orig, ft_lstsize(stack_orig));
		//show_list(copy, ft_lstsize(copy));

		
	}
}

/*
void do_push(t_list *stack_orig, t_list *stack_dest, int type, t_values *main)
{
	if(!stack_orig)
		return ;
	if (type == 0)
	{
		ft_push(stack_orig, stack_dest);
		main->size_a--;
		main->size_b++;
		write(1, "pa\n", 3);
	}
	if (type == 1)
	{
		ft_push(stack_orig, stack_dest);
		main->size_b++;
		main->size_a--;
		write(1, "pb\n", 3);
	}
	// if(main->size_a + main->size_b != main->size_g)
	// 	print_error();
}
*/


/*
printf("\n\n");
	printf("stack_orig.adress ----> %p\n", &stack_orig);
	printf("stack_orig.adress ----> %p\n", &stack_orig[1]);
	printf("stack_orig.data ----> %d\n", *stack_orig->data);
	printf("stack_orig.data ----> %d\n", *stack_orig[1].data);

	printf("stack_dest.adress ----> %p\n", &stack_dest);
	printf("copy.adress ----> %p\n", &copy);
	printf("copy.data ----> %d\n", *copy->data);
	printf("copy.next ----> %p\n", copy->next);
	printf("\n\n");


		show_list(copy, ft_lstsize(copy));
		show_list(stack_dest, ft_lstsize(stack_dest));
		show_list(stack_orig, ft_lstsize(stack_orig));

	*/


//

// printf("\n\n--------\n\n");