CXX = g++
CXXFLAGS = -Wall -Wextra -Wpedantic

.PHONY: all
all: library
library : library.cpp date.o person.o book.o member.o librarian.o
	$(CXX) $(CXXFLAGS) -o $@ $^

.PHONY: test 
test: testing

testing: test.cpp person.o date.o book.o member.o librarian.o
	$(CXX) $(CXXFLAGS) -o $@ $^ 

member.o : member.cpp member.h 
	$(CXX) $(CXXFLAGS) -c $<
person.o : person.cpp person.h
	$(CXX) $(CXXFLAGS) -c $<
librarian.o : librarian.cpp librarian.h
	$(CXX) $(CXXFLAGS) -c $<

book.o : book.cpp book.h
	$(CXX) $(CXXFLAGS) -c $<

date.o : date.cpp date.h 
	$(CXX) $(CXXFLAGS) -c $<

.PHONY: clean
clean:
	rm -f *.o testing library
