/********************************
 *         儿童测试题           *
 *                              *
 *  1. 能够选择难易程度         *
 *  2. 计算加减乘除的计算题     *
 *                              *
 *------------------------------*
 * 版本号：   1.0.0             *
 * 修改日期： 2016/3/21         *
 *------------------------------*
 * 版本号：   1.0.2             *
 * 修改日期： 2016/3/22         *
 *------------------------------*
 * 版本号：                     *
 * 修改日期：                   *
 *------------------------------*
/*******************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
//以上是需要的头文件

HANDLE g_hConsoleOutput; // 控制台输出句柄

int k[5]={0x01,0x02,0x04,0x06,0x05};//全局数组 控制难度选择菜单标题的颜色 
int defen=0;//全局变量 计算得分 
int cishu=0;//全局变量 计算答题次数
int qian[10], hou[10], daan[10] ;//全局数组 存放10道题目 加法
int qian2[10],hou2[10],daan2[10];//全局数组 存放10道题目 减法
int qian3[10],hou3[10],daan3[10];//全局数组 存放10道题目 乘法
int qian4[10],hou4[10],daan4[10];//全局数组 存放10道题目 除法
int xx=3,yy=5  ,  xx2=3,yy2=5  ,  xx3=3,yy3=5  ,  xx4=3,yy4=5;//控制输出语句的坐标参数
int x1=-1,y1=-1,z1=-1  ,  x2=-1,y2=-1,z2=-1  ,  x3=-1,y3=-1,z3=-1  ,  x4=-1,y4=-1,z4=-1;// 四个运算符的三个数
int index2 = 1; //菜单的索引号 用来移动光标
//以上是需要的全局变量

void gotoxyWithFullwidth(int x, int y); //定位到指定位置 
int  mainMenu();  //难度选择菜单
int  mainMenutwo();  //运算符选择界面  
int  rongyi();  //容易 
int  jiandan();  //一般
int  kunnan();  //困难
int  jia();  //加法函数 
int  jian();  //减法函数 
int  cheng();  //乘法函数 
int  chu();  //除法函数 
//以上是函数定义  

int main ()//主函数
{
    int Menu;//难度选择菜单返回值
    
        system("title 儿童脑力开发测试题1.0.0");//修改控制台标题
        system("mode con cols=60 lines=20");//修改控制台大小

    CONSOLE_CURSOR_INFO cursorInfo = { 1, FALSE };  // 光标信息
    g_hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);  // 获取控制台输出句柄
    SetConsoleCursorInfo(g_hConsoleOutput, &cursorInfo);  // 设置光标隐藏

    system("cls"); 

    Menu = mainMenu();//根据选择的难度 进入不同的子函数

    if (Menu == 1)
    {
        system("cls"); 
        rongyi();
    }
    if (Menu == 2)
    {
        system("cls");
        jiandan();
    }
    if (Menu == 3)
    {
        system("cls");
        kunnan();
    }    
        
    system("pause>nul");
}

void gotoxyWithFullwidth(int x, int y) //定义指定位置的参数
{
    static COORD cd;
    cd.X = (int)(x << 1);
    cd.Y = y;
    SetConsoleCursorPosition(g_hConsoleOutput, cd);
}

int  mainMenu()//难度选择菜单
{
    static const char *modelItem[] = { "简单", "一般", "困难"}; //三个难度
    int ch;//返回的键值
    int index = 1;//根据索引号改变选项 
    int i = 0;//全局变量 控制难度选择菜单标题的颜色 如果大于第四种颜色 那么让i等于0 
    int k[5]={0x01,0x02,0x04,0x06,0x05};//改变颜色 
    
    SetConsoleTextAttribute(g_hConsoleOutput, 0xF5); 
    gotoxyWithFullwidth(13, 8);
    printf("%2s%s%2s", "", modelItem[0], ""); 
    SetConsoleTextAttribute(g_hConsoleOutput, 0x05);
    gotoxyWithFullwidth(13, 10);
    printf("%2s%s%2s", "", modelItem[1], "");
    SetConsoleTextAttribute(g_hConsoleOutput, 0x05);
    gotoxyWithFullwidth(13, 12);
    printf("%2s%s%2s", "", modelItem[2], "");
    SetConsoleTextAttribute(g_hConsoleOutput, k[4]); 
    gotoxyWithFullwidth(10, 2);
    printf(" 儿童脑力开发测试题");

    do // while 是死循环 
    {
        ch = _getch(); //将键值返回给 ch 
        switch (ch) //测试键值
        {
            case 72:  // 上
                if (i>3)
                    i=0;
                if (index == 1) //通过索引号来变换光标
                {
                    index = 3;
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x05);
                    gotoxyWithFullwidth(13, 8);
                    printf("%2s%s%2s", "", modelItem[0], "");
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x05);
                    gotoxyWithFullwidth(13, 10);
                    printf("%2s%s%2s", "", modelItem[1], "");
                    SetConsoleTextAttribute(g_hConsoleOutput, 0xF5);
                    gotoxyWithFullwidth(13, 12);
                    printf("%2s%s%2s", "", modelItem[2], ""); 
                    SetConsoleTextAttribute(g_hConsoleOutput, k[i]); 
                    gotoxyWithFullwidth(10, 2);
                    printf(" 儿童脑力开发测试题");
                    i++;              
                }
                else if (index == 3)
                {
                    index = 2;
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x05);
                    gotoxyWithFullwidth(13, 8);
                    printf("%2s%s%2s", "", modelItem[0], "");
                    SetConsoleTextAttribute(g_hConsoleOutput, 0xF5);
                    gotoxyWithFullwidth(13, 10);
                    printf("%2s%s%2s", "", modelItem[1], "");
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x05);
                    gotoxyWithFullwidth(13, 12);
                    printf("%2s%s%2s", "", modelItem[2], ""); 
                    SetConsoleTextAttribute(g_hConsoleOutput, k[i]); 
                    gotoxyWithFullwidth(10, 2);
                    printf(" 儿童脑力开发测试题");
                    i++;
                }
                else if (index == 2)
                {
                    index = 1;
                    SetConsoleTextAttribute(g_hConsoleOutput, 0xF5);
                    gotoxyWithFullwidth(13, 8);
                    printf("%2s%s%2s", "", modelItem[0], "");
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x05);
                    gotoxyWithFullwidth(13, 10);
                    printf("%2s%s%2s", "", modelItem[1], "");
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x05);
                    gotoxyWithFullwidth(13, 12);
                    printf("%2s%s%2s", "", modelItem[2], ""); 
                    SetConsoleTextAttribute(g_hConsoleOutput, k[i]); 
                    gotoxyWithFullwidth(10, 2);
                    printf(" 儿童脑力开发测试题");
                    i++;
                }
                break;// 按一个键后 退出循环 继续返回键值
            case 80:  // 下
                if (i>3)
                    i=0;
                if (index == 2)
                {
                    index = 3;
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x05);
                    gotoxyWithFullwidth(13, 8);
                    printf("%2s%s%2s", "", modelItem[0], "");
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x05);
                    gotoxyWithFullwidth(13, 10);
                    printf("%2s%s%2s", "", modelItem[1], "");
                    SetConsoleTextAttribute(g_hConsoleOutput, 0xF5);
                    gotoxyWithFullwidth(13, 12);
                    printf("%2s%s%2s", "", modelItem[2], "");  
                    SetConsoleTextAttribute(g_hConsoleOutput, k[i]); 
                    gotoxyWithFullwidth(10, 2);
                    printf(" 儿童脑力开发测试题");  
                    i++;         
                }
                else if (index == 1)
                {
                    index = 2;
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x05);
                    gotoxyWithFullwidth(13, 8);
                    printf("%2s%s%2s", "", modelItem[0], "");
                    SetConsoleTextAttribute(g_hConsoleOutput, 0xF5);
                    gotoxyWithFullwidth(13, 10);
                    printf("%2s%s%2s", "", modelItem[1], "");
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x05);
                    gotoxyWithFullwidth(13, 12);
                    printf("%2s%s%2s", "", modelItem[2], "");
                    SetConsoleTextAttribute(g_hConsoleOutput, k[i]); 
                    gotoxyWithFullwidth(10, 2);
                    printf(" 儿童脑力开发测试题");
                    i++;
                }
                else if (index ==3)
                {
                    index = 1;
                    SetConsoleTextAttribute(g_hConsoleOutput, 0xF5);
                    gotoxyWithFullwidth(13, 8);
                    printf("%2s%s%2s", "", modelItem[0], "");
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x05);
                    gotoxyWithFullwidth(13, 10);
                    printf("%2s%s%2s", "", modelItem[1], "");
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x05);
                    gotoxyWithFullwidth(13, 12);
                    printf("%2s%s%2s", "", modelItem[2], "");
                    SetConsoleTextAttribute(g_hConsoleOutput, k[i]); 
                    gotoxyWithFullwidth(10, 2);
                    printf(" 儿童脑力开发测试题");
                    i++;
                }
                break; // 按一个键后 退出循环 继续返回键值
            case 13://回车
                return index; //把索引值返回给主函数 
        }
    } while (2);
}

int mainMenutwo(int a1,int b1,int c1)//运算符选择界面
{
    static const char *modelItem[] = { "加法", "减法", "乘法","除法"}; //四个菜单项
    int ch,chh; //返回的键值
    int sum=0;//计算最终得分

    if (cishu==10)//如果出题10次 那么弹出对话框
    {
        sum = defen*10;
        SetConsoleTextAttribute(g_hConsoleOutput, 0xF5);     
        gotoxyWithFullwidth(7, 14); 
        printf("┏━━━━━━━━━━━━━━┓"); //电子词典标题
        SetConsoleTextAttribute(g_hConsoleOutput, 0xF5); 
        gotoxyWithFullwidth(7, 15);
        printf("┃                            ┃");
        SetConsoleTextAttribute(g_hConsoleOutput, 0xF5); 
        gotoxyWithFullwidth(7, 16);
        printf("┃                            ┃");
        SetConsoleTextAttribute(g_hConsoleOutput, 0xF5); 
        gotoxyWithFullwidth(7, 17);
        printf("┃                            ┃");
        SetConsoleTextAttribute(g_hConsoleOutput, 0xF5); 
        gotoxyWithFullwidth(7, 18);
        printf("┗━━━━━━━━━━━━━━┛");
        
        gotoxyWithFullwidth(11, 15);
        printf("您一共答对了%d道题",defen); 
        gotoxyWithFullwidth(13, 16);
        printf("得分：%d",sum); 
        
        SetConsoleTextAttribute(g_hConsoleOutput, 0xF5);
        gotoxyWithFullwidth(12, 17);
        printf("退出答题系统 ");   
        chh = _getch();
        if (chh==13)
            main();
    }
    //以上是出题十道后 弹出对话框 显示你的分数和做对的题目数

    if (yy>5 && index2==1)
    {
        gotoxyWithFullwidth(3, yy);
        printf("%d+%d=%d",qian[x1],hou[y1],daan[z1]);
    }  
    if (yy2>5 && index2==2)
    { 
        gotoxyWithFullwidth(10, yy2);
        printf("%d-%d=%d",qian2[x2],hou2[y2],daan2[z2]);
    }    
    if (yy3>5 && index2==3)
    { 
        gotoxyWithFullwidth(17, yy3);
        printf("%d*%d=%d",qian3[x3],hou3[y3],daan3[z3]);
    }
    if (yy4>5 && index2==4)
    {
        gotoxyWithFullwidth(24, yy4);
        printf("%d/%d=%d",qian4[x4],hou4[y4],daan4[z4]);
    }
    //以上 保留做过的题

    if (c1 == 1)
    {
        SetConsoleTextAttribute(g_hConsoleOutput, 0x02);
        gotoxyWithFullwidth(14, 1);
        printf("简单");  
    } 
    else if (c1 == 2)
    {
        SetConsoleTextAttribute(g_hConsoleOutput, 0x06);
        gotoxyWithFullwidth(14, 1);
        printf("一般");  
    } 
    else if (c1 == 3)
    {
        SetConsoleTextAttribute(g_hConsoleOutput, 0x04);
        gotoxyWithFullwidth(14, 1);
        printf("困难");  
    } 
    //以上 提示当前难度

    if (index2 == 1)
    {
        SetConsoleTextAttribute(g_hConsoleOutput, 0xF0); //白色背景
        gotoxyWithFullwidth(3, 4);
        printf("%2s%s%2s", "", modelItem[0], ""); 
        SetConsoleTextAttribute(g_hConsoleOutput, 0x05);
        gotoxyWithFullwidth(10, 4);
        printf("%2s%s%2s", "", modelItem[1], "");
        SetConsoleTextAttribute(g_hConsoleOutput, 0x05);
        gotoxyWithFullwidth(17, 4);
        printf("%2s%s%2s", "", modelItem[2], "");
        SetConsoleTextAttribute(g_hConsoleOutput, 0x05);
        gotoxyWithFullwidth(24, 4);
        printf("%2s%s%2s", "", modelItem[3], "");
    }
    if (index2 == 2)
    {
        SetConsoleTextAttribute(g_hConsoleOutput, 0x05); //白色背景
        gotoxyWithFullwidth(3, 4);
        printf("%2s%s%2s", "", modelItem[0], ""); 
        SetConsoleTextAttribute(g_hConsoleOutput, 0xF0);
        gotoxyWithFullwidth(10, 4);
        printf("%2s%s%2s", "", modelItem[1], "");
        SetConsoleTextAttribute(g_hConsoleOutput, 0x05);
        gotoxyWithFullwidth(17, 4);
        printf("%2s%s%2s", "", modelItem[2], "");
        SetConsoleTextAttribute(g_hConsoleOutput, 0x05);
        gotoxyWithFullwidth(24, 4);
        printf("%2s%s%2s", "", modelItem[3], "");
    }
    if (index2 == 3)
    {
        SetConsoleTextAttribute(g_hConsoleOutput, 0x05); //白色背景
        gotoxyWithFullwidth(3, 4);
        printf("%2s%s%2s", "", modelItem[0], ""); 
        SetConsoleTextAttribute(g_hConsoleOutput, 0x05);
        gotoxyWithFullwidth(10, 4);
        printf("%2s%s%2s", "", modelItem[1], "");
        SetConsoleTextAttribute(g_hConsoleOutput, 0xF0);
        gotoxyWithFullwidth(17, 4);
        printf("%2s%s%2s", "", modelItem[2], "");
        SetConsoleTextAttribute(g_hConsoleOutput, 0x05);
        gotoxyWithFullwidth(24, 4);
        printf("%2s%s%2s", "", modelItem[3], "");
    }
    if (index2 == 4)
    {
        SetConsoleTextAttribute(g_hConsoleOutput, 0x05); //白色背景
        gotoxyWithFullwidth(3, 4);
        printf("%2s%s%2s", "", modelItem[0], ""); 
        SetConsoleTextAttribute(g_hConsoleOutput, 0x05);
        gotoxyWithFullwidth(10, 4);
        printf("%2s%s%2s", "", modelItem[1], "");
        SetConsoleTextAttribute(g_hConsoleOutput, 0x05);
        gotoxyWithFullwidth(17, 4);
        printf("%2s%s%2s", "", modelItem[2], "");
        SetConsoleTextAttribute(g_hConsoleOutput, 0xF0);
        gotoxyWithFullwidth(24, 4);
        printf("%2s%s%2s", "", modelItem[3], "");
    }
    //修复选择运算符计算后 光标调到加法的 BUG 

    do // while 是死循环 
    {
        ch = _getch(); //将键值返回给 ch 
        switch (ch) //测试键值
        {
            case 75:  // 上
                if (index2 == 3) //通过索引号来变换光标
                {
                    index2=2;
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x05);
                    gotoxyWithFullwidth(3, 4);
                    printf("%2s%s%2s", "", modelItem[0], "");
                    SetConsoleTextAttribute(g_hConsoleOutput, 0xF0);
                    gotoxyWithFullwidth(10, 4);
                    printf("%2s%s%2s", "", modelItem[1], "");
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x05);
                    gotoxyWithFullwidth(17, 4);
                    printf("%2s%s%2s", "", modelItem[2], "");
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x05);
                    gotoxyWithFullwidth(24, 4);
                    printf("%2s%s%2s", "", modelItem[3], "");                
                }
                else if (index2 == 4)
                {
                    index2 = 3;
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x05);
                    gotoxyWithFullwidth(3, 4);
                    printf("%2s%s%2s", "", modelItem[0], "");
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x05);
                    gotoxyWithFullwidth(10, 4);
                    printf("%2s%s%2s", "", modelItem[1], "");
                    SetConsoleTextAttribute(g_hConsoleOutput, 0xF0);
                    gotoxyWithFullwidth(17, 4);
                    printf("%2s%s%2s", "", modelItem[2], "");
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x05);
                    gotoxyWithFullwidth(24, 4);
                    printf("%2s%s%2s", "", modelItem[3], "");  
                }
                else if (index2 ==1)
                {
                    index2 = 4;
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x05);
                    gotoxyWithFullwidth(3, 4);
                    printf("%2s%s%2s", "", modelItem[0], "");
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x05);
                    gotoxyWithFullwidth(10, 4);
                    printf("%2s%s%2s", "", modelItem[1], "");
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x05);
                    gotoxyWithFullwidth(17, 4);
                    printf("%2s%s%2s", "", modelItem[2], "");
                    SetConsoleTextAttribute(g_hConsoleOutput, 0xF0);
                    gotoxyWithFullwidth(24, 4);
                    printf("%2s%s%2s", "", modelItem[3], "");  
                }
                else if (index2 ==2)
                {
                    index2 = 1;
                    SetConsoleTextAttribute(g_hConsoleOutput, 0xF0);
                    gotoxyWithFullwidth(3, 4);
                    printf("%2s%s%2s", "", modelItem[0], "");
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x05);
                    gotoxyWithFullwidth(10, 4);
                    printf("%2s%s%2s", "", modelItem[1], "");
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x05);
                    gotoxyWithFullwidth(17, 4);
                    printf("%2s%s%2s", "", modelItem[2], "");
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x05);
                    gotoxyWithFullwidth(24, 4);
                    printf("%2s%s%2s", "", modelItem[3], "");
                }
                break;// 按一个键后 退出循环 继续返回键值
            case 77:  // 下
                if (index2 == 1)
                {
                    index2 = 2;
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x05);
                    gotoxyWithFullwidth(3, 4);
                    printf("%2s%s%2s", "", modelItem[0], "");
                    SetConsoleTextAttribute(g_hConsoleOutput, 0xF0);
                    gotoxyWithFullwidth(10, 4);
                    printf("%2s%s%2s", "", modelItem[1], "");
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x05);
                    gotoxyWithFullwidth(17, 4);
                    printf("%2s%s%2s", "", modelItem[2], "");
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x05);
                    gotoxyWithFullwidth(24, 4);
                    printf("%2s%s%2s", "", modelItem[3], "");               
                }
                else if (index2 == 2)
                {
                    index2 = 3;
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x05);
                    gotoxyWithFullwidth(3, 4);
                    printf("%2s%s%2s", "", modelItem[0], "");
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x05);
                    gotoxyWithFullwidth(10, 4);
                    printf("%2s%s%2s", "", modelItem[1], "");
                    SetConsoleTextAttribute(g_hConsoleOutput, 0xF0);
                    gotoxyWithFullwidth(17, 4);
                    printf("%2s%s%2s", "", modelItem[2], "");
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x05);
                    gotoxyWithFullwidth(24, 4);
                    printf("%2s%s%2s", "", modelItem[3], "");
                    
                }
                else if (index2 ==3)
                {
                    index2 = 4;
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x05);
                    gotoxyWithFullwidth(3, 4);
                    printf("%2s%s%2s", "", modelItem[0], "");
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x05);
                    gotoxyWithFullwidth(10, 4);
                    printf("%2s%s%2s", "", modelItem[1], "");
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x05);
                    gotoxyWithFullwidth(17, 4);
                    printf("%2s%s%2s", "", modelItem[2], "");
                    SetConsoleTextAttribute(g_hConsoleOutput, 0xF0);
                    gotoxyWithFullwidth(24, 4);
                    printf("%2s%s%2s", "", modelItem[3], "");
                }
                else if (index2 ==4)
                {
                    index2 = 1;
                    SetConsoleTextAttribute(g_hConsoleOutput, 0xF0);
                    gotoxyWithFullwidth(3, 4);
                    printf("%2s%s%2s", "", modelItem[0], "");
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x05);
                    gotoxyWithFullwidth(10, 4);
                    printf("%2s%s%2s", "", modelItem[1], "");
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x05);
                    gotoxyWithFullwidth(17, 4);
                    printf("%2s%s%2s", "", modelItem[2], "");
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x05);
                    gotoxyWithFullwidth(24, 4);
                    printf("%2s%s%2s", "", modelItem[3], "");
                }
                break; // 按一个键后 退出循环 继续返回键值
            case 80:
                if (index2 == 1)
                    jia(a1,b1,c1); 
                else if (index2 == 2)
                    jian(a1,b1,c1);
                else if (index2 == 3)
                    cheng(a1,b1,c1);
                else if (index2 == 4)
                    chu(c1);
                break; 
            case 27:
                main();
        }
    } while (2);
}

int  rongyi()
{
    int a,b,c=0;
    
    srand(time(NULL));
    a = rand()%11;
    b = rand()%11;
    c = 1;
    mainMenutwo(a,b,c);
}

int  jiandan()
{
    int a,b,c=0;
    
    srand(time(NULL));
    a = rand()%101;
    b = rand()%101; 
    c = 2;
    mainMenutwo(a,b,c);
}

int  kunnan()
{
    int a,b,c=0;
    
    srand(time(NULL));
    a = rand()%201;
    b = rand()%201;  
    c = 3;
    mainMenutwo(a,b,c); 
}

int jia(int a2,int b2,int c2)
{
    int s;//存储计算后的结果
    int shuru;//输入的答案 

    cishu++;//计算答题次数 

    s = a2 + b2;//计算题目的答案

    yy++;//每道题在上一题的下面 坐标参数 

    x1++;//数组的下标 传给mainMenutwo函数 
    y1++;//数组的下标 传给mainMenutwo函数
    z1++;//数组的下标 传给mainMenutwo函数

    qian[x1]=a2;//将随机数给第一个数的X1 下标
    hou[y1]=b2;//将随机数给第二个数的Y1 下标

    SetConsoleTextAttribute(g_hConsoleOutput, 0x05);//出题 紫色
    gotoxyWithFullwidth(3, yy);
    printf("%d+%d=",a2,b2);

    scanf("%d",&shuru);//输入答案

    daan[z1]=shuru;//将答案给第三个数的 Z1 下标

    if (shuru == s)
    {
        defen++;//答对加分
        SetConsoleTextAttribute(g_hConsoleOutput, 0x02);//绿色
        gotoxyWithFullwidth(3, yy);//每道题在上一题的下面 坐标参数 
        printf("%d+%d=%d",a2,b2,shuru);

        if (c2==1)
            rongyi();
        else if (c2==2)
            jiandan();
        else if (c2==3)
            kunnan();
    }
    else 
    {
        SetConsoleTextAttribute(g_hConsoleOutput, 0x04);
        gotoxyWithFullwidth(3, yy);
        printf("%d+%d=%d",a2,b2,shuru);

        if (c2==1)
            rongyi();
        else if (c2==2)
            jiandan();
        else if (c2==3)
            kunnan();
    }
}

int jian(int a2,int b2,int c2)
{
    int s;
    int shuru;//输入的答案 

    cishu++;//计算答题次数

    s = a2 - b2;

    yy2++;

    x2++;
    y2++;
    z2++;

    qian2[x2]=a2;
    hou2[y2]=b2;

    SetConsoleTextAttribute(g_hConsoleOutput, 0x05);
    gotoxyWithFullwidth(10, yy2);
    printf("%d-%d=",a2,b2);

    scanf("%d",&shuru);

    daan2[z2]=shuru;

    if (shuru == s)
    {
        defen++;
        SetConsoleTextAttribute(g_hConsoleOutput, 0x02);
        gotoxyWithFullwidth(10, yy2);
        printf("%d-%d=%d",a2,b2,shuru);

        if (c2==1)
            rongyi();
        else if (c2==2)
            jiandan();
        else if (c2==3)
            kunnan();
    }
    else 
    {
        SetConsoleTextAttribute(g_hConsoleOutput, 0x04);
        gotoxyWithFullwidth(10, yy2);
        printf("%d-%d=%d",a2,b2,shuru);

        if (c2==1)
            rongyi();
        else if (c2==2)
            jiandan();
        else if (c2==3)
            kunnan();
    }
}

int cheng(int a2,int b2,int c2)
{
    int s;
    int shuru;//输入的答案 

    cishu++;//计算答题次数 

    s = a2 * b2;

    yy3++;

    x3++;
    y3++;
    z3++;

    qian3[x3]=a2;
    hou3[y3]=b2;

    SetConsoleTextAttribute(g_hConsoleOutput, 0x05);
    gotoxyWithFullwidth(17, yy3);
    printf("%d*%d=",a2,b2);

    scanf("%d",&shuru);

    daan3[z3]=shuru;

    if (shuru == s)
    {
        defen++;
        SetConsoleTextAttribute(g_hConsoleOutput, 0x02);
        gotoxyWithFullwidth(17, yy3);
        printf("%d*%d=%d",a2,b2,shuru);

        if (c2==1)
            rongyi();
        else if (c2==2)
            jiandan();
        else if (c2==3)
            kunnan();
    }
    else 
    {
        SetConsoleTextAttribute(g_hConsoleOutput, 0x04);
        gotoxyWithFullwidth(17, yy3);
        printf("%d*%d=%d",a2,b2,shuru);

        if (c2==1)
            rongyi();
        else if (c2==2)
            jiandan();
        else if (c2==3)
            kunnan();
    }
}

int chu(int c2)
{
    int  s;
    int  shuru;//输入的答案 
    int  a,b;//产生的随机数
    int  j;//在{2 3 4 5 6}中随机一个被除数
    int  suiji[5]={2,3,4,5,6};//被除数

    cishu++;//计算答题次数 
    
    srand(time(NULL));

    j = rand()%5;

    b=suiji[j];

    while(1)
    {
        a = rand()%100;
        if (a%b==0)
            break;
    }
    
    s =a / b;
    
    yy4++;

    x4++;
    y4++;
    z4++;

    qian4[x4]=a;
    hou4[y4]=b;

    SetConsoleTextAttribute(g_hConsoleOutput, 0x05);
    gotoxyWithFullwidth(24, yy4);
    printf("%d/%d=",a,b);

    scanf("%d",&shuru);

    daan4[z4]=shuru;

    if (shuru == s)
    {
        defen++;

        SetConsoleTextAttribute(g_hConsoleOutput, 0x02);
        gotoxyWithFullwidth(24, yy4);
        printf("%d/%d=%d",a,b,shuru);

        if (c2==1)
            rongyi();
        else if (c2==2)
            jiandan();
        else if (c2==3)
            kunnan();
    }
    else 
    {
        SetConsoleTextAttribute(g_hConsoleOutput, 0x04);
        gotoxyWithFullwidth(24, yy4);
        printf("%d/%d=%d",a,b,shuru);

        if (c2==1)
            rongyi();
        else if (c2==2)
            jiandan();
        else if (c2==3)
            kunnan();
    }
}
