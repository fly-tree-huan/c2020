#include<stdio.h>
int main()
{
	int num,n,t;
	int a;
	printf("������һ��������");
	scanf("%d",&num);
	if(num<=0){
		printf("���벻Ϊ������������������");
	}
	t=num;
	for(n=2;n<=t;n++){
		if(num%n==0){
			printf("%d��������",num);
			break;
		}
		else{
			t=num/n;
			
		}
		
		
	}
	if(n>t){
		printf("%d������",num);
	}
	return 0;
	
}
