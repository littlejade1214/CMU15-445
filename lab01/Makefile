CC := g++
CCFLAGS = -Wall -g
SRCDIR := ../src
BUILDDIR := ../build

SOURCEDIR = ../src/hash
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SOURCES))

INC := -I include -I include/hash -I /usr/local/include

## config.o: common/config.cpp include/common/config.h 
	## $(CC) $(CCFLAGS) -c common/config.cpp
