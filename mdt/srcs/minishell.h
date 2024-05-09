#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <signal.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <curses.h>
#include <term.h>
#include <stdio.h>
#include "../../Libft/libft.h"

//structure tokens
typedef enum s_char_tok{
    IN,
    OUT,
    S_QUOTE,
    D_QUOTE,
    PIPE,
    BLANK,
    CHAR,
    DOLLAR,
}   t_char_tok;

typedef enum s_word_tok{
    R_IN,
    R_OUT,
    HEREDOC,
    APPEND,
    W_PIPE,
    INFILE,
    OUTFILE,
    FUNCTION,
    ARGUMENT,
}   t_word_tok;

typedef struct s_word
{
    t_word_tok tok_w;
    int n;
    char *word;
    struct s_word *previous;
    struct s_word *next;
}   t_word;

typedef struct s_char
{
    t_char_tok tok_c;
    int n;
    char c;
    bool s_quoted;
    bool d_quoted;
    struct s_char *previous;
    struct s_char *next;
}   t_char;

typedef struct s_env
{
    char *var;
    char *value;
    int origin;
    struct s_env *next;
}   t_env;

// structure principale
typedef struct s_data
{
    char        **envp;
    t_alloc     **lst_alloc;
    t_env       *env;
    char        *entry;
    t_char      *lst_char;
    t_word      *lst_word;
}   t_data;
//DEV
int is_entry_empty(char *entry);

//LST_CHAR
int	add_char_node(t_data *data, char c);
t_char	*ft_lstnew_char(t_alloc *lst_alloc, char c);
void	ft_lstadd_back_char(t_char **lst, t_char *new);
t_char	*ft_lstlast_char(t_char *lst);
int	ft_lstsize_char(t_char *lst);

int exit_error(t_data *data, char *str);

//LST_WORD
int	add_word_node(t_data *data, char *word);
t_word	*ft_lstnew_word(t_alloc *lst_alloc, char *word);
void	ft_lstadd_back_word(t_word **lst, t_word *new);
t_word	*ft_lstlast_word(t_word *lst);
int	ft_lstsize_word(t_word *lst);

//CREATE LST CHAR
int create_lst_char(t_data *data);
int check_quote(t_data *data);
int token_char(t_data *data);


//DEBUG
int print_lst_char(t_data *data, char c);
int print_lst_word(t_data *data);
