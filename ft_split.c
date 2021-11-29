#include <stdlib.h>
#include <stdio.h>
#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	int	c;

	c = 0;
	while (s[c] != 0)
		c++;
	return (c);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (!src || !dst)
		return (0);
	if (dstsize == 0)
		return (ft_strlen(src));
	i = 0;
	while (i < (dstsize - 1) && src[i] != 0)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d_len;
	size_t	i;
	size_t	d_len_save;

	d_len = ft_strlen(dst);
	d_len_save = ft_strlen(dst);
	if (dstsize == 0)
		return (ft_strlen(src));
	if (dstsize < d_len)
		return (ft_strlen(src) + dstsize);
	i = 0;
	while (src[i] != '\0' && d_len < (dstsize - 1))
	{
		dst[d_len] = src[i];
		i++;
		d_len++;
	}
	dst[d_len] = '\0';
	return (d_len_save + ft_strlen(src));
}

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	int		i;

	cpy = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (cpy == NULL)
		return (cpy);
	i = 0;
	while (s1[i])
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		size;
	int		i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(size + 1 * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	size = 0;
	while (s2[size])
	{
		str[i] = s2[size];
		i++;
		size++;
	}
	str[i] = '\0';
	return (str);
}

size_t	ft_count_strings(char const *s, char c)
{
	int		new_str;
	size_t	str_n;

	new_str = 0;
	str_n = 0;
	while (*s)
	{
		if (*s != c && new_str == 0)
		{
			new_str = 1;
			str_n++;
		}
		else if (*s == c)
			new_str = 0;
		s++;
	}
	return (str_n);
}

size_t	ft_count_chrs(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s && *s++ != c)
		len++;
	return (len);
}

void	ft_free_tab(char **tab, size_t n)
{
	if (!tab[n])
	{
		while (n > 0)
			free(tab[n--]);
		free(tab);
	}
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	str_n;
	size_t	n;
	size_t	len;

	if (!s)
		return (0);
	str_n = ft_count_strings(s, c);
	split = malloc(sizeof(char *) * (str_n + 1));
	if (split == NULL)
		return (split);
	n = 0;
	while (n < str_n)
	{
		while (*s == c)
			s++;
		len = ft_count_chrs(s, c);
		split[n] = malloc(sizeof(char) * (len + 1));
		ft_free_tab(split, n);
		ft_strlcpy(split[n], s, len + 1);
		s = s + len;
		n++;
	}
	split[str_n] = 0;
	return (split);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				r;
	unsigned int	sol;

	i = 0;
	r = 1;
	sol = 0;
	while (str[i] == 32 || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			r = -1;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		sol = (sol * 10) + (str[i] - 48);
		if (sol > 2147483647 && r == 1)
			return (-1);
		if (sol > 2147483648 && r == -1)
			return (0);
		i++;
	}
	return (sol * r);
}

/*
void ft_lstadd_back(t_list **list, t_list *new)
{
	t_list *p;

	if (!*list)
		*list = new;
	else
	{
		p = ft_lstlast(*list);
		p->next = new;
	}
}

void ft_lstlast(t_list *list)
{
	if (!list)
		return(0);
	while(lst->next)
		list = list->next;
	return(list);
}*/