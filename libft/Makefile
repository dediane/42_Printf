# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/24 22:54:52 by ddecourt          #+#    #+#              #
#    Updated: 2021/01/13 14:03:19 by ddecourt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_putchar.c \
	  ft_strlen.c \
	  ft_putstr.c \
	  ft_convert.c \
	  ft_strchr.c \

OBJS	= ${SRCS:.c=.o}

NAME	= libft.a

HEADER	= libft.h

CC	= gcc

CFLAGS	= -Wall -Werror -Wextra
RM	= rm -f

.c.o:	
	${CC} -c ${CFLAGS} -o $@ $< -I ${HEADER}

$(NAME):	${OBJS}
			ar -rc ${NAME} ${OBJS}

all:	${NAME}

clean: 
	${RM} *.o 

fclean:	clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
