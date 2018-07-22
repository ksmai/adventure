CXX=g++
CXXFLAGS=-std=c++14 -Wall
EXE=adventure

SRCS=$(shell find -name "*.cpp")
OBJS=$(subst .cpp,.o,$(SRCS))

all: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXE) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm $(OBJS) $(EXE)
