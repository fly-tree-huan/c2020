#include<stdio.h>
//#define triple(i) i*i*i			//������Ϊ��define i%10*i%10�����߼����� 

long long triple(int i){
	return i * i * i;
} 
int main(){
	for(int i = 100; i <= 999; i++){
		if(triple(i/100) + triple(i%100/10) + triple(i%10) == i){
			printf("%d\n", i);
		}
	}
	return 0;
} 
