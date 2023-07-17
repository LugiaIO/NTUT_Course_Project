CXX=g++
CPPFLAGS=-std=c++11 -Wfatal-errors -Wall
LDFLAGS=-lgtest -lpthread

TEST= test/ut_term.h test/ut_polynomial.h
SRC=src/term.h src/polynomial.h

.PHONY: dirs clean

all: dirs ut_main

dirs:
	mkdir -p bin
	mkdir -p obj

ut_main: $(TEST)
	$(CXX) $(SRC) test/ut_main.cpp $(CPPFLAGS) $(LDFLAGS) -o bin/ut_all

test: ut_main
	./bin/ut_all

clean:
	rm -rf bin/* obj/*