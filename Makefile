# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmenard <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/22 17:22:18 by dmenard           #+#    #+#              #
#    Updated: 2017/03/15 18:31:02 by dmenard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_GREEN = "\033[32m"
C_YELLOW = "\033[33m"
C_RESET = "\033[0m"

PL_PATH = ./dmenard_filler_d
BA_PATH = ./battleground_d
PL_EXE = $(PL_PATH)/dmenard.filler
BA_EXE = $(BA_PATH)/battleground

ALL_EXE = $(PL_EXE) $(BA_EXE)

all:
	@make -C $(PL_PATH)
	@make -C $(BA_PATH)
	@cp $(PL_EXE) .
	@cp $(BA_EXE) .
	@echo $(C_GREEN)"[All binaries transfered]"$(C_RESET)

$(PL_EXE):
	@make -C $(PL_PATH)

$(BA_EXE):
	@make -C $(BA_PATH)

clean:
	@make clean -C $(PL_PATH)
	@make clean -C $(BA_PATH)

fclean:
	@make fclean -C $(PL_PATH)
	@make fclean -C $(BA_PATH)
	@if [ -f dmenard.filler ]; then rm dmenard.filler; fi;
	@if [ -f battleground ]; then rm battleground; fi;
	@echo $(C_YELLOW)"[All binaries destroyed]"$(C_RESET)

re: fclean all

.PHONY: all clean fclean re 

.SILENT:
