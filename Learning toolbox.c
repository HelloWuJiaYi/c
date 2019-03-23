/********************************
 *           ���ܺϼ�           *
 *                              *
 *  1. ���Ӵʵ�                 *
 *  2. ͨѶ¼                   *
 *  3. ����ϵͳ                 *
 *------------------------------*
 * �汾�ţ�   1.0.0             *
 * �޸����ڣ� 2015/12/24        *
 *------------------------------*
 * �汾�ţ�   1.1.2             *
 * �޸����ڣ� 2015/12/28        *
 *------------------------------*
 *------------------------------*
/*******************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

struct Dictionary //������Ӵʵ�Ľṹ������
{
    char English[500];//���� Ӣ�ﵥ��
    char Chinese[500];//���� ����

}leader[5]={"dictionary","�ʵ�","flushbonading","Ƕ��ʽ","microsoft","΢��","christmas","ʥ����","wujiayi","�����"};

HANDLE g_hConsoleOutput; // ����̨������

void gotoxyWithFullwidth(int x, int y); //��λ��ָ��λ��
void electronicDictionary();//���Ӵʵ�
void addressList(); //ͨѶ¼
void exercisesSystem();//����ϵͳ
void quit();//�˳� 
int  mainMenu();  // ���˵�

int main()//������
{
    CONSOLE_CURSOR_INFO cursorInfo = { 1, FALSE };  // �����Ϣ
    g_hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);  // ��ȡ����̨������
    SetConsoleCursorInfo(g_hConsoleOutput, &cursorInfo);  // ���ù������
    
    int cheshi;//�˵���
    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
    cheshi = mainMenu();
    SetConsoleTextAttribute(g_hConsoleOutput, 0x07); //��Ļ�Ǻ�ɫ����
    system("cls");//���˵�ѡ��� ����

    if (cheshi == 1)
    {
        electronicDictionary();//���á����Ӵʵ䡱�ĺ���
    }
    if (cheshi == 2)
    {
        addressList();//���á�ͨѶ¼���ĺ���
    }
    if (cheshi == 3)
    {
        exercisesSystem();//���á�����ϵͳ���ĺ���
    }
    if (cheshi == 4)
    {
        quit();
    }
        system("pause");
}

void gotoxyWithFullwidth(int x, int y) //����ָ��λ�õĲ���
{
    static COORD cd;

    cd.X = (int)(x << 1);
    cd.Y = y;

    SetConsoleCursorPosition(g_hConsoleOutput, cd);
}

int mainMenu()//���˵�����
{
    static const char *modelItem[] = { "1.���Ӵʵ�", "2.ͨѶ¼  ", "3.����ϵͳ","4.��  ��  "}; //�����˵���

    int index = 1, ch;
    int p=0;

    system("cls");//�����Ļ

    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F); //��ɫ���� 
    gotoxyWithFullwidth(15, 5); //��λ�����x,y��x=��;y=��;
    printf("������������������");
    gotoxyWithFullwidth(15, 6);
    printf("��%2s%s%2s��", "", "ѧϰ������", "");
    gotoxyWithFullwidth(15, 7);
    printf("������������������");

    SetConsoleTextAttribute(g_hConsoleOutput, 0xF0); //��ɫ����
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
            case 72:  // ��

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

            case 80:  // ��
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

void electronicDictionary()//���Ӵʵ亯��
{
    int i,j;//ѭ������
    int ch;
    char ck[1][2]={"0"};
    char keywords[30];//����Ĺؼ���
    char EnglishExtend[5][120]={"��Ϊ�ֵ䡢�ʵ䡢��Ӣ�ʵ䡢ţ��ʵ��","�Ƴ�����������˵","һ��������������Ϊ���Ĺ�˾","ʥ���������й��Ĵ���","ѧ�ţ�  154321030"};
    char EnglishExtend1[5][120]={"���Ӵʵ��Ϊ�������� �е� ���� ��Ӧ �ȵ�","����ѧԺ�������� ţX ��רҵû��֮һ","Ŀǰ�Ը���PC�Կ��ϵ��Ϊ�� ����������ǿϵ��Ϊ��","ʥ������ÿ���12��25��","Ƕ��ʽ151��һ������Գ"};
 
kaishi:

    system("cls");//����

    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
    gotoxyWithFullwidth(11, 2);
    printf("��������������������������������"); //���Ӵʵ����
    gotoxyWithFullwidth(11, 3);
    printf("��%10s%s%10s��", "", "���Ӵʵ�", "");
    gotoxyWithFullwidth(11, 4);
    printf("��%3s%s%3s��", "", "Electronic  Dictionary", "");
    gotoxyWithFullwidth(11, 5);
    printf("��������������������������������");

    printf("\n");
    printf("\n");    
    printf("                  �����������ש���������������������������\n");
    printf("                  ��%s��                          ��\n","�����룺");//���Ӵʵ�������
    printf("                  �����������ߩ���������������������������\n"); 
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

void addressList()//ͨѶ¼����
{
    int i,j,cs=0;
    int k,p=0; 
    char s[10];
    // char sss[10][2][20] = {{"�����","18548141285"},{"�����","15690849723"},{"������","15247127110"},{"��  ��","18747883059"},{"��־��","15849380983"},{"��  ��","15247156865"},{"��ΰ��","15389755377"},{"ʯ����","18704887817"},{"���Ӻ�","18704867078"},{"������","18222067522"}};
    int cx,lenc=10,lenc2=0;

    char hao[20][2][20] = {{"�����","18548141285"},{"�����","15690849723"},{"������","15247127110"},{"��  ��","18747883059"},{"��־��","15849380983"},{"��  ��","15247156865"},{"��ΰ��","15389755377"},{"ʯ����","18704887817"},{"���Ӻ�","18704867078"},{"������","18222067522"},
    {"������","15104823474"},{"����Ӱ","15248512818"},{"������","15942161776"},{"������","15332829785"},{"��  ��","15247172470"},{"��  ��","15649039062"},{"����ͩ","15248252051"},{"��  ѩ","18304865911"},{"��  ��","18829213835"},{"��  ��","15144901552"}};
/*  char hao1[2][20]={"�����","18548141285"};
    char hao2[2][20]={"�����","15690849723"};
    char hao3[2][20]={"������","15247127110"};
    char hao4[2][20]={"�ױ�","18747883059"};
    char hao5[2][20]={"��־��","15849380983"};
    char hao6[2][20]={"����","15247156865"};   
    char hao7[2][20]={"��ΰ��","15389755377"};
*/   

    /* 48 49 50 51 52 53 54 55 56 57 */
uuu:
    cs = 0;
    lenc= 20;
    lenc2=0;
    char sss[20][2][20] = {{"�����","18548141285"},{"�����","15690849723"},{"������","15247127110"},{"��  ��","18747883059"},{"��־��","15849380983"},{"��  ��","15247156865"},{"��ΰ��","15389755377"},{"ʯ����","18704887817"},{"���Ӻ�","18704867078"},{"������","18222067522"},
    {"������","15104823474"},{"����Ӱ","15248512818"},{"������","15942161776"},{"������","15332829785"},{"��  ��","15247172470"},{"��  ��","15649039062"},{"����ͩ","15248252051"},{"��  ѩ","18304865911"},{"��  ��","18829213835"},{"��  ��","15144901552"}};
    
    memset(s,0*0,strlen(s));

    system("cls");
    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
    gotoxyWithFullwidth(9, 1 );
    printf("���������ש�����������������������������\n");
    gotoxyWithFullwidth(9, 2 );
    printf("��%s��                            ��\n","��ѯ��"); //ͨѶ¼������
    gotoxyWithFullwidth(9, 3 );
    printf("���������ߩ�����������������������������\n"); 
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
                printf("���������ש�����������������������������\n");
                gotoxyWithFullwidth(9, 2 );
                printf("��%s��                            ��\n","��ѯ��"); //ͨѶ¼������
                gotoxyWithFullwidth(9, 3 );
                printf("���������ߩ�����������������������������\n"); 
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
                printf("���������ש�����������������������������\n");
                gotoxyWithFullwidth(9, 2 );
                printf("��%s��                            ��\n","��ѯ��"); //ͨѶ¼������
                gotoxyWithFullwidth(9, 3 );
                printf("���������ߩ�����������������������������\n"); 
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
                printf("���������ש�����������������������������\n");
                gotoxyWithFullwidth(9, 2 );
                printf("��%s��                            ��\n","��ѯ��"); //ͨѶ¼������
                gotoxyWithFullwidth(9, 3 );
                printf("���������ߩ�����������������������������\n");
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
                printf("���������ש�����������������������������\n");
                gotoxyWithFullwidth(9, 2 );
                printf("��%s��                            ��\n","��ѯ��"); //ͨѶ¼������
                gotoxyWithFullwidth(9, 3 );
                printf("���������ߩ�����������������������������\n"); 
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
                printf("���������ש�����������������������������\n");
                gotoxyWithFullwidth(9, 2 );
                printf("��%s��                            ��\n","��ѯ��"); //ͨѶ¼������
                gotoxyWithFullwidth(9, 3 );
                printf("���������ߩ�����������������������������\n"); 
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
                printf("���������ש�����������������������������\n");
                gotoxyWithFullwidth(9, 2 );
                printf("��%s��                            ��\n","��ѯ��"); //ͨѶ¼������
                gotoxyWithFullwidth(9, 3 );
                printf("���������ߩ�����������������������������\n"); 
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
                printf("���������ש�����������������������������\n");
                gotoxyWithFullwidth(9, 2 );
                printf("��%s��                            ��\n","��ѯ��"); //ͨѶ¼������
                gotoxyWithFullwidth(9, 3 );
                printf("���������ߩ�����������������������������\n"); 
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
                printf("���������ש�����������������������������\n");
                gotoxyWithFullwidth(9, 2 );
                printf("��%s��                            ��\n","��ѯ��"); //ͨѶ¼������
                gotoxyWithFullwidth(9, 3 );
                printf("���������ߩ�����������������������������\n"); 
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
                printf("���������ש�����������������������������\n");
                gotoxyWithFullwidth(9, 2 );
                printf("��%s��                            ��\n","��ѯ��"); //ͨѶ¼������
                gotoxyWithFullwidth(9, 3 );
                printf("���������ߩ�����������������������������\n"); 
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
                printf("���������ש�����������������������������\n");
                gotoxyWithFullwidth(9, 2 );
                printf("��%s��                            ��\n","��ѯ��"); //ͨѶ¼������
                gotoxyWithFullwidth(9, 3 );
                printf("���������ߩ�����������������������������\n"); 
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
            printf("                  �U                                     �U\n");
        } 
    */

    for (i=0;i<=15;i++)
        printf("\n");
}

void exercisesSystem()
{
    int i,j,ch,chh;//ѭ������
    int index=1,inde=0; 
    int fenshu=0,sum=0; 
    char duihuakuang[2][20]={"��  ��","��һ��"};
    char diyi[5][4][50]={{" A.���������� "," B.�ȽϿ� "," C.���ɣ�ѡ�Ұ� "," D.�����ɣ�Ƥ���� "},{" A.��ʣ��1ֻ "," B.����6ֻ��Ŀ��֤�� "," C.û���� "," D.��ʣ���� "},{" A.���������һ�ѻ� "," B.������ŷ���¡� "," C.�����С���� "," D.����������ܡ� "},{" A.�ڹ� "," B.Բ�� "," C.����԰԰��˵���� "," D.���� "},{" A.2��10�� "," B.2��9�� "," C.2��8�� "," D.2��7�� "}};

    
    SetConsoleTextAttribute(g_hConsoleOutput, 0x0F);
    gotoxyWithFullwidth(11, 1);
    printf(" ��������������������������������"); //���Ӵʵ����
    gotoxyWithFullwidth(11, 2);
    printf(" ��%10s%s%10s��", "", "����ϵͳ", "");
    gotoxyWithFullwidth(11, 3);
    printf(" ��%3s%s%3s��", "", "     Wave  Survey     ", "");
    gotoxyWithFullwidth(11, 4);
    printf(" ��������������������������������");
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
            printf(" ��������������������������������"); //���Ӵʵ����
            gotoxyWithFullwidth(11, 2);
            printf(" ��%10s%s%10s��", "", "����ϵͳ", "");
            gotoxyWithFullwidth(11, 3);
            printf(" ��%3s%s%3s��", "", "     Wave  Survey     ", "");
            gotoxyWithFullwidth(11, 4);
            printf(" ��������������������������������");
    
            printf("\n");    
            printf("          ����������������������������������������������������������\n");
            printf("          ��                                                      ��\n");
            printf("          ��                                                      ��\n");
            printf("          ��                                                      ��\n");
            printf("          ����������������������������������������������������������\n"); 
            printf("\n");

                if (i==0)
                {
                    gotoxyWithFullwidth(6, 6);
                    printf("��һ�⣺�������⡿ С������5�꣬С���ĸ�����10�꣬");   
                    gotoxyWithFullwidth(6, 7);
                    printf("         С���������,35�꣬���ʣ�̫���������Ƕ��٣�");  
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
                    printf("�ڶ��⣺���Խת�䡿 ������7ֻ��һ�����˿�ǹ");   
                    gotoxyWithFullwidth(6, 7);
                    printf("         ����һֻ�����ʣ����ϻ��м�ֻ�� ���� ");  
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
                    printf("�����⣺ ���¸����� ������£��ҵ�����Ϊ������ʹ������");   
                    gotoxyWithFullwidth(6, 7);
                    printf("    ���е������������гɻң��¹��µ����������������");  
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
                    printf("�����⣺����Ĭ��Ц�� ���мҹ棬���й��棬 ");   
                    gotoxyWithFullwidth(6, 7);
                    printf("         �Ƕ���԰��ʲô�棿�� ");  
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
                    printf("�����⣺ �����ʶ������2016��ĳ�Ϧ�Ǽ��¼���");   
                    gotoxyWithFullwidth(6, 7);
                    printf("         ��ǰף���������֣�ѧҵ�гɣ�����  ");  
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
                                    printf("��������������������������������"); //���Ӵʵ����
                                    SetConsoleTextAttribute(g_hConsoleOutput, 0xF0); 
                                    gotoxyWithFullwidth(11, 9);
                                    printf("��        ��ϲ�㣬����ˣ�    ��");
                                    SetConsoleTextAttribute(g_hConsoleOutput, 0xF0); 
                                    gotoxyWithFullwidth(11, 10);
                                    printf("��         Good for you       ��");
                                    SetConsoleTextAttribute(g_hConsoleOutput, 0xF0); 
                                    gotoxyWithFullwidth(11, 11);
                                    printf("��                            ��");
                                    SetConsoleTextAttribute(g_hConsoleOutput, 0xF0); 
                                    gotoxyWithFullwidth(11, 12);
                                    printf("��������������������������������");
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
                                                case 75:  // ��
                                                case 77:  // ��

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
                                    printf("��������������������������������"); //���Ӵʵ����
                                    SetConsoleTextAttribute(g_hConsoleOutput, 0xF0); 
                                    gotoxyWithFullwidth(11, 9);
                                    printf("��      ������˼��������ˣ�  ��");
                                    SetConsoleTextAttribute(g_hConsoleOutput, 0xF0); 
                                    gotoxyWithFullwidth(11, 10);
                                    printf("��         Sorry, wrong!      ��");
                                    SetConsoleTextAttribute(g_hConsoleOutput, 0xF0); 
                                    gotoxyWithFullwidth(11, 11);
                                    printf("��                            ��");
                                    SetConsoleTextAttribute(g_hConsoleOutput, 0xF0); 
                                    gotoxyWithFullwidth(11, 12);
                                    printf("��������������������������������");
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
                                            case 75:  // ��
                                            case 77:  // ��

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
            printf("��������������������������������"); //���Ӵʵ����
            SetConsoleTextAttribute(g_hConsoleOutput, 0xF0); 
            gotoxyWithFullwidth(11, 9);
            printf("��                            ��");
            SetConsoleTextAttribute(g_hConsoleOutput, 0xF0); 
            gotoxyWithFullwidth(11, 10);
            printf("��                            ��");
            SetConsoleTextAttribute(g_hConsoleOutput, 0xF0); 
            gotoxyWithFullwidth(11, 11);
            printf("��                            ��");
            SetConsoleTextAttribute(g_hConsoleOutput, 0xF0); 
            gotoxyWithFullwidth(11, 12);
            printf("��������������������������������");
            
            gotoxyWithFullwidth(15, 9);
            printf("��һ�������%d����",fenshu); 
            gotoxyWithFullwidth(17, 10);
            printf("�÷֣�%d",sum); 
            
            SetConsoleTextAttribute(g_hConsoleOutput, 0xF0);
            gotoxyWithFullwidth(16, 11);
            printf("�˳�����ϵͳ "); 
                    
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

