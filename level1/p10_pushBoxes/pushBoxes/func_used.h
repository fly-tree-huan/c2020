#ifndef FUNC_USED
#define FUNC_USED

typedef struct __PER_BOX__ {
	int hang;
	int lie;
}Upthing;

#define LINE 5 // �Թ�����
#define ROW  5 // �Թ�����
#define BOX_DES  2 // ����Ŀ�ĵص�ֵ
#define WALL_NUM 1 // ǽ��ֵ
#define SPACE_NUM 0 // �յط���ֵ
#define UP 'w'    // ����
#define DOWN 's'  // ����
#define LEFT 'a'  // ����
#define RIGHT 'd' // ����
#define ONE_SECOND 1000  //Sleep������һ���ֵ

/* �����µ���Ϸ */
void new_game();

/* ������Ϸ�Ƿ���� */
/* ��Ϸ��������true */
bool isGameover(Upthing*, int, int[][ROW]);

/* �����ǰ�����Ʋ���ӡ��ǰ����*/
void print_game(const int[][ROW], Upthing*, int);

/* �����Ƿ�ɹ��ƶ� */
bool move_person_box(Upthing*, int, int[][ROW]);

/* �����Ƿ�����ƶ� */
/* ͨ������ID_box����ȡ��Ҫ�ƶ������ӵĺ��� */
bool move_or_not(char, Upthing*, int, const int[][ROW], int*);

/* ���ص�ǰλ���Ǽ������� */
/* 0��ʾû������ */
int isBOX(Upthing*, int, int, int);

#endif 

