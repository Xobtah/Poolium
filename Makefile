NAME	= ThreadTest

SRC	= main.cpp \
	src/Thread.cpp \
	src/Mutex.cpp \
	src/ThreadPool.cpp \

OBJ	= $(SRC:.cpp=.o)

CXXFLAGS = -Wall -std=c++11 -pthread

all: $(NAME)

$(NAME): $(OBJ)
	g++ -pthread $^ -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
