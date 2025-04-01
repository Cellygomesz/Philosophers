# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgomes-s <mgomes-s@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/12 10:52:11 by mgomes-s          #+#    #+#              #
#    Updated: 2025/04/01 07:19:37 by mgomes-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc

CFLAGS = -g -Wall -Wextra -Werror -pthread -fsanitize=thread

SRCS = main.c routine.c scanner.c valid.c init.c errors.c dinner.c aux.c aux2.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ $(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	@ $(CC) $(CFLAGS) -c $< -o $@

clean:
	@ $(RM) $(OBJS)

fclean: clean
	@ rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
