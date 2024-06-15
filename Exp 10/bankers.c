#include<stdio.h>
#include<string.h>
void main()
{
	int pno;
	int rno;
	int allo[20][20];
	int max[20][20];
	int need[20][20];
	int avail[20];
	int flag[20];
	int safe[20];
	int l=0;
	
	printf("Kindly enter the number of processes: ");
	scanf("%d",&pno);
	printf("Kindly enter the number of resources: ");
	scanf("%d",&rno);
	printf("Kindly enter the Allocation Matrix: \n");
	for(int i=0;i<pno;i++)
	{
		for(int j=0;j<rno;j++)
		{
			scanf("%d",&allo[i][j]);
		}
	}
	printf("Kindly enter the Max Matrix: \n");
	for(int i=0;i<pno;i++)
	{
		for(int j=0;j<rno;j++)
		{
			scanf("%d",&max[i][j]);
		}
	}
	printf("Kindly enter the Availability values: \n");
	for(int i=0;i<rno;i++)
	{
		scanf("%d",&avail[i]);
	}


	for(int i=0;i<pno;i++)
	{
		for(int j=0;j<rno;j++)
		{
			need[i][j]=max[i][j]-allo[i][j];
		}
	}
	printf("The Need Matrix is as follows: \n");
	for(int i=0;i<pno;i++)
	{
		for(int j=0;j<rno;j++)
		{
			printf("%d ",need[i][j]);
		}
		printf("\n");
	}
	 
	 for(int i=0;i<pno;i++)
	 {
	 	flag[i]=0;
	 }
	 
	 
	for(int k=0;k<pno;k++)
	{
		for(int i=0;i<pno;i++)
		{
			if(flag[i]==0)
			{
				int f=0;
				for(int j=0;j<rno;j++)
				{
					if(need[i][j]>avail[j])
					{
						f=1;
						break;
					}
				}
				
				if(f==0)
				{
					safe[l]=i;
					l++;
					for(int m=0;m<rno;m++)
					{
						avail[m]+=allo[i][m];
						flag[i]=1;		
					}	
				}
			}
		}
	}
	int f=1;
	for(int i=0;i<pno;i++)
	{
		if(flag[i]==0)
		{
			f=0;
			printf("\nThe system is not safe\n");
			break;
		}
	}
	if(f==1)
	{
		printf("\nThe given system is safe\n");
		printf("The sequence is: ");
		for(int i=0;i<pno;i++)
		{
			printf(" P%d ",safe[i]);
			if((i+1)<pno)
				printf("->");
		}
	}
	printf("\n");
}
