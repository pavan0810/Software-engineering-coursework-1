CXX = g++
CXXFLAGS = -Wall -Wextra -Wpedantic

.PHONY: all
all: library
library : main.cpp person.o member.o librarian.o book.o
	$(CXX) $(CXXFLAGS) -o $@ $^

.PHONY: test 
test: testing

testing: test.cpp person.o book.o member.o librarian.o
	$(CXX) $(CXXFLAGS) -o $@ $^ 

member.o : member.cpp member.h person.o book.o
	$(CXX) $(CXXFLAGS) -c $<

person.o : person.cpp person.h
	$(CXX) $(CXXFLAGS) -c $<

librarian.o : librarian.cpp librarian.h person.o book.o
	$(CXX) $(CXXFLAGS) -c $<

book.o : book.cpp book.h 
	$(CXX) $(CXXFLAGS) -c $<

.PHONY: clean
clean:
	rm -f *.o testing library
