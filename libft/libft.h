#ifndef LIBFT_H
#define LIBFT_H
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct fd_list
{
    char            *remainder;
    int             fd;
    struct fd_list  *next;
}                   fd_list;

typedef struct s_list
{
             void *content;
        struct s_list *next;
}   t_list;

void *ft_calloc(size_t num, size_t size);
void ft_bzero(void *s, size_t  n);

void *ft_memcpy(void *dest, const void *src, size_t n);
void *ft_memccpy(void *dest, const void *src, int c, size_t n);
void *ft_memset(void *s, int c, size_t n);
void *ft_memmove(void *dest, const void *src, size_t n);
void *ft_memchr(const void *s, int c, size_t n);


size_t ft_strlen(const char *s); 
size_t ft_strlcpy(char *dst , const char *src , size_t size);
size_t ft_strlcat(char *dst , const char *src , size_t size);
char * ft_strnstr(const char *big, const char *little, size_t len);
char *ft_strchr(const char *s, int c);
char *ft_strrchr(const char *s, int c);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_strdup(const char *str);


int ft_isalpha(int c);
int ft_isascii(int c);
int ft_isalnum(int c);
int ft_isdigit(int c);
int ft_isprint(int c);
int ft_toupper(int c);
int ft_tolower(int c);
int ft_isspace(int c);

int ft_atoi(const char *nptr);

t_list *ft_lstnew(void *content);
void ft_lstadd_front(t_list **lst, t_list *new);
int ft_lstsize(t_list *lst);
t_list *ft_lstlast(t_list *lst);
void ft_lstadd_back(t_list **lst, t_list *new);




char *get_next_line(int fd);



#endif