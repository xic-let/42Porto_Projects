# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acunha <acunha@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/26 15:37:28 by acunha            #+#    #+#              #
#    Updated: 2023/06/18 18:52:29 by acunha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

BONUS = so_long_bonus

CC = gcc

CFLAGS = -WALL -WEXTRA -WERROR -lm

LIB = 

RM = rm -f

MAKE_MLX = 

SRC =

SRC_B =

OBJS = ${SRC:%.c=%.o}

OBJS_B = ${SRC_B:%.c=%.o}

all: $(NAME)

$(NAME) : $(OBJS) $(MAKE_MLX) $(CC) $(OBJS) $(LIB) $(CFLAGS) -o $(OBJS)

#falta incluir os para a Minilibx e acrescentar a flag -lm para compilar a library math.

$(BONUS) : $(OBJS_B) $(MAKE_MLX) $(CC) $(OBJS_B) $(LIB) $(CFLAGS) -o $(OBJS_B)

clean: $(RM) $(OBJS) $(OBJS_B)

fclean: clean $(RM) $(NAME) $(BONUS)

bonus: $(BONUS)

re: fclean all