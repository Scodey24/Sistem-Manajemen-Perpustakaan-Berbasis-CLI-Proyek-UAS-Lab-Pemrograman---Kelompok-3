.PHONY: all run clean
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

SRC = src/main.c src/admin.c src/auth.c src/file_io.c src/sorting.c src/user.c
TARGET = src/app

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./src/app

clean:
	rm -f $(TARGET)
