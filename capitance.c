#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#include "capitance.h"

void capitance(char capFile[10],float smallestCap,float biggestCap)
{
    float cap=0;

    FILE *fc;
    fc=fopen(capFile, "w+");
    //float tab[6]={ 1,1.5,2.2,3.3,4.7,6.8};
    float tab[3]={1,4.7,6.8};
    for( int i =0; i<=5; i++)
    {
        for( int j=0; j<=12; j++)
        {
            cap=((tab[i])*pow(10,-j));
            //fprintf(fc,"%e \n", cap);
             if(cap>=smallestCap && cap<biggestCap) 
            {
                fprintf(fc,"%e \n", cap);
            }   
        }
    }
    fclose(fc);
}