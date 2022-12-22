# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/03 12:47:40 by ytouate           #+#    #+#              #
#    Updated: 2022/12/22 12:59:23 by ytouate          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE = \
	./main.cpp	\

NAME = CONTAINERS.out

CPPFLAGS = -std=c++98 -Wall -Wextra -Werror #-fsanitize=address -g
# -Wall -Wextra -Werror 
O_FILE = $(FILE:.cpp=.o)

all: $(NAME)

$(NAME) : $(O_FILE)
	@c++  -Wall -Wextra -Werror  -std=c++98  $(O_FILE) -o $(NAME)

clean:
	@rm -rf *.o
	@rm -rf *.gch

fclean: clean
	@rm -rf $(NAME)

re: fclean all

run: re
	@./$(NAME)
