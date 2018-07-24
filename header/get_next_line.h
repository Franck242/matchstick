/*
** get_next_line.h for emacs in /home/Johanne-Franck/CPE_2016_getnextline
** 
** Made by Johanne-Franck NGBOKOLI
** Login   <Johanne-Franck@epitech.net>
** 
** Started on  Tue Jan  3 14:59:44 2017 Johanne-Franck NGBOKOLI
** Last update Sun Jan 15 13:59:10 2017 Johanne-Franck NGBOKOLI
*/

#ifndef READ_SIZE
# define READ_SIZE 1500
#endif /* !READ_SIZE */

#ifndef GET_NEXT_LINE_H_
#define GET_NEXT_LINE_H_

#include <unistd.h>
#include <stdlib.h>
#define ERROR_EXIT 84

char	*get_next_line(const int fd);

#endif /* GET_NEXT_LINE_H_ */
