#include "minishell.h"

int	create_lst_word(t_data *data)
{
	t_char	*node_c;
	t_char	*start;
	t_char	*end;

	node_c = data->lst_char;
	while (node_c != NULL)
	{
		if (node_c->next != NULL && (node_c->tok_c != node_c->next->tok_c) && node_c->next->tok_c != BLANK)
			add_word_node(data, create_word(data, node_c));
		node_c = node_c->next;
	}
	return (0);
}

char	*create_word(t_data *data, t_char *node_c)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((ft_lstlen_char(data, node_c) + 1) * sizeof(char));
	while (node_c->tok_c == CHAR && node_c != NULL)
	{
		word[i] = node_c->c;
		i++;
		node_c = node_c->next;
	}
	return (word);
}

int	ft_lstlen_char(t_data *data, t_char *node_c)
{
	t_char *temp;
	int count;
	temp = node_c;
	while (temp->tok_c == CHAR && temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}