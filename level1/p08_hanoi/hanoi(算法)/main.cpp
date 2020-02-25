#include <stdio.h>
#define NUM_LUMP 4

void swap(int*, int*);
void movelump(int*, int*, int*, int);
void find_swap(int*, int*, int*, int);
void printstep(int, int);

int main()
{
	//��ʼ��base
	int base_A[NUM_LUMP] = { 0 };
	for (int i = 0; i < NUM_LUMP; i++)
		base_A[i] = i + 1;
	int base_B[NUM_LUMP] = { 0 };
	int base_C[NUM_LUMP] = { 0 };

	//�����ƶ�
	movelump(base_A, base_B, base_C, NUM_LUMP);
	return 0;
}
void movelump(int* base_A, int* base_B, int* base_C, int n)
{
	if (n != 1) {
		movelump(base_A, base_B, base_C, n - 1);
	}
	find_swap(base_A, base_B, base_C, n);
	if (n != 1) {
		movelump(base_A, base_B, base_C, n - 1);
	}

}
//find_swap
//������˳�����
//��ֵ�����ļ�������ֵ
void find_swap(int* base_A, int* base_B, int* base_C, int n)
{
	//�ҳ�ʼֵλ��
	int* cur = base_A;
	int i;
	int num_cur = 0;
	for (i = 0; base_A[i] == 0; i++)
		continue;
	if (i < NUM_LUMP && base_A[i] == n) {
		cur = base_A;
		num_cur = 1;
		goto here;
	}
	for (i = 0; base_B[i] == 0; i++)
		continue;
	if (i < NUM_LUMP && base_B[i] == n) {
		cur = base_B;
		num_cur = 2;
		goto here;
	}
	for (i = 0; base_C[i] == 0; i++)
		continue;
	if (i < NUM_LUMP && base_C[i] == n) {
		cur = base_C;
		num_cur = 3;
		goto here;
	}
here:;
	// Ѱ��Ӧ�÷��õ�λ��
	// ���ҽ�����ֵ
	int num_find = num_cur + 1;
	if (num_find == 4) {
		num_find = 1;
	}
	for (int j = 0; j < 2; j++) {
		switch (num_find) {
			case 1: {
				int k = 0;
				for (k = 0; base_A[k] == 0 && k < NUM_LUMP; k++)
					continue;
				if (k == NUM_LUMP || base_A[k] > n) {
					swap(&base_A[k - 1], &cur[i]);
					printstep(num_cur, num_find);
					goto here1;//����ѭ��
				}
				else {
					num_find++;
					continue;//����ѭ��
				}
				break;//����switch
			}
			case 2: {
				int k = 0;
				for (k = 0; base_B[k] == 0 && k < NUM_LUMP; k++)
					continue;
				if (k == NUM_LUMP || base_B[k] > n) {
					swap(&base_B[k - 1], &cur[i]);
					printstep(num_cur, num_find);
					goto here1;//����ѭ��
				}
				else {
					num_find++;
					continue;//����ѭ��
				}
				break;//����switch
			}
			case 3: {
				int k = 0;
				for (k = 0; base_C[k] == 0 && k < NUM_LUMP; k++)
					continue;
				if (k == NUM_LUMP || base_C[k] > n) {
					swap(&base_C[k - 1], &cur[i]);
					printstep(num_cur, num_find);
					goto here1;//����ѭ��
				}
				else {
					num_find -= 2;
					continue;//����ѭ��
				}
				break;//����switch
			}
		}
	}
here1:;
}
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
void printstep(int num_cur, int num_find) 
{
	switch (num_cur) 
	{
	case 1: printf("A->"); break;
	case 2: printf("B->"); break;
	case 3: printf("C->"); break;
	}
	switch (num_find)
	{
	case 1: printf("A\n"); break;
	case 2: printf("B\n"); break;
	case 3: printf("C\n"); break;
	}
}