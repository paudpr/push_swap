#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define MAX_INT 2147483647
# define MIN_INT -2147483648

# include <stdlib.h>
# include <unistd.h>
//#include "libft.h"

typedef struct	s_list
{
	int			data;
	struct		s_list	*next;

}t_list;

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *s1);
size_t	ft_count_strings(char const *s, char c);
size_t	ft_count_chrs(char const *s, char c);
void	ft_free_tab(char **tab, size_t n);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_isdigit(int c);
void	ft_lstadd_back(t_list **list, t_list *new);
t_list	*ft_lstlast(t_list *list);





#endif
