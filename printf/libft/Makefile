# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 13:42:18 by jadithya          #+#    #+#              #
#    Updated: 2022/06/27 18:38:56 by jadithya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS =ft_atoi.c\
		ft_bzero.c\
		ft_calloc.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_itoa.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_memset.c\
		ft_putchar_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_putstr_fd.c\
		ft_split.c\
		ft_strchr.c\
		ft_strdup.c\
		ft_striteri.c\
		ft_strjoin.c\
		ft_strlcat.c\
		ft_strlcpy.c\
		ft_strlen.c\
		ft_strmapi.c\
		ft_strncmp.c\
		ft_strnstr.c\
		ft_strrchr.c\
		ft_strtrim.c\
		ft_substr.c\
		ft_tolower.c\
		ft_toupper.c

CC = gcc

BONUSSRC = ft_lstnew.c\
			ft_lstadd_back.c\
			ft_lstadd_front.c\
			ft_lstlast.c\
			ft_lstsize.c\
			ft_lstdelone.c\
			ft_lstclear.c\
			ft_lstiter.c\
			ft_lstmap.c

CFLAGS = -Wextra -Werror -Wall

DEPS = libft.h

OBJS = $(SRCS:.c=.o)

BONUSOBJ = $(BONUSSRC:.c=.o)

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS) 

all: $(NAME)

bonus: $(OBJS) $(BONUSOBJ)
	ar rcs $(NAME) $(OBJS) $(BONUSOBJ)

clean:
	rm -f $(OBJS) $(BONUSOBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all