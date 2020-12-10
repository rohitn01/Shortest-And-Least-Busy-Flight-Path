EXENAME = airports
OBJS = main.o graph.o airport.o dataset.o BFS.o Dijkstra.o BetweennessCentrality.o

CXX = clang++
CXXFLAGS = $(CS225) -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi -lm

# Custom Clang version enforcement logic:
ccred=$(shell echo -e "\033[0;31m")
ccyellow=$(shell echo -e "\033[0;33m")
ccend=$(shell echo -e "\033[0m")

IS_EWS=$(shell hostname | grep "ews.illinois.edu") 
IS_CORRECT_CLANG=$(shell clang -v 2>&1 | grep "version 6")
ifneq ($(strip $(IS_EWS)),)
ifeq ($(strip $(IS_CORRECT_CLANG)),)
CLANG_VERSION_MSG = $(error $(ccred) On EWS, please run 'module load llvm/6.0.1' first when running CS225 assignments. $(ccend))
endif
else
ifneq ($(strip $(SKIP_EWS_CHECK)),True)
CLANG_VERSION_MSG = $(warning $(ccyellow) Looks like you are not on EWS. Be sure to test on EWS before the deadline. $(ccend))
endif
endif

.PHONY: all test clean output_msg

all : $(EXENAME)

output_msg: ; $(CLANG_VERSION_MSG)

$(EXENAME) : output_msg $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

main.o : main.cpp graph/graph.h data/airport.h
	$(CXX) $(CXXFLAGS) main.cpp

graph.o : graph/graph.h graph/graph.cpp
	$(CXX) $(CXXFLAGS) graph/graph.cpp

airport.o : data/airport.h data/airport.cpp
	$(CXX) $(CXXFLAGS) data/airport.cpp

dataset.o : data/dataset.h data/dataset.cpp
	$(CXX) $(CXXFLAGS) data/dataset.cpp

BFS.o : algo/BFS.h algo/BFS.cpp
	$(CXX) $(CXXFLAGS) algo/BFS.cpp

Dijkstra.o : algo/Dijkstra.h algo/Dijkstra.cpp
	$(CXX) $(CXXFLAGS) algo/Dijkstra.cpp

BetweennessCentrality.o : algo/BetweennessCentrality.h algo/BetweennessCentrality.cpp
	$(CXX) $(CXXFLAGS) algo/BetweennessCentrality.cpp

test: output_msg catchmain.o tests.o graph.o airport.o dataset.o BetweennessCentrality.o Dijkstra.o BFS.o
	$(LD) catchmain.o tests.o graph.o airport.o dataset.o BetweennessCentrality.o Dijkstra.o BFS.o $(LDFLAGS) -o test

catchmain.o : cs225/catch/catchmain.cpp cs225/catch/catch.hpp
	$(CXX) $(CXXFLAGS) cs225/catch/catchmain.cpp

tests.o : tests/tests.cpp cs225/catch/catch.hpp graph/graph.cpp graph/graph.h data/dataset.h data/airport.h algo/BetweennessCentrality.h algo/Dijkstra.h algo/BFS.o
	$(CXX) $(CXXFLAGS) tests/tests.cpp

clean :
	-rm -f *.o $(EXENAME) test


# Use the cs225 makefile template:
include cs225/make/cs225.mk
