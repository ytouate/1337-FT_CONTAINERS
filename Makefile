# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/03 12:47:40 by ytouate           #+#    #+#              #
#    Updated: 2023/01/09 16:19:19 by ytouate          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAP = ./map/map.cpp
VECTOR = ./vector/vector.cpp

CPPFLAGS = -std=c++98 -Wall -Wextra -Werror

O_VECTOR = $(VECTOR:.cpp=.o)
O_MAP = $(MAP:.cpp=.o)

all: map vector
map: map.out
vector: vector.out

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

fclean: clean

re: fclean all
