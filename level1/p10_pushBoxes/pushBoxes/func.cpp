#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "func_used.h"

void new_game(void)
{
	/* ���²�����Ҫ�ĵ���ȡ */
	int num_upboard = 3; // �˼����ӵĸ���
	int board[LINE][ROW] = {
	{1,1,1,1,1},
	{1,0,2,2,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,1,1,1,1},
	};
	Upthing* upboard = (Upthing*)malloc(sizeof(Upthing) * num_upboard);
	upboard[0].hang = 1;
	upboard[0].lie = 1;
	upboard[1].hang = 2;
	upboard[1].lie = 2;
	upboard[2].hang = 2;
	upboard[2].lie = 3;
	int count_step = 0; // ��¼����
	/* ------------------  */


	print_game(board, upboard, num_upboard);
	while (!isGameover(upboard, num_upboard, board)) 
	{
		if (move_person_box(upboard, num_upboard, board))
			count_step++;
		print_game(board, upboard, num_upboard);
	}
	printf("\n��ϲ������%d�������Ϸ\n", count_step);
	Sleep(ONE_SECOND);
}
bool isGameover(Upthing* upboard, int num_upboard, int board[][ROW])
{
	bool gameover = true;
	for (int i = 1; i < num_upboard; i++) {
		if (board[upboard[i].hang][upboard[i].lie] != BOX_DES) {
			gameover = false;
			break;
		}
	}
	return gameover;
}

void print_game(const int board[][ROW], Upthing* upboard, int num_upboard)
{
	system("cls");
	for (int i = 0; i < LINE; i++) {
		for (int j = 0; j < ROW; j++) {
			if (board[i][j] == WALL_NUM) // �Ƿ���ǽ
				printf("��");
			else if (i == upboard[0].hang && j == upboard[0].lie) // �Ƿ�����
				printf("��");
			else if (isBOX(upboard, num_upboard, i, j)) // �Ƿ�������
				printf("��");
			else if (board[i][j] == SPACE_NUM) // �Ƿ��ǿյ�
				printf("  ");
			else if (board[i][j] == BOX_DES)  // �Ƿ������ӵ�Ŀ�ĵ�
				printf("��");
		}
		printf("\n");
	}
}
int isBOX(Upthing* upboard, int num_upboard, int cur_hang, int cur_lie)
{
	int pd = 0;
	for (int k = 1; k < num_upboard; k++) //��Ϊbox��ID��upthing�����Ǵ�1��ʼ��
	{
		if (upboard[k].hang == cur_hang && upboard[k].lie == cur_lie)
		{
			pd = k;
			break;
		}
	}
	return pd;
}
bool move_person_box(Upthing* upboard,int num_upboard, int maze[][ROW])
{
	char move;
	int ID_box = 0; // ���Ӻ�������1��ʼ��
	bool pd = 0;
	scanf_s("%c", &move, 1);
	if (pd = move_or_not(move, upboard, num_upboard, maze, &ID_box)) {
		switch (move)// �ƶ� �� ���� �˺�����
		{
		case UP:
			upboard[0].hang -= 1;
			if (ID_box)
				upboard[ID_box].hang -= 1;
			break;
		case DOWN:
			upboard[0].hang += 1;
			if (ID_box)
				upboard[ID_box].hang += 1;
			break;
		case LEFT:
			upboard[0].lie -= 1;
			if (ID_box)
				upboard[ID_box].lie -= 1;
			break;
		case RIGHT:
			upboard[0].lie += 1;
			if (ID_box)
				upboard[ID_box].lie += 1;
			break;
		}
	}
	return pd;
}
bool move_or_not(char move, Upthing* upboard,int num_upboard, const int board[][ROW], int* ID_box)
{
	int pd = true;
	switch (move)
	{
	case UP:
		if (board[upboard[0].hang - 1][upboard[0].lie] == WALL_NUM)
			pd = false;
		else if ((*ID_box = isBOX(upboard, num_upboard, upboard[0].hang - 1, upboard[0].lie))) // ��ֵ���ж��Ƿ�������
			if (board[upboard[0].hang - 2][upboard[0].lie] == WALL_NUM ||
				isBOX(upboard, num_upboard, upboard[0].hang - 2, upboard[0].lie))
				pd = false;
		break;
	case DOWN:
		if (board[upboard[0].hang + 1][upboard[0].lie] == WALL_NUM)
			pd = false;
		else if ((*ID_box = isBOX(upboard, num_upboard, upboard[0].hang + 1, upboard[0].lie))) // ��ֵ���ж��Ƿ�������
			if (board[upboard[0].hang + 2][upboard[0].lie] == WALL_NUM ||
				isBOX(upboard, num_upboard, upboard[0].hang + 2, upboard[0].lie))
				pd = false;
		break;
	case LEFT:
		if (board[upboard[0].hang][upboard[0].lie - 1] == WALL_NUM)
			pd = false;
		else if ((*ID_box = isBOX(upboard, num_upboard, upboard[0].hang, upboard[0].lie - 1))) // ��ֵ���ж��Ƿ�������
			if (board[upboard[0].hang][upboard[0].lie - 2] == WALL_NUM ||
				isBOX(upboard, num_upboard, upboard[0].hang, upboard[0].lie - 2))
				pd = false;
		break;
	case RIGHT:
		if (board[upboard[0].hang][upboard[0].lie + 1] == WALL_NUM)
			pd = false;
		else if ((*ID_box = isBOX(upboard, num_upboard, upboard[0].hang, upboard[0].lie + 1))) // ��ֵ���ж��Ƿ�������
			if (board[upboard[0].hang][upboard[0].lie + 2] == WALL_NUM ||
				isBOX(upboard, num_upboard, upboard[0].hang, upboard[0].lie + 2))
				pd = false;
		break;
	default:
		pd = false;
		break;
	}
	return pd;
}