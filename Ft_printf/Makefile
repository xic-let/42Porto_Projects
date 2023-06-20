# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acunha <acunha@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/05 17:39:07 by acunha            #+#    #+#              #
#    Updated: 2022/12/09 15:45:16 by acunha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=	libftprintf.a
CC=	cc
CFLAGS=	-Wall -Wextra -Werror
RM = rm -rf

SRCS=	ft_printf.c ft_handleformat.c ft_printpercent.c ft_printptr.c \
		ft_prthex.c ft_prtnbr.c ft_prtunsg.c ft_putchar.c ft_putstr.c \
		ft_itoa.c ft_putchar_fd.c ft_strlen.c ft_strchr.c

OBJS=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rc $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:	fclean all
