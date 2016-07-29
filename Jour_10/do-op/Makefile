##
## makefile for makefile ex2 jour10 in /u/all/sundas_c/cu/rendu/piscine/Jour_10
## 
## Made by christophe sundas
## Login   <sundas_c@epitech.net>
## 
## Started on  Tue Oct 21 18:25:49 2008 christophe sundas
## Last update Tue Oct 21 19:38:44 2008 christophe sundas
##

NAME = do-op
SRC = calcul.c do-op.c
OBJ = $(SRC:.c=.o)
CFLAGS =  -I.
INCLUDES = -L. -lmy
RM = rm -f
CC = gcc

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(INCLUDES)

all: $(NAME)

clean :
	$(RM) $(OBJ)
	$(RM) *~

fclean: clean
	$(RM) $(NAME)

.PHONY: all clean fclean re