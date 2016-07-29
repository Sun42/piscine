##
## Makefile for Makefile de cat in /u/all/sundas_c/cu/rendu/piscine/Jour_12/cat
## 
## Made by christophe sundas
## Login   <sundas_c@epitech.net>
## 
## Started on  Thu Oct 23 18:18:29 2008 christophe sundas
## Last update Thu Oct 23 18:42:41 2008 christophe sundas
##
##
## Makefile for makefile in /u/all/sundas_c/rendu/lib/my
## 
## Made by christophe sundas
## Login   <sundas_c@epitech.net>
## 
## Started on  Mon Oct 20 21:52:16 2008 christophe sundas
## Last update Tue Oct 21 01:24:20 2008 christophe sundas
##

CC 			= gcc
NAME 			= cat
SRC 			= cat.c			
HEADERS			= my.h
INCLUDES 		= -I/u/all/sundas_c/cu/rendu/include
CFLAGS 			+=  -W -Wall -ansi -pedantic -L${HOME}/rendu/lib/my -lmy
OBJ 			= $(SRC:.c=.o)
RM 			= rm -f


$(NAME): all

all:
	$(CC) -c  $(SRC) $(INCLUDES)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean: 
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

.PHONY: all clean fclean re	

#cc -c cat.c -I${HOME}/rendu/include
#cc -o lol cat.o -L${HOME}/rendu/lib/my -lmy