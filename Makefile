# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anben <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/21 17:24:20 by anben             #+#    #+#              #
#    Updated: 2019/07/21 17:24:22 by anben            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = ft_ls
CC = gcc
NOR = norminette
LIBFT = ./libft/
ARC = ar rc
FLAGS = -Wall -Werror -Wextra
#SRC_PATH = ./srcs/
SRC =	ft_ls.c \
#		error404.c \
		opitions.c \
		sort.c \
		flags.c \
		display.c



#INC =  -I ./includes/ft_ls.h -I $(LIBFT)libft.h
SRC =	ft_ls.o \
#		error404.o \
		opitions.o \
		sort.o \
		flags.o \
		display.o


all: $(NAME)

$(NAME): $(SRCO)
	@make -C $(LIBFT_PATH)
	@cc $(FLAGS) -o $(NAME) $(SRC) $(LIBFT)libft.a
	@echo "\033[32mBinary \033[1;32m$(NAME)\033[1;0m\033[32m Created.\033[0m"

$(SRC_PATH)%.o: $(SRC_PATH)%.c
	@gcc $(FLAGS) -c $< -o $@

clean:
	@make -C $(LIBFT)/ clean
	@/bin/rm -rf $(SRCO)
	@echo "\033[31mObjects Files \033[1;31m$(OBJS_LIST)\033[1;0m\033[31mRemoved.\033[0m"

fclean: clean
	@make -C $(LIBFT_PATH)/ fclean
	@/bin/rm -rf $(NAME)
	@echo "\033[31mBin \033[1;31m$(NAME)\033[1;0m\033[31m Removed.\033[0m"

re: fclean all

.PHONY: all fclean clean re