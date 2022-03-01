#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define MAX_INT 2147483647
# define MIN_INT -2147483648

# include <stdlib.h>
# include <libft.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>

typedef struct s_values
{
	unsigned int	size_g;
	unsigned int	size_a;
	unsigned int	size_b;
	int				*aux_nums;
	t_list			*head_a;
	t_list			*head_b;

}	t_values;

/* Parseo   */
int		check_valid_args(char **argv);
char	*join_argv(int argc, char **argv);
int		check_valid_chars(char **nums);
int		*transform_to_nums(char **split);
int		check_duplicates(int *nums, int len);

/* Utils   */
long	ft_atoi_long(const char *str);
void	print_error(void);
void	ft_free_double(char **tab, int n);

/* Lista   */
t_list	*init_list(int *nums, int len);
void	show_list(t_list *lst, int num);
void	ft_free(t_list **list, t_values main, int index);

/* Game Rules */
void	ft_swap(t_list **list, int type, t_values *main);
void	do_swap_ss(t_list **stack_a, t_list **stack_b, int type, t_values *main);
void	ft_push(t_list **stack_orig, t_list **stack_dest);
void	do_push(t_list *stack_orig, t_list *stack_dest, int type, t_values *main);
void	ft_rotate(t_list **list);
void	ft_rev_rotate(t_list **list);
void	do_rotate(t_list **stack_a, t_list **stack_b, int type);

/* Main    */
int *main_check(int argc, char **argv, t_values *main);

void sort_3(t_list **stack, t_values *main);
#endif
