parkingLot: *.o
	g++ -std=c++11 *.o -I -O2 -framework GLUT -framework OpenGL -o parkinglot
*.o: *.cpp
	g++ -std=c++11 *.cpp -I -O2 -Wall -framework GLUT -c
