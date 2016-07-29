##
## makefile for makefile ex2 jour10 in /u/all/sundas_c/cu/rendu/piscine/Jour_10
## 
## Made by christophe sundas
## Login   <sundas_c@epitech.net>
## 
## Started on  Tue Oct 21 18:25:49 2008 christophe sundas
## Last update Tue Oct 28 00:08:17 2008 christophe sundas
##

NAME = eval_expr
SRC = calcul.c eval_expr.c format_str.c parenthesis_mode.c
OBJ = $(SRC:.c=.o)
CFLAGS =  -I/u/all/sundas_c/rendu/include -I.
INCLUDES = -L/u/all/sundas_c/rendu/lib/my -lmy
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