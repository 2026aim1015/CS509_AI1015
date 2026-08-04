CXX = g++

CXXFLAGS = -Wall -O2 -std=c++11

SRC = src/gemm_simple.cpp \
      src/gemm_blocking.cpp \
      driver/driver.cpp

TARGET = driver

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) *.exe