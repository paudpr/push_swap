#include <push_swap.h>

int	main(int argc, char **argv)
{
	t_values	main;
	t_list		*stack_a;
	t_list		*stack_b;

	//atexit(pdel_pin);
	if (argc < 2)
		return (0);
	main.aux_nums = main_check(argc, argv, &main);
	system("leaks -q push_swap");
	




	
	stack_a = init_list(main.aux_nums, main.size_g);
	stack_b = init_list(main.aux_nums, main.size_g);
	show_list(stack_a, main.size_g);
	ft_swap_ss(&stack_a, &stack_b, 2, main);
	show_list(stack_a, main.size_g);




	// printf("numero de elementos en la lista -----> %d\n", main.size_g);
	// printf("numero de elementos en la lista -----> %d\n", main.size_a);
	// printf("numero de elementos en la lista -----> %d\n", main.size_b);
	// printf("numero de elementos en la lista -----> %p\n", main.aux_nums);


	ft_free(&stack_a, main, 0);
	
	return(0);
}
