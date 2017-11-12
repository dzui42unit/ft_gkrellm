# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dzui <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/01 15:02:50 by dzui              #+#    #+#              #
#    Updated: 2017/11/12 16:01:10 by dzui             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_gkrellm

SRC =  main.cpp IMonitorModule.cpp HostName.cpp OsModule.cpp TimeModule.cpp CpuModule.cpp DiskModule.cpp MemoryModule.cpp NetwModule.cpp NcursesOut.cpp

OBJ = $(SRC:.cpp=.o)

FLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJ)
		clang++ $(FLAGS) $(OBJ) -o $(NAME) -lncurses

%.o:%.cpp
		clang++ $(FLAGS) -c -o $@ $<

all: $(NAME)

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME) $(OBJ)

re:	fclean $(NAME)
