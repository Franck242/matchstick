/*
** get_nbr.c for emacs in /home/Johanne-Franck/CPE_2016_matchstick
** 
** Made by Johanne-Franck NGBOKOLI
** Login   <Johanne-Franck@epitech.net>
** 
** Started on  Wed Feb 15 19:03:41 2017 Johanne-Franck NGBOKOLI
** Last update Sun Feb 26 19:40:48 2017 Johanne-Franck NGBOKOLI
*/

#include "lib.h"

int	my_atoi(char *str)
{
  int res;

  res = 0;
  if (my_str_isnum(str) == 0)
    return (-1);
  if (str[0] == '-')
    return (-2);
  while (*str)
    {
      if (*str >= '0' && *str <= '9')
	{
	  res = res * 10;
	  res = res + *str - '0';
	}
      str = str + 1;
    }
  return (res);
}
