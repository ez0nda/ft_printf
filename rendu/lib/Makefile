# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ezonda <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/16 11:36:59 by ezonda            #+#    #+#              #
#    Updated: 2019/01/16 13:08:09 by ezonda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_atoi.c ft_isdigit.c ft_itoa.c ft_putchar.c ft_putnbr.c ft_putstr.c \
	ft_strnew.c ft_strrev.c ft_recursive_power.c ft_strlen.c

OBJ = ft_atoi.o ft_isdigit.o ft_itoa.o ft_putchar.o ft_putnbr.o ft_putstr.o \
	  ft_strnew.o ft_strrev.o ft_recursive_power.o ft_strlen.o

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@$(CC) $(FLAGS) -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "Compilation"
	@echo "Creation des fichiers objets"
	@echo "Creation de $(NAME)"

%.o: %.c
	$(CC) -o $@ -c $< $(FLAGS) -I./includes

clean:
	@rm -f $(OBJ)
	@echo "Suppression des fichiers objets"

fclean:
#	@rm -f $(OBJ) supprime les .c
	@rm -f $(NAME)
	@echo "Suppression des fichiers objets (pas vraiment...)"
	@echo "Suppression de $(NAME)"

re: fclean all

.PHONY: clean fclean re all
