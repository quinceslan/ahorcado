SOURCES= $(wildcard *.cpp)
OBJECTS= $(patsubst %.cpp,%.o,$(SOURCES))
CXXFLAGS= -Wall

BIN= ahorcado

all: $(BIN)

run: $(BIN)
	./$<

$(BIN): $(OBJECTS)
	$(CXX) -o $@ $^

clean:
	$(RM) $(BIN) $(OBJECTS)
