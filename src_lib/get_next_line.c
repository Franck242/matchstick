/*
** get_next_line.c for emacs in /home/Johanne-Franck/CPE_2016_getnextline
** 
** Made by Johanne-Franck NGBOKOLI
** Login   <Johanne-Franck@epitech.net>
** 
** Started on  Tue Jan  3 14:40:21 2017 Johanne-Franck NGBOKOLI
** Last update Sun Jan 15 13:58:38 2017 Johanne-Franck NGBOKOLI
*/

#include "get_next_line.h"

char	*get_available_memory(int size)
{
  char	*str;

  str = malloc(size);
  if (str == NULL)
    {
      return (NULL);
    }
  else
    return (str);
}

int	save_str_size(char *str, int size)
{
  int		index;
  int		index_str;
  static char	str_saved[READ_SIZE + 1];

  index = 0;
  index_str = size;
  if (str[0] == '\0')
    {
      while (str_saved[index] != '\0')
	str[index++] = str_saved[index++];
      str[0] = '\0';
    }
  else if (str[index_str] == '\n')
    {
      index_str = index_str + 1;
      while (str[index_str] != '\0')
	{
	  str_saved[index] = str[index_str];
	  index = index + 1;
	  index_str = index_str + 1;
	}
      str_saved[index] = '\0';
    }
  return (index);
}

char	*put_str_in_allocate_memory(char *src)
{
  int	index;
  int	index_res;
  int	size;
  char	*res;

  index = 0;
  index_res = 0;
  size = 0;
  if (src == NULL)
    return (get_available_memory(READ_SIZE + 1));
  while (src[size] != '\0');
  {
    res = get_available_memory(READ_SIZE + size);
    size = size + 1;
  }
  while (index < size)
    {
      res[index_res] = src[index];
      index_res = index_res + 1;
      index = index + 1;
    }
  res[index_res] = '\0';
  index = 0;
  free(src);
  return (res);
}

char	*get_str_result(int *size, int *saving_size, const int fd, char *str)
{
  char	*res;
  int	index;

  res = NULL;
  index = 0;
  *saving_size = 1;
  while (*saving_size != 0 && str[index] != '\n')
    {
      if ((res = put_str_in_allocate_memory(res)) == NULL)
	return (NULL);
      index = 0;
      *saving_size = save_str_size(str, 0);
      if (*saving_size == 0)
	if ((*saving_size = read(fd, str, READ_SIZE)) < 0)
	  return (NULL);
      str[*saving_size] = '\0';
      while (index < *saving_size && str[index] != '\n')
	{
	  res[*size] = str[index];
	  *size = *size + 1;
	  index = index + 1;
	}
      res[*size] = '\0';
    }
  return (res);
}

char	*get_next_line(const int fd)
{
  char	*result;
  char	*str;
  int	save;
  int	index;
  int	size;

  index = 0;
  size = -1;
  if ((str = get_available_memory(READ_SIZE + 1)) == NULL)
    return (NULL);
  str[0] = '\0';
  if ((result = get_str_result(&index, &save, fd, str)) == NULL)
    return (NULL);
  while (++size < READ_SIZE && str[size] != '\n');
  {
    if (str[size] == '\n')
      {
	save_str_size(str, size);
      }
    free(str);
  }
  if (index != 0 || save != 0)
       return (result);
  return (NULL);
}
