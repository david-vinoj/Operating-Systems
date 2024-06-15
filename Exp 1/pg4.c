#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

void main()
{
	execlp("./prog1","first",NULL);
}
