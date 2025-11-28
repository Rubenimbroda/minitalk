# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rubenior <rubenior@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/30 14:20:33 by rnuno-im          #+#    #+#              #
#    Updated: 2025/11/27 13:23:13 by rubenior         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I. -Isrc/printf

SRC_DIR		= src
PRINTF_DIR	= $(SRC_DIR)/printf

SRCS = $(wildcard *.c) $(wildcard $(SRC_DIR)/*.c) $(wildcard $(PRINTF_DIR)/*.c)
OBJS		= $(SRCS:.c=.o)

AR			= ar rcs
RM			= rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

src/printf/%.o: src/printf/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
