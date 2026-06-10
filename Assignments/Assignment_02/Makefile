CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

SRCS = Person.cpp Treatment.cpp Bill.cpp Patient.cpp \
       StaffMember.cpp Roles.cpp Ward.cpp \
       AppointmentBook.cpp Hospital.cpp main.cpp

OBJS = $(SRCS:.cpp=.o)
TARGET = medicore

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
