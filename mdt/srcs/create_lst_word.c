#include "minishell.h"

int	create_lst_word(t_data *data)
{
	t_char	*node_c;
	t_word *node_w;
	t_word *temp;
	int i;

	i = 0;
	node_c = data->lst_char;
	while (node_c != NULL)
	{
		if (node_c->tok_c != BLANK && node_c->tok_c != S_QUOTE && node_c->tok_c != D_QUOTE)
		{
			add_word_node(data, create_word(data, node_c, node_c->tok_c));
			node_w = ft_lstlast_word(data->lst_word);
			node_w->n = i;
			if (i > 0)
				node_w->previous = temp;
			temp = node_w; 
			node_w->tok_w = -1;
			i++; 
		}
		if (node_c != NULL)
			node_c = node_c->next;
	}
	return (0);
}

char	*create_word(t_data *data, t_char *node_c, t_char_tok tok)
{
	char	*word;
	int		i;

	word = NULL;
	i = 0;
	word = malloc((ft_lstlen_char(data, node_c, tok) + 1) * sizeof(char));
	while (node_c != NULL && node_c->tok_c == tok)
	{
		word[i] = node_c->c;
		i++;
		node_c = node_c->next;
	}
	word[i] = '\0';
	return (word);
}

int	ft_lstlen_char(t_data *data, t_char *node_c, t_char_tok tok)
{
	t_char *temp;
	int count;
	(void) data;

	temp = node_c;
	while (temp != NULL && temp->tok_c == tok)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}