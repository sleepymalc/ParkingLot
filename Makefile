parkinglot: **/*.cpp
	g++ -std=c++11 **/*.cpp -I -O2 -framework GLUT -framework OpenGL -o parkinglot
