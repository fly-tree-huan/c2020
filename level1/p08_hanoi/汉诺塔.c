# include  <stdio.h>

void hanoi ( int n, char a,  char b,  char c );

int main ()
{  	
	int  n ;
	printf( "���������ԭʼ����:") ;
	scanf("%d",&n) ;
	printf( "�ƶ�����Ϊ:\n") ;
	hanoi ( n,  'A' ,  'B' , 'C' ) ;
   	return 0;
   }

void hanoi ( int n, char a,  char b,  char c ) {
	if  (1 == n){
			printf("%c-->%c\t",a,c);
	}else{
		hanoi ( n-1,  a,  c,  b ) ;                  
     	printf("%c-->%c\t",a , c) ;               
     	hanoi ( n-1,  b,  a,  c ) ;         
	}            
}
