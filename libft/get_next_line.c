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

char *init_line(int fd, char *line)
{
  char *buff;
  size_t read_bytes;

  read_bytes = 1;
  buff = malloc(BUFFER_SIZE + 1);
  if(!buff)
    return(NULL);
  read_bytes = read(fd,buff,BUFFER_SIZE);
if (read_bytes <= 0)
{
    free(buff);
    return NULL;
}
  buff[read_bytes] = '\0';
  line = ft_strjoin("",buff);
  free(buff);
  return(line);
}

void purge_cache(int fd, t_list *list_of_caches)
{
  t_list *cur;
  fd_remainder *cache_elem;

  cur = list_of_caches;
  while (cur)
  {
    cache_elem = (fd_remainder *)cur->content;
    if(cache_elem && cache_elem->fd == fd)
    {
      if(cache_elem->remainder)
      {
        free(cache_elem->remainder);
        cache_elem->remainder = NULL;
      }
      return;
    }
    cur = cur->next;
  }
}

char *check_cache(int fd, t_list *list_of_caches)
{
  fd_remainder *cache_elem;

  if(!list_of_caches)
    return(NULL);
  cache_elem = list_of_caches->content;
  if( fd == cache_elem->fd)
    return ft_strdup(cache_elem->remainder);
  while(list_of_caches->next)
  {
    cache_elem = list_of_caches->content;
    if( fd == cache_elem->fd)
      return ft_strdup(cache_elem->remainder);
  }
  return(NULL);
}

void put_remainder_in_cache(int fd, char *offset, t_list *list_of_caches)
{
  fd_remainder *cache_elem;

  cache_elem = (fd_remainder *)(list_of_caches->content);
  if(fd == cache_elem->fd)
    cache_elem->remainder = ft_strdup(offset);
}

char *get_line(int fd, char *line, t_list *list_of_caches)
{
  char *offset;
  char *buff;
  size_t read_bytes;
  char *newline_pos;
  char *remainder;

  read_bytes = 1;
  buff = malloc(BUFFER_SIZE + 1);
  if(!buff)
    return(NULL);
  while(!ft_strchr(line,'\n') && read_bytes != 0)
  {
    read_bytes = read(fd,buff,BUFFER_SIZE);
    if (read_bytes <= 0)
      break;
    buff[read_bytes ] = '\0';
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
  newline_pos = ft_strchr(line, '\n');
  if (newline_pos)
  {
    remainder = ft_strdup(newline_pos + 1);
    *(newline_pos + 1) = '\0';
    if(*remainder != '\0')
      put_remainder_in_cache(fd, remainder, list_of_caches);
    free(remainder);
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
  if(!ret_line)
    ret_line = init_line(fd, ret_line);
  else
    purge_cache(fd, list_of_caches);
  if(!list_of_caches)
    list_of_caches = init_first_elem(fd, list_of_caches);
  if(ret_line != NULL)
    ret_line = get_line(fd, ret_line, list_of_caches);
 return(ret_line);
}

int main()
{
  int fd;
  char *line;

  fd = open("../text",O_RDONLY);
  line = get_next_line(fd);
  printf("%s",line);
  while(line != NULL)
  {
    free(line);
    line = get_next_line(fd);
    if(line != NULL)
      printf("%s",line);
  }
  free(line);
  return(0);
}