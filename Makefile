
CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

SRCS = $(wildcard */*.cpp)
OBJECTS = $(subst .cpp,.o,$(SRCS))

NAME = ft_containers

all:	$(NAME)

$(NAME):	$(OBJECTS)
			$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(NAME)

clean:
		rm -f $(OBJECTS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re