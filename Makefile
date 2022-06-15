#!make -f

CXX=clang++-9
CXXFLAGS=-std=c++2a -Werror 
HEADERS=spesific_game.hpp Team.hpp my_leag.hpp leag_scheduale.hpp 
OBJECTS=spesific_game.o Team.o my_leag.o leag_scheduale.o 
SOURCES=spesific_game.cpp Team.cpp my_leag.cpp leag_scheduale.cpp 

test: TestRunner.o Test.o
	$(CXX) $(CXXFLAGS) $^ -o test

tidy:
	clang-tidy $(SOURCES) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-* --warnings-as-errors=-* --

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) --compile $< -o $@

clean:
	rm -f *.o demo test
