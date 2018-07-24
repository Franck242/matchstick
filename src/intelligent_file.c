/*
** AI_file.c for emacs in /home/Johanne-Franck/CPE_2016_matchstick
** 
** Made by Johanne-Franck NGBOKOLI
** Login   <Johanne-Franck@epitech.net>
** 
** Started on  Tue Feb 21 19:44:29 2017 Johanne-Franck NGBOKOLI
** Last update Sun Feb 26 19:35:05 2017 Johanne-Franck NGBOKOLI
*/

#include "matchstick.h"
#include "lib.h"

int	random_value(int xmin, int xmax)
{
  return (rand()%(xmax - xmin) + xmin);
}

int	nbr_alum_on_line(char *line)
{
  int	index;
  int	res;

  index = 0;
  res = 0;
  while (line[index] != '\0')
    {
      if (line[index] == '|')
	res = res + 1;
      index = index + 1;
    }
  return (res);
}

int	nbr_alum_on_tab(char **map, int nb_line)
{
  int	index;
  int	nbr_alum;

  index = 0;
  nbr_alum = 0;
  while (index < nb_line)
    {
      nbr_alum = nbr_alum + nbr_alum_on_line(map[index]);
      index = index + 1;
    }
  return (nbr_alum);
}

int	AI_turn(char **map, int nb_max, int num_line_max)
{
  int	n_line;
  int	nb_matches;
  char	**result;
  int	nbr;

  srand(time(NULL));
  n_line = random_value(1, num_line_max);
  nb_matches = random_value(1, nb_max);
  result = delete_matches(map, (n_line - 1), nb_matches);
  my_putstr("\n");
  my_putstr("AI's turn...\n");
  my_putstr("AI removed ");
  my_put_nbr(nb_matches);
  my_putstr(" match(es) from line ");
  my_put_nbr(n_line);
  my_putchar('\n');
  print_2D_tab(result, num_line_max);
  if (nbr_alum_on_line(map[n_line]) > 0)
    my_putstr("\nYour turn:\n");
}
