#include "libft.h"
#define BUFFER_SIZE 64


fd_remainder *init_cache(int fd, fd_remainder *line_remainder)
{
  if(!fd)
    return(NULL);
  line_remainder = malloc(sizeof(fd_remainder));  
  line_remainder->remainder = NULL;
  line_remainder->fd = fd;
  printf("init_cache\n");
  return(line_remainder);
}

void check_cache(int fd, t_list **list_of_caches)
{
  fd_remainder *line_remainder;

  
  printf("check_remainder\n");
  if (!*list_of_caches)
  {
    line_remainder = NULL;
    line_remainder = init_cache(fd,line_remainder); // тут выделяется память при инициализации
    *list_of_caches = ft_lstnew(line_remainder); // тут выделяется память при инициализации
  }
  printf("check_remainder end\n");
}

void put_remainder_in_cache(int fd, char *offset, t_list *list_of_cahches)
{
  fd_remainder *cache_elem;

  cache_elem = (fd_remainder *)(list_of_cahches->content);
  if(fd == cache_elem->fd)
    cache_elem->remainder = ft_strdup(offset);
  printf("get_remainder%s\n",cache_elem->remainder);
}

char *get_next_line(int fd)
{
  static t_list *list_of_caches;
  size_t read_bytes;
  char *buff;
  char *ret_line;
  char *offset;

  check_cache(fd, &list_of_caches);
  if(BUFFER_SIZE > 0)
    buff = malloc(BUFFER_SIZE + 1);
  if(buff && fd >= 0)
    read_bytes = read(fd, buff, BUFFER_SIZE);  
  buff[BUFFER_SIZE] = '\0';
  if(ft_strchr(buff,'\n'))
  {
    offset = (ft_strchr(buff,'\n'));
    put_remainder_in_cache(fd, offset, list_of_caches);
    *offset = '\0';
    ret_line = ft_strdup(buff); 
  }
  // while(!ft_strchr(buff,'\n'))
  // {

  // }
 printf("offset = %ld\n",ret_line - buff);
 printf("%ld\n",read_bytes);
 free(buff);
 return(ret_line);
}