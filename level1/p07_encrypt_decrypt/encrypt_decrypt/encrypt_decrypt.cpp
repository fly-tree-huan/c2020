#include <stdio.h>
#include <stdlib.h>
#include "encrypt_decrypt.h"


static void input(link**);
static void output(link* );
static void delall(link**);
/*###���ܷ�ʽ��
//  �����Сд��ĸ��ת��Ϊ��д������5λ���ֻ���
//	����Ǵ�д��ĸ��ת����Сд������4λ���ֻ���
//  ���������: {9,8,7,6,5,4,3,2,1,0}->{ 5,2,4,7,8,0,1,9,3,6 };----->(����){4,3,8,1,7,9,0,6,5,2}
//  ����� �ո� ��ת���� *
//  ����� * ��ת���� �ո�
//  �����ַ� ����
*/

void encrypt(void)
{
	// �����ڴ棬�����ַ���
	printf("����������Ҫ���ܵ����룺\n");
	link* head = NULL;
	input(&head);

	// ���ܹ���
	link* point = head;
	int num[10] = { '5','2','4','7','8','0','1','9','3','6' };
	printf("���ܺ�\n");
	while (point != NULL) {
		if (point->a >= 'a' && point->a <= 'z')
		{
			point->a -= 32;
			if (point->a >= 'V')
				point->a = point->a - 26 + 5;
			else
				point->a += 5;
		}
		else if (point->a >= 'A' && point->a <= 'Z')
		{
			point->a += 32;
			if (point->a <= 'd')
				point->a = point->a + 26 - 4;
			else
				point->a -= 4;
		}
		else if (point->a >= '0' && point->a <= '9')
		{
			int x = point->a - '0';
			point->a = num[9 - x];
		}
		else if (point->a == ' ')
			point->a = '*';
		else if (point->a == '*')
			point->a = ' ';

		point = point->next;
	}

	// ��ӡ����
	output(head);

	// ɾ��������ڴ�
	delall(&head);
}

void decrypt(void)
{
	// �����ڴ棬�����ַ���
	printf("����������Ҫ���ܵ����룺\n");
	link* head = NULL;
	input(&head);

	// ���ܹ���
	link* point = head;
	int dnum[10] = { '4','3','8','1','7','9','0','6','5','2' };
	printf("���ܺ�\n");
	while (point != NULL) {
		if (point->a >= 'a' && point->a <= 'z')
		{
			point->a -= 32;
			if (point->a >= 'W')
				point->a = point->a - 26 + 4;
			else
				point->a += 4;
		}
		else if (point->a >= 'A' && point->a <= 'Z')
		{
			point->a += 32;
			if (point->a <= 'e')
				point->a = point->a + 26 - 5;
			else
				point->a -= 5;
		}
		else if (point->a >= '0' && point->a <= '9')
		{
			point->a = dnum[point->a - '0'];
		}
		else if (point->a == ' ')
			point->a = '*';
		else if (point->a == '*')
			point->a = ' ';

		point = point->next;
	}

	// ��ӡ����
	output(head);

	// �ͷŷ�����ڴ�
	delall(&head);
}


/* �����ڴ棬����������� */
static void input(link** head)
{
	*head = (link*)malloc(sizeof(link));
	link* last = *head;
	if (last == NULL)
		exit(-1);
	else {
		last->next = NULL;
		while ((last->a = getchar()) != '\n') {
			last->next = (link*)malloc(sizeof(link));
			if (last->next != NULL) {
				last = last->next;
				last->next = NULL; 
			}
			else
				exit(-1);
		}
		last->a = '\0';
	}
}

/* �ͷ��ڴ� */
static void delall(link** head)
{
	link* point = *head;
	*head = NULL;
	link* point_son;
	while (point != NULL) {
		point_son = point->next;
		free(point);
		point = point_son;
	}
}

/* ��ӡ���� */
static void output(link* head)
{
	link* point = head;
	while (point != NULL)
	{
		printf("%c", point->a);
		point = point->next;
	}
	printf("\n");
}