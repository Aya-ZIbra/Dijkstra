# Compiler/linker config and object/depfile directory:
CXX = g++
LD  = g++
OBJS_DIR = .objs


EXE = main
OBJS = main.o
CLEAN_RM =

# Rule for `all` (first/default rule):
all: 
	# Ensure .objs/ exists:
	@mkdir -p $(OBJS_DIR)
	g++ -std=c++14 -O0 -pedantic -Wall  -Wfatal-errors -Wextra  -MMD -MP -g -c  SSSP.cpp -o .objs/SSSP.o
	g++ -std=c++14 -O0 -pedantic -Wall  -Wfatal-errors -Wextra  -MMD -MP -g -c  main.cpp -o .objs/main.o
	g++ .objs/main.o .objs/SSSP.o -std=c++14  -o main

# Additional dependencies for object files are included in the clang++
# generated .d files (from $(DEPFILE_FLAGS)):
-include $(OBJS_DIR)/*.d
#-include $(OBJS_DIR)/uiuc/*.d

# Standard C++ Makefile rules:
clean:
	rm -rf $(EXE)  $(OBJS_DIR) $(CLEAN_RM) *.o *.d
