# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/09 19:21:46 by javiersa          #+#    #+#              #
#    Updated: 2023/03/22 20:05:58 by javiersa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra
CC = gcc
CLEAN = rm -Rf
LIBFT = Libft
NAME = $(SERVER) $(CLIENT)
PROGRAMS = $(SERVER_PROGRAM) $(CLIENT_PROGRAM)
SERVER = server.a
CLIENT = client.a
SERVER_PROGRAM = server
CLIENT_PROGRAM = client
SERVER_SRC = src/server.c
CLIENT_SRC = src/client.c
SERVER_OBJS := $(SERVER_SRC:.c=.o)
CLIENT_OBJS := $(CLIENT_SRC:.c=.o)
OBJS = $(SERVER_OBJS) $(CLIENT_OBJS)

NAME_BONUS = $(SERVER_BONUS) $(CLIENT_BONUS)
PROGRAMS_BONUS = $(SERVER_PROGRAM_BONUS) $(CLIENT_PROGRAM_BONUS)
SERVER_BONUS = server_bonus.a
CLIENT_BONUS = client_bonus.a
SERVER_PROGRAM_BONUS = server_bonus
CLIENT_PROGRAM_BONUS = client_bonus
SERVER_SRC_BONUS = src/server_bonus.c
CLIENT_SRC_BONUS = src/client_bonus.c
SERVER_OBJS_BONUS := $(SERVER_SRC_BONUS:.c=.o)
CLIENT_OBJS_BONUS := $(CLIENT_SRC_BONUS:.c=.o)
OBJS_BONUS = $(SERVER_OBJS_BONUS) $(CLIENT_OBJS_BONUS)

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
	$(CLEAN) ./$(OBJS)  ./$(PROGRAMS) ./$(OBJS_BONUS)  ./$(PROGRAMS_BONUS)
fclean: libftfclean clean
	$(CLEAN) ./$(NAME) ./$(NAME_BONUS)
re: fclean all

bonus:libftmake $(NAME_BONUS)
	$(CC) $(CFLAGS) $(SERVER_BONUS) $(LIBFT)/libft.a -o $(SERVER_PROGRAM_BONUS)
	$(CC) $(CFLAGS) $(CLIENT_BONUS) $(LIBFT)/libft.a -o $(CLIENT_PROGRAM_BONUS)
$(NAME_BONUS): $(OBJS_BONUS)
	ar rcs $(SERVER_BONUS) $(SERVER_OBJS_BONUS)
	ar rcs $(CLIENT_BONUS) $(CLIENT_OBJS_BONUS)

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