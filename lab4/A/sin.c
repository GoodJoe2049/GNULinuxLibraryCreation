#include <stdlib.h>
#include <math.h>
double mysin( float angle ){
	angle = angle * M_PI / 180.0;
	double R = (double)angle;
	double Rprev = (double)angle;
	double diff = 1.0;
	int knt = 2;
	int fVal, x;
	int factorial;
	while( diff > 0.000001 ){
		fVal = 2*knt -1;
		factorial = 1;
		for(x=2;x <= fVal; x++){
			factorial *= x;
		}
		
		if(knt%2==0){
			R = R - pow(angle, (float)fVal) / factorial;
		}else{
			R = R + pow(angle, (float)fVal) / factorial;
		}
		knt++;
		diff = fabs(R - Rprev);
		Rprev = R;
	}
	return R;
}
