CC = gcc
CFLAGS = -Wall -Wextra -Icommon/main -Icommon/maze_generator -g
LDFLAGS = 

# Directories
SRC_DIR = common
MAIN_DIR = $(SRC_DIR)/main
MAZE_DIR = $(SRC_DIR)/maze_generator
BUILD_DIR = build

# Source Files
MAIN_SRC = $(MAIN_DIR)/main.c $(MAIN_DIR)/recursive_backtracking.c
MAIN_SRC = $(MAZE_DIR)/maze_generator.c
SRC = $(MAIN_SRC) $(MAZE_SRC)

# Object Files
OBJ = $(patsubst %.c,$(BUILD_DIR)/%.o, $(SRC))

TARGET = maze_app

all: $(TARGET)

# Linking
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) 

# Compiling
$(BUILD_DIR)/%.main.o: $(MAIN_DIR)/%.c
	@mkdir -p $(BUILD_DIR)/main
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.maze_generator.o: $(MAZE_DIR)/%.c
	@mkdir -p $(BUILD_DIR)/maze_generator
	$(CC) $(CFLAGS) -c $< -o $@

# Clean Build Files
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

# Phony Targets
.PHONY: all clean

