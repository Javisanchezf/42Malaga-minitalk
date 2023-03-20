# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/09 19:21:46 by javiersa          #+#    #+#              #
#    Updated: 2023/03/20 18:06:07 by javiersa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk.a
PROGRAM = minitalk
CFLAGS = -Wall -Werror -Wextra
CC = gcc
CLEAN = rm -Rf
LIBFT = Libft
SRC = 

OBJS := $(SRC:.c=.o)

all: libftmake $(NAME)
	$(CC) $(CFLAGS) $(NAME) $(LIBFT)/libft.a -o $(PROGRAM)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

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
git: gitignore
	git add *
	git commit -m "AUTOMATIC COMMIT"
	git push
	git ls-files
gitignore:
	echo ".*\n*.out\n*.o\n*.a">.gitignore