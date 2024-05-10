#include "minishell.h"

int	add_char_node(t_data *data, char c)
{
	t_char	*node;

    node = NULL;
	if (data->lst_char == NULL)
	{
		data->lst_char = ft_lstnew_char(*data->lst_alloc,c);
		if (data->lst_char == NULL)
			exit_error(data, "Memory allocation issue");
	}
	else
	{
		node = ft_lstnew_char(*data->lst_alloc, c);
		if (node == NULL)
			exit_error(data, "Memory allocation issue");
		ft_lstadd_back_char(&(data->lst_char), node);
	}
	return (0);
}

t_char	*ft_lstnew_char(t_alloc *lst_alloc, char c)
{
	t_char	*node;

    node = NULL;
	node = malloc(sizeof(t_char));
	if (add_alloc((&lst_alloc), node, NULL))
		return (NULL);
    node->c = c;
	node->n = 0;
	node->tok_c = -1;
	node->d_quoted = false;
	node->s_quoted = false;
	node->previous = NULL;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_back_char(t_char **lst, t_char *new)
{
	t_char	*beacon;

    beacon = NULL;
	if (lst == NULL || new == NULL)
		return ;
	beacon = ft_lstlast_char(*lst);
	beacon->next = new;
}

t_char	*ft_lstlast_char(t_char *lst)
{
	t_char	*beacon;

	if (lst == NULL)
		return (NULL);
	beacon = lst;
	while (beacon != NULL)
	{
		if (beacon->next == NULL)
			return (beacon);
		beacon = beacon->next;
	}
	return (beacon);
}

int	ft_lstsize_char(t_char *lst)
{
	int		i;
	t_char	*beacon;

	i = 1;
	if (lst == NULL)
		return (0);
	beacon = lst;
	while (beacon->next != NULL)
	{
		beacon = beacon->next;
		i++;
	}
	return (i);
}

// int exit_error(t_data *data, char *str)
// {
// 	(void)str;
//     (void) data;//A VOIR
//     return (0);
// }