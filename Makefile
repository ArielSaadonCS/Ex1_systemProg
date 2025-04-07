
CC = clang++
CFLAGS = -Wall -std=c++11

# Source and object files
SRCS = $(filter-out tests.cpp, $(wildcard *.cpp))
OBJS = $(SRCS:.cpp=.o)
TEST_SRCS = tests.cpp $(filter-out main.cpp, $(SRCS))
TEST_OBJS = $(TEST_SRCS:.cpp=.o)

MAIN_EXEC = graph_algorithms
TEST_EXEC = tests


# Main target
all: $(MAIN_EXEC)

# Executable
$(MAIN_EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Pattern rule for object files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Dependencies
main.o: main.cpp graph.hpp
graph.o: graph.cpp graph.hpp
priority_queue.o: priority_queue.cpp priority_queue.hpp
queue.o: queue.cpp queue.hpp
union_find.o: union_find.cpp union_find.hpp
Algorithms.o: Algorithms.cpp graph.hpp queue.hpp priority_queue.hpp union_find.hpp
tests.o: tests.cpp graph.hpp doctest.h

Main: $(MAIN_EXEC)
	./$(MAIN_EXEC)

test: $(TEST_EXEC)
	./$(TEST_EXEC)

$(TEST_EXEC): tests.o $(filter-out main.o, $(OBJS))
	$(CC) $(CFLAGS) -o $@ $^

valgrind: $(MAIN_EXEC)
	valgrind --leak-check=full ./$(MAIN_EXEC)

# Clean
clean:
	rm -f *.o graph_algorithms tests

# Phony targets
.PHONY: all clean