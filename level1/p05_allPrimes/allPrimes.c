#include<stdio.h>
#include<time.h>
int main()
{
	int num,n,t;
	int a;
	double time;
	clock_t start,finish;
	start=clock();
	printf("2 ");
	for(num=2;num<=100;num++){
			t=num;
	for(n=2;n<=t;n++){
		if(num%n==0){
			break;
		}
		else{
			t=num/n;
			
		}
		
		
	}
	if(n>t){
		printf("%d ",num);
	} 
	}
	printf("��2~1000���ڵ���������\n");
	finish=clock();
	 time=finish-start;
	 printf("�ܵļ���ʱ����%fms",time);
	
	return 0;
}
