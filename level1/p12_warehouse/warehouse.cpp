// ����ʵ�֣��ļ����棬��ȡ���޸� 
// .house �ļ���ʽ�� # -- �µ�һ��������! -- ���� 
// ��������QAQ�������ð�QAQ 
// ��������о����˰����Ľ���һ�£�����˫���Լ��Ǹ� end ָ����Ϊɶ��һ����û���뵽QAQ
// ��˯�˸������������ vector �ˡ����� ���Ƕ�д��һ���ˣ���Ϲ 
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include "warelist.h"
using namespace std;

const int EXIT = 0, INPORT = 1, EXPORT = 2, SHOWLIST = 3, maxs = 1024, maxn = 1000;
FILE * getFile(bool recover);
void saveList(wareList warelist, FILE *f);

//�´ε�������һ��һ����д�������Ĳ������ 


int showList(){
	/*
		Clean and show the List, get input, return command
	*/
	
	system("CLS");
	printf("0 -- EXIT\n1 -- INPORT\n2 -- EXPORT\n3 -- SHOWLIST\n");
	char g;
	while(g = getch()){
		if(g >= '0' && g <= '3') break;
	}
	
	return g-'0';
	
}


wareList makeList(FILE* wareHouse){
	
	wareList* list = NULL;
	char u = getchar();
	while(u != '!' && u != EOF){
		if(u == '#'){
			char name[maxs], type[maxs];
			int num, price;
			scanf("%s%s%d%d", name, type, &num, &price);
			
			if(list == NULL)
				list = new wareList(name, type, num, price);
			else list->addWare(name, type, num, price);
		}
		u = getchar();
	}
	fclose(wareHouse);
	delete(list);
} 


void inport(){
	 
	char name[maxs], type[maxs];
	int num, price;
	
	printf("��������Ʒ��\n");
	scanf("%s", name);
	printf("�������ͺ�\n");
	scanf("%s", type);
	printf("��������������\n");
	scanf("%d", &num);
	printf("������۸�\n");
	scanf("%d", &price);
	
	wareList warelist = makeList(getFile(false));
	warelist.addWare(name, type, num, price);
 	saveList(warelist, getFile(true)); 	
 	
}


void saveList(wareList warelist, FILE* f){
	ware* now = warelist.father;
	 
	while(warelist.len){
		printf("#%s %s %d %d\n", now->name, now->type, now->price, now->num);
		if(now->isEnd())	break;
		now = now->next;
	}
	printf("!");
	fclose(f);
}


void printList(wareList warelist){
	ware* now = warelist.father;
	int len  = warelist.len;
	while(len--){
		printf("%s	%s	%d	%d��\n", now->name, now->type, now->price, now->num)
	}
}


void outport(){
	
	char name[maxs], type[maxs];
	int num, price;
	
	printf("��������Ʒ��\n");
	scanf("%s", name);
	printf("�������ͺ�\n");
	scanf("%s", type);
	printf("�������������\n");
	scanf("%d", &num);
	pritf("������۸�Ϊ�˷�ֹ��ͬ�۸��ͬ�����QAQ��\n");
	scanf("%d", &price);
	
	wareList warelist = makeList(getFile(false));
	warelist.addWare(name, type, -num, price);
 	saveList(wareList, getFile(true));
	  	
}


void showWareList(){
	printList(makeList(getFile(false)));
}


void LISTLOOP(){
	
	int command = showCommandList();
	switch(command):
		case 0: return;
		case 1: inport(); break;
		case 2: outport(); break;
		case 3: showWareList(); break;
		default: break;
		
	LISTLOOP();	
	
}


FILE* getFile(bool recover){
	
	FILE* wareHouse = fopen("wareHouse.house", "r+");
	if(wareHouse == NULL){
		wareHouse = fopen("wareHouse.house", "w+");
		printf("���½��ļ��������������...")
		getch();
	}
	else if(recover){
		fclose(wareHouse);
		wareHouse = fopen("wareHouse.house","w+");
	}
	return wareHouse;	
	
}


int main(){
	
	Listloop();
	printf("���˳�\n");
	getch();
	return 0;
	
} 
