# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arodiono <arodiono@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/01 15:02:50 by dzui              #+#    #+#              #
#    Updated: 2017/11/12 01:08:09 by arodiono         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_gkrellm

SRC =  main.cpp Module.cpp HostName.cpp OsModule.cpp TimeModule.cpp CpuModule.cpp DiskModule.cpp MemoryModule.cpp NetwModule.cpp Window.cpp

OBJ = $(SRC:.cpp=.o)

FLAGS = -Wall -Wextra -Werror

INC= -I includes/sfml/2.4.2_1/include

LIB= -L includes/sfml/2.4.2_1/lib -lsfml-graphics -lsfml-window -lsfml-system

$(NAME): $(OBJ)
		clang++ -g $(FLAGS) -o $(NAME) $(OBJ) $(LIB)

%.o:%.cpp
		clang++ $(FLAGS) -c $(INC) -o $@ $<

all: $(NAME)

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re:	fclean $(NAME)
