/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 14:13:59 by aait-ham          #+#    #+#             */
/*   Updated: 2019/10/21 09:44:34 by aait-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFT_H
# define FT_LIBFT_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>


# include "array_list.h"


typedef unsigned char	t_byte;

typedef struct			s_list
{
	void				*content;
	struct s_list		*next;
}						t_list;
int			ft_atoi_p(char **str);
void					*ft_calloc(size_t count, size_t size);
int						ft_tolower(int c);
int						ft_toupper(int c);
int						ft_isprint(int c);
int						ft_isascii(int c);
int						ft_isalnum(int c);
int						ft_isdigit(int c);
int						ft_isalpha(int c);
int						ft_atoi(const char *str);
int						ft_strncmp(const char *s1,
					const char *s2, size_t n);
size_t					ft_strlen(const char *s);
char					*ft_strchr(const char *s, int c);
char					*ft_strrchr(const char *s, int c);
char					*ft_strnstr(const char *haystack,
		const char *needle, size_t len);
void					*ft_memset(void *b, int c, size_t len);
void					ft_bzero(void *s, size_t n);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					*ft_memccpy(void *dst,
			const void *src, int c, size_t n);
void					*ft_memmove(void *dst, const void *src, size_t len);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
char					*ft_strdup(const char *s);
size_t					ft_strlcpy(char *dst, const char *src, size_t size);
size_t					ft_strlcat(char *dst, const char *src, size_t size);
char					*ft_substr(char const *s,
		unsigned int start, size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char *s, int fd);
void					ft_putendl_fd(char *s, int fd);
void					ft_putnbr_fd(int n, int fd);
char					*ft_strmapi(char const *s,
			char (*f)(unsigned int, char));
char					*ft_itoa(int n);
char					*ft_strtrim(char const *s1, char const *set);
char					**ft_split(char const *s, char c);
t_list					*ft_lstnew(void *content);
void					ft_lstadd_front(t_list **alst, t_list *new);
int						ft_lstsize(t_list *lst);
t_list					*ft_lstlast(t_list *lst);
void					ft_lstadd_back(t_list **alst, t_list *new);
void					ft_lstdelone(t_list *lst, void (*del)(void *));
void					ft_lstclear(t_list **lst, void (*del)(void *));
void					ft_lstiter(t_list	*lst, void (*f)(void *));
t_list					*ft_lstmap(t_list *lst, void *(*f)(void *),
			void (*del)(void *));
int						ft_islower(int c);
int						ft_isupper(int c);
int						ft_iswhitespace(int c);
void					split_that(t_array_list *words , char *line , char ch);
int						skip(char *line , int index, char ch);
#endif
