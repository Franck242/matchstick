/*
** macthstick.h for emacs in /home/Johanne-Franck/CPE_2016_matchstick
** 
** Made by Johanne-Franck NGBOKOLI
** Login   <Johanne-Franck@epitech.net>
** 
** Started on  Wed Feb 15 16:45:59 2017 Johanne-Franck NGBOKOLI
** Last update Sun Feb 26 19:29:21 2017 Johanne-Franck NGBOKOLI
*/

#include <time.h>
#define EXIT_ERROR 84

#ifndef MATCHSTICK_H_
# define MATCHSTICK_H_

typedef struct	s_my_compt
{
  int	i;
  int	x;
  int	y;
  int	z;
}	t_my_compt;

typedef struct	s_my_init_value
{
  char	*str;
  int	i;
  int	space;
  int	k;
  int	index;
}	t_my_initvalue;

typedef struct	s_my_action
{
  char	*str;
  int	num_line;
  int	nb_matches;
  int	execute;
  int	final_execute;
}	t_my_action;

typedef struct	s_my_main_value
{
  int	nb_line;
  int	nb_matches;
  int	size;
  char	*str;
  char	**map;
  int	exec;
}	t_my_main_value;

char    *init_map(int nb);
int	get_nbr_matches(char *str);
void	print_line(int nb);
void	print_space(int nbr);
int	made_user_action(int nb_matches, int nb_line, char **map);
void	print_2D_tab(char **tab, int size);
char    **tab_map(char *str, int size);
char	**delete_matches(char **map, int num_line, int nb_matches);
int	nbr_of_alum(char *str);
int	AI_turn(char **map, int nb_max, int num_line_max);
int	error_arguments(int ac, char **argv);
void	error_message();
void	message_player(int nb_matches, int num_line);
void	error(int nb);
int	nbr_alum_on_tab(char **map, int nb_line);
int	nbr_alum_on_line(char *line);
int	execute_action(int nb_matches, int num_line, char **map, int matches_max);
int	get_nb_matches_action(t_my_action action, int matches_max, char **map);
void	player_action(int nb_matches, int num_line, char **map, int nb_line);

#endif /* MATCHSTICK_H_ */
