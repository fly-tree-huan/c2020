//### ����Ҫ��
//
//1. ��ӡ������3λˮ�ɻ���
//
//ˮ�ɻ�����nλ����ÿ����λ��n�η�֮�͵��ڸ�nλ������
//
//���磺153 = 1 ^ 3 + 5 ^ 3 + 3 ^ 3
#include <stdio.h>

int main(int argc, char* argv[])
{
	for (int i = 100; i < 1000; i++)
	{
		int bai = i / 100;
		int shi = i % 100 / 10;
		int ge = i % 10;
		if (bai * bai * bai + shi * shi * shi + ge * ge * ge == i)
			printf("%d\n", i);
	}
	return 0;
}