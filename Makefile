##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

NAME	=	mysh

CC	=	gcc

CFLAGS	+=	-Iinclude -g3

FILES	=	lib/my_putchar.c	\
		lib/my_putstr.c	\
		lib/my_strcpy.c	\
		lib/my_strlen.c	\
		lib/my_strdup.c	\
		lib/my_strcmp.c	\
		lib/my_intdup.c	\
		lib/my_getnbr.c	\
		lib/my_strcat.c	\
		lib/my_putnbr.c	\
		lib/my_strncmp.c	\
		src/gest_env.c	\
		src/gest_shell.c	\
		src/loop.c	\
		src/str2tab.c	\
		src/main.c

OBJ	=	$(FILES:.c=.o)

VAL	=	valgrind

RED             =       \033[0;31m
GREEN           =       \033[0;32m
GREY            =       \033[90m
BLUE            =       \033[0;94m
NC              =       \033[0m
IRED            =       \033[0;91m
PURPLE          =       \033[0;95m

all:	$(NAME)

$(NAME):	$(OBJ)
	@echo -e '${BLUE}Cflags${NC}: ${GREY}$(CFLAGS) ${NC}'
	@$(CC) $(OBJ) -o $(NAME) 2>>errors.txt\
	&& echo -e '${BLUE}Create${NC}: ${GREY}./$(NAME)${NC}'\
	|| echo -e '${RED}[ FAILED ]${NC}: __Create__${GREY} ./$(NAME)${NC}'

%.o :		%.c
	@-$(CC) -o $@ -c $< $(CFLAGS) 2>>errors.txt\
		&& echo -e '${GREEN} [ OK ]${NC} Build $<'\
		|| echo -e '${RED}[ FAILED ]${NC} __Build__ $<'\
		&& echo -ne '${PURPLE}' && grep  $< errors.txt |\
		grep warning |cut -d':' -f2- |cut -d'[' -f-1\
		&& echo -ne '${IRED}' && grep  $< errors.txt |\
		grep error |cut -d':' -f2-\
		||:

clean:
	@rm -f $(NAME)
	@rm -rf $(OBJ)
	@rm -rf vgcore.*
	@rm -rf errors.txt 2>/dev/null
	@echo -e '${BLUE}Clean${NC} : ${GREY}OK'

fclean:	clean
	@rm -rf $(NAME)
	@echo -e '${BLUE}Fclean${NC}: ${GREY}$(NAME) removed'

er:	re
	@$(VAL) ./$(NAME)

re:	fclean all
