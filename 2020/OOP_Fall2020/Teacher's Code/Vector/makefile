.PHONY: all
#all: target
all:karma

#target: src/stringExample.cpp src/chk_string.cpp what
#	g++ src/stringExample.cpp src/chk_string.cpp -o bin/stringExample

karma: test/ut_main.cpp what
	g++ -std=c++11 test/ut_main.cpp -o bin/ut_all -lgtest -lpthread

what:
	mkdir -p bin obj

.PHONY: clean
clean:
	rm -f bin/*
	rm -f obj/*
