#include <stdlib.h>
float sumFloats( float x[], int numFloats ){
	float sum = 0.0;
	int j;
	for(j = 0; j<numFloats; j++){
		sum += x[j];
	}
	return sum;
}
