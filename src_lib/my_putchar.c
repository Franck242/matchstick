/*
** my_putchar.c for emacs in /home/Johanne-Franck/CPE_2016_matchstick
** 
** Made by Johanne-Franck NGBOKOLI
** Login   <Johanne-Franck@epitech.net>
** 
** Started on  Wed Feb 15 17:58:25 2017 Johanne-Franck NGBOKOLI
** Last update Sat Feb 25 18:16:40 2017 Johanne-Franck NGBOKOLI
*/

#include "lib.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}
