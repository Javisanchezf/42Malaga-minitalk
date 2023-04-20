# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/09 19:21:46 by javiersa          #+#    #+#              #
#    Updated: 2023/04/20 18:35:46 by javiersa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra
CC = gcc
CLEAN = rm -Rf
LIBFTPLUS = libftplus
NAME = $(SERVER) $(CLIENT)
PROGRAMS = $(SERVER_PROGRAM) $(CLIENT_PROGRAM)
SERVER = server.a
CLIENT = client.a
PERSONALNAME = CLIENT-SERVER
PERSONALNAME_BONUS = CLIENT-SERVER BONUS
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

all: libftplusmake $(NAME) $(SERVER_PROGRAM)

$(SERVER_PROGRAM):
	@$(CC) $(CFLAGS) $(SERVER) $(LIBFTPLUS)/libftplus.a -o $(SERVER_PROGRAM)
	@$(CC) $(CFLAGS) $(CLIENT) $(LIBFTPLUS)/libftplus.a -o $(CLIENT_PROGRAM)
	@echo "$(MAGENTA)Program $(PERSONALNAME) created successfully.$(DEFAULT)"
$(NAME): $(OBJS)
	@ar rcs $(SERVER) $(SERVER_OBJS)
	@ar rcs $(CLIENT) $(CLIENT_OBJS)
	@echo "$(MAGENTA)Library $(NAME) created successfully.$(DEFAULT)"
.c.o:
	@$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}
	@echo "$(GREEN)Compiling:$(DEFAULT) $(notdir $<)"
clean: libftplusclean
	@$(CLEAN) ./$(OBJS)  ./$(PROGRAMS) ./$(OBJS_BONUS)  ./$(PROGRAMS_BONUS)
fclean: libftplusfclean clean
	@$(CLEAN) ./$(NAME) ./$(NAME_BONUS)
re: fclean all

bonus:libftplusmake $(NAME_BONUS) $(SERVER_PROGRAM_BONUS)

$(SERVER_PROGRAM_BONUS):
	@$(CC) $(CFLAGS) $(SERVER_BONUS) $(LIBFTPLUS)/libftplus.a -o $(SERVER_PROGRAM_BONUS)
	@$(CC) $(CFLAGS) $(CLIENT_BONUS) $(LIBFTPLUS)/libftplus.a -o $(CLIENT_PROGRAM_BONUS)
	@echo "$(MAGENTA)Program $(PERSONALNAME_BONUS) created successfully.$(DEFAULT)"
$(NAME_BONUS): $(OBJS_BONUS)
	@ar rcs $(SERVER_BONUS) $(SERVER_OBJS_BONUS)
	@ar rcs $(CLIENT_BONUS) $(CLIENT_OBJS_BONUS)
	@echo "$(MAGENTA)Library $(NAME_BONUS) created successfully.$(DEFAULT)"

libftplusmake:
	@make -C $(LIBFTPLUS)
libftplusmakeubuntu:
	@make ubuntu -C $(LIBFTPLUS)
libftplusclean:
	@make clean -C $(LIBFTPLUS)
libftplusfclean:
	@make fclean -C $(LIBFTPLUS)
libftplusre: libftplusclean libftplusmake

.PHONY : all clean fclean re libftplusfclean libftplusclean libftplusmake libftplusre

#Personal use
git: fclean gitignore
	@git add *
	@echo "$(BOLD)$(YELLOW)Git:$(WHITE) Adding all archives.$(DEFAULT)"
	@git commit -m "Little changes"
	@echo "$(BOLD)$(CYAN)Git:$(WHITE) Commit this changes with "Little changes".$(DEFAULT)"
	@git push
	@echo "$(BOLD)$(GREEN)Git:$(WHITE) Pushing all changes.$(DEFAULT)"
gitignore:
	@echo ".*\n*.out\n*.o\n*.a">.gitignore
	@echo "$(GREEN)Creating:$(DEFAULT) Gitignore."
42prepare: submodules
	@rm -rf $(LIBFT)/.git
	@rm -rf $(NEXTILE)/.git
	@rm -rf $(PRINTF)/.git
	@rm -rf .git .gitmodules
	@echo "$(GREEN)All .git removed.$(DEFAULT)"

#COLORS
BOLD	:= \033[1m
BLACK	:= \033[30;1m
RED		:= \033[31;1m
GREEN	:= \033[32;1m
YELLOW	:= \033[33;1m
BLUE	:= \033[34;1m
MAGENTA	:= \033[35;1m
CYAN	:= \033[36;1m
WHITE	:= \033[37;1m
DEFAULT	:= \033[0m