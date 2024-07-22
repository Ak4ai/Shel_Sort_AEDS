# Detect OS
ifeq ($(OS),Windows_NT)
    RM = -del /s /q
    MD = @mkdir 2> nul || echo.
    EXE = .exe
else
    RM = rm -rf
    MD = @mkdir -p
    EXE =
endif

# Compiladores e Flags
CXX      := g++
CC       := gcc
CXXFLAGS := -Wall -Wextra -Werror
CFLAGS   := -Wall -Wextra -Werror
LDFLAGS  := -lstdc++ -lm
BUILD    := build
OBJ_DIR  := $(BUILD)/objects
APP_DIR  := $(BUILD)
TARGET   := app$(EXE)
INCLUDE  := -Iinclude
SRC_CPP  := $(wildcard src/*.cpp)
SRC_C    := $(wildcard src/*.c)

# Arquivos objeto
OBJECTS_CPP := $(SRC_CPP:src/%.cpp=$(OBJ_DIR)/%.o)
OBJECTS_C   := $(SRC_C:src/%.c=$(OBJ_DIR)/%.o)
OBJECTS     := $(OBJECTS_CPP) $(OBJECTS_C)

all: build $(APP_DIR)/$(TARGET)

$(OBJ_DIR)/%.o: src/%.cpp
	$(MD) $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ -c $<

$(OBJ_DIR)/%.o: src/%.c
	$(MD) $(@D)
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

$(APP_DIR)/$(TARGET): $(OBJECTS)
	$(MD) $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(LDFLAGS) -o $@ $(OBJECTS)

.PHONY: all build clean debug release run

build:
	$(MD) $(APP_DIR)
	$(MD) $(OBJ_DIR)

debug: CXXFLAGS += -DDEBUG -g
debug: CFLAGS += -DDEBUG -g
debug: all

release: CXXFLAGS += -O3
release: CFLAGS += -O3
release: all

clean:
	$(RM) $(OBJ_DIR)/*
	$(RM) $(APP_DIR)/*

run:
	$(APP_DIR)/$(TARGET)
