#include<stdio.h>
#include<string.h> 
void  encrypt (char *a);
void  decrypt (char *b);
int main()
{
	int t;
	char a[1000000];
	scanf("%s",a);
	printf("���Ƿ���Ҫ���ܣ���������1��ʾ�룬0��ʾ���룩");
	scanf("%d",&t);
	if(t==1){
	encrypt(a);	
	}
	printf("���Ƿ���Ҫ���ܣ���������1��ʾ�룬0��ʾ���룩");
	scanf("%d",&t);
		if(t==1){
	decrypt(a);
	}    

      return 0;
}

void encrypt (char *a)
{
	int num;
	for (num=0; num<strlen(a);num++){
			if(a[num]==126){
		a[num]=20;
		printf("%c",a[num]);
	}else{
			a[num]=a[num]+1;
			printf("%c",a[num]);
	}

	}
	printf("\n");
	
}

	
void decrypt (char *b)
{
	int num;
	for (num=0; num<strlen(b);num++){

	if(b[num]==20){
		b[num]=126;
		printf("%c",b[num]);
	}else{
			b[num]=b[num]-1;
			printf("%c",b[num]);
	}
	
		
	}
	printf("\n");
} 



