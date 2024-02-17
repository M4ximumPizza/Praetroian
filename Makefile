SRC_FILES := $(filter-out ./src/main.cpp, $(wildcard ./src/*.cpp))

all: build

build:
	g++ -std=c++11 ./src/main.cpp $(SRC_FILES) -Isrc -o ./jc

run:
	./jc

.PHONY: build