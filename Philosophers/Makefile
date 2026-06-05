NAME = philo
CC = cc
FLAGS = -Wall -Werror -Wextra -I.

OBJS	= $(SRCS:.c=.o)

SRCS = main/main.c main/utils.c main/verif_and_allocate.c\
	routine/eat.c routine/monitor.c routine/philo_routine.c\
	routine/sleep_and_think.c

all: $(NAME)
	clear

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -lpthread $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)
	clear

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

fclean: clean
	rm -f $(NAME)
	clear

re: fclean all