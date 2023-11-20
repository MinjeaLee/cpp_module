NAME = phonebook

CC = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp \
	   phonebook.cpp

INC = phonebook.hpp
	
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: clean fclean all

.PHONY: all clean fclean re