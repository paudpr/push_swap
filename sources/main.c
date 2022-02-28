#include <push_swap.h>

int	main(int argc, char **argv)
{
	t_values	main;

	if (argc < 2)
		return (0);
	main.aux_nums = main_check(argc, argv, &main);
	

	main.head_b = NULL;
	main.head_a = init_list(main.aux_nums, main.size_g);
	main.size_a = main.size_g;

	show_list(main.head_a, main.size_a);
	printf("\n\n ----------------- \n\n");
	show_list(main.head_b, main.size_b);
	printf("\n\n ----------------- \n\n");

	ft_push(main.head_a, main.head_b, &main);
	
		show_list(main.head_a, main.size_a);
		printf("AQUI\n");
	printf("\n\n ----------------- \n\n");
	show_list(main.head_b, main.size_b);
	printf("\n\n ----------------- \n\n");

	system("leaks -q push_swap");
	return(0);
}
