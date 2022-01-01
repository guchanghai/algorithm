#
#  Makefile
#  algorithm

CC := gcc

# Folders
SRCDIR := src
BUILDDIR := build
TARGETDIR := bin

# Targets
EXECUTABLE := algorithm
TARGET := $(TARGETDIR)/$(EXECUTABLE)

# Final Paths
INSTALLBINDIR := /usr/local/bin

# Folder Lists
# Note: Intentionally excludes the root of the include folder so the lists are clean
INCDIRS := $(shell find include/**/* -name '*.h' -exec dirname {} \; | sort | uniq)

build:
  gcc -o ./bin/algorithm ./src/median-two-arrays/median-two-arrays.cpp ./src/regular-expression/regular-expression.cpp ./src/main.cpp -I ./include -g -lstdc++

.PHONY: clean