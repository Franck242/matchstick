/*
** my_str_isnum.c for emacs in /home/Johanne-Franck/CPE_2016_matchstick
** 
** Made by Johanne-Franck NGBOKOLI
** Login   <Johanne-Franck@epitech.net>
** 
** Started on  Thu Feb 16 16:57:01 2017 Johanne-Franck NGBOKOLI
** Last update Sat Feb 25 18:17:13 2017 Johanne-Franck NGBOKOLI
*/

#include "lib.h"

int	my_str_isnum(char *str)
{
  int	i;

  if (my_strlen(str) == 0)
    return (1);
  i = 0;
  if (str[0] == '-')
    i = 1;
  while (str[i] != '\0')
    {
      if (!(str[i] >= '0' && str[i] <= '9'))
	{
	  return (0);
	}
      i = i + 1;
    }
  return (1);
}
