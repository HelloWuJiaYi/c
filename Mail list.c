//********************************
//*         AddressList          *
//*                              *
//*  1. ����                     *
//*  2. ɾ��                     *
//*  3. ����                     *
//*  4. �޸�                     *
//*------------------------------*
//* �汾�ţ�   V 1.0             *
//* �޸����ڣ� 2016/6/3          *
//*------------------------------*
//* �汾�ţ�                     *
//* �޸����ڣ�                   *
//*------------------------------*
//* �汾�ţ�                     *
//* �޸����ڣ�                   *
//*------------------------------*
//********************************
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

int biao = 0;//��

HANDLE g_hConsoleOutput;                // ����̨������

void  gotoxyWithFullwidth(int x, int y); // ��λ��ָ��λ��
int  insert();                                    // ����
int  del();                                       // ɾ��
int  find();                                      // ����
//int  modification();                              // �޸�
int  boundary();                                // ������
int  mainMenu();

typedef struct
{
	char name[20][20]; // ����
	char phone[20][20]; // �ֻ���
	char site[20][100]; // ��ַ

	int length;//��ǰ�ı���  
}SeqList;

int boundary(SeqList *L) // ������
{
	int i, j;  //ѭ������
	int index; // ������

	system("cls");

	SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);

	for (i = 0; i <= 28; i++)
	{
		gotoxyWithFullwidth(i, 3);
		printf("�|");
		gotoxyWithFullwidth(i, 6);
		printf("��");
		gotoxyWithFullwidth(i, 26);
		printf("�|");
		gotoxyWithFullwidth(i, 30);
		printf("��");

		if (i >= 4 && i <= 25)
		{
			gotoxyWithFullwidth(2, i);
			printf("��");
			gotoxyWithFullwidth(6, i);
			printf("��");
			gotoxyWithFullwidth(14, i);
			printf("��");

		}
		if (i > 11 && i < 16)
		{
			gotoxyWithFullwidth(i, 2);
			printf("�y")
			if (i == 12)
			{
				gotoxyWithFullwidth(i, 1);
				printf("ͨ Ѷ ¼");
			}
		}
	}
	SetConsoleTextAttribute(g_hConsoleOutput, 0x0E); // �ڵװ���
	gotoxyWithFullwidth(3, 5);
	printf("��  ��");
	gotoxyWithFullwidth(8, 5);
	printf("��  ��  ��");
	gotoxyWithFullwidth(20, 5);
	printf("��   ַ");


	for (i = 7; i < biao + 7; i++)
	{
		for (j = i - 7; j <= 20; j++)
		{
			SetConsoleTextAttribute(g_hConsoleOutput, 0x0E);
			gotoxyWithFullwidth(1, i);
			printf("%d", j + 1);
			SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
			gotoxyWithFullwidth(3, i);
			printf("%s", L->name[j]);
			gotoxyWithFullwidth(8, i);
			printf("%s", L->phone[j]);
			gotoxyWithFullwidth(16, i);
			printf("%s", L->site[j]);
			break;
		}
	}

	index = mainMenu();     // �������˵�
	return index;   

}

int  mainMenu()
{
	static const char *modelItem[] = { "����", "ɾ��", "����", "�滻" }; //�ĸ��˵���
	int index = 1;                                        //�˵��������� �����ƶ����
	int ch;                                                              //���صļ�ֵ

	SetConsoleTextAttribute(g_hConsoleOutput, 0xF0);                       //��ɫ����
	gotoxyWithFullwidth(3, 28);
	printf("%2s%s%2s", "", modelItem[0], "");
	SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
	gotoxyWithFullwidth(9, 28);
	printf("%2s%s%2s", "", modelItem[1], "");
	SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
	gotoxyWithFullwidth(15, 28);
	printf("%2s%s%2s", "", modelItem[2], "");
	SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
	gotoxyWithFullwidth(21, 28);
	printf("%2s%s%2s", "", modelItem[3], "");

	do                                                               // while ����ѭ�� 
	{
		ch = _getch();                                               //����ֵ���ظ� ch 
		switch (ch)                                                         //���Լ�ֵ
		{
		case 75:                                                                 // ��
			if (index == 3)                                     //ͨ�����������任���
			{
				index = 2
				SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
				gotoxyWithFullwidth(3, 28);
				printf("%2s%s%2s", "", modelItem[0], "");
				SetConsoleTextAttribute(g_hConsoleOutput, 0xF0);
				gotoxyWithFullwidth(9, 28);
				printf("%2s%s%2s", "", modelItem[1], "");
				SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
				gotoxyWithFullwidth(15, 28);
				printf("%2s%s%2s", "", modelItem[2], "");
				SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
				gotoxyWithFullwidth(21, 28);
				printf("%2s%s%2s", "", modelItem[3], "");
			}
			else if (index == 4)
			{
				index = 3;
				SetConsoleTextAttribute(g_hConsoleOutput, 0x0F)
				gotoxyWithFullwidth(3, 28);
				printf("%2s%s%2s", "", modelItem[0], "");
				SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
				gotoxyWithFullwidth(9, 28);
				printf("%2s%s%2s", "", modelItem[1], "");
				SetConsoleTextAttribute(g_hConsoleOutput, 0xF0);
				gotoxyWithFullwidth(15, 28);
				printf("%2s%s%2s", "", modelItem[2], "");
				SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
				gotoxyWithFullwidth(21, 28);
				printf("%2s%s%2s", "", modelItem[3], "");
			}
			else if (index == 1)
			{
				index = 4;
				SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
				gotoxyWithFullwidth(3, 28);
				printf("%2s%s%2s", "", modelItem[0], "");
				SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
				gotoxyWithFullwidth(9, 28);
				printf("%2s%s%2s", "", modelItem[1], "");
				SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
				gotoxyWithFullwidth(15, 28);
				printf("%2s%s%2s", "", modelItem[2], "");
				SetConsoleTextAttribute(g_hConsoleOutput, 0xF0);
				gotoxyWithFullwidth(21, 28);
				printf("%2s%s%2s", "", modelItem[3], "");
			}
			else if (index == 2)
			{
				index = 1;
				SetConsoleTextAttribute(g_hConsoleOutput, 0xF0);
				gotoxyWithFullwidth(3, 28);
				printf("%2s%s%2s", "", modelItem[0], "");
				SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
				gotoxyWithFullwidth(9, 28);
				printf("%2s%s%2s", "", modelItem[1], "");
				SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
				gotoxyWithFullwidth(15, 28);
				printf("%2s%s%2s", "", modelItem[2], "");
				SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
				gotoxyWithFullwidth(21, 28);
				printf("%2s%s%2s", "", modelItem[3], "");
			}
			break;                         // ��һ������ �˳�ѭ�� �������ؼ�ֵ
		case 77:                                                         // ��
			if (index == 1)
			{
				index = 2;
				SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
				gotoxyWithFullwidth(3, 28);
				printf("%2s%s%2s", "", modelItem[0], "");
				SetConsoleTextAttribute(g_hConsoleOutput, 0xF0);
				gotoxyWithFullwidth(9, 28);
				printf("%2s%s%2s", "", modelItem[1], "");
				SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
				gotoxyWithFullwidth(15, 28);
				printf("%2s%s%2s", "", modelItem[2], "");
				SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
				gotoxyWithFullwidth(21, 28);
				printf("%2s%s%2s", "", modelItem[3], "");
			}
			else if (index == 2)
			{
				index = 3;
				SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
				gotoxyWithFullwidth(3, 28);
				printf("%2s%s%2s", "", modelItem[0], "");
				SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
				gotoxyWithFullwidth(9, 28);
				printf("%2s%s%2s", "", modelItem[1], "");
				SetConsoleTextAttribute(g_hConsoleOutput, 0xF0);
				gotoxyWithFullwidth(15, 28);
				printf("%2s%s%2s", "", modelItem[2], "");
				SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
				gotoxyWithFullwidth(21, 28);
				printf("%2s%s%2s", "", modelItem[3], "");
			}
			else if (index == 3)
			{
				index = 4;
				SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
				gotoxyWithFullwidth(3, 28);
				printf("%2s%s%2s", "", modelItem[0], "");
				SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
				gotoxyWithFullwidth(9, 28);
				printf("%2s%s%2s", "", modelItem[1], "");
				SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
				gotoxyWithFullwidth(15, 28);
				printf("%2s%s%2s", "", modelItem[2], "");
				SetConsoleTextAttribute(g_hConsoleOutput, 0xF0);
				gotoxyWithFullwidth(21, 28);
				printf("%2s%s%2s", "", modelItem[3], "");
			}
			else if (index == 4)
			{
				index = 1;
				SetConsoleTextAttribute(g_hConsoleOutput, 0xF0);
				gotoxyWithFullwidth(3, 28);
				printf("%2s%s%2s", "", modelItem[0], "");
				SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
				gotoxyWithFullwidth(9, 28);
				printf("%2s%s%2s", "", modelItem[1], "");
				SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
				gotoxyWithFullwidth(15, 28);
				printf("%2s%s%2s", "", modelItem[2], "");
				SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
				gotoxyWithFullwidth(21, 28);
				printf("%2s%s%2s", "", modelItem[3], "");
			}
			break;                        // ��һ������ �˳�ѭ�� �������ؼ�ֵ
		case 13:                                                       //�س�
			return index;                            //������ֵ���ظ�boundary
		}
	} while (2);
}

int insert(SeqList *K) // ����
{
	char name2[1][20];    // ����
	char phone2[1][20];// �ֻ���
	char site2[1][100];    // ��ַ

	int i, j;// ѭ������
	int weizhi;//�����λ��
	int index;

	SetConsoleTextAttribute(g_hConsoleOutput, 0x0C);
	gotoxyWithFullwidth(1, 31);
	printf("��������Ҫ����ġ�λ�á���");

	SetConsoleTextAttribute(g_hConsoleOutput, 0x0E);
	scanf("%d", &weizhi);

	SetConsoleTextAttribute(g_hConsoleOutput, 0x0C);
	gotoxyWithFullwidth(1, 32);
	printf("��������Ҫ�������ϵ�ˡ���������");

	SetConsoleTextAttribute(g_hConsoleOutput, 0x0E);
	scanf("%s", &name2[0]);

	SetConsoleTextAttribute(g_hConsoleOutput, 0x0C);
	gotoxyWithFullwidth(1, 33);
	printf("��������Ҫ�������ϵ�ˡ��绰����");

	SetConsoleTextAttribute(g_hConsoleOutput, 0x0E);
	scanf("%s", &phone2[0]);

	SetConsoleTextAttribute(g_hConsoleOutput, 0x0C);
	gotoxyWithFullwidth(1, 34);
	printf("��������Ҫ�������ϵ�ˡ���ַ����");

	SetConsoleTextAttribute(g_hConsoleOutput, 0x0E);
	scanf("%s", &site2[0]);


	for (j = biao - 1; j >= weizhi - 1; j--)
	{
		strcpy(K->name[j + 1], K->name[j]);
		strcpy(K->phone[j + 1], K->phone[j]);
		strcpy(K->site[j + 1], K->site[j]);
	}

	strcpy(K->name[weizhi - 1], name2[0]);
	strcpy(K->phone[weizhi - 1], phone2[0]);
	strcpy(K->site[weizhi - 1], site2[0]);

	biao++;

	index = boundary(K);
	return index;
}

int del(SeqList *H)
{
	int i, j; //ѭ������
	int weihzi; 
	int ii;
	int index;
	int jianzhi;
	char guanjianzi[1][20]; //���ҹؼ���
	char dianhua[1][20] = { "18548141285" };
	char *n,*p,*s;

	SetConsoleTextAttribute(g_hConsoleOutput, 0x0C);
	gotoxyWithFullwidth(1, 31);
	printf("��������Ҫɾ���ġ��ؼ��֡���");

	SetConsoleTextAttribute(g_hConsoleOutput, 0x0E);
	scanf("%s", &guanjianzi[0]);

	for (i = 0; i <= biao; i++)
	{
		for (j = 0; j <= 2;j++)
		{
			if (j == 0)
			{
				if (strcmp(H->name[i], guanjianzi[0])==0)
				{
					ii = i;
					goto a;
				}
			}
			if (j == 1)
			{
				if (strcmp(H->phone[i], guanjianzi[0]) == 0)
				{
					ii = i;
					goto a;
				}
			}
			if (j == 1)
			{
				if (strcmp(H->site[i], guanjianzi[0]) == 0)
				{
					ii = i;
					goto a;
				}
			}
		}
	}

a:

	SetConsoleTextAttribute(g_hConsoleOutput, 0x0C);
	gotoxyWithFullwidth(1, 32);
	printf("��Ҫɾ������ϵ����Ϣ�ǣ�");
	Sleep(400);
	SetConsoleTextAttribute(g_hConsoleOutput, 0x0E);
	gotoxyWithFullwidth(1, 33);
	printf("%s %s %s",H->name[ii],H->phone[ii],H->site[ii]);
	Sleep(400);
	SetConsoleTextAttribute(g_hConsoleOutput, 0x0C);
	gotoxyWithFullwidth(1, 34);
	printf("ȷ��ɾ����Y/N��?");

	jianzhi = _getch();

	if (jianzhi == 121)
	{
		for (j = ii; j <=biao-1; j++)
		{
			strcpy(H->name[j], H->name[j+1]);
			strcpy(H->site[j], H->site[j+1]);
			strcpy(H->phone[j], H->phone[j+1]);
		}
	}
	else
	{
		index = boundary(H);
		return index;
	}

    biao--;                                                                                                                        

	for (i = 0; i <= biao; i++)
	{
		if (strcmp(H->phone[i], dianhua[0] )== 0)
		{
			if (strcmp(H->site[i], "���ɹ��˰�����������" )!= 0)
			{
				strcpy(H->site[i], "���ɹ��˰�����������");
				goto b;
			}
		}
	}
b:

	index = boundary(H);
	return index;
}

int find(SeqList *O)
{
	int i, j;
	int ii[10];
	int iii = -1;
	int iiii = 0;
	int index;
	int cx;
	char guanjian[1][20]; //���ҹؼ���

	SetConsoleTextAttribute(g_hConsoleOutput, 0x0C);
	gotoxyWithFullwidth(1, 31);
	printf("��������Ҫ���ҵġ��ؼ��֡���");

	SetConsoleTextAttribute(g_hConsoleOutput, 0x0E);
	scanf("%s", &guanjian[0]);

	for (i = 0; i<biao; i++)
	{
		for (j = 0; j <= 2; j++)
		{
			if (j == 0)
			{
				if (NULL != strstr(O->name[i], guanjian[0]))
				{
					iii++;
					ii[iii] = i;
				}
			}
			else if (j == 1)
			{
				if (NULL != strstr(O->phone[i], guanjian[0]))
				{
					iii++;
					ii[iii] = i;
				}
			}
			else if (j == 2)
			{
				if (NULL != strstr(O->site[i], guanjian[0]))
				{
					iii++;
					ii[iii] = i;
				}
			}
		}
	}

	for (i = 0; i <= iii; i++)
	{
		iiii = ii[i];
		SetConsoleTextAttribute(g_hConsoleOutput, 0x0E);
		gotoxyWithFullwidth(1, i + 32);
		printf("%s %s %s", O->name[iiii], O->phone[iiii], O->site[iiii]);
	}

	index = mainMenu();
	return index;
	
}

int modification(SeqList *F)
{
	int i, j; //ѭ������
	int weihzi;
	int ii;
	int index;
	int jianzhi;
	int len;
	char guanjianzi[1][20]; //���ҹؼ���
	char neirong[1][100];

	SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);


	SetConsoleTextAttribute(g_hConsoleOutput, 0x0C);
	gotoxyWithFullwidth(1, 31);
	printf("��������Ҫ�޸ĵ���ϵ�ˡ��ؼ��֡���");

	SetConsoleTextAttribute(g_hConsoleOutput, 0x0E);
	scanf("%s", &guanjianzi[0]);

	for (i = 0; i <= biao; i++)
	{
		for (j = 0; j <= 2; j++)
		{
			if (j == 0)
			{
				if (strcmp(F->name[i], guanjianzi[0]) == 0)
				{
					ii = i;
					goto a;
				}
			}
			if (j == 1)
			{
				if (strcmp(F->phone[i], guanjianzi[0]) == 0)
				{
					ii = i;
					goto a;
				}
			}
			if (j == 1)
			{
				if (strcmp(F->site[i], guanjianzi[0]) == 0)
				{
					ii = i;
					goto a;
				}
			}
		}
	}
a:
	SetConsoleTextAttribute(g_hConsoleOutput, 0x0C);
	gotoxyWithFullwidth(1, 32);
	printf("��������Ҫ�޸ĵġ����ݡ���");

	SetConsoleTextAttribute(g_hConsoleOutput, 0x0E);
	scanf("%s", &neirong[0]);

	len = strlen(neirong[0]);

	if (len <= 6)
	{
		strcpy(F->name[ii], neirong[0]);
	}
	else if (len <= 11)
	{
		for (i = 0; i < len; i++)
		{
			if (neirong[0][i] >= '0' && neirong[0][i] <= '9')
			{
				strcpy(F->phone[ii], neirong[0]);
			}
		}
	}
    if (len > 11)
	{
		strcpy(F->site[ii], neirong[0]);
	}

	index = boundary(F);
	return index;
}

void gotoxyWithFullwidth(int x, int y) //����ָ��λ�õĲ���
{
	static COORD cd;
	cd.X = (int)(x << 1);
	cd.Y = y;
	SetConsoleCursorPosition(g_hConsoleOutput, cd);
}

int main()
{
	system("title ͨѶ¼ V1.0");// �޸Ŀ���̨����
	system("mode con cols=58 lines=40");// �޸Ŀ���̨��С

	CONSOLE_CURSOR_INFO cursorInfo = { 1, FALSE };  // �����Ϣ
	g_hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);  // ��ȡ����̨������
	SetConsoleCursorInfo(g_hConsoleOutput, &cursorInfo);  // ���ù������

	SeqList list;

	int index = 0; // ���˵���������
	int i;         // ѭ������
	//list.length = 0;
	char name1[15][20] = { "�����", "�����", "������", "����", "�ײ�˹", "����ͩ", "�ǲ�˹", "�����", "����־", "�ų���", "��С��", "������", "������", "�ߴ��", "�˴���" };
	char phone1[15][20] = { "18548141285", "15690849723", "15104823474", "15248512818", "15332829785", "15248252051", "18704887817", "18222067522", "18304865911", "18829213835", "13612348765", "18714782369", "18298527825", "18044226699", "18813135268" };
	char site1[15][100] = { "���ɹ��˰�����������", "����ʡ�����л�����", "���ɹ��˰�������������", "�Ϻ���½�����Ͼ�·", "���ɹź��ͺ�����������", "���ɹ��˰��˰���ɽ��", "����ʡ��֣������˹��ѧ", "���ɹ��˰��˿���ǰ��", "����ʡ�����л�����", "����ʡ�߷����б���", "��򹷲�����ӽ�32��", "����ʡ�������Ͼ�·", "�����з�����81��", "�׶������Ķ���18��", "����ʡ�����п�����" };

	for (i = 0; i <= 14; i++)
	{
		strcpy(list.name[i], name1[i]);
		strcpy(list.phone[i], phone1[i]);
		strcpy(list.site[i], site1[i]);
		list.length++;
		biao++;
	}

	index = boundary(&list); // ����������

	do
	{
		if (index == 1)
		{
			index = insert(&list); // ���ò��뺯��
		}
		else if (index == 2)
		{
			index = del(&list); // ����ɾ������
		}
		else if (index == 3)
		{
			index = find(&list); // ���ò��Һ���
			system("cls");
			index = boundary(&list);
		}
		else if (index == 4)
		{
			index = modification(&list); // �����滻����
		}
	} while (2);

	system("pause>nul");// ��Ļͣ��
}