#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void *))
{   
    t_list *tmp;
    if (!lst || !del)
        return;
    while((*lst)->next != NULL)
    {
        tmp = *lst;
        *lst = (*lst)->next;
        del(tmp->content);
        free(tmp); 
    }
    if ((*lst)->next == NULL)
    {
        del((*lst)->content);
        free(*lst);
    }
    *lst = NULL; 
}