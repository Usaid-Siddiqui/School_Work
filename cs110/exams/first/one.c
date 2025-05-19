#include <stdio.h>
#include <string.h>

int main() {
    int starthrs, startmin, endhrs, endmin, totalstartmin, totalendmin, elapsedmin, eventhrs, eventmin;
    char startm[3];
    char endm[3];

    //inputs
    printf("Enter the start time: ");
    scanf("%d %d %s", &starthrs, &startmin, startm);

    printf("Enter the end time: ");
    scanf("%d %d %s", &endhrs, &endmin, endm);

    //calculations
    if ((strcmp(startm, "am")==0) && (starthrs == 12)) starthrs -= 12;
    if ((strcmp(endm, "am")==0) && (endhrs == 12)) endhrs -= 12;

    if ((strcmp(startm, "pm")==0) && starthrs!=12) starthrs+=12;
    if ((strcmp(endm, "pm")==0) && endhrs!= 12) endhrs+=12;
    

    totalstartmin = starthrs*60 + startmin;
    totalendmin = endhrs*60 + endmin;

    elapsedmin = totalendmin - totalstartmin;
    eventhrs = elapsedmin/60;
    eventmin = elapsedmin%60;

    //output
    printf("The event lasts %d hour(s) and %d minute(s).\n", eventhrs, eventmin);
    return 0;
}