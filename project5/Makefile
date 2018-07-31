CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall 
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
LDFLAGS = -lboost_date_time

OBJS = Die.o LoadedDie.o Game.o main.o

SRCS = Die.cpp LoadedDie.cpp Game.cpp main.cpp

HEADERS = Die.hpp LoadedDie.hpp Game.hpp

war: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o war

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)