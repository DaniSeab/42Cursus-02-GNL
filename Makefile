# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlima-se <dlima-se@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/24 18:30:28 by dlima-se          #+#    #+#              #
#    Updated: 2022/09/24 18:52:57 by dlima-se         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# GNL_FOLDER	= ../gnl
SRCS	= get_next_line.c get_next_line_utils.c
# SRCS	= $(addprefix $(GNL_FOLDER), $(FILES))
BUF_OPT	= -D BUFFER_SIZE=
BUF_SZ	= 200
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
VARS	= $(BUF_OPT)$(BUF_SZ)
COMPL	= $(CC) $(CFLAGS) -o $(NAME) $(SRCS) main.c
NAME	= a.out

all: $(NAME)

$(NAME):
	$(COMPL) $(VARS)
	./$(NAME)

fclean:		
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re