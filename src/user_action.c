/*
** user_action.c for emacs in /home/Johanne-Franck/CPE_2016_matchstick
** 
** Made by Johanne-Franck NGBOKOLI
** Login   <Johanne-Franck@epitech.net>
** 
** Started on  Thu Feb 16 16:43:33 2017 Johanne-Franck NGBOKOLI
** Last update Mon Feb 27 09:32:35 2017 Johanne-Franck NGBOKOLI
*/

#include "matchstick.h"
#include "get_next_line.h"
#include "lib.h"

void	player_action(int nb_matches, int num_line, char **map, int nb_line)
{
  char	**res;

  message_player(nb_matches, num_line);
  res = delete_matches(map, (num_line - 1), nb_matches);
  print_2D_tab(res, nb_line);
}

int	get_line(char *str)
{
  int	num_line;

  str = get_next_line(0);
  if (str == NULL)
    {
      my_putchar('\n');
      return (-3);
    }
  num_line = my_atoi(str);
  if (num_line == -2)
    my_putstr("Error: this line is out of range\n");
  return (num_line);
}

int	made_user_action(int matches_max, int nb_line, char **map)
{
  t_my_action	action;

  action.execute = 0;
  while (1)
    {
      my_putstr("Line:  ");
      action.num_line = get_line(action.str);
      if (action.num_line == -3)
	return (0);
      else if (action.num_line == 0 || action.num_line > nb_line)
	my_putstr("Error : this line is out of range\n");
      else if (action.num_line == -1)
	my_putstr("Error: invalid input (positive number expected)\n");
      else if (action.num_line > 0)
	{
	  action.final_execute = get_nb_matches_action(action, matches_max, map);
	  if (action.final_execute  == 1)
	    return (1);
	  else if (action.final_execute == 2)
	    return (2);
	  else if (action.final_execute == -3)
	    return (0);
	}
    }
}
