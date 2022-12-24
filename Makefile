# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syavuz <syavuz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/27 12:38:51 by syavuz            #+#    #+#              #
#    Updated: 2022/11/30 14:23:06 by syavuz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					= libftprintf.a

CC                      = gcc

SRCS					= ft_printf.c ft_process.c

OBJS					= $(SRCS:.c=.o)

FLAGS					= -Wall -Wextra -Werror

all	:	$(NAME)

$(NAME):	$(OBJS)
				$(CC) $(FLAGS) -c $(SRCS) -I./
				ar rc $(NAME) $(OBJS)

clean:
		rm -f $(OBJS)

fclean:	clean
		rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re