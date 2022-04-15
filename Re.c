#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#define _USE_MATH_DEFINES 

float Re(int Pwr, int uIn, int uOut)
{   
    //Re=8/pi^2 * (n1/n2)^2 Rl; Rl opór obciazenia res load
    float inductLr=0, inductLm=0,capCr=0, frqW0=0,resRe=0;double resRl; double magnet=0; 
    int nRatio=0;
    if(uIn != 0 && uOut !=0)
    {
        nRatio=round(uOut/uIn);
    }
    else
    {
        nRatio=1;
    }
    double n1=1,n2=nRatio;
    
   // return resRe=(8/( pow(M_PI,2) )*(   pow( (uOut/uIn)-fmod(uOut/uIn,1),  -2)   )   *   pow(uIn,2)/Pwr)   ;
    //return resRe=(8/( pow(M_PI,2) )*(   pow(round(uOut/uIn),  -2)   )   *   pow(uIn,2)/Pwr)   ;
    //Rac=(8/pow(pi,2))*(pow(1/round(Vout/Vin),2)/Pwr)
    return resRe=(8/pow(M_PI,2))*(pow((n1/n2)*uOut,2));
}