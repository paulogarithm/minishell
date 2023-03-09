##
## EPITECH PROJECT, 2022
## radar
## File description:
## Makefile
##


## ---------- ##

BIN		= mysh

INC		=

SRC		= src/main.c\
		src/check.c\
		src/vaguelette.c\
		src/custom.c\
		src/env.c\
		src/pipe.c\
		src/lib.c\


## ---------- ##

CC	  = gcc
RM	  = rm -rf

LIB 	= lib/my_putchar.c\
		lib/my_putstr.c\
		lib/my_countnb.c\
		lib/my_countstr.c\
		lib/my_addchar.c\
		lib/my_addstr.c\
		lib/my_conv_nb_str.c\
		lib/my_conv_str_nb.c\
		lib/my_conv_str_array.c\
		lib/my_printf.c\
		lib/my_scanf.c\
		lib/my_compstr.c\
		lib/my_dupstr.c\
		lib/my_isnb.c\
		lib/my_revstr.c\
		lib/my_cutstr.c\
		lib/my_findinstr.c\
		lib/my_replace_char.c\

SRCOBJ  = $(SRC:.c=.o)
LIBOBJ  = $(LIB:.c=.o)

LIBNAME = lib$(BIN).a

CFLAGS  = -Wall -Wextra -g3


## ---------- ##

all: build

build: $(LIBOBJ) $(SRCOBJ)
	ar rc $(LIBNAME) $(LIBOBJ) $(SRCOBJ)
	$(CC) -L. -l$(BIN) $(INC) -o $(BIN)

clean:
	$(RM) $(SRCOBJ)
	$(RM) $(LIBOBJ)
	$(RM) $(LIBNAME)
	$(RM) *.c~

fclean: clean
	$(RM) $(SRCNAME)

re: fclean build

pol: re
	make clean

.PHONY:
	clean fclean re build all pol
