# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytouate <touateyoussef2003@gmail.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/03 12:47:40 by ytouate           #+#    #+#              #
#    Updated: 2022/11/03 13:48:25 by ytouate          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE = ./file.cpp

NAME = main

CPPFLAGS = #-Wall -Wextra -Werror

O_FILE = $(FILE:.cpp=.o)

all: $(NAME)

$(NAME) : $(O_FILE)
	@c++ -Wall -Wextra -Werror -std=c++98 $(O_FILE) -o $(NAME)

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf megaphone

re: fclean all

run: re
	@echo "\n"
	@./$(NAME)
