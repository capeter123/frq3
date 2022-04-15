#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#define _USE_MATH_DEFINES 
#ifndef ROUNDER_C
#include "rounder.c"
#endif

void gainer(char gainFile[20],char LmFile[20], int uIn, int uOut, float deltauIn)
{
    FILE *LM, *GN;
    LM=fopen(LmFile,"r+"); GN=fopen(gainFile,"w+");

    double gain=uOut/uIn;
    float gMin= (float) uIn/(uIn+deltauIn), gMax=(float) uIn/(uIn-deltauIn);
    float frqWx=0,frqW=0,frqW0=0,quality=0,Cr=0,Lr=0,Lm=0;
    int m=0;
    float newM=0;
    printf("%d\t%f\t%f\t%f\n",m,gain,gMax,gMin);
    double newWx=0;

    for(int i=-1;i<=1;i++)//potega
    {
        for(int j=1;j<=10;j++) //podstawa
        {
            frqWx=j*pow(10,i);
            while(fscanf(LM,"%d\t%e\t%e\t%e\t%e\n",&m,&quality,&Cr,&Lr,&Lm)!=EOF)
            {
                frqW0=1/sqrt(rounder(Lr)*(rounder(Cr)));
                frqW=frqW0*frqWx;
                newM=(rounder(Lr)+rounder(Lm))/rounder(Lr);
                newWx=(double) (rounder(frqW)/rounder(frqW0));
                gain=(pow(frqWx,2)*(m-1))/(sqrt(pow((m*pow(frqWx,2)-1),2) + pow((pow(frqWx,2)-1),2)*pow(m-1,2)*pow(quality,2)));
                if(gain > gMin && gain<gMax && frqWx<=10)
                {
                   fprintf(GN,"%f\t%d\t%f\t%e\t%e\t%e\n",frqWx,m,gain,rounder(Cr),rounder(Lm),rounder(Lr));
                    //fprintf(GN,"%f\t%d\t%f\t%e\t%e\t%e\n",newM,m,gain,rounder(Cr),rounder(Lr),rounder(Lm));
                    //fprintf(GN,"%f\t\t%f\t\t%f\n",newWx,frqWx,rounder(frqW0));
                }
                //fprintf(GN,"%f\t%d\t%f\t%f\n",gain,m,gMax,gMin);
            }
            fseek(LM,0L,SEEK_SET);
        }
    }
    fclose(LM);fclose(GN);
}
/*
skanujemu &m,&quality,&Cr,&Lr,&Lm
    CrFinder()
gejnujemy juz tutaj
jak gain<gmin*1.1 && gain>gmin 0.9

function CrFinder(Cr_matrix, Lm, Lr, m)
    skanujemy plik Cr
        jesli Cr= Cr 
            wrzucasz do pliku o nazwie "Cr_n_M"



*/