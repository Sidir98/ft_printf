/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 15:22:12 by ibouabda          #+#    #+#             */
/*   Updated: 2019/07/11 16:41:46 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H
# define ABS(Value) (Value < 0 ? Value * -1 : Value)

# include <string.h>
# include <stdlib.h>
# include <stdio.h>

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_atoi(const char *str);
void				ft_bzero(void *src, size_t n);
void				*ft_memchr(const void *src, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t len);
void				*ft_memset(void *src, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strcat(char *dest, const char *src);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dest, const char *src);
size_t				ft_strlen(const char *str);
char				*ft_strncat(char *dest, const char *src, size_t nb);
int					ft_strncmp(const char *src, const char *dest, size_t n);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strstr(const char *str, const char *to_find);
char				*ft_strnstr(const char *str, const char *to_find, size_t n);
char				*ft_strdup(const char *s1);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strchr(const char *src, int c);
char				*ft_strrchr(const char *src, int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
size_t				ft_lstlen(t_list *lst);
void				ft_lstaddend(t_list **alst, t_list *new);
t_list				*ft_lstmanynew(size_t lst_size, void *content,\
size_t content_size);
void				ft_putstrlst(t_list *m);
void				ft_lstaddafter(t_list **alst, t_list *new);
t_list				*ft_lstnewstr(char *content, size_t content_size);
void				ft_lstdellink(t_list *m);
char				**ft_2dstrnew(size_t size);
char				***ft_3dstrnew(size_t size);
int					ft_3dstrin(char ***s1, char ***s2);
void				ft_3dputstr(char ***tetrim);
int					ft_2dstrcmp(char **s1, char **s2);
int					ft_2dstrlen(char **str);
int					ft_3dstrlen(char ***str);
int					ft_sqrt(int nb);
int					ft_sqrt_aprox(int nb);
void				ft_2dputstr(char **tetrim);
void				ft_2dstrdel(char **as);
void				ft_3dstrdel(char ***tetrim);
void				ft_putnbr_count(int nb, int *i);
char				*ft_strrev(char *str);
void				ft_putdouble(double nb, int *i);
int					ft_countnumbers(int nb);
char				*ft_itoa_base(int nb, int base);
char				*ft_itoa_base_maj(int nb, int base);
char				*ft_strchar(int nb, char c);
#endif
