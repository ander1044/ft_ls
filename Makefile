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

NAME  = ft_ls
SRC	  = ft_ls.c
OBJ	  = $(SRC:.c=.o)
NOR   = norminette
FLAGS = -Wall -Wextra -Werror
RED	  =	\033[0;31m
GREEN =	\033[0;32m
NC    =	\033[0m


$(NAME): $(OBJ)
	@echo "$(GREEN)<<compiling executable>>$(NC)"
	@make -C libft/
	@gcc $(OBJ) -o $(NAME) -L libft/ -lft
	@echo "$(GREEN)<<./ft_ls is ready to test>>$(NC)"

all: $(NAME)

clean:
	@echo "$(RED)<<deleting all objects>>$(NC)"
	@make -C libft/ clean
	@rm -rf $(OBJ)

fclean: clean
	@echo "$(RED)<<deleting executable and libraries>>$(NC)"
	@rm -rf $(NAME) $(OBJ)

re: fclean $(NAME)