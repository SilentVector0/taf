CXX = c++
NAME = ClapTrap
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
SRCS = ClapTrap.cpp main.cpp ScavTrap.cpp
OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -c -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean :
	rm -f $(OBJS)

fclean :
	rm -f $(OBJS)
	rm -f $(NAME)

re : fclean
	$(MAKE) all
