# This is the default target, which will be built when
# you invoke make
.PHONY: all
all: bin/stringExample

# This rule tells make how to build hello_world from hello_world.cpp
bin/stringExample: src/stringExample.cpp directories
	g++ src/stringExample.cpp -o bin/stringExample

# This rule create the bin and obj directory if they do not exist
directories:
	mkdir -p bin obj

# This rule tells make to delete hello and hello.o
.PHONY: clean
clean:
	rm -f bin/*
	rm -f obj/*
