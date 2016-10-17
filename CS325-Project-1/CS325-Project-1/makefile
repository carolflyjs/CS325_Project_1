CC=g++
CFLAGS=-c -Wall -std=c++11
LDFLAGS=
SOURCES = main.cpp operator.cpp 1_num.cpp 2_betterNum.cpp 3_DandC.cpp 4_linear.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = proj1

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
