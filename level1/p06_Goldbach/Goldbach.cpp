//copy һ���ϵ��������ɸ���������� 
#include<stdio.h>
#include<cstring>
const int maxn = 100 + 5;
bool not_prime[maxn];		//���µ�˫�ط� 
int prime[maxn/2], top = 0;	//��ʵ�������ŷ���������壬��ͷ 
int main(){
	memset(not_prime, 0, sizeof(not_prime));
	for(int i = 2;i <= maxn - 5; i++){
		if(!not_prime[i]){		//������ 
//			printf("%d\n", i);
			prime[++top] = i;
		}
		
		for(int j = 1; j <= top && i*prime[j] <= maxn-5; j++){
			not_prime[i*prime[j]] = true;
			if(i % prime[j] == 0)	//���������Ļ�
				break; 
		}
		
	}
//	��ʼģ��� 
	for(int i = 6; i <= 100; i++){			//��5��ʼ 
		int yes = false;
		for(int j = 1; j <= top; j++)
			for(int k = j; k <= top; k++)
				for(int l = k; l <= top; l++)
					if(prime[j]+prime[k]+prime[l] == i){
						yes = true;
						printf("%d=%d+%d+%d\n", i, prime[j], prime[k], prime[l]);
					}
		if(!yes)	printf("���ҵ��˲����ϸ�°ͺղ����������ͷ\n");
	}
	 
} 
