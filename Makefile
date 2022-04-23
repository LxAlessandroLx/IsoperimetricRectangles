.PHONY: build

CXX := g++
CXXFLAGS := -Wall 
SFMLFLAGS := -lsfml-graphics -lsfml-window -lsfml-system
BUILDDIR := build
TARGET := IsoperimetricRectangles
OBJ := src/main.o src/Program.o
INCLUDE := -I src

all: $(TARGET)

$(TARGET): $(OBJ)
	make -p build
	$(CXX) -o $(BUILDDIR)/$(TARGET) $^ $(SFMLFLAGS)

%.o: %.cpp
	$(CXX) -c $(INCLUDE) -o $@ $^ $(CXXFLAGS)

clean:
	$(RM) $(OBJ)

run:
	./$(BUILDDIR)/$(TARGET)
