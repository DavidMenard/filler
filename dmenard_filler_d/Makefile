# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmenard <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/21 07:52:30 by dmenard           #+#    #+#              #
#    Updated: 2017/03/07 23:50:06 by dmenard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_GREEN = "\033[32m"
C_YELLOW = "\033[33m"
C_RESET = "\033[0m"

NAME = dmenard.filler
CC = gcc
CFLAGS = -Wall -Wextra -Werror
IFLAGS = -I./includes -I../libft
SRC = main.c parser.c debug.c parser_get_grid.c parser_get_piece.c			\
	  clear_turn.c make_move.c char_identifier.c

OBJ = $(addprefix $(ODIR)/, $(addsuffix .o, $(basename $(SRC))))
LIBFT = ../libft/libftprintf.a
ODIR = ./obj
SDIR = ./src
DEP = ./includes/filler.h $(LIBFT)

all:		$(NAME) $(LIBFT)

$(NAME):	$(OBJ) $(DEP)
	@$(CC) $(OBJ) $(LIBFT) -o $@ $(IFLAGS)
	@echo  $(C_GREEN)"[$(NAME)]	[Compilation Completed]"$(C_RESET)

clean:
	@make clean -C ../libft
	@rm -rf $(ODIR)
	@echo $(C_YELLOW)"[$(NAME)]	[Object Files Deleted]"$(C_RESET)

fclean:		clean
	@make cleanexe -C ../libft
	@rm -f $(NAME)
	@echo  $(C_YELLOW)"[$(NAME)]	[Executable Deleted]"$(C_RESET)

$(LIBFT):
	@make -C ../libft

re: fclean all

$(ODIR)/%.o: $(SDIR)/%.c $(DEP)
	@mkdir -p $(ODIR)
	@$(CC) -c -o $@ $< $(CFLAGS) $(IFLAGS)

.PHONY: fclean clean all
