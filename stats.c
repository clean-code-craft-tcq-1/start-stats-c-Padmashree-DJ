#include "stats.h"
#include "alerter.h"


struct Stats
{
     float average, min, max;
};


void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    s.average = 0;
    s.min = 0;
    s.max = 0;
    int next_index=0;
    int i,j,k,sum;

    for (i=0;i<setlength-1;i++)
    {
        next_index=i;
        for (j=i+1;j<setlength;j++)
        {
            if (numberset[j]<numberset[next_index])
            {
                next_index=j;
            }
        }

        swap(numberset[next_index],numberset[i]);
    }

    for (k=0;k<setlength-1;k++)
    {
        sum += numberset[k];
    }

    s.average=sum/setlength;
    s.min=numberset[setlength-1];
    s.max=numberset[0];

    return s;
}


int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

void check_and_alert(const float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats)
{
    if(computedStats.max==maxThreshold)
    {
      (alerters[0])();
      (alerters[1])();

    }
}
