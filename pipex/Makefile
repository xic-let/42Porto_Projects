# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acunha <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/30 23:14:44 by acunha            #+#    #+#              #
#    Updated: 2023/05/01 11:09:02 by acunha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

NAME_BONUS = pipex_bonus

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC = pipex.c pipex_cmd.c pipex_utils.c ft_error.c ft_split.c ft_strdup.c ft_strjoin.c ft_strlen.c ft_putstr_fd.c ft_strnstr.c ft_strncmp.c

OBJS = $(SRC:.c=.o)

SRC_BONUS = 

OBJS_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) -o $(NAME_BONUS)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)

rmfile :
	$(RM) outfile
	$(RM) infile
	$(RM) output

re: fclean all
