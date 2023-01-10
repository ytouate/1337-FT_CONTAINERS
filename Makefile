# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/03 12:47:40 by ytouate           #+#    #+#              #
#    Updated: 2023/01/10 16:12:01 by ytouate          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAP = ./map/map.cpp
VECTOR = ./vector/vector.cpp
STACK = ./stack/stack.cpp

CPPFLAGS = -std=c++98 -Wall -Wextra -Werror

O_STACK = $(STACK:.cpp=.o)
O_VECTOR = $(VECTOR:.cpp=.o)
O_MAP = $(MAP:.cpp=.o)

all: map vector stack

stack: stack.out
map: map.out
vector: vector.out

stack.out : $(O_STACK)
	@c++ $(CPPFLAGS) $(STACK) -o stack.out
	@rm ./stack/stack.o
	@./stack.out

map.out : $(O_MAP)
	@c++ $(CPPFLAGS) $(MAP) -o map.out
	@rm ./map/map.o
	@./map.out

vector.out : $(O_VECTOR)
	@c++ $(CPPFLAGS) $(VECTOR) -o vector.out
	@rm ./vector/vector.o
	@./vector.out

clean:
	@rm -f map.out
	@rm -f vector.out
	@rm -f stack.out

fclean: clean

re: fclean all
