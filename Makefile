# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 21:17:21 by ebennix           #+#    #+#              #
#    Updated: 2023/02/06 21:17:22 by ebennix          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AR_NAME := pipex.a
NAME := pipex

CC := gcc
CFLAGS := -g -Wall -Wextra -Werror

HEADER := pipex.h
FILES := pipex /
		pipex_utils /


SRC := $(FILES:=.c)
OBJ:= $(SRC:.c=.o)


AR := ar -rc
RM := rm -rf


all :$(NAME)

$(NAME):$(OBJ)
	$(cc) $(OBJ) -o $(NAME)
#$(cc) $(OBJ) main.c -o $(NAME) 


%.o : $(SRC) $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

ar : $(OBJ)
	$(AR) $(AR_NAME) $(OBJ)

clean :
	$(RM) $(OBJ)

fclean :
	$(RM) $(NAME)

re : fclean all
	
.PHONY : clean fclean re