#include<stdio.h>
#include<stdlib.h>

struct process{
	int pid;
	int at;
	int wt;
	int tat;
	int bt;
	int ct;
	int st;
	int ft;
} p[20],tempo;

int n,i,j,temp,btime,min,k=1,ta=0,sum=1,wflag=0,tflag=0;

float tavg,wavg,tsum,wsum;

void asort()
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(p[i].at>p[j].at)
			{
				tempo=p[i];
				p[i]=p[j];
				p[j]=tempo;
			}
		}
	}
	
	if(p[0].at==0)
	{	wflag=1;
		tflag=1;
	}
}

void sjf()
{
	asort();

	for(j=0;j<n;j++)
	{
		btime=btime+p[j].bt;
		min=p[k].bt;

		for(i=k;i<n;i++)
		{
			if (btime>=p[i].at && p[i].bt<min)
			{

				tempo=p[k];
				p[k]=p[i];
				p[i]=tempo;
				
			}
		}
		k++;
	}

	p[0].wt=0;

	
		
	
	if(wflag==1)
	{
	
		for(i=1;i<n;i++)
		{
				
			sum=sum+p[i-1].bt;
			p[i].wt=sum-1-p[i].at;
			wsum=wsum+p[i].wt;
		}
	}
	else
	{
		for(i=1;i<n;i++)
		{
				
			sum=sum+p[i-1].bt;
			p[i].wt=sum-p[i].at;
			wsum=wsum+p[i].wt;
		}
	}
		
	wavg=(wsum/n);
	
	
	if(tflag==1)
	{
	
		for(i=0;i<n;i++)
		{
			ta=ta+p[i].bt;
			p[i].tat=ta-p[i].at;
			tsum=tsum+p[i].tat;
		}
	}
	else
	{
		for(i=0;i<n;i++)
		{
			ta=ta+p[i].bt;
			p[i].tat=ta+1-p[i].at;
			tsum=tsum+p[i].tat;
		}
	}
	tavg=(tsum/n);
	
	p[0].ct=p[0].at+p[0].bt;
	for(int i=0;i<n;i++)
	{
		p[i+1].ct=p[i].ct+p[i+1].bt;
	}
	
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(p[i].pid>p[j].pid)
			{
				tempo=p[i];
				p[i]=p[j];
				p[j]=tempo;
			}
		}
	}
	    
	printf("\nSJF: \n");
	printf("  ______________________________________________________________________________________________________________\n");
	printf(" | Process ID\t| Arrival Time\t| Burst Time\t| Completion Time\t| Turn Around Time\t| Wait Time     |\n");
	printf(" |______________|_______________|_______________|_______________________|_______________________|_______________|\n");
	for(int i=0;i<n;i++)
	{
		printf(" | %d\t\t|",p[i].pid);
		printf(" %d\t\t|",p[i].at);
		printf(" %d\t\t|",p[i].bt);
		printf(" %d\t\t\t|",p[i].ct);
		printf(" %d\t\t\t|",p[i].tat);
		printf(" %d\t\t|",p[i].wt);
		printf("\n");
	}
		printf(" |______________|_______________|_______________|_______________________|_______________________|_______________|\n");
	printf("\nAverage Turn Around Time: %f\n",tavg);
	printf("Average Waiting Time: %f\n",wavg);
}

void main()
{
	printf("Kindly enter the number of processes: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("Enter the process id: ");
		scanf("%d",&p[i].pid);
		printf("Enter the arrival time: ");
		scanf("%d",&p[i].at);
		printf("Enter the burst time: ");
		scanf("%d",&p[i].bt);
		printf("\n");
	}
	sjf();
}


