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
	// stack_b = ft_lstnew_pw(&w);
	
	//printf("%d, %d, %d\n", main.size_g, main.size_a, main.size_b);

	//show_list(stack_a, main.size_a);
	// show_list(stack_b, main.size_b);

	// ft_rev_rotate(&stack_a);
	// if(main.size_g < 4)


	
		// sort_2_3(&stack_a, &main);
	printf("\n----------------------\n");
	// if(main.size_g > 3 && main.size_g < 6)
	// sort_4_5(&stack_a, &stack_b, &main);

mapping(&stack_a);
// show_list(stack_a, 10);
printf("\n\n prueba -> %d\n", stack_a->index);
binary_check(stack_a->index, 1);
printf("binary_check -> %d\n", binary_check(stack_a->index, 1));

radix(&stack_a, &stack_b, &main);



	// if (main.size_g > 5)
	// 	sort_chunks(&stack_a, &stack_b, &main);
	// printf("lalalalalalalalalalalalalalalalla\n");
	// show_list(stack_a, 15);
	// show_list(stack_b, 3);
	// show_list(stack_b, main.size_b + 1);
	if(check_sort(&stack_a, &main)  == 1)
		printf("Hello world!\n");
	else
		printf("mierda\n");

	// system("leaks -q push_swap");
	return(0);
}
