/*
** init_board.c for emacs in /home/Johanne-Franck/CPE_2016_matchstick
** 
** Made by Johanne-Franck NGBOKOLI
** Login   <Johanne-Franck@epitech.net>
** 
** Started on  Wed Feb 15 17:27:29 2017 Johanne-Franck NGBOKOLI
** Last update Sun Feb 26 19:37:47 2017 Johanne-Franck NGBOKOLI
*/

#include "matchstick.h"
#include "lib.h"

char	**tab_map(char *str, int size)
{
  t_my_compt	index;
  char		**tab;

  index.i = 0;
  index.y = size -1;
  index.z = size - 1;
  if ((tab = malloc(sizeof(char*) * ((size) + 1))) ==  NULL)
    return (NULL);
  while (index.i < size)
    {
      index.x = 0;
      tab[index.i] = malloc(sizeof(char) * (size * 2) -1);
      while (index.x < (size * 2))
	{
	  if (index.x >= index.z && index.x <= index.y )
	    tab[index.i][index.x] = '|';
	  else
	    tab[index.i][index.x] = ' ';
	  index.x += 1;
	}
      index.y += 1;
      index.z -= 1;
      index.i += 1;
    }
  return (tab);
}

void	init_value(int *x, int *y, int *z)
{
  *x = 0;
  *y = 1;
  *z = 0;
}

char	*init_map(int nb)
{
  t_my_initvalue	val;

  init_value(&val.k, &val.i, &val.index);
  val.str = malloc(sizeof(char *) * ((nb) + 1));
  while (val.i <= nb)
     {
      val.space = 1;
      while (val.space <= nb - val.i)
	{
	  val.str[val.index] = ' ';
	  ++val.space;
	  val.index++;
	}
      while (val.k != 2 * val.i -1)
	{
	  val.str[val.index] = '|';
	  ++val.k;
	  val.index++;
	}
      val.str[val.index] = '\n';
      val.k = 0;
      ++val.i;
      val.index++;
    }
  return (val.str);
}

void	print_line(int nb)
{
  int	i;

  i = 0;
  while (i <= (nb * 2))
    {
      my_putchar('*');
      i++;
    }
  my_putchar('\n');
}

void	print_2D_tab(char **map, int size)
{
  int	i;
  int	j;

  i = 0;
  print_line(size);
  while (i < size)
    {
      j = 0;
      my_putchar('*');
      while (j < (size * 2) - 1)
	{
	  my_putchar(map[i][j]);
	  j++;
	}
      my_putchar('*');
      i++;
      my_putchar('\n');
    }
  print_line(size);
}
