//### ����Ҫ��
//
//1. ��ӡ2 - 1000���ڵ���������
//2. ��ӡ���ܵļ���ʱ��
//3. �������Ż��㷨��Ч��

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 1000
int main(int argc, char* argv[])
{
	clock_t start = clock();  //��ʼʱ��(clock_t)
	clock_t end;              //����ʱ��(clock_t)
	double t;                 //�������õ�ʱ��(s)
	bool* isPrime = (bool*)malloc(sizeof(bool) * (SIZE + 1));
	if (isPrime == NULL)
		exit(-1);
	else{
		/* ��ȫ����ʼ��Ϊtrue����2��ʼ��*/
		for (int i = 2; i < SIZE + 1; i++)
			isPrime[i] = true;
		/* �������� */
		for (int i = 2; i < SIZE + 1; i++) {
			if (isPrime[i] == true)
				for (int j = i + i; j < SIZE + 1; j += i)
					isPrime[j] = false;
		}
		/* ������������ʱ�� */
		end = clock();
		t = (0.0 + end - start) / CLOCKS_PER_SEC;
		printf("������ʱ��%lf(s)\n", t);

		/* ��ӡ���� */
		for (int i = 2; i < SIZE + 1; i++) {
			if (isPrime[i] == true)
				printf("%d ", i);//���ÿ�������涼�ǻ��У����ķѴ���ʱ��
		}

	}		
	free(isPrime);
	/* ������ʱ�� */
	end = clock();
	t = (0.0 + end - start) / CLOCKS_PER_SEC;
	printf("\n����ʱ��%lf(s)", t);
	return 0;
}