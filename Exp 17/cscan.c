#include<stdio.h>
#include<math.h>

int DiskScheduling_CSCAN(int rq[], int n, int head, int totalTrack)
{
    int trackMovement=0;
    int small=totalTrack;
    int difference = totalTrack;
    int nearest=0;
    for(int i=0; i<n; i++)
    {
        if(rq[i]<small)
            small = rq[i];
        if(abs(head-rq[i]) < difference)
        {
            difference = abs(head-rq[i]);
            nearest = rq[i];
        }
            
    }
    trackMovement = abs(totalTrack-head) + abs(totalTrack-0) + abs(nearest - 0);
    return trackMovement;
}

int main()
{
    printf("\nC-SCAN Disk Scheduling\n\n");
    int n, requestQueue[200], head, totalTrack;
    printf("Kindly enter the number of tracks present in request queue: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        printf("Kindly enter track number %d: ", i+1);
        scanf("%d", &requestQueue[i]);
    }
    printf("\nKindly enter the total number of tracks in the disk: ");
    scanf("%d", &totalTrack);
    printf("\nKindly enter the current position of R/W head: ");
    scanf("%d", &head);
    int trackMovement = DiskScheduling_CSCAN(requestQueue, n, head, totalTrack-1);
    printf("\nThe total number of track movement using C-SCAN is: %d\n", trackMovement);
}
