#include<stdio.h>
#include<stdlib.h>
struct process{
	int pid,at,wt,tat,bt,ct;
};
void swap(int i,int j,struct process p[20]){
	struct process temp=p[i];
	p[i]=p[j];
	p[j]=temp;
}

void atSort(struct process p[20],int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(p[i].at>p[j].at){
				swap(i,j,p);
			}
		}
	}
}
void pidSort(struct process p[20],int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if((p[i].at==p[j].at)&&(p[i].pid>p[j].pid)){
				swap(i,j,p);
			}
		}
	}
}
void btSort(struct process p[20],int i,int n,int ict){
	for(int a=i+1;a<n;a++){
		for(int b=a;b<n;b++){
			if((p[0].at<=ict)&&(p[b].at<=ict)){
				if(p[a].bt>p[b].bt){
					swap(a,b,p);
				}
			}
		}
	}
}
void sjf(struct process p[20],int n){
	atSort(p,n);
	pidSort(p,n);
	int ict=p[0].at;
	for(int i=0;i<n;i++){
		if(ict<p[i].at)
			p[i].ct=p[i].at+p[i].bt;
		else
			p[i].ct=ict+p[i].bt;
		ict=p[i].ct;
		p[i].tat=p[i].ct-p[i].at;
		p[i].wt=p[i].tat-p[i].bt;
		btSort(p,i,n,ict);
	}
	
}
void main(){
	struct process p[20],temp;
	int n; 
	float avwt,avtat,twt=0,ttat=0;
	printf("\nEnter number of processes:");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("Enter the proces ID of process %d:",i+1);
		scanf("%d",&p[i].pid);
		printf("Enter AT:");
		scanf("%d",&p[i].at);
		printf("Enter BT:");
		scanf("%d",&p[i].bt);
		printf("\n");
	}
	sjf(p,n);
	
	
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(p[i].pid>p[j].pid)
			{
				temp=p[i];
				p[i]=p[j];
				p[j]=temp;
			}
		}
	}
	
	
	
	printf("SJF:\n");
	printf("Process id\t Arrival time\t\t  Burst time\t\tCompletion time\t\tTurn around time\tWaiting time\n");
	for(int i=0;i<n;i++){
		twt+=p[i].wt;
		ttat+=p[i].tat;
		printf("%d\t\t\t",p[i].pid);
		printf("%d\t\t\t",p[i].at);
		printf("%d\t\t\t",p[i].bt);
		printf("%d\t\t\t",p[i].ct);
		printf("%d\t\t\t",p[i].tat);
		printf("%d\t\t\t",p[i].wt);
		printf("\n");
	}
	avwt=twt/n;
	avtat=ttat/n;
	printf("\nAverage WT:%f",avwt);
	printf("\nAverage TAT:%f",avtat);
	printf("\n");
}



























































/*p[20],temp;
int n,arrt[20],ctime=0,rq[20];
void asort(){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(p[i].at>p[j].at){
				temp=p[i];
				p[i]=p[j];
				p[j]=temp;
			}
		}
	}
}
void basort(){
	for(int i=1;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(p[i].bt>p[j].bt){
				temp=p[i];
				p[i]=p[j];
				p[j]=temp;
			}
		}
	}
}
void redq(){
	int b=0;

	for(int i=0;i<ctime+1;i=i+arrt[b]){
		rq[b]=p[b].pid;
		b++;
		
	}
	for(int i=0;i<b;i++){
		printf("\nRQ:\n");
		printf("%d\n",rq[i]);	
	}
}
	
void fcfs(){
	float sum1=0,sum2=0;
	asort();
	p[0].ct=p[0].at+p[0].bt;
	ctime=p[0].at+p[0].bt;
	redq();
	for(int i=0;i<n;i++){
		p[i+1].ct=p[i].ct+p[i+1].bt;
		ctime=ctime+p[i].ct+p[i+1].bt;
		p[i].tat=p[i].ct-p[i].at;
		sum1=sum1+p[i].tat;
		p[i].wt=p[i].tat-p[i].bt;
		sum2=sum2+p[i].wt;
	}
	printf("FCFS:\n");
	printf("Process id\t Arrival time\t\t  Burst time\t\tCompletion time\t\tTurn around time\tWaiting time\n");
	for(int i=0;i<n;i++){
		printf("%d\t\t\t",p[i].pid);
		printf("%d\t\t\t",p[i].at);
		printf("%d\t\t\t",p[i].bt);
		printf("%d\t\t\t",p[i].ct);
		printf("%d\t\t\t",p[i].tat);
		printf("%d\t\t\t",p[i].wt);
		printf("\n");
	}
	printf("\nAverage turn around time: %f\n",(sum1/n));
	printf("\nAverage waiting time: %f\n",(sum2/n));
}
void main(){
	printf("Enter number of processes:");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("Enter process id:");
		scanf("%d",&p[i].pid);
		printf("Enter arrival time:");
		scanf("%d",&p[i].at);
		arrt[i]=p[i].at;
		printf("Enter burst time:");
		scanf("%d",&p[i].bt);
	}
	fcfs();
} 
*/

		
		
			
		
		
		
