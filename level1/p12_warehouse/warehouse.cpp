// ����ʵ�֣��ļ����棬��ȡ���޸� 
// .house �ļ���ʽ�� # -- �µ�һ��������! -- ���� 


#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string> 
#include "warelist.h"
using namespace std;

const int EXIT = 0, INPORT = 1, EXPORT = 2, SHOWLIST = 3, DEL = 4, CMDBEGIN = '0', CMDEND = '4', maxn = 1000;
FILE * getFile(bool recover);
void saveList(wareList warelist, FILE *f);


int showCommandList(){
	/*
		Clean and show the List, get input, return command
	*/
	
	system("CLS");
	printf("0 -- EXIT\n1 -- INPORT\n2 -- EXPORT\n3 -- SHOWLIST\n4 -- DELETE LIST\n");
	char g;
	while(g = getch()){
		if(g >= CMDBEGIN && g <= CMDEND) break;
	}
	
	return g-'0';
	
}


void inport(){
	 
	char name[maxs], type[maxs];
	int num;
	float price;
	
	printf("��������Ʒ��\n");
	scanf("%s", name);
	printf("�������ͺ�\n");
	scanf("%s", type);
	printf("��������������\n");
	scanf("%d", &num);
	printf("������۸�\n");
	scanf("%f", &price);
	
	wareList* warelist = makeList(getFile(false));
	if(warelist != NULL)
		warelist->addWare(name, type, num, price);
	else 
		warelist = new wareList(name, type,num, price);
 	saveList(*warelist, getFile(true)); 	
 	
 	delete(warelist);
}


void saveList(wareList warelist, FILE* f){
	ware* now = warelist.father;
	 
	while(warelist.len){
		fprintf(f, "#%s %s %f %d\n", now->name.c_str(), now->type.c_str(), now->price, now->num);
		if(now->isEnd())	break;
		now = now->next;
	}
	fprintf(f, "!");
	fclose(f);
}


void printList(wareList* warelist){
	system("CLS");
	printf("����			����			�۸�			����\n");
	
	if(warelist == NULL){
		printf("�������ޣ���һ�㶫���ɣ����������ʵҲ������Ӹ���ֵร�\n"); 
		return;
	}
		
	ware* now = warelist->father;
	int len  = warelist->len;
	while(len--){
		printf("%s			%s			%.1f��			%d\n",
			   now->name.c_str(), now->type.c_str(), now->price, now->num);
		now = now->next;
	}
}


void outport(){
	
	char name[maxs], type[maxs];
	int num;
	float price;
	
	printf("��������Ʒ��\n");
	scanf("%s", name);
	printf("�������ͺ�\n");
	scanf("%s", type);
	printf("�������������\n");
	scanf("%d", &num);
	printf("������۸�Ϊ�˷�ֹ��ͬ�۸��ͬ�����QAQ��\n");
	scanf("%f", &price);
	
	wareList* warelist = makeList(getFile(false));
	if(warelist != NULL)
		warelist->addWare(name, type, -num, price);
	else
		warelist = new wareList(name, type, -num, price);	
 	saveList(*warelist, getFile(true));
	delete(warelist);  	
}


void deleteList(){
	
	int res = remove("warehouse.house");
	printf("��ɾ������������������˵�\n");
	getch();
}


void showWareList(){
	printList(makeList(getFile(false)));
	
	printf("��������ص����˵�...");
	getch();
}


void listLoop(){
	
	int command = showCommandList();
	switch(command){
		case 0: return;
		case 1: inport(); break;
		case 2: outport(); break;
		case 3: showWareList(); break;
		case 4: deleteList();break;
		default: break;
	}
	listLoop();	
	
}


FILE* getFile(bool recover){
	/*
		WARNING: ���������û�� flose()!!!!!! 
	*/ 
	FILE* wareHouse = fopen("wareHouse.house", "r");
	if(wareHouse == NULL){
		wareHouse = fopen("wareHouse.house", "w+");
		printf("���½��ļ��������������...");
		getch();
	}
	else if(recover){
		fclose(wareHouse);
		wareHouse = fopen("wareHouse.house","w+");
	}
	return wareHouse;	
	
}


int main(){
	
	listLoop();
	printf("���˳�\n");
	getch();
	return 0;
	
} 
