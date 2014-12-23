
OPT_FLAGS = -g

CPPFLAGS = $(OPT_FLAGS) -I.

TARGETS = testSmallLA

all: $(TARGETS)

testSmallLA: testSmallLA.o
	g++ -o testSmallLA testSmallLA.o

%.o: %.cpp
	g++ -c $(CPPFLAGS) $< -o $@

clean::
	-rm -vf $(TARGETS) *.o
