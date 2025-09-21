#include "libft.h"
#define BUFFER_SIZE 64


void init_cache(int fd, fd_remainder *line_remainder)
{
  if(!fd)
    return;
  line_remainder = malloc(sizeof(fd_remainder));  
  line_remainder->remainder = NULL;
  line_remainder->fd = fd;
  printf("init_cache\n");
}

void check_cache(int fd, t_list *list_of_caches)
{
  fd_remainder *line_remainder;

  
  printf("check_remainder\n");
  if (!list_of_caches)
  {
    line_remainder = NULL;
    init_cache(fd,line_remainder); // тут выделяется память при инициализации
    ft_lstnew(line_remainder); // тут выделяется память при инициализации
  }
  printf("check_remainder end\n");
}

void put_remainder_in_cache()
{
  printf("get_remainder\n");
}

void get_line()
{
  printf("get_line\n");
}

char *get_next_line(int fd)
{
  static t_list *list_of_caches;
  size_t read_bytes;
  char *buff;
  char *ret_line;
  char *offset;

  check_cache(fd, list_of_caches);
  if(BUFFER_SIZE > 0)
    buff = malloc(BUFFER_SIZE + 1);
  if(buff && fd >= 0)
    read_bytes = read(fd, buff, BUFFER_SIZE);  
  buff[BUFFER_SIZE] = '\0';
  offset = (ft_strchr(buff,'\n') + 1);
  *offset = '\0';
  ret_line = ft_strdup(buff); 
  printf("offset = %ld\n",ret_line - buff);
  
  // buff[31] = '\0';
 printf("%ld\n",read_bytes);
  // printf("%s\n",(char*)buff);  
  if(ret_line)
    {
      printf("%d\n",fd);
    }
  free(buff);
  return(ret_line);
}