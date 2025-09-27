#include "libft.h"
#define BUFFER_SIZE 64


t_list *init_first_elem(int fd, t_list *list_of_caches)
{
  fd_remainder *line_remainder;

  if(fd < 0)
    return(NULL);
  line_remainder = malloc(sizeof(fd_remainder));  
  line_remainder->remainder = NULL;
  line_remainder->fd = fd;
  return(list_of_caches = ft_lstnew(line_remainder));
}

char *check_cache(int fd, t_list *list_of_caches)
{
  fd_remainder *cache_elem;

  if(!list_of_caches)
    return(NULL);
  cache_elem = list_of_caches->content;
  if( fd == cache_elem->fd)
    return(cache_elem->remainder);
  while(list_of_caches->next)
  {
    cache_elem = list_of_caches->content;
    if( fd == cache_elem->fd)
      return(cache_elem->remainder);
  }
  return(NULL);
}

void put_remainder_in_cache(int fd, char *offset, t_list *list_of_caches)
{
  fd_remainder *cache_elem;

  cache_elem = (fd_remainder *)(list_of_caches->content);
  if(fd == cache_elem->fd)
    cache_elem->remainder = ft_strdup(offset);
  //printf("get_remainder%s\n",cache_elem->remainder);
}

char *get_line(int fd, char *line)
{
  char *offset;
  char *buff;
  size_t read_bytes;

  read_bytes = -1;
  buff = malloc(BUFFER_SIZE + 1);
  if(!buff)
    return(NULL);
  if(!line)
  {
    offset = ft_strdup("\0");
    read_bytes = read(fd,buff,BUFFER_SIZE);
    buff[read_bytes] = '\0';
    line = ft_strjoin(offset,buff);
    free(offset);
  }
  while(!ft_strchr(line,'\n') && read_bytes != 0)
  {
    read_bytes = read(fd,buff,BUFFER_SIZE);
    buff[read_bytes] = '\0';
    offset = ft_strdup(line);
    free(line);
    line = ft_strjoin(offset,buff);
    free(offset);
  }
  free(buff);
  if(*line == '\0')
  {
    free(line);
    return(NULL);
  }
  return(line); 
}

char *get_next_line(int fd)
{
  static t_list *list_of_caches;
  char *ret_line;

  if(BUFFER_SIZE < 0 || fd < 0)
    return(NULL);
  ret_line = check_cache(fd, list_of_caches);
  ret_line = get_line(fd, ret_line);
    // if(!list_of_caches)
  //   list_of_caches = init_first_elem(fd, list_of_caches);
 return(ret_line);
}