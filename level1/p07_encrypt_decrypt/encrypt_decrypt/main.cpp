#include <stdio.h>
#include "encrypt_decrypt.h"

int main(int argc, char* argv[])
{
	int choice = -1;
	// ѭ�� + �˵�
	while (choice)
	{
		printf("����˵���\n");
		printf("1������\n");
		printf("2������\n");
		printf("���������뽫�˳�����\n");
		printf("����������ѡ��");
		if (scanf_s("%d", &choice) == 1)
		{
			//�����������
			while (getchar() != '\n')
				continue;

			switch (choice)
			{
				case 1:   // ����
					encrypt();
					break;
				case 2:   // ����
					decrypt();
					break;
				default:  // �˳�����
					choice = 0;
					break;
			}
		}
		else
			choice = 0;  // �����˳�����
	}
	printf("��л����ʹ�ã��ټ���\n");
	printf("������س��˳�����\n");
	while (getchar() != '\n')
		continue;
	return 0;
}