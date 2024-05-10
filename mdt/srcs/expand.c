#include "minishell.h"

int expand(t_data *data)
{
    t_char *value;
    t_char *node;
    t_char *previous;
    t_char *next;

    node = data->lst_char;
    while(node != NULL)
    {
        if (node->tok_c == DOLLAR)
        {
            previous = node->previous;
//            printf("PREVIOUS=%p\n", previous);
            next = find_end_var(data, node);
  //          printf("NEXT=%p\n", next);
            value = replace(data, node);
    //        printf("VALUE=%p\n", value);
            if (value == NULL)
            {
                if(previous != NULL)
                    previous->next = next;
                else
                    data->lst_char = next;
            }
            else
            {
                value->previous = previous;
                value = ft_lstlast_char(value);
                value->next = next;
            }
        }
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

    end = find_end_var(data, node);
//    printf("END= %c\n", end->c);
    var = create_var_str(data, node, end);
//    printf("VAR= %s\n",var);
    delete_var_name(data, node, end);
    var_node = get_env_var(data, var);
//    printf("NODE_VAR= %p",var_node);
    if(var_node == NULL)
        return (NULL);//AVOIR
    value_str = var_node->value;
//    printf("%s", value_str);
    value = create_var_list(data, value_str);
//    printf("\n%c\n",value->c);
    return (value);
}

t_char *find_end_var(t_data *data, t_char *node)
{
    t_char *temp;

    temp = node;
    (void) data;
    temp = temp->next;
    if(ft_isalpha(temp->c) || temp->c == '_')
        temp = temp->next;
    else
        return(temp->next); //Quel caractere stop expand?
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
    int i;

    i = 0;
    node = ft_lstnew_char(*data->lst_alloc,str[i]);
    node->tok_c = CHAR;
    lst_var = node;
    i++;
    while(str[i] != '\0')
    {
        node = ft_lstnew_char(*data->lst_alloc,str[i]);
        ft_lstadd_back_char(&lst_var, node);
        node->tok_c = CHAR;
        i++;
    }
    return (lst_var);
}
