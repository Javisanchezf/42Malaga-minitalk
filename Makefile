# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/09 19:21:46 by javiersa          #+#    #+#              #
#    Updated: 2023/03/20 20:26:42 by javiersa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = $(SERVER) $(CLIENT)
SERVER = server.a
CLIENT = client.a
SERVER_PROGRAM = server
CLIENT_PROGRAM = client
CFLAGS = -Wall -Werror -Wextra
CC = gcc
CLEAN = rm -Rf
LIBFT = Libft
SERVER_SRC = src/server.c
SERVER_OBJS := $(SERVER_SRC:.c=.o)
CLIENT_SRC = src/client.c
CLIENT_OBJS := $(CLIENT_SRC:.c=.o)
OBJS = $(SERVER_OBJS) $(CLIENT_OBJS)

all: libftmake $(NAME)
	$(CC) $(CFLAGS) $(SERVER) $(LIBFT)/libft.a -o $(SERVER_PROGRAM)
	$(CC) $(CFLAGS) $(CLIENT) $(LIBFT)/libft.a -o $(CLIENT_PROGRAM)
$(NAME): $(OBJS)
	ar rcs $(SERVER) $(SERVER_OBJS)
	ar rcs $(CLIENT) $(CLIENT_OBJS)
.c.o:
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}
clean: libftclean
	make clean -C $(LIBFT)
	$(CLEAN) ./$(OBJS)  $(PROGRAM)
fclean: libftfclean clean
	$(CLEAN) ./$(NAME)
re: fclean all

libftmake:
	make -C $(LIBFT)
libftclean:
	make clean -C $(LIBFT)
libftfclean:
	make fclean -C $(LIBFT)

.PHONY : all clean fclean re libftclean libftfclean libftmake

#Personal use
git: fclean gitignore
	git add *
	git commit -m "AUTOMATIC COMMIT"
	git push
	git ls-files
gitignore:
	echo ".*\n*.out\n*.o\n*.a">.gitignore