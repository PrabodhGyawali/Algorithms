CC = gcc
CFLAGS = -Wall -Wextra -g
INCLUDES = -Icommon/algorithms -Icommon/maze_utils
LDFLAGS =

# Directories containing source files
DIRS = algorithms maze_utils

# Source Files
SRC = main.c $(foreach dir,$(DIRS),$(wildcard $(dir)/*.c))

# Object Files
OBJ = $(SRC:.c=.o)

# Target executable
TARGET = maze_app

# Default target
all: $(TARGET)

# Rule to create object files
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Rule to create the executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) -o $@

# Clean build files
clean:
	rm -f $(OBJ) $(TARGET)

# Phony targets
.PHONY: all clean