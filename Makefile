# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 21:17:21 by ebennix           #+#    #+#              #
#    Updated: 2023/02/13 02:51:26 by ebennix          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc

CFLAGS = -g -Wall -Wextra -Werror

HEADER = pipex.h

FILES = pipex /
		pipex_utils /
		ft_split /


SRC = $(FILES:=.c)
OBJ = $(SRC:.c=.o)

RM = rm -rf

all : $(NAME)

$(NAME) : $(OBJ)
	$(cc) $(OBJ) -o $(NAME)

%.o : %.c $(SRC) $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ)

fclean :
	$(RM) $(NAME)

re : fclean all

git :
	git add .
	git commit -m "MakefileAutoPush"
	git push

.PHONY : clean fclean re
