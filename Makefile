# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmonnier <gmonnier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/10 15:44:42 by gmonnier          #+#    #+#              #
#    Updated: 2019/01/12 10:26:03 by gmonnier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_retro

CXX = clang++
CXX_WARNINGS = -Wall -Werror -Wextra
CXX_STD = -std=c++98
CXX_FLAGS = $(CXX_WARNINGS) $(CXX_STD)

SRC = \
		main.cpp \

OBJ = $(SRC:%.cpp=%.o)

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXX_FLAGS) $(OBJ) -o $@

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
