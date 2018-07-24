/*
** other_action.c for emacs in /home/Johanne-Franck/CPE_2016_matchstick
** 
** Made by Johanne-Franck NGBOKOLI
** Login   <Johanne-Franck@epitech.net>
** 
** Started on  Sat Feb 25 17:49:28 2017 Johanne-Franck NGBOKOLI
** Last update Sun Feb 26 19:39:06 2017 Johanne-Franck NGBOKOLI
*/

#include "get_next_line.h"
#include "matchstick.h"
#include "lib.h"

int	size_2D_tab(char **map)
{
  int	index;

  index = 0;
  while (map[index])
    {
      index++;
    }
  return (index);
}

int	execute_action(int nb_matches, int num_line, char **map, int matches_max)
{
  int	nb_line;

  nb_line = size_2D_tab(map);
  player_action(nb_matches, num_line, map, nb_line);
  if (nbr_alum_on_tab(map, nb_line) == 0)
    {
      my_putstr("You lost, too bad...\n");
      return (1);
    }
  AI_turn(map, matches_max, nb_line);
  if (nbr_alum_on_tab(map, nb_line) == 0)
    {
      my_putstr("I lost... snif... but I'll get you next time!!\n");
      return (2);
    }
}

int	get_nb_matches_action(t_my_action action, int matches_max, char **map)
{
  my_putstr("Matches:  ");
  action.str = get_next_line(0);
  if (action.str == NULL)
    {
      my_putchar('\n');
      return (-3);
    }
  action.nb_matches = my_atoi(action.str);
  if (action.nb_matches > matches_max)
    error(matches_max);
  else if (action.nb_matches == 0 || action.nb_matches == -2)
    my_putstr("Error: you have to remove at least one match\n");
  else if (action.nb_matches == -1)
    my_putstr("Error: invalid input (positive number expected)\n");
  else
    {
      action.execute = execute_action(action.nb_matches,
				      action.num_line, map, matches_max);
      if (action.execute == 1)
	return (1);
      if (action.execute == 2)
	return (2);
    }
}
