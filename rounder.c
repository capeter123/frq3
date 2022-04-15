#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float rounder(float number)
{
    int i=0;
    while (i<=12)
    {
        i++;
        if(number<1)
        {
            float powered=number*pow(10,i);
            if(powered<=10 && powered >=1)
            {   
                return round(powered*10)/pow(10,i+1);
            }
        }
        else
        {
            float powered2=number/pow(10,i);
            if(powered2<=10 && powered2 >=1)
            {   
                return round(powered2*100)*pow(10,i-2);
            } 
        }
    }
    
}