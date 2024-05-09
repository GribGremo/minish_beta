#include "minishell.h"


#define RED     "\033[0;31m"
#define GREEN   "\033[0;32m"
#define YELLOW  "\033[0;33m"
#define BLUE    "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN    "\033[0;36m"
#define WHITE   "\033[0;37m"
#define GRAY    "\033[0;90m"
#define RESET   "\033[0m"


int print_lst_char(t_data *data, char c)
{
    t_char *node;
    char *color;

    node = data->lst_char;
    while(node != NULL && c == 's')
    {

        if(node->tok_c == PIPE)
            color = RED;
        if(node->tok_c == OUT)
            color = GREEN;
        if(node->tok_c == IN)
            color = YELLOW;
        if(node->tok_c == D_QUOTE)
            color = BLUE;
        if(node->tok_c == DOLLAR)
            color = MAGENTA;
        if(node->tok_c == S_QUOTE)
            color = CYAN;
        if(node->tok_c == CHAR)
            color = WHITE;
        if(node->tok_c == BLANK)
            color = GRAY;

        printf("%s___________NODE___________\n", color);
        printf("%p\n",node);
        printf("TOKEN= %d\n",node->tok_c);
        printf("CHAR= %c\n",node->c);
        printf("INDEX= %d\n",node->n);
        printf("S_QUOTE= %d\n",node->s_quoted);
        printf("D_QUOTE= %d\n",node->d_quoted);
        printf("NEXT= %p\n",node->next);
        printf("PREVIOUS= %p\n%s",node->previous, RESET);
        node = node->next;
    }
    node = data->lst_char;
    printf("___________RESUME___________\n");
    while(node != NULL && c == 'r')
    {

        if(node->tok_c == PIPE)
            color = RED;
        if(node->tok_c == OUT)
            color = GREEN;
        if(node->tok_c == IN)
            color = YELLOW;
        if(node->tok_c == D_QUOTE)
            color = BLUE;
        if(node->tok_c == DOLLAR)
            color = MAGENTA;
        if(node->tok_c == S_QUOTE)
            color = CYAN;
        if(node->tok_c == CHAR)
            color = WHITE;
        if(node->tok_c == BLANK)
            color = GRAY;

        printf(" %s|_%c_|%s\n", color, node->c, RESET);
//        printf("%s%c%s", color, node->c, RESET);
        node = node->next;
    }
        printf("\n");
    return (0);
}
//JE SUIS UNE "'$QUOTE'" '"$QUOTE"' | < > $ "|" "<" ">" "$" '|' '<' '>' '$'