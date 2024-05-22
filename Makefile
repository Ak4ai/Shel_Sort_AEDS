CXX      := g++
CXXFLAGS := -Wall -Wextra -Werror
LDFLAGS  := -lstdc++ -lm
BUILD    := build
OBJ_DIR  := $(BUILD)/objects
APP_DIR  := $(BUILD)
TARGET   := app.exe
INCLUDE  := -Iinclude
SRC      := $(wildcard src/*.cpp)

OBJECTS := $(SRC:src/%.cpp=$(OBJ_DIR)/%.o)

all: build $(APP_DIR)/$(TARGET)

$(OBJ_DIR)/%.o: src/%.cpp
	@mkdir $(@D) 2> nul || echo.
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ -c $<

$(APP_DIR)/$(TARGET): $(OBJECTS)
	@mkdir $(@D) 2> nul || echo.
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(LDFLAGS) -o $@ $(OBJECTS)

.PHONY: all build clean debug release run

build:
	@mkdir $(APP_DIR) 2> nul || echo.
	@mkdir $(OBJ_DIR) 2> nul || echo.

debug: CXXFLAGS += -DDEBUG -g
debug: all

release: CXXFLAGS += -O3
release: all

clean:
	-del /s /q $(OBJ_DIR)/* 2> nul || echo.
	-del /s /q $(APP_DIR)/* 2> nul || echo.

run:
	$(APP_DIR)/$(TARGET)