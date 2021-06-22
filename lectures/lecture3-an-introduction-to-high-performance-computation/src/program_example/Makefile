CXX = g++
CXXFLAGS = -std=c++11 -Wall -fopenmp -pthread
LDFLAGS = 
LDLIBS = -lmysys -lmymathCC -lrt

%.out: %.cpp
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^ $(LDLIBS)

EXECS := $(patsubst %.cpp, %.out, $(wildcard *.cpp))
$(EXECS):