CC      = cc
CFLAGS  = -std=c11 -Wall -Wextra -Wpedantic -O2

TARGET  = linear_alloc
SRCS    = heap.c main.c
OBJS    = heap.o main.o

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

heap.o: heap.c heap.h
	$(CC) $(CFLAGS) -c heap.c

main.o: main.c heap.h
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f $(OBJS) $(TARGET)

