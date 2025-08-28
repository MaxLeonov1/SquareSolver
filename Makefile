CXX = g++
CFLAGS=-c -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

OBJ = main.o input_output_functions.o solve_equation.o supporting_functions.o unit_test.o

all: $(OBJ)
	$(CXX) $(OBJ) -o square_solver
	rm -f $(OBJ)  

main.o: ./src/main.c
	@$(CXX) $(CFLAGS) -I./include/ ./src/main.c

input_output_functions.o: ./src/input_output_functions.cpp
	@$(CXX) $(CFLAGS) -I./include/ ./src/input_output_functions.cpp

solve_equation.o: ./src/solve_equation.cpp
	@$(CXX) $(CFLAGS) -I./include/ ./src/solve_equation.cpp

supporting_functions.o: ./src/supporting_functions.cpp
	@$(CXX) $(CFLAGS) -I./include/ ./src/supporting_functions.cpp

unit_test.o: ./test/unit_test.cpp
	@$(CXX) $(CFLAGS) -I./include/ ./test/unit_test.cpp

clean:
	@rm -f *.o square_solver