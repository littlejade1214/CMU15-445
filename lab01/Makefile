CC := g++
CCFLAGS = -Wall -g
SRCDIR := ../src
BUILDDIR := ../build
TARGET :=

SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SOURCES))

INC := -I include -I /usr/local/include

## $(TARGET): $(OBJECTS)
	## $(CC) $^ -o $(TARGET) $(LIB)
## $(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	## $(CC) $(CCFLAGS) -c $< -o $@

## extendible_hash_test.o: extendible_hash_test.cpp extendible_hash.o
	## $(CC) $(CCFLAGS) -c extendible_hash_test.cpp

