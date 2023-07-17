.PHONY: all
#all: target
all:karma

target: src/stringExample.cpp src/chk_string.cpp what
	g++ src/stringExample.cpp src/chk_string.cpp -o bin/stringExample

karma: src/chk_string.cpp test/ut_main.cpp what
	g++ test/ut_main.cpp src/chk_string.cpp -o bin/ut_main -lgtest -lpthread

what:
	mkdir -p bin obj

.PHONY: clean
clean:
	rm -f bin/*
	rm -f obj/*
