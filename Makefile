CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
SRC = src/main.c src/calendar.c src/event_manager.c src/utils.c
OBJ = $(SRC:.c=.o)
TARGET = calendar

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJ) $(TARGET)