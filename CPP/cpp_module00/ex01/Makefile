
CXX = c++
NAME = PhoneBook
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
SRCS = sources/PhoneBook.cpp sources/Contact.cpp sources/Main.cpp sources/verif.cpp
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
