OBJS = fixedpoint_test.cpp
CC = clang++
CFLAGS = -std=c++14
OUT = fixed_test

all: fixedpoint.hpp fixedpoint_test.cpp fixedpoint.cpp
	$(CC) $(CFLAGS) -o $(OUT) $(OBJS)

clean:
	rm -rf $(OUT)