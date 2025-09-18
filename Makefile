##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC 		= 		src/main.c \
					src/handle_errors.c \
					src/run_simulation.c \

OBJ 		=		$(SRC:.c=.o)

NAME 		=	 	panoramix

CPPFLAGS	=		-iquote include/

CFLAGS 		=		-Werror -Wall -Wextra

LIB			=		-lpthread

CC 		?=		gcc

RM 		= 		rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIB)

debug: CFLAGS += -g3
debug: re

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:	fclean clean all re debug
