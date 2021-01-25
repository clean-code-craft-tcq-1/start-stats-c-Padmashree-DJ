#include "alerter.h"


void swap(float *xp, float *yp)
{
    float temp = *xp;
    *xp = *yp;
    *yp = temp;
}

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    s.average = 0;
    s.min = 0;
    s.max = 0;
    int next_index=0;
    int i,j,k;
	float sum=0.0;
	float lnumberset[setlength-1];

    for (k=0;k<setlength;++k)
    {
        sum += numberset[k];
    }

    s.average= sum/(float)setlength ;
	for (int loop_counter=0; loop_counter<setlength-1;loop_counter++)
	{
		lnumberset[loop_counter]=numberset[loop_counter];
	}
	
    for (i=0;i<setlength-1;i++)
    {
        next_index=i;
        for (j=i+1;j<setlength;j++)
        {
            if (lnumberset[j]<lnumberset[next_index])
            {
                next_index=j;
            }
        }

        swap(&lnumberset[next_index],&lnumberset[i]);
    }

    s.min=lnumberset[setlength-1];
    s.max=lnumberset[0];

    return s;
}


int emailAlertCallCount = 0;
int ledAlertCallCount = 0;


void check_and_alert(const float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats)
{
    if(computedStats.max>maxThreshold)
    {
      (alerters[0])();
      (alerters[1])();

    }
}
