##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile
##

CC	=	gcc

OBJ	=	$(SRC:.c=.o)

NAME	=	a.aout

.SILENT:

$(NAME):

test_run:
	make -C tests/ re
	./units_tests
	make -C tests/ fclean

.PHONY: clean fclean re all
