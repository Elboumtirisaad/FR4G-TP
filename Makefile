CXX = g++
CXXFLAGS = -Wall

main.exe : FragTrap.o main.o
	$(CXX) $(CXXFLAGS) -o $@ FragTrap.o main.o
	 
main.o : main.cpp FragTrap.hpp
	$(CXX) $(CXXFLAGS) -c $<

FragTrap.o : FragTrap.cpp FragTrap.hpp 
	$(CXX) $(CXXFLAGS) -c $<
clean : 
	rm -f *.o *.exe