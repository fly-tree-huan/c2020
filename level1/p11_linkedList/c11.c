#include<stdio.h>
#include <malloc.h>

typedef struct MyStruct
{
	int value;
	struct MyStruct *next;
}LinkList;
LinkList* creat(int n) {
	LinkList* head, * node, * end;//����ͷ�ڵ㣬��ͨ�ڵ㣬β���ڵ㣻
	head = (LinkList*)malloc(sizeof(LinkList));//�����ַ
	end = head;         //���ǿ�������ͷβ�ڵ�һ��
	for (int i = 0; i < n; i++) {
		node = (LinkList*)malloc(sizeof(LinkList));
		printf("�������%d���ڵ����ֵ:",(i + 1));
		scanf("%d", &node->value);
		end->next = node;
		end = node;
	}
	end->next = NULL;//��������
	return head;
}
LinkList* reverse(LinkList* head) {
	LinkList* p1 = NULL;
	LinkList* p2 = NULL;
	LinkList* p3 = NULL;
	
	p1 = head->next;
	p2 = p1;
	while (p2 != NULL)
	{
		p1 = p1->next;
		p2->next = p3;
		p3 = p2;
		p2 = p1;
		
	};
	head->next = p3;//ͷָ��ָ�����һ��
	return head;
}
int find5(LinkList* head) {
	int j = 1;
	LinkList* p = head;
	p = p->next;
	while (p != NULL) {
		if (p->value == 5) {
			return j;
		}
		p = p->next;
		j++;
	}
	return EOF;
}
int findsecond5(LinkList* head) {
	int j = 1;
	LinkList* p = head;
	p = p->next;
	int first5 = 0;
	while (p != NULL) {
		
		if (p->value == 5&& first5 == 1) {
			return j;
		}
		if (p->value == 5) {
			first5 = 1;
		}
		p = p->next;
		j++;
	}
	return EOF;
}
void print(LinkList* head) {
	LinkList* p = head;
	int j = 1;
	p = p->next;  //����ӡͷ�ڵ���������е�ֵ 
	while (p != NULL) {
		printf("%d %d\n", j, p->value);
		p = p->next;
		j++;
	}
}
int main() {
	int n;
	LinkList* head = NULL;   //����ͷָ�� 
	printf("����������Ҫ�����Ľڵ������\n");
	scanf("%d", &n);
	head = creat(n);
	print(head);
	head = reverse(head);
	print(head);
	int site = find5(head);
	int site2 = findsecond5(head);
	if (site!=EOF)
	{
		printf("��һ��5�Ľڵ��ǣ�%d\n",site);
		if (site2 != EOF)
		{
			printf("�ڶ���5�Ľڵ��ǣ�%d\n", site2);
		}
		else
		{
			printf("û�еڶ���Ϊ5�Ľڵ�");
		}
	}
	else
	{
		printf("û��Ϊ5�Ľڵ�");
	}
}

