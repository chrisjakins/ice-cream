CFLAGS := -std=c++11 -pedantic -Wall
DEBUG := -g
OBJECTS := main.o scoop.o
TESTSCOOP := test_scoop.o scoop.o
SOURCE := ./src/

# TODO find a place to put the bin files
run: build
	./a.out

build: $(OBJECTS)
	$(CXX) $(CFLAGS) $(OBJECTS)

%.o: $(SOURCE)%.cpp
	$(CXX) $(CFLAGS) -c $<

testall: testscoop

testscoop: $(TESTSCOOP)
	$(CXX) $(CFLAGS) $(TESTSCOOP)
	./a.out

clean:
	-rm *.o *.out
