#include<stdio.h>
#include<stdlib.h>
#define MAX 20

typedef struct goods {
	int size;
	int amount;
	char name[MAX];
}Goods;

int read(Goods *goods){
	FILE* fp = fopen("data.txt", "r");
	int num;
	fscanf(fp, "%d",&num);
	for (int i = 0; i < num; i++)
	{
		fscanf(fp, "%d %d %20s", &goods[i].size, &goods[i].amount, goods[i].name);
	}
	fclose(fp);
	return num;
};

void view(Goods* goods,int *num) {
	printf
	(
		"��ӭʹ�ÿ��ϵͳ\n"
		"1.��ʾ����б�\n"
		"2.���\n"
		"3.����\n"
		"4.�˳�����\n"
	);
};

void viewStore(Goods* goods, int num) {
	printf("����%d������\n", num);
	int exit = 0;
	for (int i = 0; i < num; i++)
	{
		printf(
			"��%d�����\n", i + 1);
		printf(
			"           ���֣�%s\n", goods[i].name);
		printf(
			"           ������%d\n", goods[i].amount);
		printf(
			"           �ͺţ�%d\n", goods[i].size);

	};
	while (1) {
		printf("����1�������˵�\n");
		scanf("%d", &exit);
		if (exit == 1) {
			break;
		}
	}
	system("CLS");
};

void enter(Goods* goods, int *num) {
	printf("������Ҫ������Ļ������֣�");
	scanf("%s",goods[*num].name);
	printf("�ͺţ�1����ţ�2���кţ�3��С��\n������Ҫ������Ļ����ͺţ�");
	scanf("%d", &goods[*num].size);
	printf("������Ҫ������Ļ���������");
	scanf("%d", &goods[*num].amount);
	*num=*num+1;
	system("CLS");
};

void out(Goods* goods, int* num) {
	int outnum;
	while (1) {
		printf("��ѡ��Ҫ�ڼ��������˳����Ļ��");
		scanf("%d", &outnum);
		if ((outnum -1)< (*num))
		{
			break;
		}
		else {
			printf("ѡ��Ļ��ﲻ�ڿ����\n");
		}
		
	}
	for (int n = outnum; n < (*num); n++)
	{
		for (int i = 0; i < MAX; i++)
		{
			goods[n - 1].name[i] = goods[n].name[i];
		};

		goods[n - 1].amount = goods[n].amount;
		goods[n - 1].size = goods[n].size;
	}
	*num = (*num - 1);
	system("CLS");
};


void write(Goods* goods,int num) {
	FILE* fp = fopen("data.txt", "w");
	fprintf(fp, "%d\n", num);
	for (int i = 0; i < num; i++)
	{
		fprintf(fp, "%d %d %-20s\n", goods[i].size, goods[i].amount, goods[i].name);
	}
	fclose(fp);
};


int main() {
	Goods goods[MAX];//��ʼ���ṹ
	Goods* pgoods = goods;
	int num;
	num=read(pgoods);
	while (1) {
		int chose= 0;
		int exit = 0;
		view(pgoods, &num);
		scanf("%d", &chose);
		switch (chose)
		{
		case 1:viewStore(pgoods, num); break;
		case 2:enter(pgoods, &num); break;
		case 3:out(pgoods, &num); break;
		case 4:exit = 1; break;
		default:break;
		}
		if (exit == 1)
		{
			write(pgoods, num);
			break;
		}
		system("CLS");
	};
	return 0;
}



