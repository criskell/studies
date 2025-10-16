TARGET = sqlite-clone
SRCS = main.c
CC = gcc
CFLAGS = -Wall -Wextra

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -rf $(TARGET)