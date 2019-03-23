//********************************
//*         AddressList          *
//*                              *
//*  1. 插入                     *
//*  2. 删除                     *
//*  3. 查找                     *
//*  4. 修改                     *
//*------------------------------*
//* 版本号：   V 1.0             *
//* 修改日期： 2016/6/3          *
//*------------------------------*
//* 版本号：                     *
//* 修改日期：                   *
//*------------------------------*
//* 版本号：                     *
//* 修改日期：                   *
//*------------------------------*
//********************************
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

int biao = 0;//表长

HANDLE g_hConsoleOutput;                // 控制台输出句柄

void  gotoxyWithFullwidth(int x, int y); // 定位到指定位置
int  insert();                                    // 插入
int  del();                                       // 删除
int  find();                                      // 查找
//int  modification();                              // 修改
int  boundary();                                // 主界面
int  mainMenu();

typedef struct
{
	char name[20][20]; // 姓名
	char phone[20][20]; // 手机号
	char site[20][100]; // 地址

	int length;//当前的表长度  
}SeqList;

int boundary(SeqList *L) // 主界面
{
	int i, j;  //循环变量
	int index; // 索引号

	system("cls");

	SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);

	for (i = 0; i <= 28; i++)
	{
		gotoxyWithFullwidth(i, 3);
		printf("▅");
		gotoxyWithFullwidth(i, 6);
		printf("┄");
		gotoxyWithFullwidth(i, 26);
		printf("▅");
		gotoxyWithFullwidth(i, 30);
		printf("┄");

		if (i >= 4 && i <= 25)
		{
			gotoxyWithFullwidth(2, i);
			printf("┆");
			gotoxyWithFullwidth(6, i);
			printf("┆");
			gotoxyWithFullwidth(14, i);
			printf("┆");

		}
		if (i > 11 && i < 16)
		{
			gotoxyWithFullwidth(i, 2);
			printf("▂")
			if (i == 12)
			{
				gotoxyWithFullwidth(i, 1);
				printf("通 讯 录");
			}
		}
	}
	SetConsoleTextAttribute(g_hConsoleOutput, 0x0E); // 黑底白字
	gotoxyWithFullwidth(3, 5);
	printf("姓  名");
	gotoxyWithFullwidth(8, 5);
	printf("手  机  号");
	gotoxyWithFullwidth(20, 5);
	printf("地   址");


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

	index = mainMenu();     // 调用主菜单
	return index;   

}

int  mainMenu()
{
	static const char *modelItem[] = { "插入", "删除", "查找", "替换" }; //四个菜单项
	int index = 1;                                        //菜单的索引号 用来移动光标
	int ch;                                                              //返回的键值

	SetConsoleTextAttribute(g_hConsoleOutput, 0xF0);                       //白色背景
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

	do                                                               // while 是死循环 
	{
		ch = _getch();                                               //将键值返回给 ch 
		switch (ch)                                                         //测试键值
		{
		case 75:                                                                 // 左
			if (index == 3)                                     //通过索引号来变换光标
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
			break;                         // 按一个键后 退出循环 继续返回键值
		case 77:                                                         // 右
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
			break;                        // 按一个键后 退出循环 继续返回键值
		case 13:                                                       //回车
			return index;                            //把索引值返回给boundary
		}
	} while (2);
}

int insert(SeqList *K) // 插入
{
	char name2[1][20];    // 姓名
	char phone2[1][20];// 手机号
	char site2[1][100];    // 地址

	int i, j;// 循环变量
	int weizhi;//插入的位置
	int index;

	SetConsoleTextAttribute(g_hConsoleOutput, 0x0C);
	gotoxyWithFullwidth(1, 31);
	printf("请输入您要插入的【位置】：");

	SetConsoleTextAttribute(g_hConsoleOutput, 0x0E);
	scanf("%d", &weizhi);

	SetConsoleTextAttribute(g_hConsoleOutput, 0x0C);
	gotoxyWithFullwidth(1, 32);
	printf("请输入您要插入的联系人【姓名】：");

	SetConsoleTextAttribute(g_hConsoleOutput, 0x0E);
	scanf("%s", &name2[0]);

	SetConsoleTextAttribute(g_hConsoleOutput, 0x0C);
	gotoxyWithFullwidth(1, 33);
	printf("请输入您要插入的联系人【电话】：");

	SetConsoleTextAttribute(g_hConsoleOutput, 0x0E);
	scanf("%s", &phone2[0]);

	SetConsoleTextAttribute(g_hConsoleOutput, 0x0C);
	gotoxyWithFullwidth(1, 34);
	printf("请输入您要插入的联系人【地址】：");

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
	int i, j; //循环变量
	int weihzi; 
	int ii;
	int index;
	int jianzhi;
	char guanjianzi[1][20]; //查找关键字
	char dianhua[1][20] = { "18548141285" };
	char *n,*p,*s;

	SetConsoleTextAttribute(g_hConsoleOutput, 0x0C);
	gotoxyWithFullwidth(1, 31);
	printf("请输入您要删除的【关键字】：");

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
	printf("您要删除的联系人信息是：");
	Sleep(400);
	SetConsoleTextAttribute(g_hConsoleOutput, 0x0E);
	gotoxyWithFullwidth(1, 33);
	printf("%s %s %s",H->name[ii],H->phone[ii],H->site[ii]);
	Sleep(400);
	SetConsoleTextAttribute(g_hConsoleOutput, 0x0C);
	gotoxyWithFullwidth(1, 34);
	printf("确认删除（Y/N）?");

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
			if (strcmp(H->site[i], "内蒙古兴安盟乌兰浩特" )!= 0)
			{
				strcpy(H->site[i], "内蒙古兴安盟乌兰浩特");
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
	char guanjian[1][20]; //查找关键字

	SetConsoleTextAttribute(g_hConsoleOutput, 0x0C);
	gotoxyWithFullwidth(1, 31);
	printf("请输入您要查找的【关键字】：");

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
	int i, j; //循环变量
	int weihzi;
	int ii;
	int index;
	int jianzhi;
	int len;
	char guanjianzi[1][20]; //查找关键字
	char neirong[1][100];

	SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);


	SetConsoleTextAttribute(g_hConsoleOutput, 0x0C);
	gotoxyWithFullwidth(1, 31);
	printf("请输入您要修改的联系人【关键字】：");

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
	printf("请输入您要修改的【内容】：");

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

void gotoxyWithFullwidth(int x, int y) //定义指定位置的参数
{
	static COORD cd;
	cd.X = (int)(x << 1);
	cd.Y = y;
	SetConsoleCursorPosition(g_hConsoleOutput, cd);
}

int main()
{
	system("title 通讯录 V1.0");// 修改控制台标题
	system("mode con cols=58 lines=40");// 修改控制台大小

	CONSOLE_CURSOR_INFO cursorInfo = { 1, FALSE };  // 光标信息
	g_hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);  // 获取控制台输出句柄
	SetConsoleCursorInfo(g_hConsoleOutput, &cursorInfo);  // 设置光标隐藏

	SeqList list;

	int index = 0; // 主菜单的索引号
	int i;         // 循环变量
	//list.length = 0;
	char name1[15][20] = { "吴佳轶", "张舒妤", "葛晓宇", "马化腾", "雷布斯", "邵宇桐", "乔布斯", "李宏彦", "柳传志", "张朝阳", "张小三", "赵老五", "杜老七", "七大姑", "八大姨" };
	char phone1[15][20] = { "18548141285", "15690849723", "15104823474", "15248512818", "15332829785", "15248252051", "18704887817", "18222067522", "18304865911", "18829213835", "13612348765", "18714782369", "18298527825", "18044226699", "18813135268" };
	char site1[15][100] = { "内蒙古兴安盟乌兰浩特", "河南省信阳市淮滨县", "内蒙古兴安盟乌兰浩特市", "上海市陆家嘴南京路", "内蒙古呼和浩特市赛罕区", "内蒙古兴安盟阿尔山市", "河南省新郑市西亚斯大学", "内蒙古兴安盟科右前旗", "辽宁省辽阳市化工厂", "辽宁省瓦房店市北区", "天津狗不理包子街32号", "河南省信阳市南京路", "北京市丰田区81号", "伦敦市中心二街18号", "辽宁省沈阳市开天区" };

	for (i = 0; i <= 14; i++)
	{
		strcpy(list.name[i], name1[i]);
		strcpy(list.phone[i], phone1[i]);
		strcpy(list.site[i], site1[i]);
		list.length++;
		biao++;
	}

	index = boundary(&list); // 调用主界面

	do
	{
		if (index == 1)
		{
			index = insert(&list); // 调用插入函数
		}
		else if (index == 2)
		{
			index = del(&list); // 调用删除函数
		}
		else if (index == 3)
		{
			index = find(&list); // 调用查找函数
			system("cls");
			index = boundary(&list);
		}
		else if (index == 4)
		{
			index = modification(&list); // 调用替换函数
		}
	} while (2);

	system("pause>nul");// 屏幕停留
}