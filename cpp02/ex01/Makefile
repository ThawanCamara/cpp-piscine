# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/22 17:07:42 by tde-souz          #+#    #+#              #
#    Updated: 2023/04/22 17:07:43 by tde-souz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fixedUseful

INCLUDES	= -I ./

CFLAGS		= -Wall -Wextra -Werror -std=c++98 -g

CC			= c++

RM			= rm -rf

SRCS		= \
				Fixed.cpp	\
				main.cpp
OBJS		= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(INCLUDES) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS): $(SRCS)
	$(CC) $(INCLUDES) -c $(CFLAGS) $(subst .o,.cpp,$@) -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all
