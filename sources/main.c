#include <push_swap.h>

int	main(int argc, char **argv)
{
	t_values	main;
	t_list		*stack_a;
	t_list		*stack_b;
	int i;
	int j;

	if (argc < 2)
		return (0);
	main.aux_nums = main_check(argc, argv, &main);
	
	// i = 0;
	// printf("-------------\n");
	// while(i < main.size_g)
	// {
	// 	printf("main.aux_nums --> %d\n", main.aux_nums[i]);
	// 	i++;
	// }

	main.head_b = NULL;
	stack_b = main.head_b;
	main.head_a = init_list(main.aux_nums, main.size_g);
	stack_a = main.head_a;
	main.size_a = main.size_g;

	printf("-------------\n");

	// printf("main.size_g --> %d\n", main.size_g);
	// printf("main.size_a --> %d\n", main.size_a);
	// printf("main.size_b --> %u\n", main.size_b);
	// printf("main.head --> %p\n", main.head_a);
	// printf("main.head --> %d\n", *main.head_a->data);
	
	// show_list(main.head, main.size_g);
	// ft_swap(&main.head_a, 2, &main);
	// show_list(main.head, main.size_g);
	
	// show_list(main.head_a, main.size_a);	//imprime lista inicial
	// show_list(main.head_b, main.size_b);	//imprime lista vacía
	// printf("main.size_a = %d\n", main.size_a);
	// printf("main.size_b = %d\n", main.size_b);
	// printf("\n\n");


	i = 7;
	j = 9;
	// main.head_b = ft_lstnew(&i);
	// ft_lstadd_back(&main.head_b, ft_lstnew(&j));

	ft_push(main.head_a, main.head_b, &main);
	system("leaks -q push_swap");
	//do_push(&stack_a, &stack_b, 0, &main);

	// printf("---------------\n\n");
	// printf("main.size_a = %d\n\n", main.size_a);
	// printf("main.size_b = %d\n\n", main.size_b);
	// show_list(stack_a, main.size_a);
	// printf("--------2\n\n");
	// show_list(stack_b, main.size_b);
	// show_list(stack_a, main.size_a);

	//do_rotate(dsfghjgfdssafsgh)

	//ft_free(&stack_a, main, 0);
	//ft_free(&stack_b, main, 0);*/
	return(0);
}
