#include <stdio.h>

/* 
   �˴���ֻ���ṩ��ͷ��ʼ�Ľⷨ��
   ���ܲ�����Ϸ 
 */
void move_step(int, char, char, char, int*);
void move_one(int*, char, char);

int main()
{
    int count = 0;
    int lump = 0;
    printf("�����������\n");
    scanf_s("%d", &lump);
    move_step(lump, 'A', 'B', 'C', &count);
    return 0;
}

void move_step(int lump,char a,char b,char c,int* count)
{
    if (lump == 1)
        move_one(count, a, c);
    else {
        move_step(lump - 1, a, c, b, count);
        move_one(count, a, c);
        move_step(lump - 1, b, a, c, count);
    }
}
void move_one(int* count, char a, char b)
{
    (*count)++;
    printf("step%d��%c->%c\n", *count, a, b);
}