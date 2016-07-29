##
## makefile for makefile ex2 jour10 in /u/all/sundas_c/cu/rendu/piscine/Jour_10
## 
## Made by christophe sundas
## Login   <sundas_c@epitech.net>
## 
## Started on  Tue Oct 21 18:25:49 2008 christophe sundas
## Last update Wed Nov  5 02:47:39 2008 christophe sundas
##

NAME = calc
SRC = 				main.c \
				eval_expr.c \
				utils.c \
				utils2.c \
				utils_cleanstr.c \
				parenthesis_mode.c \
				format_expr.c \
				operations.c \
				addition.c \
				soustraction.c \
				multiplication.c \
				division.c \
				modulo.c

OBJ = $(SRC:.c=.o)
CFLAGS = -I/u/all/sundas_c/rendu/include -I.
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