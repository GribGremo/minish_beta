#include "minishell.h"

t_char *add_lst_char(t_data *data, t_char *one, t_char *two);
int expand(t_data *data)
{
    t_char *node;

    node = data->lst_char;
    while(node != NULL)
    {
        if (node->tok_c == DOLLAR)
        {
            if (node->next != NULL && node->next->tok_c == CHAR)
                node = replace(data, node);
        }
        if (node != NULL && node->tok_c != DOLLAR)
            node = node->next;
    }
    return(0);
}

t_char *replace(t_data *data, t_char *node)
{
    t_char *end;
    t_char *value;
    char *var;
    char *value_str;
    t_env *var_node;

    if (node->previous != NULL)//
        node->previous->next = NULL;//
    else    //
        data->lst_char = NULL;//
    end = find_end_var(data, node);
    if (end != NULL)//
        end->previous = NULL;//
    var = create_var_str(data, node, end);
    delete_var_name(data, node, end);
    var_node = get_env_var(data, var);
    if(var_node == NULL)
        value = NULL;//AVOIR
    else
    {
        value_str = var_node->value;
        value = create_var_list(data, value_str);
    }
    data->lst_char = add_lst_char(data, data->lst_char, value);//
    data->lst_char = add_lst_char(data, data->lst_char, end);//
    return (end);
}

t_char *find_end_var(t_data *data, t_char *node)
{
    t_char *temp;

    temp = node;
    (void) data;
    temp = temp->next;
    if (temp == NULL)
        return NULL;
    if(ft_isalpha(temp->c) || temp->c == '_')
        temp = temp->next;
    else if (temp->tok_c != S_QUOTE && temp->tok_c != D_QUOTE)
        return(temp->next); //Quel caractere stop expand?
    else if (temp->tok_c == S_QUOTE || temp->tok_c == D_QUOTE)
        return (temp);
    while(temp != NULL && (ft_isalnum(temp->c) || temp->c == '_'))
        temp = temp->next;
    return (temp);
}

int delete_var_name(t_data *data, t_char *start, t_char *end)
{
    t_char *temp;
    while(start != end)
    {
        temp = start;
        start = start->next;
        rm_alloc(*data->lst_alloc, temp, NULL);
    }
    return (0);
}

char *create_var_str(t_data *data, t_char *start, t_char *end)
{
    t_char *temp;
    int count;
    char *var;

    (void) data;
    count = 0;
    temp = start->next;
    while(temp != end)
    {
        count++;
        temp = temp->next;
    }
    var = malloc((count + 1) * sizeof(char));
    temp = start->next;
    count = 0;
    while(temp != end)
    {
        var[count] = temp->c;
        count++;
        temp = temp->next;
    }
    var[count] = '\0';
    return (var);
}
t_char *create_var_list(t_data *data, char *str)
{
    t_char *lst_var;
    t_char *node;
    t_char *previous;
    int i;

    i = 0;
    node = ft_lstnew_char(*data->lst_alloc,str[i]);
    node->tok_c = CHAR;
    node->previous = NULL;
    previous = node;
    lst_var = node;
    i++;
    while(str[i] != '\0')
    {
        node = ft_lstnew_char(*data->lst_alloc,str[i]);
        node->previous = previous;
        previous = node;
        ft_lstadd_back_char(&lst_var, node);
        node->tok_c = CHAR;
        i++;
    }
    return (lst_var);
}
t_char *add_lst_char(t_data *data, t_char *one, t_char *two)
{
    (void) data;
    t_char *temp;
    if(one == NULL && two == NULL)
        return (NULL);
    if (one == NULL && two != NULL)
        return (two);
    temp = ft_lstlast_char(one);
    temp->next = two;
    if(two != NULL)
        two->previous = temp;
    return (one);
}
