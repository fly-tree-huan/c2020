#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct goods_type
{
    char name[20];
    char xh[20];
    int num;
};
struct goods_type goods[100];
int goods_num=0;

void load_txt()
{
    FILE * fp;
    int i=0, flag;
    if((fp=fopen("cangku.txt","r"))==NULL)
    {
        printf("���ܴ��ļ����ļ���ȡʧ�ܣ�\n");
        return;
    }
    while(1)
    {
        flag=fscanf(fp, "%s %s %d",goods[i].name,
                    goods[i].xh, &goods[i].num);
        if(flag == EOF)
            break;
        i++;
    }
    goods_num = i;
    fclose(fp);
}

void save_txt()
{
    FILE * fp;
    int i;
    if((fp=fopen("cangku.txt","w"))==NULL)
    {
        printf("���ܴ��ļ����ļ�����ʧ�ܣ�\n");
        return;
    }
    for(i=0; i<goods_num; i++)
        fprintf(fp, "%s %s %d\n",goods[i].name, goods[i].xh,
                goods[i].num);
    fclose(fp);
}

void add()  //���
{
    int k=-1,n;
    char str1[20],str2[20];
    printf("���������������ƣ�");
    scanf("%s",str1);
    printf("�������������ͺţ�");
    scanf("%s",str2);
    printf("������������������");
    scanf("%d",&n);
    for(int i=0; i<goods_num; i++)
    {
        if((strcmp(str1,goods[i].name) == 0)&&(strcmp(str2,goods[i].xh)==0)) //�Ƚϻ�������ƺ��ͺ��Ƿ������Ķ�һ���������һ������ԭ�л�������������n
        {
            goods[i].num=goods[i].num+n;
            k = i;
        }
    }
    if(k==-1) //��������ƺ��ͺź�����Ķ���һ�����½�һ���µĻ������Ϊn
    {
        strcpy(goods[goods_num].name,str1);
        strcpy(goods[goods_num].xh,str2);
        goods[goods_num].num=n;
        goods_num++;
    }
    printf("���ɹ���\n");
}

void del() //���� ԭ����������
{
    int k=-1,n;
    char str1[20],str2[20];
    printf("���������������ƣ�");
    scanf("%s",str1);
    printf("�������������ͺţ�");
    scanf("%s",str2);
    printf("������������������");
    scanf("%d",&n);
    for(int i=0; i<goods_num; i++)
    {
        if((strcmp(str1,goods[i].name) == 0)&&(strcmp(str2,goods[i].xh)==0)) //�ҵ��������
        {
            goods[i].num=goods[i].num-n;
            if(goods[i].num==0) //�����������Ϊ0����ɾ���û���
            {
                goods_num--; //�ܻ�������1
                for(int j=i; j<goods_num; j++)
                    goods[j] = goods[j+1];  //��λ�ڸû��������л�����ǰ��һλ
            }
            printf("����ɹ���\n");
            k = i;
        }
    }
    if(k==-1)
    {
        printf("���ͺŻ��ﲻ���ڣ�����ʧ�ܣ�\n");
    }
}

void display()
{
    int i;
        if(goods_num>0)
        {
            printf("��������\t�ͺ�\t����\n");
            for(i=0; i<goods_num; i++)
                printf("%-16s%s\t%d\n",goods[i].name,goods[i].xh,goods[i].num);
        }
        else
            printf("������ϢΪ�գ�");
}

int main()
{
    while(1)
    {
        load_txt();
        int choice;
        printf("\n��ӭʹ����Ʒ���������ϵͳ\n");
        printf("----------------------\n");
        printf("1.��ʾ����б�\n");
        printf("2.���\n");
        printf("3.����\n");
        printf("0.�˳�����\n");
        printf("-----------------------\n");
        printf("��ѡ����ģ�飬��������0-3��");
        while(1)
        {
            scanf("%d",&choice);
            if(choice>=0&& choice<=3)
                break;
            else
                printf("�������ֲ���ȷ����������0-3��");
        }
        switch(choice)
        {
        case 1:
            display();
            break;
        case 2:
            add();
            break;
        case 3:
            del();
            break;
        case 0:
            exit(0);
        }
        save_txt();
    }

}
