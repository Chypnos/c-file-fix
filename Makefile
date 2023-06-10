# TARGETS

CC = gcc
CXX = g++

DEBUG ?= 1
ENABLE_WARNINGS ?= 1
WARNING_AS_ERRORS ?= 0

CSTANDARD = -std=c99

ifeq ($(ENABLE_WARNINGS), 1)
CFLAGS = -Wall -Wextra -g -Wpedantic
else
CFLAGS = 
endif

ifeq ($(WARNING_AS_ERRORS), 1)
CFLAGS += -Werror
endif
CLIBS = -lm

EXECUTABLE_NAME = app

SOURCE_DIR = ./src/*.c
BUILD_DIR = build

ifeq ($(DEBUG), 1)
CFLAGS += -g -O0
else
CFLAGS += -O3
endif

GREEN='\033[32m'
NC='\033[0m' # No Color

all: build execute

create:
	@mkdir -p $(BUILD_DIR)

build: create
	@echo -e $(GREEN)Compiling with $(CC) $(CSTANDARD) and $(CFLAGS) debug mode $(DEBUG) ...$(NC)
	@$(CC) $(CFLAGS) $(CSTANDARD) $(SOURCE_DIR) -o $(BUILD_DIR)/$(EXECUTABLE_NAME) $(CLIBS)

execute:
	@$(BUILD_DIR)/$(EXECUTABLE_NAME)

clean:
	rm -f $(BUILD_DIR)/*.o
	rm -f $(BUILD_DIR)/$(EXECUTABLE_NAME)

.PHONY: all build execute clean