#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#define _USE_MATH_DEFINES 

void gainer2(int m,float quality, float Cr, float Lr, float Lm, FILE *fp, int uIn,int uOut, int Pwr,float deltauIn)
{
    double gain=uOut/uIn;
    float gMin= (float) uIn/(uIn+deltauIn), gMax=(float) uIn/(uIn-deltauIn);

    float frqW0=1/sqrt(Lr*Cr);
   // frqW
}