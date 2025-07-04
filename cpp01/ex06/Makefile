NAME = harlfilter
CC = c++
CFLAGS = -Wall -Wextra -Werror -Ilibft/include -Iinclude -std=c++98 -g3
SRCS =	main.cpp \
		Harl.cpp \

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
