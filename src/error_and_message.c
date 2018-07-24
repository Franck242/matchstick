/*
** error_and_message.c for emacs in /home/Johanne-Franck/CPE_2016_matchstick
** 
** Made by Johanne-Franck NGBOKOLI
** Login   <Johanne-Franck@epitech.net>
** 
** Started on  Tue Feb 21 21:35:58 2017 Johanne-Franck NGBOKOLI
** Last update Sat Feb 25 18:18:43 2017 Johanne-Franck NGBOKOLI
*/

#include "matchstick.h"
#include "lib.h"

int	error_arguments(int ac, char **argv)
{
  int	index;

  index = 1;
  while (index <= ac - 1)
    {
      if (my_str_isnum(argv[index]) == 0)
	{
	  write(2, " ERROR, all argument must be numbers\n", 37);
	  return (EXIT_ERROR);
	}
      index++;
    }
}

char	**delete_matches(char **map, int num_line, int nb_matches)
{
  int	size;
  int	index;
  int	i;

  size = my_strlen(map[num_line]) - 1;
  index = size;
  i = 0;
  while (index >= 0 && i< nb_matches)
    {
      if (map[num_line][index] == '|')
	{
	  map[num_line][index] = ' ';
	  i++;
	}
      index = index - 1;
    }
  return (map);
}

void	error_message()
{
   my_putstr("Error : this line is out of range\n");
   my_putstr("line :\n");
}

void	message_player(int nb_matches, int num_line)
{
   my_putstr("Player removed ");
   my_put_nbr(nb_matches);
   my_putstr(" match(es) from line ");
   my_put_nbr(num_line);
   my_putchar('\n');
}

void	error(int nb)
{
  my_putstr("Error : you cannot remove more than ");
  my_put_nbr(nb);
  my_putstr(" matches per turn\n");
}
