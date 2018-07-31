CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall 
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
LDFLAGS = -lboost_date_time

OBJS = Building.o Instructor.o Person.o Student.o University.o main.o

SRCS = Building.cpp Instructor.cpp Person.cpp Student.cpp University.cpp main.cpp

HEADERS = Building.hpp Instructor.hpp Person.hpp Student.hpp University.hpp

sis: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o sis

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)