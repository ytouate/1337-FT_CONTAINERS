# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/03 12:47:40 by ytouate           #+#    #+#              #
#    Updated: 2022/11/22 14:10:49 by ytouate          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE = ./main.cpp

NAME = main.exe

CPPFLAGS = -std=c++98  #-fsanitize=address -g#-Wall -Wextra -Werror 

O_FILE = $(FILE:.cpp=.o)

all: $(NAME)

$(NAME) : $(O_FILE)
	@c++ -Wall -Wextra -Werror -std=c++98  $(O_FILE) -o $(NAME)

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all

run: re
	@./$(NAME)
