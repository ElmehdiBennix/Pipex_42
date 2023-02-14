# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 21:17:21 by ebennix           #+#    #+#              #
#    Updated: 2023/02/14 20:43:20 by ebennix          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXE := pipex

NAME := printf.a

CC := cc

CFLAGS := -g -Wall -Wextra -Werror

HEADER := pipex.h

FILES := pipex \
		utils/pipex_utils \
		utils/ft_split \
		ft_printf/utils/ft_printf_hex \
		ft_printf/utils/ft_printf_put \
		ft_printf/ft_printf

SRC := $(FILES:=.c)
OBJ := $(SRC:.c=.o)

RM := rm -rf

m := MakefileAutoPush

all : $(EXE)

$(EXE) : $(OBJ)
	$(CC) $(OBJ) -o $(EXE)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(EXE)

re : fclean all

git :
	git add .
	git commit -m "$(m)"
	git push

.PHONY : clean fclean re
