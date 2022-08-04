# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/02 22:13:13 by jadithya          #+#    #+#              #
#    Updated: 2022/08/04 21:08:03 by jadithya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS = pipex.c

CC = gcc

CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

LIB = libft/libft.a\
		printf/libftprintf.a

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

$(NAME): $(OBJS)
	make -C printf
	gcc $(OBJS) -o $(NAME) $(CFLAGS)

bonus: 

all: $(NAME)

clean:
	rm -f $(OBJS) printf/*.o printf/libft/*.o

fclean: clean
	rm -f $(NAME) printf/libftprintf.a printf/libft.a

re: fclean all