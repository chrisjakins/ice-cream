CFLAGS := -std=c++11 -pedantic -Wall `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
DEBUG := -g
TESTSCOOP := test_scoop.o scoop.o
OBJECTS := main.o scoop.o main_window.o
SOURCE := ./src/

# TODO find a place to put the bin files
run: build
	./a.out

build: $(OBJECTS)
	$(CXX) $(OBJECTS) $(CFLAGS)

%.o: $(SOURCE)%.cpp
	$(CXX) -c $< $(CFLAGS)

testall: testscoop

testscoop: $(TESTSCOOP)
	$(CXX) $(TESTSCOOP) $(CFLAGS)
	./a.out

clean:
	-rm *.o *.out
