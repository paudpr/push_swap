#include <push_swap.h>

//take the first element of one stack to the top of the other stack
/*comprobación que el stack del que viene el elemento no es nulo. 
caso_1: si el stack que recibe está vacío, el stack es igual al nodo que movemos.
casp_2: si el stack que recibe no está vacío, */

void ft_push(t_list **stack_a, t_list **stack_b, int type, t_values main)
{
	t_list *copy;
	t_list *aux;
	int aux;

	if (stack_b == NULL)
		return(0);
	copy = *stack_b;
	if(stack_a == NULL)
	{
		*stack_a = copy;
		*stack_b = copy->next;
		//stack_a->next = NULL;
		printf("DATA STACK_A ----> %i\n", stack_a.data);
		printf("NEXT STACK_A ----> %p\n", stack_a.next);
	}
	else
	{
		aux = *stack_a;
		*stack_a = copy;
		*stack_b = copy->next;
		copy->next = aux;
	}
	if (type == 0)
	{
		main.size_a++;
		main.size_b--;
		write(1, "pa\n", 3);
	}
	if (type == 1)
	{
		main.size_b++;
		main.size_a--;
		write(1, "pb\n", 3);
	}


}