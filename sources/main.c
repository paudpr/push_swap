#include <push_swap.h>

int	main(int argc, char **argv)
{
	t_values	main;
	t_list		*stack_a;
	t_list		*stack_b;

	if (argc < 2)
		return (0);
	main.aux_nums = main_check(argc, argv, &main);
	stack_b = NULL;
	main.size_b = 0;
	main.size_a = main.size_g;
	stack_a = init_list(main.aux_nums, main.size_g);
	// push_swap(&stack_a, &stack_b, main);
	system("leaks -q push_swap");
	return(0);
}
