CXX = c++
NAME = megaphone
CXXFLAGS = -Wall -Werror -Wextra

all : $(NAME)

megaphone.o : megaphone.cpp
	$(CXX) $(CXXFLAGS) megaphone.cpp -c -o megaphone.o

$(NAME) : megaphone.o
	$(CXX) $(CXXFLAGS) megaphone.o -o megaphone

clean :
	rm -f megaphone.o

fclean :
	rm -f megaphone.o
	rm -f megaphone

re : fclean
	$(MAKE) all