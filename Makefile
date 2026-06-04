# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amendibi <amendibi@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/29 16:50:19 by amendibi          #+#    #+#              #
#    Updated: 2026/06/04 22:10:49 by amendibi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra -I src

SRCS = \
	src/push_swap.c \
	src/algorithm/dispatch_adaptative.c \
	src/algorithm/sort_five.c \
	src/algorithm/complex/sort_complex.c \
	src/algorithm/medium/sort_medium_utils.c \
	src/algorithm/medium/sort_medium.c \
	src/algorithm/simple/sort_simple.c \
	src/operations/push.c \
	src/operations/rev_rotate.c \
	src/operations/rotate.c \
	src/operations/swap.c \
	src/utils/atoi.c \
	src/utils/disorder.c \
	src/utils/error_and_free.c \
	src/utils/init.c \
	src/utils/print_bench.c \
	src/utils/utils.c

OBJS = $(SRCS:.c=.o)

HEADERS=./src/push_swap.h

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

