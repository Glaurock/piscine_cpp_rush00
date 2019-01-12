# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmonnier <gmonnier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/10 15:44:42 by gmonnier          #+#    #+#              #
#    Updated: 2019/01/12 17:36:15 by gmonnier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_retro

CXX = g++
#CXX_WARNINGS = -Wall -Werror -Wextra
CXX_STD = -std=c++98
CXX_FLAGS = $(CXX_WARNINGS) $(CXX_STD)

SRC = \
		srcs/main.cpp \
		srcs/Ship.cpp \
		srcs/Missile.cpp \
		srcs/Enemy.cpp \
		srcs/Display.cpp \
		srcs/Game.cpp \
		srcs/AGameEntity.cpp \
		srcs/Background.cpp \
		srcs/Hurler.cpp

OBJ = $(SRC:%.cpp=%.o)

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXX_FLAGS) $(OBJ) -lncurses -o $@

%.o: %.cpp
	$(CXX) $(CXX_FLAGS) -c $? -o $@

.PHONY: clean
clean:
	rm -rf $(OBJ)

.PHONY: fclean
fclean: clean
	rm -rf $(NAME)

.PHONY: re
re: fclean all

test: all
	./$(NAME)