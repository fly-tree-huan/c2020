#include <stdio.h>
#include <string.h>
void encryption(char a[10000]);
void decode(char a[100]);
int main()
{ 
  char a[100];
  gets(a);
  printf("����ǰ %s\n",a); 
  encryption(a);
  printf("���ܺ� %s\n",a);
  decode(a);
  printf("���ܺ� %s\n",a);
} 

void encryption(char a[10000])
{	
	int i;
	for(i=0;a[i];i++)
	 a[i]=a[i]+2;
}

void decode(char a[100]) 
{	
	int i;
	for(i=0;a[i];i++)
	 a[i]=a[i]-2;
	
}
