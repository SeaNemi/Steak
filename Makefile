#Compilter flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -g -I.

#Contingencies
SRC_DIRS = . cards random_gen
OBJ_DIR = obj
BIN_DIR = bin
TARGET = $(BIN_DIR)/steak

#get all .cpp files, create object file names
SRCS = $(foreach dir,$(SRC_DIRS), $(wildcard $(dir)/*.cpp))
OBJS = $(patsubst %.cpp, $(OBJ_DIR)/%.o,$(SRCS))

#default target
all: directories $(TARGET)

#ensuring directories exist
#@ used to prevent it outputting onto the screen
directories:
	@mkdir -p $(OBJ_DIR) $(foreach dir,$(SRC_DIRS),$(OBJ_DIR)/$(dir))
	@mkdir -p $(BIN_DIR)

#objects linked to create executables
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

#source files compiled to object files, directories needed as prereq to prevent comp error
$(OBJ_DIR)/%.o: %.cpp | directories
	$(CXX) $(CXXFLAGS) -c -o $@ $<

#.d files included
-include $(OBJS:.o=.d)

#dependency files generated, again directories needed as prereq
$(OBJ_DIR)/%.d: %.cpp | directories
	@set -e; rm -f $@; \
	$(CXX) -MM $(CXXFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,$(OBJ_DIR)/\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

#clean for testing
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

#rebuild
rebuild: clean all

#run executable
run: all
	@./$(TARGET)

#target for test
test: all
	./$(TARGET) --test

.PHONY: all clean rebuild run test directories