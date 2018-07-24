##
## Makefile for emacs in /home/Johanne-Franck/CPE_2016_matchstick
## 
## Made by Johanne-Franck NGBOKOLI
## Login   <Johanne-Franck@epitech.net>
## 
## Started on  Wed Feb 15 16:45:29 2017 Johanne-Franck NGBOKOLI
## Last update Sun Feb 26 19:36:10 2017 Johanne-Franck NGBOKOLI
##

NAME	= 	matchstick

RM	=	rm -rf

CFLAGS	=	-I./header

CFLAGS  += -Wextra

SRCS	=	main.c                 \
		src_lib/get_next_line.c \
		src_lib/my_putchar.c     \
		src_lib/my_putstr.c	  \
		src/init_board.c	   \
		src_lib/my_strlen.c	    \
		src_lib/get_nbr.c	     \
		src/user_action.c	      \
		src_lib/my_str_isnum.c	       \
		src_lib/my_put_nbr.c		\
		src/intelligent_file.c		 \
		src/error_and_message.c		  \
		src/other_action.c

OBJS 	=	$(SRCS:.c=.o)


$(NAME): $(OBJS)
	$(CC) -g3 $(OBJS) $(LIBS) -o $(NAME)

all: $(NAME)
	@echo Compilation DONE

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	$(RM) *~
	$(RM) *#

re: fclean all

.PHONY: all clean fclean re
