#include <push_swap.h>

int *main_check(int argc, char **argv, t_values *main)//
{
	int		i;
	char	**split;
	char	*str;
	int		*nums;

	check_valid_args(argv);
	str = join_argv(argc, argv);
	split = ft_split(str, ' ');
	free(str);
	if (split == NULL)
		return (0);
	if (check_valid_chars(split) != 1)
		print_error();
	nums = transform_to_nums(split);
	i = 0;
	while (split[i])
		i++;
	main->size_g = i;
	if (check_duplicates(nums, i) != 1)
		print_error();
	ft_free_double(split, i);
	return (nums);
}

void pdel_pin()
{
	system("leaks -q push_swap");
}

int	main(int argc, char **argv)
{
	t_values	main;
	t_list		*list;

	atexit(pdel_pin);
	if (argc < 2)
		return (0);
	main.aux_nums = main_check(argc, argv, &main);
	
	
	//list = init_list(main.aux_nums, main.size_g);
	//show_list(list, main.size_g);
	ft_free(&list, main, 0);
	return(0);
}
