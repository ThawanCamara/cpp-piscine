# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/22 10:55:27 by tde-souz          #+#    #+#              #
#    Updated: 2023/04/22 10:55:29 by tde-souz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= sedloser

INCLUDES	= -I ./

CFLAGS		= -Wall -Wextra -Werror -std=c++98 -g

CC			= c++

RM			= rm -rf

SRCS		= \
				main.cpp
OBJS		= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(INCLUDES) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "Use 'make input' to generate a test file"

input:
	@touch input
	@echo "Devon Devon \n \
\n\
And then there were no more Devons,\n\
and while the Devons could not believe it\n\
It was indeed the Devon'est truth.\n\
\n\
\"IT CAN'T BE\". One said. But it was not Devon\n\
Because DEvons were no more.\n\
\n\
Rip devon" > input
	@echo "Input file created/updated for your convenience"

$(OBJS): $(SRCS)
	$(CC) $(INCLUDES) -c $(CFLAGS) $(subst .o,.cpp,$@) -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) input
	$(RM) input.replace

re: fclean all

.PHONY: clean fclean re all input
