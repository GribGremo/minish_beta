#include "minishell.h"

int expand(t_data *data)
{
    t_char *node;
    t_char *previous;
    t_char *next;


    node = data->lst_char;
    while(node != NULL)
    {
        if (node->tok_c == DOLLAR)
        {
            previous = node->previous;
            next = node->next;
           
        }
        node = node->next;
    }
}
int replace(t_data *data, t_char *node)
{
    t_char *end;

    end = find_end_var(data, node);
    delete_var_name()

    
}

t_char *find_end_var(t_data *data, t_char *node)
{
    node = node->next;
    if(ft_isalpha(node->n) || node->n == '_')
        node = node->next;
    else
        return(node->next); //Quel caractere stop expand?
    while(node != NULL && (ft_isalnum(node->n) || node->n == '_'))
        node = node->next;
    return (node);
}

int delete_var_name(t_data *data, t_char *start, t_char *end)
{
    t_char *temp;
    while(start != end)
    {
        temp = start;
        start = start->next;
        rm_alloc(data->lst_alloc, temp, NULL);
    }
    return (0);
}