#include <push_swap.h>

//take the first element of one stack to the top of the other stack
/*comprobación que el stack del que viene el elemento no es nulo. 
caso_1: si el stack que recibe está vacío, el stack es igual al nodo que movemos.
casp_2: si el stack que recibe no está vacío, */

void ft_push(t_list **stack_orig, t_list **stack_dest)
{
	t_list *copy;
	t_list *aux;

	if (stack_orig == NULL)
		return ;
	//copy = ft_lstnew(stack_orig[0]->data);
	copy = *stack_orig;
	if(*stack_dest == NULL)
	{
		*stack_dest = copy;
		aux = *stack_dest;
		*stack_orig = copy->next;
		aux->next = NULL;
		//free(aux);
	}
	else
	{
		printf("----------------hago ft_lstaddd_front después\n\n");
		show_list(copy, ft_lstsize(copy));
		show_list(*stack_dest, ft_lstsize(*stack_dest));
		show_list(*stack_orig, ft_lstsize(*stack_orig));
		ft_lstadd_front(stack_dest, ft_lstnew(stack_orig[0]->data));
		copy = copy->next;
		free(copy);
		printf("----------------he hecho ya ft_lstaddd_front\n\n");
		show_list(copy, ft_lstsize(copy));
		show_list(*stack_dest, ft_lstsize(*stack_dest));
		show_list(*stack_orig, ft_lstsize(*stack_orig));
		printf("lalala\n");

		show_list(*stack_orig, ft_lstsize(*stack_orig));
		//show_list(copy, ft_lstsize(copy));

		//free(copy);
	}
}

void do_push(t_list **stack_orig, t_list **stack_dest, int type, t_values *main)
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
