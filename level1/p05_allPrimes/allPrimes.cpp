//�����Ҫ�õ�����д������ɸ�� 
#include<stdio.h>
#include<cstring>

const int maxn = 1000 + 5;
bool not_prime[maxn];		//���µ�˫�ط� 
int prime[maxn/2], top = 0;	//��ʵ�������ŷ���������壬��ͷ 
int main(){
	memset(not_prime, 0, sizeof(not_prime));
	for(int i = 2;i <= maxn - 5; i++){
		if(!not_prime[i]){		//������ 
			printf("%d\n", i);
			prime[++top] = i;
		}
		
		for(int j = 1; j <= top && i*prime[j] <= maxn-5; j++){
			not_prime[i*prime[j]] = true;
			if(i % prime[j] == 0)	//���������Ļ�
				break; 
		}
		
	}
	printf("����ɸ�����ӶȽӽ�O(n)\n");
	return 0;
} 
