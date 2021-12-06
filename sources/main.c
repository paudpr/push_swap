#include <push_swap.h>

int	main(int argc, char **argv)
{
	t_values	main;
	t_list		*stack_a;
	t_list		*stack_b;

	if (argc < 2)
		return (0);
	main.aux_nums = main_check(argc, argv, &main);
	system("leaks -q push_swap");
	




	
	stack_a = init_list(main.aux_nums, main.size_g);
	stack_b = init_list(main.aux_nums, main.size_g);
	
	// show_list(stack_a, main.size_g);
	// ft_swap_ss(&stack_a, &stack_b, 2, main);
	// show_list(stack_a, main.size_g);

	show_list(stack_a, main.size_g);
	ft_push(&stack_a, &stack_b);
	show_list(stack_a, main.size_g);
	show_list(stack_b, main.size_g);

	ft_free(&stack_a, main, 0);
	//ft_free(&stack_b, main, 0);
	return(0);
}
