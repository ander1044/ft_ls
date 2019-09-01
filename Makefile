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

$(NAME): $(OBJ)
	@make -C libft/
	@gcc $(OBJ) -o $(NAME) -L libft/ -lft

all: $(NAME)

clean:
	@make -C libft/ clean
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME) $(OBJ)

re: fclean $(NAME)