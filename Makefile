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
LIBFT = ./libft/
CC = gcc
NOR = norminette
FLAGS = -Wall -Werror -Wextra
ARC = ar rc
SRC = d.c\
	  
	

OBJ = ft_isdigit.o\



# all: $(NAME)

$(NAME):
		$(CC) $(FLAGS) -c $(SRC)
		$(ARC) $(NAME) $(OBJ)
		ranlib $(NAME)

all: $(NAME)

norm:
	$(NOR)

clean:
		rm -f *.o

fclean: clean
		rm -f $(NAME)

re: fclean all