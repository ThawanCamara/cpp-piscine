NAME		= phonebook

INCLUDES	= -I phonebook.hpp contact.hpp

CFLAGS		= -Wall -Wextra -Werror -std=c++98

CC			= c++

RM			= rm -rf

SRCS		= \
			  phonebook.cpp		\
			  contact.cpp

OBJS		= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all
