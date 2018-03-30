CXXFLAGS = -std=c++11
all:
	
	g++ -c calculator.cpp ${CXXFLAGS} -o calculator.o
	ar rcs libcalculator.a calculator.o
	g++ -g main.cpp ${CXXFLAGS} -L. -lcalculator -o res

.PHONY: all clean

dyn:
	g++ -fPIC -c calculator.cpp -o dyn.o
	g++ -shared -o libdynamic.so dyn.o
	g++ main.cpp -L. -ldynamic -o resdyn


clean:
	rm *.o
	rm *.so
	rm *.a
