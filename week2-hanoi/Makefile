# Makefile for CSC-301 Worksheet #2
# Eric A. Autry, 09/02/25
# 
# As usual, you can build this software by typing:
#
#     make


# ----- Make Macros -----

CXXFLAGS =	
CXX	=	clang

TARGETS =	worksheet2
OBJECTS =	worksheet2.cpp
REMOVE =	worksheet2.o
LINKS =	-std=c++20 -lstdc++ -lm
INCLUDE = 

# ----- Make Rules -----

all:	$(TARGETS)

worksheet2:	$(OBJECTS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o worksheet2 $(OBJECTS) $(LINKS)

clean:
	rm -f $(TARGETS) $(REMOVE)