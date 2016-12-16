CC=g++
CFLAGS=-c -Wall -std=c++11 -lstdc++ -lm
LDFLAGS=-lstdc++ -lm
SOURCES=main.cpp calculator.cpp types.cpp
SOURCES_TEST=tests.cpp types.cpp calculator.cpp libgtest.a
OBJECTS=$(SOURCES:.cpp=.o)
BIN=calc
TESTS=calc_tests

all: $(SOURCES) $(BIN)
	
$(BIN): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.o rm $(BIN) rm $(TESTS)

tests:
	$(CC) -std=c++11 -isystem gtest/include -pthread $(SOURCES_TEST) -o $(TESTS)