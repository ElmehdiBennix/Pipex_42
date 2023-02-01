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