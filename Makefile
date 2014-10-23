#######################################
# Standard C++ Makefile               #
#																      #
# By Florian schneider                #
# florian.schneider@student.tugraz.at #
#######################################
SUBMISSION = pfix
EXECUTABLE = $(SUBMISSION)
SOURCES    = $(wildcard *.cpp)
OBJECTS    = $(patsubst %,%,${SOURCES:.cpp=.o})
CXX        = g++
CXXFLAGS   = -Wall -g -c -std=c++11 -o
EXEFLAGS   = 

all: $(EXECUTABLE) 

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $@ $< -MMD -MF ./$@.d

#link Objects
$(EXECUTABLE) : $(OBJECTS)
	$(CXX) -o $@ $^ $(LDFLAGS)

#make valgrind
valgrind:
	valgrind --tool=memcheck --leak-check=full ./$(EXECUTABLE)

submission:
	zip $(SUBMISSION).zip *.cpp *.h Makefile

run: 
		./$(EXECUTABLE) $(EXEFLAGS)

#make clean
clean:
	rm -f ./*.o
	rm -f ./*.o.d
	rm -f $(EXECUTABLE)