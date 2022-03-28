/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauladelpinoramirez <pauladelpinoramire    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:22:51 by pauladelpin       #+#    #+#             */
/*   Updated: 2022/03/28 17:09:03 by pauladelpin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

//arguments cleaning and processing
int	*main_check(int argc, char **argv, t_values *main)
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
