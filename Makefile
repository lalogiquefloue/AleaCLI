CC      = gcc
CFLAGS  = -Wall -g -Isrc
SRC_DIR = src
BIN_DIR = bin
OBJ_DIR = obj

SRCS   = $(shell find $(SRC_DIR) -name '*.c')
OBJS   = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
TARGET = $(BIN_DIR)/alea_cli

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

debug: $(TARGET)
	gdb $(TARGET)

check: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET) $(ARGS)

run: $(TARGET)
	./$(TARGET) $(ARGS)

clean:
	@echo "Cleaning up..."
	rm -rf $(BIN_DIR) $(OBJ_DIR)

rebuild: clean all