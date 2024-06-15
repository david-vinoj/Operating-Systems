#include<stdlib.h>
#include<stdio.h>
#include<sys/stat.h>

void main()
{
	struct stat sfile;
	stat("pg1.c",&sfile);
	printf("st_size=%ld\n",sfile.st_size);	
}
