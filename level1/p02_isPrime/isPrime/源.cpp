#include <stdio.h>
#include <math.h>

int main()
{
	double number = 0;
	int s = 0;
	printf("������һ�����֣�");
	int u = scanf_s("%lf", &number); //number�ǲ���һ������
	int a = (int)number;             //number�ǲ�������
	if (u == 1 && a == number && a > 0) {
		if (a == 1)
			printf("1��������\n");
		else {
			int i = 2;
			s = (int)sqrt((double)a);
			for (i = 2; i <= s && a % i != 0; i++);
			if (i > s)
				printf("%d������\n", a);
			else
				printf("%d��������\n", a);
		}

	}
	else
		printf("��������ȷ��ֵ��\n");
	return 0;
}
