# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/02 22:13:13 by jadithya          #+#    #+#              #
#    Updated: 2022/08/07 01:31:46 by jadithya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS = pipex.c\
		parsing.c

CC = gcc

CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

LIB = printf/libftprintf.a

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

$(NAME): $(OBJS)
	make -C printf
	gcc $(OBJS) -o $(NAME) $(CFLAGS) $(LIB)

bonus: 

all: $(NAME)

clean:
	rm -f $(OBJS) printf/*.o printf/libft/*.o

fclean: clean
	rm -f $(NAME) printf/libftprintf.a printf/libft.a

re: fclean all