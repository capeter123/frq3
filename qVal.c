#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void qVal(char qFile[20])
{
    FILE *QL;
    QL=fopen(qFile,"w+");

    float quality=0;
    for(int i=-1;i<1;i++)
    {
        
        for(int j=1;j<=10;j++)
        {
            quality=j*pow(10,i);
            fprintf(QL,"%e\n",quality);
            //printf("%e\n",quality);
        }
            
        
    }
    fclose(QL);
}