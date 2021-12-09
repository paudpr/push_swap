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
	

	int array[] = {6, 7, 8};
	stack_b = init_list(array, 3);
	//stack_b = 0;
	stack_a = init_list(main.aux_nums, main.size_g);
	main.size_b = 3;
	main.size_a = argc - 1;
	// if(main.size_a + main.size_b != main.size_g)
	// 	print_error();
	
	// show_list(stack_a, main.size_g);
	// do_swap_ss(&stack_a, &stack_b, 2, &main);
	// show_list(stack_a, main.size_g);

	//printf("-------> %d\n", *stack_b->data);
	show_list(stack_a, main.size_a);
	show_list(stack_b, 3);
	printf("main.size_a = %d\n\n", main.size_a);
	printf("main.size_b = %d\n\n", main.size_b);
	do_push(&stack_a, &stack_b, 0, &main);
	printf("---------------\n\n");
	printf("main.size_a = %d\n\n", main.size_a);
	printf("main.size_b = %d\n\n", main.size_b);
	show_list(stack_a, main.size_a);
	printf("--------2\n\n");
	show_list(stack_b, main.size_b);
	show_list(stack_a, main.size_a);

	//do_rotate(dsfghjgfdssafsgh)

	//ft_free(&stack_a, main, 0);
	//ft_free(&stack_b, main, 0);*/
	return(0);
}
