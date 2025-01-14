/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:17:14 by ncampbel          #+#    #+#             */
/*   Updated: 2025/01/13 13:20:53 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "../../headers.h"

//PARTE1
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);

//PARTE2
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char	const *s, char c);
char	*ft_itoa(int c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

//BONUS

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

//EXTRAS

int		ft_htoi(char *hex);
int		ft_array_len(char **array);
long	ft_atol(const char *nbr);
bool	int_number(const char *nbr);
void	ft_error_print(char *error);
int		get_charlen(char c);
bool	ft_isspace(char c);
void	ft_strcpy(char *dest, char *src);
void	ft_strcat(char *dest, char *src);
char	*ft_strndup(const char *s, size_t n);
char	**ft_array_insert_extra(char **array, char *insert, \
char *extra, int index);
int		ft_arraylcpy(char **dst, const char **src, int size);
void	ft_arraycpy(char **dest, char **src);
char	*ft_strcutstr(const char *big, const char *little);
char	*ft_strjoin_free(char const *s1, char const *s2);
char	*ft_strreplace(char *src, int i, char *insert, char *name);

int		ft_find_char(const char *str, char c);

int		ft_itoui(int negative);

bool	ft_is_number(char *str);

bool	ft_is_pipe_redir(char c);

char	**ft_strdupd(char **src);

void	ft_free_array(char **array);

int		ft_fixed_to_int(int fixed);
float	ft_fixed_to_float(int fixed);
int		ft_float_to_fixed(float const float_number);
int		ft_int_to_fixed(int const i);

t_list	*ft_lstget(t_list *lst, int index);
void	ft_lstiter_param(t_list *lst, void (*f)(void *, void *), void *ptr);

bool	ft_isdigit_str(char *str);
int		ft_amount_char(char *str, char c);

#endif
