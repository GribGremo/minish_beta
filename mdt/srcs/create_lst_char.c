#include "minishell.h"

int create_lst_char(t_data *data)
{
    int i;
    t_char *node;
   t_char *temp;

    i = 0;
    while(data->entry[i] != '\0')
    {
        add_char_node(data,data->entry[i]);
        node = ft_lstlast_char(data->lst_char);
        if(i > 0)
            node->previous = temp;
        temp = node;
        node->c = data->entry[i];
        node->n = i;
        node->tok_c = -1;//
        i++;
    }
    return (0);
}
int check_quote(t_data *data)
{
    t_char *node;
    int d_quoted;
    int s_quoted;

    node = data->lst_char;
    d_quoted = -1;
    s_quoted = -1;
    while(node != NULL)
    {
        if (node->c == '\'' && d_quoted == -1)
            s_quoted *= -1;
        if (node->c == '"' && s_quoted == -1)
            d_quoted *= -1;
        if (d_quoted == -1)
            node->d_quoted = false;
        else
            node->d_quoted = true;
        if (s_quoted == -1)
            node->s_quoted = false;
        else
            node->s_quoted = true;
        node = node->next;
    }
    return (0);
}
int token_char(t_data *data)
{
    t_char *node;

    node = data->lst_char;
    while(node != NULL)
    {
//        if(node->d_quoted == true || node->s_quoted == true)
        node->tok_c = CHAR;
        if(node->c == '\'' && node->d_quoted == false)
            node->tok_c = S_QUOTE;
        if(node->c == '"' && node->s_quoted == false)
            node->tok_c = D_QUOTE;
        if (node->s_quoted == false && node->d_quoted == false  && node->c == '|')
            node->tok_c = PIPE;
        if (node->s_quoted == false && node->d_quoted == false && node->c == '<')
            node->tok_c = IN;
        if (node->s_quoted == false && node->d_quoted == false && node->c == '>')
            node->tok_c = OUT;
        if (node->s_quoted == false && node->d_quoted == false && node->c == ' ')
            node->tok_c = BLANK;
        if (node->s_quoted == false && node->c == '$')
            node->tok_c = DOLLAR;
        node = node->next;
    }
    return (0);
}
