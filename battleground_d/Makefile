# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmenard <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/21 07:52:30 by dmenard           #+#    #+#              #
#    Updated: 2017/03/18 14:54:40 by dmenard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_GREEN = "\033[32m"
C_YELLOW = "\033[33m"
C_RESET = "\033[0m"

NAME = battleground
CC = gcc
CFLAGS = -Wall -Wextra -Werror
IFLAGS = -I./includes -I../libft
NCURSES = -lncurses
SRC = main.c parser.c parser_get_turns.c error.c print_debug.c win_grid.c \
	  input.c win_ban.c display.c colors.c

OBJ = $(addprefix $(ODIR)/, $(addsuffix .o, $(basename $(SRC))))
LIBFT = ../libft/libftprintf.a
ODIR = ./obj
SDIR = ./src
DEP = ./includes/battle.h $(LIBFT)

all:		$(NAME) $(LIBFT)

$(NAME):	$(OBJ) $(DEP)
	@$(CC) $(OBJ) $(LIBFT) $(NCURSES) -o $@ $(IFLAGS)
	@echo  $(C_GREEN)"[$(NAME)]		[Compilation Completed]"$(C_RESET)

clean:
	@make clean -C ../libft
	@rm -rf $(ODIR)
	@echo $(C_YELLOW)"[$(NAME)]		[Object Files Deleted]"$(C_RESET)

fclean:		clean
	@make cleanexe -C ../libft
	@rm -f $(NAME)
	@echo  $(C_YELLOW)"[$(NAME)]		[Executable Deleted]"$(C_RESET)

$(LIBFT):
	@make -C ../libft

re: fclean all

$(ODIR)/%.o: $(SDIR)/%.c $(DEP)
	@mkdir -p $(ODIR)
	@$(CC) -c -o $@ $< $(CFLAGS) $(IFLAGS)

.PHONY: fclean clean all

.SILENT:
