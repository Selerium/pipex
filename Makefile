# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/02 22:13:13 by jadithya          #+#    #+#              #
#    Updated: 2022/09/18 12:07:08 by jadithya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS = pipex.c\
		parsing.c\
		errors.c\
		wrappers.c\
		ft_findcmd.c

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3

OBJS = $(SRCS:.c=.o)

LIB = libft/libft.a

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

$(NAME): $(OBJS)
	make bonus -C libft
	gcc $(OBJS) -o $(NAME) $(CFLAGS) $(LIB)

bonus: 

all: $(NAME)

norm: 
	/home/jadithya/.local/bin/norminette

normpipex:
	norminette pipex.c parsing.c errors.c wrappers.c pipex.h

clean:
	rm -f $(OBJS)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all