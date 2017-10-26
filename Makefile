CFLAGS := -std=c++11 -pedantic -Wall `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
OBJECTS := main.o scoop.o main_window.o container.o item.o topping.o
SOURCE := ./src/

DEBUG := -g

TESTSCOOP := test_scoop.o scoop.o item.o
TESTCONTAINER := test_container.o container.o item.o
TESTTOPPING := test_topping.o topping.o item.o


# TODO find a place to put the bin files
run: build
	./a.out

build: $(OBJECTS)
	$(CXX) $(OBJECTS) $(CFLAGS)

%.o: $(SOURCE)%.cpp
	$(CXX) -c $< $(CFLAGS)

testall: testscoop testcontainer testtopping

testscoop: $(TESTSCOOP)
	$(CXX) $(TESTSCOOP) $(CFLAGS)
	./a.out

testcontainer: $(TESTCONTAINER)
	$(CXX) $(TESTCONTAINER) $(CFLAGS)
	./a.out

testtopping: $(TESTTOPPING)
	$(CXX) $(TESTTOPPING) $(CFLAGS)
	./a.out

clean:
	-rm *.o *.out
