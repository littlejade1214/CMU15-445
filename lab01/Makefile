CC := g++
CCFLAGS = -Wall -g
SRCDIR := ../src
BUILDDIR := ../build

SOURCEDIR = ../src/hash
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SOURCES))

INC := -I include -I include/hash -I /usr/local/include

## extendible_hash.o: hash/extendible_hash.cpp include/hash/extendible_hash.h include/page/page.h
	## $(CC) $(CCFLAGS) -c hash/extendible_hash.cpp
