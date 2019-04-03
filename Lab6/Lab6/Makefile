# src/*.cpp
SRC :=  $(wildcard src/*.cpp)

# src/*.cpp -> src/*.o
OBJ := $(patsubst %.cpp,%.o, $(SRC))

# test/*.cpp
TEST := $(sort $(wildcard test/*.cpp)) 

# test/*.cpp -> test/*.exe
TARGET := $(patsubst %.cpp,%.exe, $(TEST))

# err_msg.txt
ERR_MSG := err_msg.txt

all: reset_err_msg build test clean

# Tricks used in this makefile are as following:

# 1. "@" at the beginning of a command.
#    Adding "@" before a command can avoid echoing it.

# 2. "|| true" at the end of a command.
#    Makefile will terminate if any of the commands fails (and returns false). 
#    Adding "|| true" after a command makes it always return true.
#    This avoids compilation terminating halfway.

# 3. "2>>$(ERR_MSG)" or "2>>/dev/null".
#    When a command encounters some errors, it will output error messages via stderr (or std::cerr in C++).
#    Comparing to stdout (std::cout in C++), stderr (std:cerr) is a different channel.
#    In our case, we want to output the "meet cook" message (coming from stdout) and hide compilation error messages (coming from stderr).
#    So we need to redirect the stderr message to "somewhere" by adding "2>>somewhere" at the end of the command.
#    Where "2" is for stderr, ">>" means redirection, "somewhere" is a filename, if the file does not exist, it will be created automatically.
#    /dev/null is a black hole file called "null device", which takes data and discards them.
#    If you redirect your messages into it, you will never find them again.

# Step 1: Remove previous err_msg.txt.
reset_err_msg:
	@rm -f $(ERR_MSG)

# Step 2: Build the .o for the compilable .cpp in src/ and ignore the uncompilable ones.
build: $(OBJ)

%.o: %.cpp
	@g++ $< -c -o $@ -std=c++11 2>>$(ERR_MSG) || true

# Step 3: Build and run the .exe for the compilale .cpp in test/ given the compiled src/*.o. Uncompilable ones will be ignored.
test: $(TARGET)

%.exe: %.cpp
	@g++ $< src/*.o -o $@ -std=c++11 2>>$(ERR_MSG) || true
	@./$@ 2>>/dev/null || true

# Step 4: Clean .o and .exe
clean:
	@rm -f $(OBJ)
	@rm -f $(TARGET)
