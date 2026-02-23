CC      = gcc
CFLAGS  = -Wall -g
SRC_DIR = src
BIN_DIR = bin

SRCS = $(SRC_DIR)/main.c
TARGET = $(BIN_DIR)/alea_cli

all: $(TARGET)

$(TARGET): $(SRCS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)