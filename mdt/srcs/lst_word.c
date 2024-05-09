#include "minishell.h"

int	add_word_node(t_data *data, char *word)
{
	t_word	*node;

    node = NULL;
	if (data->lst_word == NULL)
	{
		data->lst_word = ft_lstnew_word(*data->lst_alloc, word);
		if (data->lst_word == NULL)
			exit_error(data, "Memory allocation issue");
	}
	else
	{
		node = ft_lstnew_word(*data->lst_alloc, word);
		if (node == NULL)
			exit_error(data, "Memory allocation issue");
		ft_lstadd_back_word(&(data->lst_word), node);
	}
	return (0);
}

t_word	*ft_lstnew_word(t_alloc *lst_alloc, char *word)
{
	t_word	*node;

    node = NULL;
	node = malloc(sizeof(t_word));
	if (add_alloc((&lst_alloc), node, NULL))
		return (NULL);
    node->word = word;
	node->n = 0;
	node->tok_w = -1;
	node->previous = NULL;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_back_word(t_word **lst, t_word *new)
{
	t_word	*beacon;

    beacon = NULL;
	if (lst == NULL || new == NULL)
		return ;
	beacon = ft_lstlast_word(*lst);
	beacon->next = new;
}

t_word	*ft_lstlast_word(t_word *lst)
{
	t_word	*beacon;

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

int	ft_lstsize_word(t_word *lst)
{
	int		i;
	t_word	*beacon;

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