#!/bin/bash
gcc -c -Wall sphere.c
gcc -c -Wall volCylinder.c
gcc -c -Wall sumFloats.c
gcc -c -Wall sin.c
ar -cru libExtendedAPI.a sphere.o volCylinder.o sumFloats.o sin.o
gcc -o main main.c -L. -lExtendedAPI -lm
