NAME        = polymorphism_brain
CC          = c++
FLAGS       = -Wall -Wextra -Werror -std=c++98
RM          = rm -rf

SRCS        = main.cpp \
              Animal.cpp \
              Dog.cpp \
              Cat.cpp \
              Brain.cpp

OBJS        = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re