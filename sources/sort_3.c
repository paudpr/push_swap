#include <push_swap.h>

void sort_3(t_list **list, t_values main)
{
	if (!list)
		return ;
	if (main.size_g >= 2 && main.size_g <= 3)
	{
		while(check_sort(*stack_a, main) != 0)
		{
			if(list->data > list->next->next->data &&
				list->data > list->next->data)
				ft_rotate(list, 0)
			else if(list->next->data < list->data &&
				list->next->data > llist->next->next->data)
				ft_rev_rotate(list, 0);
			else if(list->next->data > list->data &&
				list->next->data < llist->next->next->data)
				ft_rev_rotate(list, 0);
			else if(list->data > list->next->data &&
				list->data < list->next->next->data &&
				lis->next->data < list->next->next->data)
				do_swap(list, 0);
		}
	}
	return(0);
}




void sort_4(t_list **stack_a, t_list **stack_b, t_values main)
{
	if(!list)
		return ;
		
	if(main.size_g >= 2 && main.size_g <= 4)
	{
		while(check_sort(*stack_a, main)


	}


}