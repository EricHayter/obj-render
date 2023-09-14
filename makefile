BINARY=main
BUILDDIR=./build

CC=g++
OPT=-O0
DEPFLAGS=-MP -MD
CLAGS=`-ggdb -pedantic-errors -std=c++20 -Werror -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -I.`
SDLFLAGS=`sdl2-config --cflags --libs`

CFILES=$(wildcard *.cpp)
OBJECTS=$(patsubst %.cpp, $(BUILDDIR)/%.o,$(CFILES))
DEPFILES=$(patsubst %.cpp,%.d,$(CFILES))

$(info $(CFILES))

all: $(BINARY)

$(BINARY): $(OBJECTS)
	$(CC) -o $@ $^ $(SDLFLAGS) -ggdb

$(BUILDDIR)/%.o:%.cpp
	$(CC) -ggdb $(CFLAGS) -c -o $@ $^

clean:
	rm -rf $(BINARY) $(OBJECTS)
