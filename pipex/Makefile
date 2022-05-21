# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/07 15:54:16 by dhaliti           #+#    #+#              #
#    Updated: 2022/03/08 11:52:08 by dhaliti          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex.a

SRCS =     	1-pipex.c \
			2-paths.c \
			3-utils.c \
			4-libft.c \
			4-ft_split.c

SRCS_BONUS =     	1-pipex_bonus.c \
					2-paths.c \
					3-utils.c \
					4-libft.c \
					4-ft_split.c \
					5-get_next_line.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -fno-omit-frame-pointer
RM = rm -rf

all: ${NAME}

${NAME}: $(OBJS)
		@$(CC) $(OBJS) $(CFLAGS) -o pipex

clean:
	@$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
		@$(RM) pipex pipex_bonus

re: fclean all

bonus:	$(OBJS_BONUS)
		@$(CC) $(OBJS_BONUS) $(CFLAGS) -o pipex_bonus

.PHONY: clean fclean re all
