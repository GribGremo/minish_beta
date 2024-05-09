/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <natrijau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:37:19 by sylabbe           #+#    #+#             */
/*   Updated: 2024/05/01 14:30:42 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_alloc
{
	void			*alloc;
	void			**ptr_alloc;
	struct s_alloc	*next;
}					t_alloc;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int		ft_atoi(const char *str);
void	*ft_bzero(void *ptr, size_t count);
void	*ft_calloc(size_t elementCount, size_t elementSize);
int		ft_isalnum(int car);
int		ft_isalpha(int car);
int		ft_isascii(int car);
int		ft_isdigit(int car);
int		ft_isprint(int car);
void	*ft_memchr(const void *s, int c, size_t size);
int		ft_memcmp(const void *ptr1, const void *ptr2, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t size);
void	*ft_memmove(void *dest, const void *source, size_t size);
void	*ft_memset(void *ptr, int val, size_t count);
char	*ft_strdup(const char *source);
char	*ft_strchr(const char *string, int searchedChar);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
int		ft_strlen(const char *str);
int		ft_strncmp(const char *first, const char *second, size_t length);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *string, int searchedChar);
int		ft_tolower(int character);
int		ft_toupper(int character);
char	*ft_itoa(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*create_str_a(t_alloc **lst_alloc, const char *s, int start, int end);
char	**errfree_a(t_alloc **lst_alloc);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
//ADD
char	*ft_strjoin_f(char *s1, char *s2);
char	*ft_strjoin_a(t_alloc **lst_alloc, char const *s1, char const *s2);
char	**ft_split_a(t_alloc **lst_alloc, char const *s, char c);
char	*ft_strdup_a(t_alloc **lst_alloc, const char *source);
char	*ft_substr_a(t_alloc **lst_alloc, char const *s, unsigned int start, size_t len);
int		ft_tablen(char **str);
//ALLOC
int		add_alloc(t_alloc **lst_alloc, void *alloc, void **ptr_alloc);
int		add_s_alloc(t_alloc **lst_alloc, void *alloc);
int		add_d_alloc(t_alloc **lst_alloc, void **ptr_alloc);
int		rm_alloc(t_alloc *lst_alloc, void *alloc, void **ptr_alloc);
int		rm_lst_alloc(t_alloc *lst, char *str);
t_alloc	*ft_lstnew_a(void *alloc, void **ptr_alloc);
void	ft_lstadd_back_a(t_alloc *lst, t_alloc *node);
t_alloc	*ft_lstlast_a(t_alloc *lst);
void	print_list_alloc(t_alloc *lst_alloc);
int		ft_lstsize_a(t_alloc *lst);

//PRINTF
int		ft_printf(const char *str, ...);
int		ft_putchar(int c, int cnt);
int		print_int(long int nb, int count);
int		print_string(char *s, int count);
int		print_ptr(unsigned long nb, int count, char c);
int		print_hexa(unsigned long nb, int count, char c);
int		print_arg(int count, char c, va_list prmt, int *cpt);
char	*ft_strchr(const char *string, int searchedChar);
//GET NEXT LINE
char	*get_next_line(int fd);
char	*get_read(char *temp, char *mem, int fd);
char	*join_to_mem(char *line);
int		create_mem(char *line, char *mem);
int		islinefeed(char *string);
//BONUS
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (del)(void *));
void	ft_lstclear(t_list **lst, void (del)(void *));
void	ft_lstiter(t_list *lst, void (f)(void *));
//t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
#endif
