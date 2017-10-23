CFLAGS := -std=c++11 -pedantic -Wall
DEBUG := -g
OBJECTS := main.o

run: build
	./a.out

build: $(OBJECTS)
	$(CXX) $(CFLAGS) $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $<

clean:
	-rm $(OBJECTS) *.out
