#include <stdio.h> 
#include <math.h>
//�жϳ���407 
int main(){
	int x=100;
	double a,b,c;
	for(x=100;x<1000;x++){
		a=x/100;//ȡ����λ�� 
		b=x/10%10;//ʮλ�� 
		c=x%10;//��λ�� 
		if(x==pow(a,3)+pow(b,3)+pow(c,3)){
			printf("%d ",x);
		}
	}
	return 0;
}
