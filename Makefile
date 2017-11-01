CFLAGS := -std=c++11 -pedantic -Wall `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
DEBUG := -g

OBJECTS := main.o scoop.o main_window.o container.o item.o serving.o
OBJECTS += topping.o person.o customer.o order.o server.o emporium.o

SOURCEDIR := ./src/
TESTDIR := ./tests/
BINDIR := ./bin/

TESTSCOOP := test_scoop.o scoop.o item.o
TESTCONTAINER := test_container.o container.o item.o
TESTTOPPING := test_topping.o topping.o item.o
TESTSERVING := test_serving.o serving.o item.o container.o topping.o scoop.o
TESTCUSTOMER := test_customer.o person.o customer.o
TESTSERVER := test_server.o person.o server.o

# TODO find a place to put the bin files
run: build
	./a.out

build: $(OBJECTS)
	$(CXX) $(OBJECTS) $(CFLAGS)

%.o: $(SOURCEDIR)%.cpp
	$(CXX) -c $< $(CFLAGS)

testall: testscoop testcontainer testtopping testserving testcustomer testserver

testscoop: $(TESTSCOOP)
	$(CXX) $(TESTSCOOP) $(CFLAGS)
	./a.out

testcontainer: $(TESTCONTAINER)
	$(CXX) $(TESTCONTAINER) $(CFLAGS)
	./a.out

testtopping: $(TESTTOPPING)
	$(CXX) $(TESTTOPPING) $(CFLAGS)
	./a.out

testserving: $(TESTSERVING)
	$(CXX) $(TESTSERVING) $(CFLAGS)
	./a.out

testcustomer: $(TESTCUSTOMER)
	$(CXX) $(TESTCUSTOMER) $(CFLAGS)
	./a.out

testserver: $(TESTSERVER)
	$(CXX) $(TESTSERVER) $(CFLAGS)
	./a.out

clean:
	-rm *.o *.out
