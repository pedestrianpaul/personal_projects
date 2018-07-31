CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall 
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
LDFLAGS = -lboost_date_time

OBJS = Animal.o Cheetah.o Penguin.o Tiger.o Turtle.o Zoo.o main.o

SRCS = Animal.cpp Cheetah.cpp Penguin.cpp Tiger.cpp Turtle.cpp Zoo.cpp main.cpp

HEADERS = Animal.hpp Cheetah.hpp Penguin.hpp Tiger.hpp Turtle.hpp Zoo.hpp

zoo: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o zoo

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)