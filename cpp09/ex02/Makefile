# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/06 10:54:14 by tde-souz          #+#    #+#              #
#    Updated: 2023/08/12 14:44:29 by tde-souz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= PmergeMe

INCLUDES	= -I ./

CFLAGS		= -Wall -Wextra -Werror -std=c++98 -g

CC			= c++

RM			= rm -rf

SRCS		= \
				PmergeMe.cpp	\
				main.cpp
OBJS		= $(SRCS:.cpp=.o)

N			?= 3000

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

random: all
	clear
	./PmergeMe `shuf -i 1-100000 -n ${N} | tr "\n" " "`

.PHONY: clean fclean re all random
