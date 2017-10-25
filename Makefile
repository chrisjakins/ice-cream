CFLAGS := -std=c++11 -pedantic -Wall
DEBUG := -g
OBJECTS := main.o scoop.o
SOURCE := ./src/

# TODO find a place to put the bin files
run: build
	./a.out

build: $(OBJECTS)
	$(CXX) $(CFLAGS) $(OBJECTS)

%.o: $(SOURCE)%.cpp
	$(CXX) $(CFLAGS) -c $<

clean:
	-rm $(OBJECTS) *.out
