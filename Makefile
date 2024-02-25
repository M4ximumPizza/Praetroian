SRC_FILES := $(filter-out ./src/main.cpp, $(wildcard ./src/*.cpp))
OS := $(OS)

ifeq ($(OS),Windows_NT)
    CXX := g++
    CXXFLAGS := -std=c++11 -Wall
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
        CXX := g++
        CXXFLAGS := -std=c++11 -Wall
    endif
    ifeq ($(UNAME_S),Darwin)
        CXX := g++
        CXXFLAGS := -std=c++11 -Wall
    endif
    ifeq ($(UNAME_S),FreeBSD)
        CXX := g++
        CXXFLAGS := -std=c++11 -Wall
    endif
endif

all: build

build:
	$(CXX) $(CXXFLAGS) ./src/main.cpp $(SRC_FILES) -Isrc -o ./jc

run:
	./jc

.PHONY: build
