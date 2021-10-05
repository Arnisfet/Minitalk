SRC_C	=	client.c	ft_strchr_ps.c

SRC_S	=	server.c

OBJ_C	=	$(SRC_C:.c=.o)

OBJ_S	=	$(SRC_S:.c=.o)

CLIENT	=	client

SERV	=	server

INC_LIB	=	-I libft/libft.h

INC		=	-I includes/minitalk.h

WWW		=	-Wall -Werror -Wextra

LIB		=	libft/libft.a

%.o:	%.c
	gcc -c $(INC) $(INC_LIB) $(WWW) $< -o $@

all:	$(CLIENT)	$(SERV)

$(CLIENT):	$(OBJ_C)
	make -C libft
	gcc $(OBJ_C) $(LIB) $(WWW) -o $(CLIENT)

$(SERV):	$(OBJ_S)
	gcc $(OBJ_S) $(LIB) $(WWW) -o $(SERV)

clean:
	@make clean -C libft
	@rm -f $(OBJ_C) $(OBJ_S)

fclean: clean
	@make fclean -C libft
	@rm -f $(SERV) $(CLIENT)
	@echo "\t\t\t\t\033[0;41mDelete $(SERV) $(CLIENT)"

re: fclean all