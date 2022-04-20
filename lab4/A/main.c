#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <dlfcn.h>
#include "ExtendedAPI.h"

int main(){
	void *handle;
	char *err;
	void (*sphere_d)( float, float* , float* );
	float (*volCylinder_d)(float, float);
	float (*sumFloats_d)(float[], int );
	double (*mysin_d)(float);
	
	handle = dlopen("./libExtendedAPI.so", RTLD_LAZY);
	if(handle == (void*)0){
		fputs(dlerror(), stderr);
		exit(-1);
	}
	sphere_d = dlsym( handle, "sphere");
	err = dlerror();
	if(err != NULL){
		fputs(err, stderr);
		exit(-1);
	}
	volCylinder_d = dlsym( handle, "volCylinder");
	err = dlerror();
	if(err != NULL){
		fputs(err, stderr);
		exit(-1);
	}
	sumFloats_d = dlsym( handle, "sumFloats");
	err = dlerror();
	if(err != NULL){
		fputs(err, stderr);
		exit(-1);
	}
	mysin_d = dlsym( handle, "mysin");
	err = dlerror();
	if(err != NULL){
		fputs(err, stderr);
		exit(-1);
	}
	
	FILE *fout;
	char output[] = "results.dat";
	float radius, surface, volume, height, angle = 0.0;
	float arr[8];
	int knt;
	fout = fopen(output, "w");
	
	printf("Enter Radius: ");
	scanf("%f", &radius);
	(*sphere_d)(radius, &surface, &volume);
	printf("\nA) Sphere with radius %f has a surface area of %f and volume of %f", radius, surface, volume);
	fprintf(fout, "A) Sphere with radius %f has a surface area of %f and volume of %f", radius, surface, volume);
	
	printf("\nEnter Radius and Height: ");
	scanf("%f%f", &radius, &height);
	printf("\nB) Cylinder with radius of %f and height of %f has a volume of %f", radius, height, (*volCylinder_d)(radius, height) );
	fprintf(fout, "\nB) Cylinder with radius of %f and height of %f has a volume of %f", radius, height, (*volCylinder_d)(radius, height) );
	
	printf("\nEnter 8 floats for addition: ");
	printf("\nC) Unsorted:");
	fprintf(fout, "\nC) Unsorted:");
	for(knt = 0; knt < 8; knt++){
		scanf("%f", &arr[knt]);
		printf("\n%f", arr[knt]);
		fprintf(fout, "\n%f", arr[knt]);
	}
	printf("\n\nSorted: ");
	fprintf(fout, "\n\nSorted: ");
	float sum = 0.0;
	float small;
	int j,y, loc = 0;
	for(j = 0; j<8; j++){
		small = arr[j];
		loc = j;
		for(y = j+1; y<8; y++){
			if( arr[y] < small ){
				loc = y;
				small = arr[y];
			}
		}
		arr[loc] = arr[j];
		arr[j] = small;
		printf("\n%f", arr[j]);
		fprintf(fout, "\n%f", arr[j]);
	}
	printf("\nSum after sorting: %f", (*sumFloats_d)(arr, 8));
	fprintf(fout, "\nSum after sorting: %f", (*sumFloats_d)(arr, 8));
	
	printf("\n\nD) Enter first angle: ");
	fprintf(fout, "\nD)");
	scanf("%f", &angle);
	printf("\nsin of %f is %f", angle, (*mysin_d)(angle));
	fprintf(fout, "\nsin of %f is %f", angle, (*mysin_d)(angle));
	
	printf("\n\nEnter second angle: ");
	scanf("%f", &angle);
	printf("\nsin of %f is %f", angle, (*mysin_d)(angle));
	fprintf(fout, "\nsin of %f is %f", angle, (*mysin_d)(angle));
	
	printf("\n\nEnter third angle: ");
	scanf("%f", &angle);
	printf("\nsin of %f is %f", angle, (*mysin_d)(angle));
	fprintf(fout, "\nsin of %f is %f", angle, (*mysin_d)(angle));
	
	dlclose(handle);
	fclose(fout);
	return 0;
}
