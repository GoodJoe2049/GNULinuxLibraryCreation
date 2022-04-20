#include <stdlib.h>
#include <math.h>
void sphere( float radius, float *surface, float *volume){
	(*surface) = 4.0 * M_PI * pow( radius, 2.0);
	(*volume) = (4.0/3.0) * M_PI * pow( radius, 3.0);
}
