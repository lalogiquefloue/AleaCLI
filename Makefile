CC      = gcc
CFLAGS  = -Wall -g
SRC_DIR = ./src
BIN_DIR = ./bin

SRCS = $(SRC_DIR)/main.c
TARGET = $(BIN_DIR)/alea_cli

all: $(TARGET)

$(TARGET): $(SRCS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

debug: $(TARGET)
	gdb ./$(TARGET)

check: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET) $(ARGS)

run: $(TARGET)
	./$(TARGET) $(ARGS)

clean:
	@echo "Cleaning up..."
	rm -rf $(BIN_DIR)/*
	rm -f $(TARGET)

rebuild: clean all