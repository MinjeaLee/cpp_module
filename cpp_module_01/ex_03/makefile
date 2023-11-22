NAME = weapon

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp \
	   HumanA.cpp \
	   HumanB.cpp \
	   Weapon.cpp

INC = HumanA.hpp \
	  HumanB.hpp \
	  Weapon.hpp
	
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