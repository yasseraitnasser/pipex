# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yait-nas <yait-nas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 16:07:41 by yait-nas          #+#    #+#              #
#    Updated: 2024/03/11 00:44:14 by yait-nas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
NAMEB = pipex_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror
FILES = main.c ft_split.c ft_strdup.c ft_strjoin3.c ft_strlcat.c \
	ft_strlcpy.c ft_strncmp.c ft_strlen.c free.c \
	error.c child_processes.c child_processes_helper.c

BONUS = main_bonus.c child_processes_bonus.c close_bonus.c error_bonus.c \
	free_bonus.c ft_split_bonus.c ft_strdup_bonus.c ft_strjoin3_bonus.c \
	ft_strlcat_bonus.c ft_strlcpy_bonus.c ft_strlen_bonus.c ft_strncmp_bonus.c \
	ft_strcmp_bonus.c ft_strjoin_bonus.c here_doc_bonus.c \
	get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
	child_processes_helper_bonus.c here_doc_helper_bonus.c

FILES_o = $(FILES:.c=.o)
BONUS_o = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(FILES_o)
	$(CC) $(CFLAGS) $(FILES_o) -o $(NAME)

bonus: $(NAMEB)

$(NAMEB): $(BONUS_o)
	$(CC) $(CFLAGS) $(BONUS_o) -o $(NAMEB)

clean:
	rm -f $(FILES_o) $(BONUS_o)

fclean: clean
	rm -f $(NAME) $(NAMEB)

re: fclean all

#.PHONY: all fclean re clean bonus
