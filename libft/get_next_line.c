#include "libft/libft.h"
#define BUFFER_SIZE 64


void init_cache(int fd)
{
  printf("init_cahce\n");
}

void check_cache(int fd, fd_list lst)
{
  printf("check_remainder\n");
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
  size_t read_bytes;
  char *buff;
  static fd_list lst;
  char *ret_line;

  
  check_cache(fd,lst);
  buff = malloc(BUFFER_SIZE + 1);
  read_bytes = read(fd, buff, BUFFER_SIZE);
  buff[BUFFER_SIZE] = '\0';
  if(ft_strchr(buff,'\n'))
  {
    get_line();
    ret_line = ft_strdup(buff);
  }
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

int main()
{
  int fd;
  char *line;
  //char **list_of_lines;

  line = NULL;
  fd = open("../AttackDefense", O_RDONLY);
  line = get_next_line(fd);
  printf("%s\n",line);
  free(line);
  return(0);
}