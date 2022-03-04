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
	// main.size_b = 1;
	main.size_a = main.size_g;
	stack_a = init_list(main.aux_nums, main.size_g);
	
	// int w = 2;
	// //int q = 5;
	// stack_b = ft_lstnew(&w);
	
	printf("%d, %d, %d\n", main.size_g, main.size_a, main.size_b);

	//show_list(stack_a, main.size_a);
	// show_list(stack_b, main.size_b);

	// ft_rev_rotate(&stack_a);

	// if(main.size_g < 4)
	// 	sort_2_3(&stack_a, &main);
	printf("\n----------------------\n");
	// if(main.size_g > 3 && main.size_g < 6)
		sort_4_5(&stack_a, &stack_b, &main);


	// if (main.size_g > 5)
	// 	sort_chunks(&stack_a, &stack_b, &main);

	show_list(stack_a, main.size_a);
	// show_list(stack_b, main.size_b + 1);


	system("leaks -q push_swap");
	return(0);
}
