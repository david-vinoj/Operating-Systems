#include<stdio.h>
#include<math.h>

int DiskScheduling_SSTF(int rq[], int n, int head, int totalTrack)
{
    int trackMovement=0;
    int small=totalTrack, large=0;
    for(int i=0; i<n; i++)
    {
        if(rq[i]<small)
            small = rq[i];
        if(rq[i]>large)
            large = rq[i];
    }
    trackMovement = abs(head-small) + abs(large-small);
    return trackMovement;
}

int main()
{
    printf("\nSSTF Disk Scheduling\n\n");
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
    int trackMovement = DiskScheduling_SSTF(requestQueue, n, head, totalTrack-1);
    printf("\nThe total number of track movement using SSTF is: %d\n", trackMovement);
}

