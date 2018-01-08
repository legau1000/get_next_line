##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile
##

CFLAGS	=	-Iinclude

SRC	=	test.c		\
		../get_next_line.c

OBJ	=	$(SRC:.c=.o)

NAME	=	units_tests

.SILENT:

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -lcriterion
		@echo Compilation tests faite!

all:	$(NAME)

clean:
	rm -f $(OBJ)
		@echo Clean fait!

fclean: clean
	rm -f $(NAME)
		@echo Fclean fait!

re:	fclean all
		@echo RE fait!

.PHONY: clean
