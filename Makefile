# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bennix <bennix@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/28 19:07:45 by ebennix           #+#    #+#              #
#    Updated: 2023/02/01 01:28:46 by bennix           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := pipex
CC := gcc
CFLAGS := -g -Wall -Wextra -Werror

HEADER := pipex.h
FILES := pipex /
		pipex_utils /
SRC := $(FILES:=.c)
OBJ:= $(SRC:.c=.o)

AR := ar rc
RM := rm -rf


all :$(NAME)

$(NAME):$(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

exe : $(SRC) $(HEADER)
	$(CC) $(CFLAGS) $(SRC) -o pipex

clean :
	$(RM) $(OBJ)

fclean :
	$(RM) $(NAME)

re : fclean all
	
.PHONY : clean fclean re