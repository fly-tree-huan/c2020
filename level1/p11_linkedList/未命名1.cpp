#include<stdio.h> 

typedef struct Node {
	int data;
	struct Node *Next;
};

void Init(Node **First)//��ʼ��
{
	assert(First != NULL);
	*First = NULL;
}
int main()
{
	
}
