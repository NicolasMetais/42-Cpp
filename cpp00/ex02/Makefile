NAME = cpp00
CC = c++
CFLAGS = -Wall -Wextra -Werror -Ilibft/include -Iinclude -std=c++98 -g3
SRCS =	Account.cpp \
		tests.cpp \

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