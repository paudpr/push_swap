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
	copy = *stack_orig;
	if(stack_dest == NULL)
	{
		aux = *stack_dest;
		*stack_dest = copy;
		aux->next = NULL;
		*stack_orig = copy->next;
		//free(aux);
	}
	else
	{
		// ft_lstadd_front(stack_dest, copy);
		aux = *stack_dest;
		*stack_dest = copy;
		*stack_orig = copy->next;
		copy->next = aux;
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
		main->size_a++;
		main->size_b--;
		write(1, "pa\n", 3);
	}
	if (type == 1)
	{
		ft_push(stack_orig, stack_dest);
		main->size_b++;
		main->size_a--;
		write(1, "pb\n", 3);
	}
	if(main->size_a + main->size_b != main->size_g)
		print_error();
}
