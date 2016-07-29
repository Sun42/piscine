##
## Makefile for yes in /u/all/sundas_c/cu/rendu/piscine/bistro/operations/multiplication
## 
## Made by christophe sundas
## Login   <sundas_c@epitech.net>
## 
## Started on  Sat Nov  1 04:34:54 2008 christophe sundas
## Last update Sat Nov  1 22:39:44 2008 christophe sundas
##
NAME = calc
SRC = main.c
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