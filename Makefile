CXX = g++
CXXFLAGS = -Wall -Wextra -Wpedantic

library : main.cpp person.o member.o librarian.o book.o
	$(CXX) $(CXXFLAGS) -o $@ $^

member.o : member.cpp member.h person.h book.h
	$(CXX) $(CXXFLAGS) -c $<

person.o : person.cpp person.h
	$(CXX) $(CXXFLAGS) -c $<

librarian.o : librarian.cpp librarian.h person.h book.h
	$(CXX) $(CXXFLAGS) -c $<

book.o : book.cpp book.h member.h
	$(CXX) $(CXXFLAGS) -c $<

.PHONY: clean
clean:
	rm -f *.o library
