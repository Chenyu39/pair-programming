#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
void move(char a[][50], char m, int* money, int* x, int* y,int* stronger)  /*���������ƶ�����ý�ң�ʰȡ����*/
{

	if (m == 's' && a[*x + 1][*y] == ' ')
	{

		a[*x][*y] = ' ';
		(*x)++;
		a[*x][*y] = 'o';
	}
	else if (m == 's'&& (a[*x + 1][*y] == '$'||a[*x + 1][*y] == '!'))
	{
		if (a[*x+1 ][*y] == '!')
		{
			(* stronger)++;
		}
		a[*x][*y] = ' ';
		(*x)++;
		a[*x][*y] = 'o';
		(*money)++;
	}
	 else if (m == 'w' && a[*x - 1][*y] == ' ')
	{

		a[*x][*y] = ' ';
		(*x)--;
		a[*x][*y] = 'o';
	}
	else if (m == 'w' && (a[*x - 1][*y] == '$'||a[*x - 1][*y] == '!'))
	{

		if (a[*x-1][*y] == '!')
		{
			(*stronger)++;
		}
		a[*x][*y] = ' ';
		(*x)--;
		a[*x][*y] = 'o';
		(*money)++;
	}
	else if (m == 'a' && a[*x][*y - 1] == ' ')
	{
		a[*x][*y] = ' ';
		(*y)--;
		a[*x][*y] = 'o';
	}
	else if (m == 'a' && (a[*x][*y - 1] == '$'|| a[*x][*y - 1] == '!'))
	{

		if (a[*x ][*y-1] == '!')
		{
			(*stronger)++;
		}
		a[*x][*y] = ' ';
		(*y)--;
		a[*x][*y] = 'o';
		(*money)++;
	}
	else if (m == 'd' && a[*x][*y + 1] == ' ')
	{
		a[*x][*y] = ' ';
		(*y)++;
		a[*x][*y] = 'o';
	}
	else if (m == 'd' &&( a[*x][*y + 1] == '$'|| a[*x][*y + 1] == '!'))
	{
		if (a[*x][*y +1] == '!')
		{
			(*stronger)++;
		}
		a[*x][*y] = ' ';
		(*y)++;
		a[*x][*y] = 'o';
		(*money)++;
	}
}
void prop(char a[][50], char m, int* x, int* y)     /*����Ч��������#����ǽ��*/
{
	
		if (m == 's'&& a[*x + 1][*y] != 'x'&& a[*x + 1][*y] != '|')
		{

			a[*x][*y] = ' ';
			(*x)++;
			a[*x][*y] = 'o';

		}
		else if (m == 'w'&& a[*x -1][*y] != 'x'&& a[*x - 1][*y] != '|')
		{

			a[*x][*y] = ' ';
			(*x)--;
			a[*x][*y] = 'o';
		}
		else if (m == 'a'&& a[*x ][*y-1] != 'x'&& a[*x][*y - 1] != '|')
		{
			a[*x][*y] = ' ';
			(*y)--;
			a[*x][*y] = 'o';
		}
		else if (m == 'd'&& a[*x ][*y+1] != 'x'&& a[*x][*y + 1] != '|')
		{
			a[*x][*y] = ' ';
			(*y)++;
			a[*x][*y] = 'o';
		}
}
void put1(char a[][50],int count,int money)     /*��Ļ�����Ϸ����*/
	{
		printf("ʣ��%d��\n���������%d,����Ҫ������Ҳ��ܿ�������\n", 80 - count, money);
		int i = 0;
		for (i = 0; i < 12; i++)
			puts(a[i]);
	}
void introduction(int count,int money)  /*��Ϸ����*/
{
	printf("��ʹ��Ӣ�����뷨��\n������ʽ����������=wsad\n o �������������� # ����ǽ��,xΪ�߽磬$Ϊ��ң���Ϊ���ص����������ӽ��������\n");
	Sleep(4000);
	system("cls");
	printf("��Ϸ�����ڹ涨�����ڣ�����Ҫ��3����ҿ������Ų������յ�Ϊ��ʤ\n");
	printf("��ܰ��ʾ����������Ч������������������Ŷ!\n��ʼ�����Ϸ�ɣ�\n\n\n");
	Sleep(4000);
	system("cls");
}
int main()
{
	char a[50][50] =     {"xxxxxxxxxxxxxxxxxxxxxxxxxxxx",
		                  "x o# ### # ###    ####    |  �յ�",
						  "x  # # $##    # ##     #  #x",
						  "x  #  #  # #  #  #   ##### x",
					  	  "x#  #  #   # $# ####    #  x",
						  "x     ##  #####     #   #  x",
						  "x ## #  # ##   # # ## ##!  x",
	                      "x#   #   $   ### # #   ### x",
		                  "x  # ###  ### #   ####     x",
		                  "x  #      #      #       # x",
		                  "x   #####   ###     ##  # #x",
	                      "xxxxxxxxxxxxxxxxxxxxxxxxxxxx"};     /*���ҵ�ͼ*/
	int  x = 1, y = 2;
	char ch;
	int count = 0,money=0,stronger=0;
	introduction(count, money);
	put1(a,count,money);
	
	while (x != 1 || y != 27)
	{
		ch = _getch();
		count++;
		if (stronger == 0)                          /*�ж��Ƿ��ȡ����*/
		{	
			move(a, ch, &money, &x, &y, &stronger);
		}
		else if (stronger == 1)
		{
			prop(a, ch, &x, &y);
		}
		system("cls");
		if (money ==3&&a[1][26]!='o')        /*���������ж�*/
		{
			a[1][26] = ' ';
		}
		put1(a,count,money);
		if (x == 1 && y == 27)          /*���ѳɹ��ж�*/
		{
			system("cls");
			printf("���سɹ�!!!\n");
			break;
		}
		if (count >= 80)              /*����ʧ���ж�*/
		{
			system("cls");
			printf("���������꣬�����ˣ�");
			break;
		}
	}
	Sleep(5000);
	return 0;
}

