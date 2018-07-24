/*
** my_put_nbr.c for emacs in /home/Johanne-Franck/CPE_2016_matchstick
** 
** Made by Johanne-Franck NGBOKOLI
** Login   <Johanne-Franck@epitech.net>
** 
** Started on  Thu Feb 16 18:30:20 2017 Johanne-Franck NGBOKOLI
** Last update Sun Feb 26 16:16:53 2017 Johanne-Franck NGBOKOLI
*/

#include "lib.h"

int	my_put_nbr(int nb)
{
  int	neg;
  int	i;

  i = 0;
  neg = 0;
  if (nb == 0)
    return (0);
  if (nb < 0)
    {
      my_putchar('-');
      i++;
      nb = nb * -1;
    }
  if (nb >= 10)
    my_put_nbr(nb / 10);
  if (neg == 1)
    {
      neg = 0;
      my_putchar(nb % 10 + '1');
    }
  else
    my_putchar(nb % 10 + '0');
  i++;
  return (i);
}
