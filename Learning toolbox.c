/********************************
 *           功能合集           *
 *                              *
 *  1. 电子词典                 *
 *  2. 通讯录                   *
 *  3. 答题系统                 *
 *------------------------------*
 * 版本号：   1.0.0             *
 * 修改日期： 2015/12/24        *
 *------------------------------*
 * 版本号：   1.1.2             *
 * 修改日期： 2015/12/28        *
 *------------------------------*
 *------------------------------*
/*******************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

struct Dictionary //定义电子词典的结构体名称
{
    char English[500];//声明 英语单词
    char Chinese[500];//声明 汉字

}leader[5]={"dictionary","词典","flushbonading","嵌入式","microsoft","微软","christmas","圣诞节","wujiayi","吴佳轶"};

HANDLE g_hConsoleOutput; // 控制台输出句柄

void gotoxyWithFullwidth(int x, int y); //定位到指定位置
void electronicDictionary();//电子词典
void addressList(); //通讯录
void exercisesSystem();//答题系统
void quit();//退出 
int  mainMenu();  // 主菜单

int main()//主函数
{
    CONSOLE_CURSOR_INFO cursorInfo = { 1, FALSE };  // 光标信息
    g_hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);  // 获取控制台输出句柄
    SetConsoleCursorInfo(g_hConsoleOutput, &cursorInfo);  // 设置光标隐藏
    
    int cheshi;//菜单项
    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
    cheshi = mainMenu();
    SetConsoleTextAttribute(g_hConsoleOutput, 0x07); //屏幕是黑色背景
    system("cls");//主菜单选择后 隐藏

    if (cheshi == 1)
    {
        electronicDictionary();//调用“电子词典”的函数
    }
    if (cheshi == 2)
    {
        addressList();//调用“通讯录”的函数
    }
    if (cheshi == 3)
    {
        exercisesSystem();//调用“答题系统”的函数
    }
    if (cheshi == 4)
    {
        quit();
    }
        system("pause");
}

void gotoxyWithFullwidth(int x, int y) //定义指定位置的参数
{
    static COORD cd;

    cd.X = (int)(x << 1);
    cd.Y = y;

    SetConsoleCursorPosition(g_hConsoleOutput, cd);
}

int mainMenu()//主菜单函数
{
    static const char *modelItem[] = { "1.电子词典", "2.通讯录  ", "3.答题系统","4.退  出  "}; //三个菜单项

    int index = 1, ch;
    int p=0;

    system("cls");//清除屏幕

    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F); //黑色背景 
    gotoxyWithFullwidth(15, 5); //定位输出（x,y）x=列;y=行;
    printf("┏━━━━━━━┓");
    gotoxyWithFullwidth(15, 6);
    printf("┃%2s%s%2s┃", "", "学习工具箱", "");
    gotoxyWithFullwidth(15, 7);
    printf("┗━━━━━━━┛");

    SetConsoleTextAttribute(g_hConsoleOutput, 0xF0); //白色背景
    gotoxyWithFullwidth(16, 12);
    printf("%2s%s%2s", "", modelItem[0], "");
    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
    gotoxyWithFullwidth(16, 14);
    printf("%2s%s%2s", "", modelItem[1], "");
    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
    gotoxyWithFullwidth(16, 16);
    printf("%2s%s%2s", "", modelItem[2], "");
    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
    gotoxyWithFullwidth(16, 18);
    printf("%2s%s%2s", "", modelItem[3], "");

    do
    {
        ch = _getch();
        switch (ch)
        {
            case 72:  // 上

                if (index == 3)
                {
                    index=2;

                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                    gotoxyWithFullwidth(16, 12);
                    printf("%2s%s%2s", "", modelItem[0], "");
                    SetConsoleTextAttribute(g_hConsoleOutput, 0xF0);
                    gotoxyWithFullwidth(16, 14);
                    printf("%2s%s%2s", "", modelItem[1], "");
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                    gotoxyWithFullwidth(16, 16);
                    printf("%2s%s%2s", "", modelItem[2], "");
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                    gotoxyWithFullwidth(16, 18);
                    printf("%2s%s%2s", "", modelItem[3], "");                
                }
                else if (index == 4)
                {
                    index = 3;

                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                    gotoxyWithFullwidth(16, 12);
                    printf("%2s%s%2s", "", modelItem[0], "");
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                    gotoxyWithFullwidth(16, 14);
                    printf("%2s%s%2s", "", modelItem[1], "");
                    SetConsoleTextAttribute(g_hConsoleOutput, 0xF0);
                    gotoxyWithFullwidth(16, 16);
                    printf("%2s%s%2s", "", modelItem[2], "");
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                    gotoxyWithFullwidth(16, 18);
                    printf("%2s%s%2s", "", modelItem[3], "");  
                }
                else if (index ==1)
                {
                    index = 4;

                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                    gotoxyWithFullwidth(16, 12);
                    printf("%2s%s%2s", "", modelItem[0], "");
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                    gotoxyWithFullwidth(16, 14);
                    printf("%2s%s%2s", "", modelItem[1], "");
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                    gotoxyWithFullwidth(16, 16);
                    printf("%2s%s%2s", "", modelItem[2], "");
                    SetConsoleTextAttribute(g_hConsoleOutput, 0xF0);
                    gotoxyWithFullwidth(16, 18);
                    printf("%2s%s%2s", "", modelItem[3], "");  
                }
                else if (index ==2)
                {
                    index = 1;

                    SetConsoleTextAttribute(g_hConsoleOutput, 0xF0);
                    gotoxyWithFullwidth(16, 12);
                    printf("%2s%s%2s", "", modelItem[0], "");
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                    gotoxyWithFullwidth(16, 14);
                    printf("%2s%s%2s", "", modelItem[1], "");
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                    gotoxyWithFullwidth(16, 16);
                    printf("%2s%s%2s", "", modelItem[2], "");
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                    gotoxyWithFullwidth(16, 18);
                    printf("%2s%s%2s", "", modelItem[3], "");
                }
                break;

            case 80:  // 下
                if (index == 1)
                {
                    index = 2;

                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                    gotoxyWithFullwidth(16, 12);
                    printf("%2s%s%2s", "", modelItem[0], "");
                    SetConsoleTextAttribute(g_hConsoleOutput, 0xF0);
                    gotoxyWithFullwidth(16, 14);
                    printf("%2s%s%2s", "", modelItem[1], "");
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                    gotoxyWithFullwidth(16, 16);
                    printf("%2s%s%2s", "", modelItem[2], "");
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                    gotoxyWithFullwidth(16, 18);
                    printf("%2s%s%2s", "", modelItem[3], "");               
                }
                else if (index == 2)
                {
                    index = 3;

                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                    gotoxyWithFullwidth(16, 12);
                    printf("%2s%s%2s", "", modelItem[0], "");
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                    gotoxyWithFullwidth(16, 14);
                    printf("%2s%s%2s", "", modelItem[1], "");
                    SetConsoleTextAttribute(g_hConsoleOutput, 0xF0);
                    gotoxyWithFullwidth(16, 16);
                    printf("%2s%s%2s", "", modelItem[2], "");
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                    gotoxyWithFullwidth(16, 18);
                    printf("%2s%s%2s", "", modelItem[3], "");
                }
                else if (index ==3)
                {
                    index = 4;

                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                    gotoxyWithFullwidth(16, 12);
                    printf("%2s%s%2s", "", modelItem[0], "");
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                    gotoxyWithFullwidth(16, 14);
                    printf("%2s%s%2s", "", modelItem[1], "");
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                    gotoxyWithFullwidth(16, 16);
                    printf("%2s%s%2s", "", modelItem[2], "");
                    SetConsoleTextAttribute(g_hConsoleOutput, 0xF0);
                    gotoxyWithFullwidth(16, 18);
                    printf("%2s%s%2s", "", modelItem[3], "");
                }
                else if (index ==4)
                {
                    index = 1;

                    SetConsoleTextAttribute(g_hConsoleOutput, 0xF0);
                    gotoxyWithFullwidth(16, 12);
                    printf("%2s%s%2s", "", modelItem[0], "");
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                    gotoxyWithFullwidth(16, 14);
                    printf("%2s%s%2s", "", modelItem[1], "");
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                    gotoxyWithFullwidth(16, 16);
                    printf("%2s%s%2s", "", modelItem[2], "");
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                    gotoxyWithFullwidth(16, 18);
                    printf("%2s%s%2s", "", modelItem[3], "");
                }
                break; 

            case 13:
                return index;
        }
    } while (2);
}

void electronicDictionary()//电子词典函数
{
    int i,j;//循环变量
    int ch;
    char ck[1][2]={"0"};
    char keywords[30];//输入的关键字
    char EnglishExtend[5][120]={"分为字典、词典、汉英词典、牛津词典等","科长经常对我们说","一家以生产处理器为主的公司","圣诞节类似中国的春节","学号：  154321030"};
    char EnglishExtend1[5][120]={"电子词典较为出名的是 有道 还有 必应 等等","电子学院是最最最 牛X 的专业没有之一","目前以个人PC以酷睿系列为优 服务器以至强系列为优","圣诞节在每年的12月25号","嵌入式151班一名程序猿"};
 
kaishi:

    system("cls");//清屏

    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
    gotoxyWithFullwidth(11, 2);
    printf("┏━━━━━━━━━━━━━━┓"); //电子词典标题
    gotoxyWithFullwidth(11, 3);
    printf("┃%10s%s%10s┃", "", "电子词典", "");
    gotoxyWithFullwidth(11, 4);
    printf("┃%3s%s%3s┃", "", "Electronic  Dictionary", "");
    gotoxyWithFullwidth(11, 5);
    printf("┗━━━━━━━━━━━━━━┛");

    printf("\n");
    printf("\n");    
    printf("                  ┏━━━━┳━━━━━━━━━━━━━┓\n");
    printf("                  ┃%s┃                          ┃\n","请输入：");//电子词典搜索框
    printf("                  ┗━━━━┻━━━━━━━━━━━━━┛\n"); 
    printf("\n");

    gotoxyWithFullwidth(15, 8);
    scanf("%s",keywords);
    
    for (i=0;i<=11;i++)
    {
        printf("\n");
    }

    if (strcmp(keywords,ck[0])==0)
    {
        main();
    }
    
        for (i=0;i<=4;i++)
        {
            if (strcmp(keywords,leader[i].Chinese)==0)
            {
                gotoxyWithFullwidth(10, 11);
                printf("%s",leader[i].English);
                gotoxyWithFullwidth(10, 13);
                printf("%s",EnglishExtend[i]);
                gotoxyWithFullwidth(10, 15);
                printf("%s",EnglishExtend1[i]);  
                          
                for (i=0;i<=5;i++)
                    printf("\n");

                break;
            }
        }

        for (i=0;i<=4;i++)
        {
            if (strcmp(keywords,leader[i].English)==0)
            {
                gotoxyWithFullwidth(10, 11);
                printf("%s",leader[i].Chinese);
                gotoxyWithFullwidth(10, 13);
                printf("%s",EnglishExtend[i]);
                gotoxyWithFullwidth(10, 15);
                printf("%s",EnglishExtend1[i]); 
                           
                for (i=0;i<=5;i++)
                    printf("\n");

                break;
            }
        }
        
    ch = _getch();

    if (ch==13)
        goto kaishi;

}

void addressList()//通讯录函数
{
    int i,j,cs=0;
    int k,p=0; 
    char s[10];
    // char sss[10][2][20] = {{"吴佳轶","18548141285"},{"张舒妤","15690849723"},{"朱坤亮","15247127110"},{"白  豹","18747883059"},{"王志军","15849380983"},{"郭  琪","15247156865"},{"盖伟达","15389755377"},{"石晓娜","18704887817"},{"王子航","18704867078"},{"王晓雨","18222067522"}};
    int cx,lenc=10,lenc2=0;

    char hao[20][2][20] = {{"吴佳轶","18548141285"},{"张舒妤","15690849723"},{"朱坤亮","15247127110"},{"白  豹","18747883059"},{"王志军","15849380983"},{"郭  琪","15247156865"},{"盖伟达","15389755377"},{"石晓娜","18704887817"},{"王子航","18704867078"},{"王晓雨","18222067522"},
    {"葛晓宇","15104823474"},{"庞玉影","15248512818"},{"王新松","15942161776"},{"张荣荣","15332829785"},{"王  鑫","15247172470"},{"王  宠","15649039062"},{"邵宇桐","15248252051"},{"孙  雪","18304865911"},{"安  瑞","18829213835"},{"李  静","15144901552"}};
/*  char hao1[2][20]={"吴佳轶","18548141285"};
    char hao2[2][20]={"张舒妤","15690849723"};
    char hao3[2][20]={"朱坤亮","15247127110"};
    char hao4[2][20]={"白豹","18747883059"};
    char hao5[2][20]={"王志军","15849380983"};
    char hao6[2][20]={"郭琪","15247156865"};   
    char hao7[2][20]={"盖伟达","15389755377"};
*/   

    /* 48 49 50 51 52 53 54 55 56 57 */
uuu:
    cs = 0;
    lenc= 20;
    lenc2=0;
    char sss[20][2][20] = {{"吴佳轶","18548141285"},{"张舒妤","15690849723"},{"朱坤亮","15247127110"},{"白  豹","18747883059"},{"王志军","15849380983"},{"郭  琪","15247156865"},{"盖伟达","15389755377"},{"石晓娜","18704887817"},{"王子航","18704867078"},{"王晓雨","18222067522"},
    {"葛晓宇","15104823474"},{"庞玉影","15248512818"},{"王新松","15942161776"},{"张荣荣","15332829785"},{"王  鑫","15247172470"},{"王  宠","15649039062"},{"邵宇桐","15248252051"},{"孙  雪","18304865911"},{"安  瑞","18829213835"},{"李  静","15144901552"}};
    
    memset(s,0*0,strlen(s));

    system("cls");
    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
    gotoxyWithFullwidth(9, 1 );
    printf("┏━━━┳━━━━━━━━━━━━━━┓\n");
    gotoxyWithFullwidth(9, 2 );
    printf("┃%s┃                            ┃\n","查询："); //通讯录搜索框
    gotoxyWithFullwidth(9, 3 );
    printf("┗━━━┻━━━━━━━━━━━━━━┛\n"); 
    gotoxyWithFullwidth(14, 5);
    printf("%s : %s",hao[0][0],hao[0][1]);
    gotoxyWithFullwidth(14, 6);
    printf("%s : %s",hao[1][0],hao[1][1]);
    gotoxyWithFullwidth(14, 7);
    printf("%s : %s",hao[2][0],hao[2][1]);
    gotoxyWithFullwidth(14, 8);
    printf("%s : %s",hao[3][0],hao[3][1]);
    gotoxyWithFullwidth(14, 9);
    printf("%s : %s",hao[4][0],hao[4][1]);
    gotoxyWithFullwidth(14, 10);
    printf("%s : %s",hao[5][0],hao[5][1]);
    gotoxyWithFullwidth(14, 11);
    printf("%s : %s",hao[6][0],hao[6][1]);  
    gotoxyWithFullwidth(14, 12);
    printf("%s : %s",hao[7][0],hao[7][1]);
    gotoxyWithFullwidth(14, 13);
    printf("%s : %s",hao[8][0],hao[8][1]);
    gotoxyWithFullwidth(14, 14);
    printf("%s : %s",hao[9][0],hao[9][1]);
    gotoxyWithFullwidth(14, 15);
    
    printf("%s : %s",hao[10][0],hao[10][1]);
    gotoxyWithFullwidth(14, 16);
    printf("%s : %s",hao[11][0],hao[11][1]);
    gotoxyWithFullwidth(14, 17);
    printf("%s : %s",hao[12][0],hao[12][1]);
    gotoxyWithFullwidth(14, 18);
    printf("%s : %s",hao[13][0],hao[13][1]);
    gotoxyWithFullwidth(14, 19);
    printf("%s : %s",hao[14][0],hao[14][1]);
    gotoxyWithFullwidth(14, 20);
    printf("%s : %s",hao[15][0],hao[15][1]);
    gotoxyWithFullwidth(14, 21);
    printf("%s : %s",hao[16][0],hao[16][1]);  
    gotoxyWithFullwidth(14, 22);
    printf("%s : %s",hao[17][0],hao[17][1]);
    gotoxyWithFullwidth(14, 23);
    printf("%s : %s",hao[18][0],hao[18][1]);
    gotoxyWithFullwidth(14, 24);
    printf("%s : %s",hao[19][0],hao[19][1]);
    do
    {
        cs++;
        cx = _getch();
            if (cx == 49)
            {
                p=0;
                lenc2=0;
                s[cs-1]='1';
                system("cls");
                    for (i=0;i<=lenc-1;i++)
                    {
                        if ('1'==sss[i][1][cs-1])
                        {
                            p++;
                            lenc2++;
                            gotoxyWithFullwidth(14, 4+p );
                            printf("%s : %s",sss[i][0],sss[i][1]);
                            strcpy(sss[lenc2-1][1],sss[i][1]);
                            strcpy(sss[lenc2-1][0],sss[i][0]);
                        }
                    }
                lenc = lenc2;
                SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                gotoxyWithFullwidth(9, 1 );
                printf("┏━━━┳━━━━━━━━━━━━━━┓\n");
                gotoxyWithFullwidth(9, 2 );
                printf("┃%s┃                            ┃\n","查询："); //通讯录搜索框
                gotoxyWithFullwidth(9, 3 );
                printf("┗━━━┻━━━━━━━━━━━━━━┛\n"); 
                gotoxyWithFullwidth(15, 2 );
                printf("%s",s);
            }
        
            else if (cx == 50)
            {
                p=0;
                lenc2=0;
                s[cs-1]='2';
                system("cls");
                    for(i=0;i<=lenc-1;i++)
                    {
                        if ('2'==sss[i][1][cs-1])
                        {
                            p++;
                            lenc2++;
                            gotoxyWithFullwidth(14, 4+p );
                            printf("%s : %s",sss[i][0],sss[i][1]);
                            strcpy(sss[lenc2-1][1],sss[i][1]);
                            strcpy(sss[lenc2-1][0],sss[i][0]);               
                        }
                    }
                lenc = lenc2;
                SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                gotoxyWithFullwidth(9, 1 );
                printf("┏━━━┳━━━━━━━━━━━━━━┓\n");
                gotoxyWithFullwidth(9, 2 );
                printf("┃%s┃                            ┃\n","查询："); //通讯录搜索框
                gotoxyWithFullwidth(9, 3 );
                printf("┗━━━┻━━━━━━━━━━━━━━┛\n"); 
                gotoxyWithFullwidth(15, 2 );
                printf("%s",s);
            }
     
            else if (cx == 51)
            {
                p=0;
                lenc2=0;
                s[cs-1]='3';
                system("cls");
                    for(i=0;i<=lenc-1;i++)
                    {
                        if ('3'==sss[i][1][cs-1])
                        {   
                            p++;
                            lenc2++;
                            gotoxyWithFullwidth(14, 4+p );
                            printf("%s : %s",sss[i][0],sss[i][1]);
                            strcpy(sss[lenc2-1][1],sss[i][1]);
                            strcpy(sss[lenc2-1][0],sss[i][0]);
                        }
                    }
                lenc = lenc2;
                SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                gotoxyWithFullwidth(9, 1 );
                printf("┏━━━┳━━━━━━━━━━━━━━┓\n");
                gotoxyWithFullwidth(9, 2 );
                printf("┃%s┃                            ┃\n","查询："); //通讯录搜索框
                gotoxyWithFullwidth(9, 3 );
                printf("┗━━━┻━━━━━━━━━━━━━━┛\n");
                gotoxyWithFullwidth(15, 2 );
                printf("%s",s); 
            }    
     
            else  if (cx == 52)
            {
                p=0;
                lenc2=0;
                s[cs-1]='4';
                system("cls");
                    for(i=0;i<=lenc-1;i++)
                    {
                        if ('4'==sss[i][1][cs-1])
                        {
                            p++;
                            lenc2++;
                            gotoxyWithFullwidth(14, 4+p );
                            printf("%s : %s",sss[i][0],sss[i][1]);
                            strcpy(sss[lenc2-1][1],sss[i][1]);
                            strcpy(sss[lenc2-1][0],sss[i][0]);
                        }
                    }
                lenc = lenc2;
                SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                gotoxyWithFullwidth(9, 1 );
                printf("┏━━━┳━━━━━━━━━━━━━━┓\n");
                gotoxyWithFullwidth(9, 2 );
                printf("┃%s┃                            ┃\n","查询："); //通讯录搜索框
                gotoxyWithFullwidth(9, 3 );
                printf("┗━━━┻━━━━━━━━━━━━━━┛\n"); 
                gotoxyWithFullwidth(15, 2 );
                printf("%s",s);
            }
     
            else  if (cx == 53)
            {
                p=0;
                lenc2=0;
                s[cs-1]='5';
                system("cls");
                    for(i=0;i<=lenc-1;i++)
                    {
                        if ('5'==sss[i][1][cs-1])
                        {
                            p++;
                            lenc2++;
                            gotoxyWithFullwidth(14, 4+p );
                            printf("%s : %s",sss[i][0],sss[i][1]);
                            strcpy(sss[lenc2-1][1],sss[i][1]);
                            strcpy(sss[lenc2-1][0],sss[i][0]);
                        }
                    }
                lenc = lenc2;
                SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                gotoxyWithFullwidth(9, 1 );
                printf("┏━━━┳━━━━━━━━━━━━━━┓\n");
                gotoxyWithFullwidth(9, 2 );
                printf("┃%s┃                            ┃\n","查询："); //通讯录搜索框
                gotoxyWithFullwidth(9, 3 );
                printf("┗━━━┻━━━━━━━━━━━━━━┛\n"); 
                gotoxyWithFullwidth(15, 2 );
                printf("%s",s);
            }

            else  if (cx == 54)
            {
                p=0;
                lenc2=0;
                s[cs-1]='6';
                system("cls");
                    for(i=0;i<=lenc-1;i++)
                    {
                        if ('6'==sss[i][1][cs-1])
                        {
                            p++;
                            lenc2++;
                            gotoxyWithFullwidth(14, 4+p );
                            printf("%s : %s",sss[i][0],sss[i][1]);
                            strcpy(sss[lenc2-1][1],sss[i][1]);
                            strcpy(sss[lenc2-1][0],sss[i][0]);
                        }
                    }
                lenc = lenc2;
                SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                gotoxyWithFullwidth(9, 1 );
                printf("┏━━━┳━━━━━━━━━━━━━━┓\n");
                gotoxyWithFullwidth(9, 2 );
                printf("┃%s┃                            ┃\n","查询："); //通讯录搜索框
                gotoxyWithFullwidth(9, 3 );
                printf("┗━━━┻━━━━━━━━━━━━━━┛\n"); 
                gotoxyWithFullwidth(15, 2 );
                printf("%s",s);
            }

            else  if (cx == 55)
            {
                p=0;
                lenc2=0;
                s[cs-1]='7';
                system("cls");
                    for(i=0;i<=lenc-1;i++)
                    {
                        if ('7'==sss[i][1][cs-1])
                        {
                            p++;
                            lenc2++;
                            gotoxyWithFullwidth(14, 4+p );
                            printf("%s : %s",sss[i][0],sss[i][1]);
                            strcpy(sss[lenc2-1][1],sss[i][1]);
                            strcpy(sss[lenc2-1][0],sss[i][0]);
                        }
                    }
                lenc = lenc2;
                SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                gotoxyWithFullwidth(9, 1 );
                printf("┏━━━┳━━━━━━━━━━━━━━┓\n");
                gotoxyWithFullwidth(9, 2 );
                printf("┃%s┃                            ┃\n","查询："); //通讯录搜索框
                gotoxyWithFullwidth(9, 3 );
                printf("┗━━━┻━━━━━━━━━━━━━━┛\n"); 
                gotoxyWithFullwidth(15, 2 );
                printf("%s",s);
            }

            else if (cx == 56)
            {
                p=0;
                lenc2=0;
                s[cs-1]='8';
                system("cls");
                    for(i=0;i<=lenc-1;i++)
                    {
                        if ('8'==sss[i][1][cs-1])
                        {
                            p++;
                            lenc2++;
                            gotoxyWithFullwidth(14, 4+p );
                            printf("%s : %s",sss[i][0],sss[i][1]);
                            strcpy(sss[lenc2-1][1],sss[i][1]);
                            strcpy(sss[lenc2-1][0],sss[i][0]);
                        }
                    }
                lenc = lenc2;
                SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                gotoxyWithFullwidth(9, 1 );
                printf("┏━━━┳━━━━━━━━━━━━━━┓\n");
                gotoxyWithFullwidth(9, 2 );
                printf("┃%s┃                            ┃\n","查询："); //通讯录搜索框
                gotoxyWithFullwidth(9, 3 );
                printf("┗━━━┻━━━━━━━━━━━━━━┛\n"); 
                gotoxyWithFullwidth(15, 2 );
                printf("%s",s);
            }

            else  if (cx == 57)
            {
                p=0;
                lenc2=0;
                s[cs-1]='9';
                system("cls");
                    for(i=0;i<=lenc-1;i++)
                    {
                        if ('9'==sss[i][1][cs-1])
                        {
                            p++;
                            lenc2++;
                            gotoxyWithFullwidth(14, 4+p );
                            printf("%s : %s",sss[i][0],sss[i][1]);
                            strcpy(sss[lenc2-1][1],sss[i][1]);
                            strcpy(sss[lenc2-1][0],sss[i][0]);
                        }
                    }
                lenc = lenc2;
                SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                gotoxyWithFullwidth(9, 1 );
                printf("┏━━━┳━━━━━━━━━━━━━━┓\n");
                gotoxyWithFullwidth(9, 2 );
                printf("┃%s┃                            ┃\n","查询："); //通讯录搜索框
                gotoxyWithFullwidth(9, 3 );
                printf("┗━━━┻━━━━━━━━━━━━━━┛\n"); 
                gotoxyWithFullwidth(15, 2 );
                printf("%s",s);
            }

            else  if (cx == 48)
            {
                p=0;
                lenc2=0;
                s[cs-1]='0';
                system("cls");
                    for(i=0;i<=lenc-1;i++)
                    {
                        if ('0'==sss[i][1][cs-1])
                        {
                            p++;
                            lenc2++;
                            gotoxyWithFullwidth(14, 4+p );
                            printf("%s : %s",sss[i][0],sss[i][1]);
                            strcpy(sss[lenc2-1][1],sss[i][1]);
                            strcpy(sss[lenc2-1][0],sss[i][0]);
                        }
                    }
                lenc = lenc2;
                SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                gotoxyWithFullwidth(9, 1 );
                printf("┏━━━┳━━━━━━━━━━━━━━┓\n");
                gotoxyWithFullwidth(9, 2 );
                printf("┃%s┃                            ┃\n","查询："); //通讯录搜索框
                gotoxyWithFullwidth(9, 3 );
                printf("┗━━━┻━━━━━━━━━━━━━━┛\n"); 
                gotoxyWithFullwidth(15, 2 );
                printf("%s",s);
            }

            else  if (cx == 13)
            {   
                goto uuu;
            }

            else  if (cx == 27)
            {
                system("cls");
                main();
            }     

    } while (1);    

        
        
    gotoxyWithFullwidth(15, 2);
    scanf("%d",&k);
    
    printf("\n");

    /*  for (i=0;i<=12;i++)
        {
            gotoxyWithFullwidth(0, i+4);
            printf("                  ║                                     ║\n");
        } 
    */

    for (i=0;i<=15;i++)
        printf("\n");
}

void exercisesSystem()
{
    int i,j,ch,chh;//循环变量
    int index=1,inde=0; 
    int fenshu=0,sum=0; 
    char duihuakuang[2][20]={"退  出","下一题"};
    char diyi[5][4][50]={{" A.这题有问题 "," B.比较坑 "," C.来吧，选我吧 "," D.翻滚吧，皮卡丘 "},{" A.还剩下1只 "," B.其他6只做目击证人 "," C.没鸟了 "," D.还剩俩猴 "},{" A.《冬天里的一把火》 "," B.《怪侠欧阳德》 "," C.《大城小爱》 "," D.《冬天的秘密》 "},{" A.乌龟 "," B.圆规 "," C.动物园园长说了算 "," D.大象 "},{" A.2月10号 "," B.2月9号 "," C.2月8号 "," D.2月7号 "}};

    
    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
    gotoxyWithFullwidth(11, 1);
    printf(" ┏━━━━━━━━━━━━━━┓"); //电子词典标题
    gotoxyWithFullwidth(11, 2);
    printf(" ┃%10s%s%10s┃", "", "答题系统", "");
    gotoxyWithFullwidth(11, 3);
    printf(" ┃%3s%s%3s┃", "", "     Wave  Survey     ", "");
    gotoxyWithFullwidth(11, 4);
    printf(" ┗━━━━━━━━━━━━━━┛");
    Sleep(500);
    
    gotoxyWithFullwidth(15, 6);    
    printf("  A");
    Sleep(60);
    gotoxyWithFullwidth(15, 6);
    printf("  Ar");
    Sleep(60);
    gotoxyWithFullwidth(15, 6); 
    printf("  Are");
    Sleep(60);
    gotoxyWithFullwidth(15, 6); 
    printf("  Are ");
    Sleep(60);
    gotoxyWithFullwidth(15, 6); 
    printf("  Are Y");
    Sleep(60);
    gotoxyWithFullwidth(15, 6); 
    printf("  Are Yo");
    Sleep(60);
    gotoxyWithFullwidth(15, 6); 
    printf("  Are You");
    Sleep(60);
    gotoxyWithFullwidth(15, 6); 
    printf("  Are You ");
    Sleep(60);
    gotoxyWithFullwidth(15, 6); 
    printf("  Are You R");
    Sleep(60);
    gotoxyWithFullwidth(15, 6); 
    printf("  Are You Re");
    Sleep(60);
    gotoxyWithFullwidth(15, 6); 
    printf("  Are You Rea");
    Sleep(60);
    gotoxyWithFullwidth(15, 6); 
    printf("  Are You Read");
    Sleep(60);
    gotoxyWithFullwidth(15, 6); 
    printf("  Are You Ready");
    Sleep(60);
    gotoxyWithFullwidth(15, 6); 
    printf("  Are You Ready?");    
    
    ch = _getch();

    if (ch==13)
    {
        for (i=0;i<=4;i++)
        {
            index=1;
            inde=0;

            SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
            gotoxyWithFullwidth(11, 1);
            printf(" ┏━━━━━━━━━━━━━━┓"); //电子词典标题
            gotoxyWithFullwidth(11, 2);
            printf(" ┃%10s%s%10s┃", "", "答题系统", "");
            gotoxyWithFullwidth(11, 3);
            printf(" ┃%3s%s%3s┃", "", "     Wave  Survey     ", "");
            gotoxyWithFullwidth(11, 4);
            printf(" ┗━━━━━━━━━━━━━━┛");
    
            printf("\n");    
            printf("          ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
            printf("          ┃                                                      ┃\n");
            printf("          ┃                                                      ┃\n");
            printf("          ┃                                                      ┃\n");
            printf("          ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n"); 
            printf("\n");

                if (i==0)
                {
                    gotoxyWithFullwidth(6, 6);
                    printf("第一题：【超纲题】 小明今年5岁，小明的哥哥今年10岁，");   
                    gotoxyWithFullwidth(6, 7);
                    printf("         小明妈妈今年,35岁，请问，太阳的质量是多少？");  
                    printf("\n");

                    SetConsoleTextAttribute(g_hConsoleOutput, 0xF0);
                    gotoxyWithFullwidth(6, 11);
                    printf("%s",diyi[0][0]);
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                    gotoxyWithFullwidth(20, 11);
                    printf("%s",diyi[0][1]);
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                    gotoxyWithFullwidth(6, 13);
                    printf("%s",diyi[0][2]);
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                    gotoxyWithFullwidth(20, 13);
                    printf("%s",diyi[0][3]);
                    printf("\n");
                }
                if (i==1)
                {
                    gotoxyWithFullwidth(6, 6);
                    printf("第二题：【脑筋急转弯】 树上有7只鸟，一名猎人开枪");   
                    gotoxyWithFullwidth(6, 7);
                    printf("         打死一只，请问，树上还有几只鸟 ？？ ");  
                    printf("\n");

                    SetConsoleTextAttribute(g_hConsoleOutput, 0xF0);
                    gotoxyWithFullwidth(6, 11);
                    printf("%s",diyi[1][0]);
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                    gotoxyWithFullwidth(20, 11);
                    printf("%s",diyi[1][1]);
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                    gotoxyWithFullwidth(6, 13);
                    printf("%s",diyi[1][2]);
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                    gotoxyWithFullwidth(20, 13);
                    printf("%s",diyi[1][3]);
                    printf("\n");
                }
                if (i==2)
                {
                    gotoxyWithFullwidth(6, 6);
                    printf("第三题： 【猜歌名】 歌词如下：我的眼泪为何流的痛彻心扉");   
                    gotoxyWithFullwidth(6, 7);
                    printf("    所有的期盼在你眼中成灰，月光下的箫声，吹得深沉醉？");  
                    printf("\n");

                    SetConsoleTextAttribute(g_hConsoleOutput, 0xF0);
                    gotoxyWithFullwidth(6, 11);
                    printf("%s",diyi[2][0]);
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                    gotoxyWithFullwidth(20, 11);
                    printf("%s",diyi[2][1]);
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                    gotoxyWithFullwidth(6, 13);
                    printf("%s",diyi[2][2]);
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                       gotoxyWithFullwidth(20, 13);
                   printf("%s",diyi[2][3]);
                         printf("\n");
                }
                if (i==3)
                {
                    gotoxyWithFullwidth(6, 6);
                    printf("第四题：【幽默搞笑】 家有家规，国有过规， ");   
                    gotoxyWithFullwidth(6, 7);
                    printf("         那动物园有什么规？？ ");  
                    printf("\n");

                    SetConsoleTextAttribute(g_hConsoleOutput, 0xF0);
                    gotoxyWithFullwidth(6, 11);
                    printf("%s",diyi[3][0]);
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                    gotoxyWithFullwidth(20, 11);
                    printf("%s",diyi[3][1]);
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                    gotoxyWithFullwidth(6, 13);
                    printf("%s",diyi[3][2]);
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                    gotoxyWithFullwidth(20, 13);
                    printf("%s",diyi[3][3]);
                    printf("\n");
                }
                if (i==4)
                {
                    gotoxyWithFullwidth(6, 6);
                    printf("第五题： 【生活常识】请问2016年的除夕是几月几号");   
                    gotoxyWithFullwidth(6, 7);
                    printf("         提前祝大家新年快乐，学业有成！！！  ");  
                    printf("\n");

                    SetConsoleTextAttribute(g_hConsoleOutput, 0xF0);
                    gotoxyWithFullwidth(6, 11);
                    printf("%s",diyi[4][0]);
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                    gotoxyWithFullwidth(20, 11);
                    printf("%s",diyi[4][1]);
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                    gotoxyWithFullwidth(6, 13);
                    printf("%s",diyi[4][2]);
                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                    gotoxyWithFullwidth(20, 13);
                    printf("%s",diyi[4][3]);
                    printf("\n");
                }

                do
                {
                    ch = _getch();

                        switch (ch)
                        {
                            case 75:  // you
                                if (index == 3)
                                {
                                    index=2;

                                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                                    gotoxyWithFullwidth(6, 11);
                                    printf("%s",diyi[i][0]);
                                    SetConsoleTextAttribute(g_hConsoleOutput, 0xF0);
                                    gotoxyWithFullwidth(20, 11);
                                    printf("%s",diyi[i][1]);
                                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                                    gotoxyWithFullwidth(6, 13);
                                    printf("%s",diyi[i][2]);
                                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                                    gotoxyWithFullwidth(20, 13);
                                    printf("%s",diyi[i][3]); 
                                }
                                else if (index ==4)
                                {
                                    index=3;

                                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                                    gotoxyWithFullwidth(6, 11);
                                    printf("%s",diyi[i][0]);
                                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                                    gotoxyWithFullwidth(20, 11);
                                    printf("%s",diyi[i][1]);
                                    SetConsoleTextAttribute(g_hConsoleOutput, 0xF0);
                                    gotoxyWithFullwidth(6, 13);
                                    printf("%s",diyi[i][2]);
                                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                                    gotoxyWithFullwidth(20, 13);
                                    printf("%s",diyi[i][3]); 
                                }
                                else if (index ==1)
                                {
                                    index=4;

                                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                                    gotoxyWithFullwidth(6, 11);
                                    printf("%s",diyi[i][0]);
                                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                                    gotoxyWithFullwidth(20, 11);
                                    printf("%s",diyi[i][1]);
                                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                                    gotoxyWithFullwidth(6, 13);
                                    printf("%s",diyi[i][2]);
                                    SetConsoleTextAttribute(g_hConsoleOutput, 0xF0);
                                    gotoxyWithFullwidth(20, 13);
                                    printf("%s",diyi[i][3]); 
                                }
                                else if (index == 2)
                                {
                                    index=1;

                                    SetConsoleTextAttribute(g_hConsoleOutput, 0xF0);
                                    gotoxyWithFullwidth(6, 11);
                                    printf("%s",diyi[i][0]);
                                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                                    gotoxyWithFullwidth(20, 11);
                                    printf("%s",diyi[i][1]);
                                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                                    gotoxyWithFullwidth(6, 13);
                                    printf("%s",diyi[i][2]);
                                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                                    gotoxyWithFullwidth(20, 13);
                                    printf("%s",diyi[i][3]);                              
                                }   
                                    break;

                            case 77:  //zuo
                                if (index == 1)
                                {
                                    index=2;

                                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                                    gotoxyWithFullwidth(6, 11);
                                    printf("%s",diyi[i][0]);
                                    SetConsoleTextAttribute(g_hConsoleOutput, 0xF0);
                                    gotoxyWithFullwidth(20, 11);
                                    printf("%s",diyi[i][1]);
                                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                                    gotoxyWithFullwidth(6, 13);
                                    printf("%s",diyi[i][2]);
                                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                                    gotoxyWithFullwidth(20, 13);
                                    printf("%s",diyi[i][3]); 
                                }
                                else if (index ==2)
                                {
                                    index=3;

                                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                                    gotoxyWithFullwidth(6, 11);
                                    printf("%s",diyi[i][0]);
                                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                                    gotoxyWithFullwidth(20, 11);
                                    printf("%s",diyi[i][1]);
                                    SetConsoleTextAttribute(g_hConsoleOutput, 0xF0);
                                    gotoxyWithFullwidth(6, 13);
                                    printf("%s",diyi[i][2]);
                                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                                    gotoxyWithFullwidth(20, 13);
                                    printf("%s",diyi[i][3]); 
                                }
                                else if (index ==3)
                                {
                                    index=4;

                                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                                    gotoxyWithFullwidth(6, 11);
                                    printf("%s",diyi[i][0]);
                                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                                    gotoxyWithFullwidth(20, 11);
                                    printf("%s",diyi[i][1]);
                                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                                    gotoxyWithFullwidth(6, 13);
                                    printf("%s",diyi[i][2]);
                                    SetConsoleTextAttribute(g_hConsoleOutput, 0xF0);
                                    gotoxyWithFullwidth(20, 13);
                                    printf("%s",diyi[i][3]); 
                                }
                                else if (index == 4)
                                {               
                                    index=1;

                                    SetConsoleTextAttribute(g_hConsoleOutput, 0xF0);
                                    gotoxyWithFullwidth(6, 11);
                                    printf("%s",diyi[i][0]);
                                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                                    gotoxyWithFullwidth(20, 11);
                                    printf("%s",diyi[i][1]);
                                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                                    gotoxyWithFullwidth(6, 13);
                                    printf("%s",diyi[i][2]);
                                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                                    gotoxyWithFullwidth(20, 13);
                                    printf("%s",diyi[i][3]);                                 
                                }               
                                    break; 

                            case 13:
                                if (i==0 && index == 4 || i==1 &&index == 3  ||i==2 && index == 2 || i==3 &&index == 1 || i==4 &&index == 4 )
                                {      
                                    fenshu++;   

                                    SetConsoleTextAttribute(g_hConsoleOutput, 0xF0);     
                                    gotoxyWithFullwidth(11, 8); 
                                    printf("┏━━━━━━━━━━━━━━┓"); //电子词典标题
                                    SetConsoleTextAttribute(g_hConsoleOutput, 0xF0); 
                                    gotoxyWithFullwidth(11, 9);
                                    printf("┃        恭喜你，答对了！    ┃");
                                    SetConsoleTextAttribute(g_hConsoleOutput, 0xF0); 
                                    gotoxyWithFullwidth(11, 10);
                                    printf("┃         Good for you       ┃");
                                    SetConsoleTextAttribute(g_hConsoleOutput, 0xF0); 
                                    gotoxyWithFullwidth(11, 11);
                                    printf("┃                            ┃");
                                    SetConsoleTextAttribute(g_hConsoleOutput, 0xF0); 
                                    gotoxyWithFullwidth(11, 12);
                                    printf("┗━━━━━━━━━━━━━━┛");
                                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                                    gotoxyWithFullwidth(15, 11);
                                    printf("%s",duihuakuang[0]); 
                                    SetConsoleTextAttribute(g_hConsoleOutput, 0xF0);
                                    gotoxyWithFullwidth(21, 11);
                                    printf("%s",duihuakuang[1]); 
                    
                                    do
                                    {
                                        chh = _getch();
                                            switch (chh)
                                            {
                                                case 75:  // 左
                                                case 77:  // 右

                                                    if (inde == 1)
                                                    {
                                                        inde = 0;

                                                        SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                                                        gotoxyWithFullwidth(15, 11);
                                                        printf("%s",duihuakuang[0]); 
                                                        SetConsoleTextAttribute(g_hConsoleOutput, 0xF0);
                                                        gotoxyWithFullwidth(21, 11);
                                                        printf("%s",duihuakuang[1]); 
                                                    }
                                                    else if (inde == 0)
                                                    {
                                                        inde = 1;

                                                        SetConsoleTextAttribute(g_hConsoleOutput, 0xF0);
                                                        gotoxyWithFullwidth(15, 11);
                                                        printf("%s",duihuakuang[0]); 
                                                        SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                                                        gotoxyWithFullwidth(21, 11);
                                                        printf("%s",duihuakuang[1]); 
                                                    }
                                                    break;

                                                case 13:
                                                    if (inde==0)
                                                    { 
                                                        SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                                                        main();
                                                    } 
                                                    if (inde==1) 
                                                    {
                                                        goto kaishi;
                                                    }
        
                                            }
                                    } while (1);

                                }
                                else 
                                {
                                    SetConsoleTextAttribute(g_hConsoleOutput, 0xF0);     
                                    gotoxyWithFullwidth(11, 8); 
                                    printf("┏━━━━━━━━━━━━━━┓"); //电子词典标题
                                    SetConsoleTextAttribute(g_hConsoleOutput, 0xF0); 
                                    gotoxyWithFullwidth(11, 9);
                                    printf("┃      不好意思，您答错了！  ┃");
                                    SetConsoleTextAttribute(g_hConsoleOutput, 0xF0); 
                                    gotoxyWithFullwidth(11, 10);
                                    printf("┃         Sorry, wrong!      ┃");
                                    SetConsoleTextAttribute(g_hConsoleOutput, 0xF0); 
                                    gotoxyWithFullwidth(11, 11);
                                    printf("┃                            ┃");
                                    SetConsoleTextAttribute(g_hConsoleOutput, 0xF0); 
                                    gotoxyWithFullwidth(11, 12);
                                    printf("┗━━━━━━━━━━━━━━┛");
                                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                                    gotoxyWithFullwidth(15, 11);
                                    printf("%s",duihuakuang[0]); 
                                    SetConsoleTextAttribute(g_hConsoleOutput, 0xF0);
                                    gotoxyWithFullwidth(21, 11);
                                    printf("%s",duihuakuang[1]); 
                    
                                    do
                                    {
                                        chh = _getch();

                                        switch (chh)
                                        {
                                            case 75:  // 左
                                            case 77:  // 右

                                                if (inde == 1)
                                                {
                                                    inde = 0;

                                                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                                                    gotoxyWithFullwidth(15, 11);
                                                    printf("%s",duihuakuang[0]); 
                                                    SetConsoleTextAttribute(g_hConsoleOutput, 0xF0);
                                                    gotoxyWithFullwidth(21, 11);
                                                    printf("%s",duihuakuang[1]); 
                                                }
                                                else if (inde ==0)
                                                {
                                                    inde = 1;

                                                    SetConsoleTextAttribute(g_hConsoleOutput, 0xF0);
                                                    gotoxyWithFullwidth(15, 11);
                                                    printf("%s",duihuakuang[0]); 
                                                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                                                    gotoxyWithFullwidth(21, 11);
                                                    printf("%s",duihuakuang[1]); 
                                                }
                                                    break;

                                            case 13:
                                                if (inde==0)
                                                { 
                                                    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                                                    main();
                                                } 
                                                if (inde==1) 
                                                {
                                                    goto kaishi;
                                                }
                                        }
                                    } while (1);
                                } 
                        }
                } while (1);
            kaishi:

            system("cls");
        }

        if (i==5)
        {
            system("cls");

            sum=fenshu*20; 

            SetConsoleTextAttribute(g_hConsoleOutput, 0xF0);     
            gotoxyWithFullwidth(11, 8); 
            printf("┏━━━━━━━━━━━━━━┓"); //电子词典标题
            SetConsoleTextAttribute(g_hConsoleOutput, 0xF0); 
            gotoxyWithFullwidth(11, 9);
            printf("┃                            ┃");
            SetConsoleTextAttribute(g_hConsoleOutput, 0xF0); 
            gotoxyWithFullwidth(11, 10);
            printf("┃                            ┃");
            SetConsoleTextAttribute(g_hConsoleOutput, 0xF0); 
            gotoxyWithFullwidth(11, 11);
            printf("┃                            ┃");
            SetConsoleTextAttribute(g_hConsoleOutput, 0xF0); 
            gotoxyWithFullwidth(11, 12);
            printf("┗━━━━━━━━━━━━━━┛");
            
            gotoxyWithFullwidth(15, 9);
            printf("您一共答对了%d道题",fenshu); 
            gotoxyWithFullwidth(17, 10);
            printf("得分：%d",sum); 
            
            SetConsoleTextAttribute(g_hConsoleOutput, 0xF0);
            gotoxyWithFullwidth(16, 11);
            printf("退出答题系统 "); 
                    
            chh = _getch();

            if (chh==13)
            {
                SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
                main();
            }
        } 
    }
}

void quit()
{
    exit(0); 
} 

