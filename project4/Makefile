CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall 
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
LDFLAGS = -lboost_date_time

OBJS = count_letters.o output_letters.o main.o

SRCS = count_letters.cpp output_letters.cpp main.cpp

HEADERS = count_letters.hpp output_letters.hpp

countLetters: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o countLetters

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)