# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/24 22:54:52 by ddecourt          #+#    #+#              #
#    Updated: 2021/01/18 23:44:29 by ddecourt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_display_string.c \
	  ft_display_char.c \
	  ft_display_int.c \
	  ft_display_unsigned.c \
	  ft_display_octal.c \
	  ft_display_hexa.c \
	  ft_display_percent.c \
	  ft_display_point.c \
	  ft_checkflag.c \
	  ft_init_flags.c \
	  ft_printf.c \
	  libft/ft_strlen.c \
	  libft/ft_strchr.c \
	  libft/ft_putstr.c \
	  libft/ft_putchar.c \
	  libft/ft_convert.c \
	  

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

HEADER	= libftprintf.h

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
	${RM} libft/*.o

fclean:	clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
