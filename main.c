/*
** main.c for emacs in /home/Johanne-Franck/CPE_2016_matchstick
** 
** Made by Johanne-Franck NGBOKOLI
** Login   <Johanne-Franck@epitech.net>
** 
** Started on  Wed Feb 15 17:02:14 2017 Johanne-Franck NGBOKOLI
** Last update Tue Feb 28 15:49:57 2017 Johanne-Franck NGBOKOLI
*/

#include "matchstick.h"
#include "lib.h"

int	print_board(char **argv, t_my_main_value val)
{
  val.nb_line = my_atoi(argv[1]);
  val.nb_matches = my_atoi(argv[2]);
  val.str = init_map(val.nb_line);
  val.map = tab_map(val.str, val.nb_line);
  if (val.map == NULL)
    return (EXIT_ERROR);
  print_2D_tab(val.map, val.nb_line);
  my_putchar('\n');
  my_putstr("Your turn:\n");
  val.size = made_user_action(val.nb_matches, val.nb_line, val.map);
}

int	argv_error(char **argv)
{
  if (my_atoi(argv[2]) <= 0 || (my_atoi(argv[1]) <= 0
				|| my_atoi(argv[1]) > 100))
    {
      write(2, "ERROR, invalid number of line or of matches\n", 44);
      return (EXIT_ERROR);
    }
}

int	main(int ac, char **argv)
{
  t_my_main_value	val;

  if ( ac > 3 ||  ac < 3)
    {
      write(2, "ERROR, too few or too many arguments\n", 37);
      return (EXIT_ERROR);
    }
  if (ac == 3)
    {
      if (argv_error(argv) == EXIT_ERROR)
	return (EXIT_ERROR);
      if (my_atoi(argv[1]) > 10)
	return (0);
      if (error_arguments(ac, argv) == EXIT_ERROR)
	return (EXIT_ERROR);
      val.exec = print_board(argv, val);
      if (val.exec == EXIT_ERROR)
	return (EXIT_ERROR);
      if (val.size == 1)
	return (1);
      else if (val.size  == 2)
	return (2);
    }
  return (0);
}
