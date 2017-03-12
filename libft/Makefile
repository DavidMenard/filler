# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmenard <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 10:03:47 by dmenard           #+#    #+#              #
#    Updated: 2017/03/12 17:05:26 by dmenard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_GREEN = "\033[32m"
C_YELLOW = "\033[33m"
C_RESET = "\033[0m"

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
DEP = libft.h ft_printf.h get_next_line.h
SRC = ft_memset.c ft_atoi.c ft_bzero.c ft_strlen.c ft_memcpy.c ft_memccpy.c \
	  ft_memmove.c ft_memchr.c ft_memcmp.c ft_strdup.c ft_strcpy.c			\
	  ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c		\
	  ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c		\
	  ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c		\
	  ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c ft_strnew.c		\
	  ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c		\
	  ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c		\
	  ft_strtrim.c ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c			\
	  ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c			\
	  ft_putnbr_fd.c ft_strsplit.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c	\
	  ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_putnstr.c ft_strdjoin.c		\
	  ft_lexisort.c ft_putchartab.c ft_strchrend.c ft_reverse_chartab.c		\
	  ft_putl.c ft_itoalong.c ft_putnbrlong.c ft_strquicksort.c 			\
	  ft_strvalueqsort.c ft_putstrpad.c get_next_line.c ft_putnbrl.c		\
	  ft_ishexa.c ft_atoihexa.c ft_isinstr.c ft_next_word.c ft_putfile.c	\
	  ft_iswspace.c ft_putfd.c ft_meminit.c ft_printf.c pcft_s.c pft_misc.c \
	  pft_parse_conv.c pcft_percent.c ft_wstrlen.c ft_putwchar.c 			\
	  ft_putwnstr.c ft_putwstr.c pcft_sl.c pcft_d.c ft_strprepad.c			\
	  ft_strpostpad.c ft_itoaabs.c pft_switchd.c pcft_hhd.c pcft_c.c		\
	  ft_wcharlen.c pcft_lc.c ft_itoabase_max.c ft_itoabase_max_abs.c		\
	  ft_strtolower.c pcft_x.c pcft_o.c ft_itoa_max_abs.c ft_itoa_umax_abs.c\
	  pcft_u.c ft_itoabase_umax_abs.c pcft_p.c pcft_y.c ft_putnstr_fd.c		\
	  ft_putstrpad_fd.c ft_putwnstr_fd.c ft_putwchar_fd.c pcft_hd.c			\
	  pcft_ld.c pcft_lld.c pcft_jd.c pcft_zd.c pcft_hhx.c pcft_hx.c			\
	  pcft_lx.c pcft_llx.c pcft_jx.c pcft_zx.c pft_switchx.c pft_switcho.c	\
	  pcft_hho.c pcft_ho.c pcft_lo.c pcft_llo.c pcft_jo.c pcft_zo.c			\
	  pft_switchu.c pcft_hhu.c pcft_hu.c pcft_lu.c pcft_llu.c pcft_ju.c		\
	  pcft_zu.c pft_parse_conv2.c ft_atoi_max.c ft_max.c ft_min.c			\
	  ft_lstaddend.c ft_lstnew_ref.c ft_abs.c ft_atoi_safe.c ft_lstcount.c	\
	  ft_lstget.c ft_round.c ft_charcount.c ft_strexclu.c ft_isupper.c

OBJ = $(SRC:.c=.o)
all: $(NAME)

$(NAME): $(SRC) $(DEP)
	@$(CC) $(CFLAGS) -I./ -c $(SRC)
	@ar rc $@ $(OBJ) $(POBJ)
	@ranlib $(NAME)
	@echo  $(C_GREEN)"[$(NAME)]		[Compilation Completed]"$(C_RESET)

clean:
	@rm -f $(OBJ)
	@echo $(C_YELLOW)"[$(NAME)]		[Object Files Deleted]"$(C_RESET)

fclean: clean cleanexe

cleanexe:
	@rm -f $(NAME)
	@echo  $(C_YELLOW)"[$(NAME)]		[Library Deleted]"$(C_RESET)

re: fclean all
