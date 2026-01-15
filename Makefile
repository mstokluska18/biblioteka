
CXX = g++

CXXFLAGS = -std=c++11 -Wall

TARGET = biblioteka_projekt


SRC = main.cpp item.cpp book.cpp movie.cpp magazine.cpp library.cpp
OBJ = $(SRC:.cpp=.o)
all: $(TARGET)
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
clean:
	rm -f $(OBJ) $(TARGET)

