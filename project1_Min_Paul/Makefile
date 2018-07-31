CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall 
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
LDFLAGS = -lboost_date_time

OBJS = Ant.o Board.o Interface.o main.o

SRCS = Ant.cpp Board.cpp Interface.cpp main.cpp

HEADERS = Ant.hpp Board.hpp Interface.hpp

langtonAnt: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o langtonAnt

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)
