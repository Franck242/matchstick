/*
** my_putstr.c for emacs in /home/Johanne-Franck/CPE_2016_matchstick
** 
** Made by Johanne-Franck NGBOKOLI
** Login   <Johanne-Franck@epitech.net>
** 
** Started on  Wed Feb 15 17:59:28 2017 Johanne-Franck NGBOKOLI
** Last update Sat Feb 25 18:17:01 2017 Johanne-Franck NGBOKOLI
*/

#include "lib.h"

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
  return (0);
}
