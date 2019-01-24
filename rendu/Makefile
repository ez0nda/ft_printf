# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ezonda <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/16 11:36:59 by ezonda            #+#    #+#              #
#    Updated: 2019/01/23 16:01:42 by jebrocho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c ft_dispatch.c ft_float.c ft_hexa.c ft_indic_csp.c ft_octal.c \
	ft_parser.c ft_print_numbers.c ft_unsigned.c ft_indic_mod.c ft_flag_u.c

LIB_SRC = lib/ft_atoi.c lib/ft_isdigit.c lib/ft_itoa.c lib/ft_putchar.c \
	lib/ft_putnbr.c lib/ft_putstr.c lib/ft_strnew.c lib/ft_strrev.c \
	lib/ft_recursive_power.c lib/ft_strlen.c lib/ft_strdup.c lib/ft_strcmp.c \
	lib/ft_strsub.c

OBJ = $(SRC:.c=.o)

LIB_OBJ = ft_atoi.o ft_isdigit.o ft_itoa.o ft_putchar.o ft_putnbr.o ft_putstr.o\
	ft_strnew.o ft_strrev.o ft_recursive_power.o ft_strlen.o ft_strdup.o \
	ft_strcmp.o ft_strsub.o

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@$(CC) $(FLAGS) -c $(SRC) $(LIB_SRC)
	@ar rc $(NAME) $(OBJ) $(LIB_OBJ)
	@ranlib $(NAME)
	@echo "Compilation"
	@echo "Creation des fichiers objets"
	@echo "Creation de $(NAME)"

%.o: %.c
	$(CC) -o $@ -c $< $(FLAGS) -I./includes

clean:
	@rm -f $(OBJ)
	@rm -f $(LIB_OBJ)
	@echo "Suppression des fichiers objets"

fclean:
	@rm -rf $(OBJ)
	@rm -rf $(LIB_OBJ)
	@rm -rf $(NAME)
	@echo "Suppression des fichiers objets"
	@echo "Suppression de $(NAME)"

re: fclean all

.PHONY: clean fclean re all
