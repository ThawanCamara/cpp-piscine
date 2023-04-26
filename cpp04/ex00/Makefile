# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/22 11:40:06 by tde-souz          #+#    #+#              #
#    Updated: 2023/04/23 09:13:45 by tde-souz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= animals

INCLUDES	= -I ./

CFLAGS		= -Wall -Wextra -Werror -std=c++98 -g

CC			= c++

RM			= rm -rf

SRCS		= \
				Animal.cpp	\
				Dog.cpp		\
				Cat.cpp		\
				WrongAnimal.cpp	\
				WrongCat.cpp	\
				main.cpp
OBJS		= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(INCLUDES) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS): $(SRCS)
	$(CC) $(INCLUDES) -c $(CFLAGS) $(subst .o,.cpp,$@) -o $@

clean:
	$(RM) $(OBJS)
	$(RM) $(NAME).dSYM

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all
