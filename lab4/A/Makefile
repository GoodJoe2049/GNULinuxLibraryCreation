
main: libExtendedAPI.so main.o
	gcc main.c -L. -lExtendedAPI -o main -ldl

libExtendedAPI.so: sphere.o volCylinder.o sumFloats.o sin.o
	gcc -shared -o libExtendedAPI.so sphere.o volCylinder.o sumFloats.o sin.o -lm
sphere.o: sphere.c
	gcc -fPIC -c sphere.c
volCylinder.o: volCylinder.c
	gcc -fPIC -c volCylinder.c
sumFloats.o: sumFloats.c
	gcc -fPIC -c sumFloats.c
sin.o: sin.c
	gcc -fPIC -c sin.c
#Performed in terminal:
#$export LD_LIBRARY_PATH=./
