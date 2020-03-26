# --------------------------------------------------------------------
# @program       predatorPrey makefile
# @author        Michael Copland
# @date          2019-04-23
# --------------------------------------------------------------------

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++0x -g

PROJECT = predatorPrey
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

# $@ file name of the target of the rule
# $^ names of all prerequisites
$(PROJECT): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# $< name of first prerequisite
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

zip:
	zip Group13.zip $(SOURCES) $(wildcard *.hpp) $(wildcard *.pdf) makefile
	@echo "Files zipped."

clean:
	rm *.o $(PROJECT)
	@echo "Files cleaned."
