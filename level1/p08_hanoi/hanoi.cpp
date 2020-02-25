#include<stdio.h>
#include<stdlib.h>
void move(int x, char from, char to)
{printf("%d from %c  --> to %c\n", x, from, to);return;}

void hanoi(int n, char from, char middle, char to)
{
	if(n == 1) 
	{
		move(1, from, to);
		return;
	}
	hanoi(n - 1, from, to, middle);
	move(n, from, to);
	hanoi(n - 1, middle, from, to); 
	
}
int main(void)
{
	int n = 64;
	hanoi(n,'A','B','C');
 } 
