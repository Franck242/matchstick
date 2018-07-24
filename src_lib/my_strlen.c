/*
** my_strlen.c for emacs in /home/Johanne-Franck/CPE_2016_matchstick
** 
** Made by Johanne-Franck NGBOKOLI
** Login   <Johanne-Franck@epitech.net>
** 
** Started on  Wed Feb 15 18:52:25 2017 Johanne-Franck NGBOKOLI
** Last update Sat Feb 25 18:17:23 2017 Johanne-Franck NGBOKOLI
*/

#include "lib.h"

int	my_strlen(char *str)
{
  int	index;

  index = 0;
  while (str[index] != '\0')
    {
      index = index + 1;
    }
  return (index);
}
