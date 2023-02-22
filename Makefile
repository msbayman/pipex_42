# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amsaoub <amsaoub@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 17:46:49 by amsaoub           #+#    #+#              #
#    Updated: 2023/02/21 12:50:22 by amsaoub          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
NAMEB = pipex_bonus

HEADER = pipex.h
HEADERB = pipex_bon.h

SRC = manda/pipex.c \
	 manda/ft_strjoin.c \
	 manda/ft_split.c \
	 manda/parsing.c \
	 manda/tools.c \
	 manda/procces.c

SRCB = bon/pipex_bonus.c \
	 bon/ft_strjoin_bonus.c \
	 bon/ft_split_bonus.c \
	 bon/parsing_bonus.c \
	 bon/tools_bonus.c \
	 bon/proccesher_bonus.c \
	 bon/get_next_line_utils_bonus.c \
	 bon/get_next_line_bonus.c 

CC = cc
CFLAGS =  -Wall -Wextra -Werror
RM = rm -rf

all: $(NAME)

bonus: $(NAMEB)

$(NAME): $(SRC) $(HEADER)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)
	
$(NAMEB): $(SRCB) $(HEADERB)
	$(CC) $(CFLAGS) $(SRCB) -o $(NAMEB)

clean:
	$(RM) $(NAME) 

fclean: clean
	$(RM) $(NAME) $(NAMEB)

re: fclean all bonus