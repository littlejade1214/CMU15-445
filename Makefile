UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Darwin)
  CC := clang++ -arch x86_64
else
  CC := g++
endif

SRCDIR := src
LIBDIR := lib
BUILDDIR := build
TARGETDIR := bin
INSTALLBINDIR := /usr/local/bin
TARGET := bin/sqlite3


SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))


SRCEXT2 := cc
SOURCES2 := $(shell find $(SRCDIR)/proto -type f -name *.$(SRCEXT2))
OBJECTS2 := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES2:.$(SRCEXT2)=.o))

CFLAGS := -c
ifeq ($(UNAME_S),Linux)
  CFLAGS += -std=gnu++11 -O2
else
  CFLAGS += -std=c++11 -stdlib=libc++ -O2
endif

LIB := -L /usr/local/lib -lsqlite3 -lprotobuf 
INC := -I include -I include/proto -I /usr/local/include