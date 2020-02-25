#include <stdio.h>
#include <stdlib.h>

#define L1 1
#define L2 2
#define L3 3
#define L4 4

void printgame(const int*, const int*,const int*, int, int, const char*);
int onemove(int*, int*, int*, char*);
int input_move(char*);


int main()
{
	int A[5] = { 0,L4,L3,L2,L1 };
	int B[5] = { 0 };
	int C[5] = { 0 };
	char move[2] = { 'A','A' };
	int count = 0;
	int why = 0;
	while (B[4] != L1 && C[4] != L1)
	{
		printgame(A, B, C, count, why, move);
		why = input_move(move);
		if(why != 1 && why != 2)
			why = onemove(A, B, C, move);
		if (why == 5 || why == 2)
			count++;
		system("cls");

	}
	why = 0;
	printgame(A, B, C, count, why, move);
	printf("��ϲ������ɺ�ŵ����Ϸ��\n");
	printf("���ܹ��ƶ���%d�Σ�\n", count);
	printf("����ʾ��Ϣ: ����ո��������");
	while (getchar() != '\n')
		continue;
	return 0;
}

void printgame(const int* A, const int* B, const int* C, int count, int why, const char* move)
{	 
	// ��ӡ��Ϸ��ͷ
	printf("    ��ŵ����Ϸ\n\n");

	// ��ӡA�Ķ�
	for (int j = 4; j > 0; j--)
		printf("  ");//�����ո�
	printf("||\n");
	for (int i = 4; i >= 1; i--) {
		for (int j = 5 - A[i]; j > 0; j--)
			printf("  ");//�����ո�
		if (A[i] == 0) {
			printf("\b\b||");
		}
		else {
			for (int j = A[i] * 2 - 1; j > 0; j--)
				printf("��");
		}
		printf("\n");
	}
	for (int j = 0; j < 9; j++)
		printf("==");
	printf("\n");
	for (int j = 0; j < 4; j++)
		printf("  ");
	printf("A:");
	printf("\n\n");

	// ��ӡB�Ķ�
	for (int j = 4; j > 0; j--)
		printf("  ");//�����ո�
	printf("||\n");
	for (int i = 4; i >= 1; i--) {
		for (int j = 5 - B[i]; j > 0; j--)
			printf("  ");//�����ո�
		if (B[i] == 0) {
			printf("\b\b||");
		}
		else {
			for (int j = B[i] * 2 - 1; j > 0; j--)
				printf("��");
		}
		printf("\n");
	}
	for (int j = 0; j < 9; j++)
		printf("==");
	printf("\n");
	for (int j = 0; j < 4; j++)
		printf("  ");
	printf("B:");
	printf("\n\n");

	// ��ӡC�Ķ�
	for (int j = 4; j > 0; j--)
		printf("  ");//�����ո�
	printf("||\n");
	for (int i = 4; i >= 1; i--) {
		for (int j = 5 - C[i]; j > 0; j--)
			printf("  ");//�����ո�
		if (C[i] == 0) {
			printf("\b\b||");
		}
		else {
			for (int j = C[i] * 2 - 1; j > 0; j--)
				printf("��");
		}
		printf("\n");
	}
	for (int j = 0; j < 9; j++)
		printf("==");
	printf("\n");
	for (int j = 0; j < 4; j++)
		printf("  ");
	printf("C:");
	printf("\n\n");

	// ��ӡ��ʾ��Ϣ
	printf(" ���Ѿ��ƶ���%02d��\t", count);
	printf("\n");
	switch (why)
	{
	case 1:
		printf("����ʾ��Ϣ: �����ϴ����벻��\"A\"��\"B\"��\"C\" \n");
		break;
	case 2:
		printf("����ʾ��Ϣ: ��%c�Ŀ��ƶ���%c��������\n", move[0], move[1]);
		break;
	case 3:
		printf("����ʾ��Ϣ: %c��û�п飬�����ƶ�\n", move[0]);
		break;
	case 4:
		printf("����ʾ��Ϣ: ��鲻������С������\n");
		break;
	case 5:
		printf("����ʾ��Ϣ: ���Ѿ���%c������Ŀ��Ƶ���%c��\n", move[0], move[1]);
		break;
	default://why = 0
		break;// ��ʼ��Ϸ�������Ϸ
	}

}
int onemove(int* A, int* B, int* C, char* move)
{
	int* p1, * p2;

	//p1
	if (move[0] == 'A')
		p1 = A;
	else if (move[0] == 'B')
		p1 = B;
	else
		p1 = C;
	//p2
	if (move[1] == 'A')
		p2 = A;
	else if (move[1] == 'B')
		p2 = B;
	else
		p2 = C;
	

	int i1 = 4;// ��ָֹ��Խ��
	while (p1[i1] == 0 && i1 > 0)
		i1--;
	if (i1 == 0) {
		return 3; // 3.��move[0](��һ������)��û�п飬�����ƶ�
	}
	int i2 = 4;// ��ָֹ��Խ��
	while (p2[i2] == 0 && i2 > 1)
		i2--;
	if (p1[i1] > p2[i2] && p2[i2] != 0) {
		return 4; // 4.����鲻������С������
	}
	else {
		if (p2[i2] != 0)
			i2++;
		p2[i2] = p1[i1];
		p1[i1] = 0;
		return 5; // 5.�����Ѿ���move[0]��������Ŀ��Ƶ���move[1]��
	}
}

int input_move(char* move)
{
	printf("���������Ĳ���(�磺����AB -> ��A������Ŀ�����B) �����д���룩\n");
	move[0] = getchar();
	move[1] = getchar();
	while (getchar() != '\n')
		continue;
	if (move[0] < 'A' || move[0] > 'C' || move[1] < 'A' || move[1] > 'C') {
		return 1; // 1.������ȷ����
	}
	else if (move[0] == move[1]) {
		return 2; // 2.����������ƶ�
	}
}