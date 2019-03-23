#include <stdio.h>    // 标准的输入输出头文件
#include <windows.h>  // 控制时间停留
#include <stdlib.h>
#include "string.h"   //控制字符数组
main()
{
	int diyi[7],dier[7],disan[7],disi[7],diwu[7],diliu[7];         					//存放排序后的各科成绩
	int diyi1[7],dier1[7],disan1[7],disi1[7],diwu1[7],diliu1[7];   					//存放排序前的各科成绩 
	int i,j,k;         										      				    // 循环变量 
	int t;                            							  	 				//排序暂存变量
	int caidan,fanhuicaidan;          							   					//主菜单变量   次菜单变量（返回主菜单）
	int tianjia;         							               					//添加成绩的位置变量  
	char CZguanjianzi1[1][8],CZguanjianzi2[1][12];                 					//查找关键字 （姓名）     查找关键字 （科目）
	char xingming[6][8]={" "," "," "," "," "," "};                 					//存放学生的姓名   
	char kemu[7][12]={"英语","C语言","电路基础","计算机文化","体育","思修"};   // 存放默认排序科目 
	char kemu1[7][12],shanchu[1][12];                                				//存放排序后的科目   存放删除的科目变量
	
	//--------------------------------------------------------------------------------------------------------------------------
	// 第一部分  启动本系统的界面  

    printf("\n");
	printf("            欢迎使用学生成绩管理系统\n");
	Sleep(1000);
	system("cls");
	
    printf("\n");
	printf("            欢迎使用学生成绩管理系统\n");    
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("                   正在加载.  \n");
	Sleep(600);
	system("cls");

    printf("\n");
	printf("            欢迎使用学生成绩管理系统\n");    
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("                   正在加载..  \n");
	Sleep(600);
	system("cls");
    
    printf("\n");
	printf("            欢迎使用学生成绩管理系统\n");    
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("                   正在加载...  \n");
	Sleep(600);
	system("cls");
    
    printf("\n");
	printf("            欢迎 使用学生成绩管理系统\n");    
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("                   正在加载.  \n");
	Sleep(600);
	system("cls");
    
    printf("\n");
	printf("            欢迎使用学生成绩管理系统\n");    
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("                   正在加载..  \n");
	Sleep(600);
	system("cls");
    
    printf("\n");
	printf("            欢迎使用学生成绩管理系统\n");    
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("                   正在加载...  \n");
	Sleep(600);
	system("cls");
	
	//-------------------------------------------------------------------------------------------------------------------------
	// 第二部分  进入系统主菜单界面  并实现输入成绩  输出成绩  还有排序	  

	zhucaidan:
        system("cls");
		printf("\n");
		printf("                   主菜单  \n");
		printf("\n");
		printf("         输入学生姓名和成绩   请按 【 1 】 \n");
		printf("\n");
		printf("         查找学生各科目成绩   请按 【 2 】  \n");
		printf("\n");
		printf("         添加学生科目成绩     请按 【 3 】  \n");
		printf("\n");
		printf("         删除学生科目成绩     请按 【 4 】  \n");
		printf("\n");	
	
	scanf("%d",&caidan);                    										    //菜单选择键
	
	if (caidan==1)                              										//执行选择菜单项
	{
		system("cls");     																//清除屏幕
		for(j=0;j<=5;j++)					   										    //因为定义的是6个学生 所以循环6次 
		{                                                                              
			printf("\n");                                                               //换行
			printf("         请输入第%d名学生的姓名: ",j+1);	                        //提示输入学生的名字
			scanf("%s",&xingming[j]);                                                   //把名字存放在 xingming[]字符数组里
					for (k=0;k<=5;k++)   		   										    //内循环 六个科目 每循环一次 都把成绩存放在每个学生成绩数组中
					{
						printf("         请输入%s的【%s】成绩: ",xingming[j],kemu[k]);	    //提示输入成绩
							if (j==0)
							{
								scanf("%d",&diyi[k]);							// diyi[]  指的是第一个学生的成绩 
								diyi1[k]=diyi[k];
							}	
							else if (j==1)
							{
								scanf("%d",&dier[k]); 							// dier[]  指的是第二个学生的成绩
								dier1[k]=dier[k];
							}
							else if (j==2)
							{
								scanf("%d",&disan[k]);    						// disan[]  指的是第三个学生的成绩
								disan1[k]=disan[k];
							}
							else if (j==3)
							{
								scanf("%d",&disi[k]);    						// disi[]  指的是第四个学生的成绩
								disi1[k]=disi[k];
							}
							else if (j==4)
							{
								scanf("%d",&diwu[k]);    						// diwu[]  指的是第五个学生的成绩
								diwu1[k]=diwu[k];
							}
							else if (j==5)
							{
								scanf("%d",&diliu[k]);    						// diliu[]  指的是第六个学生的成绩
								diliu1[k]=diliu[k];
							}
					}	
						system("cls");			                                // 清除屏幕
		}
	
			system("cls"); 		//清除屏幕
			printf("-------------------------------------------------------------\n");
			printf("                 排序前的成绩单:\n");
		
			printf("%s 的各科成绩如下:\n",xingming[0]);
			printf("%s %d  %s %d  %s %d  %s %d  %s %d  %s %d\n",kemu[0],diyi[0],kemu[1],diyi[1],kemu[2],diyi[2],kemu[3],diyi[3],kemu[4],diyi[4],kemu[5],diyi[5]); // 列 是成绩
			printf("\n");
            printf("%s 的各科成绩如下:\n",xingming[1]);
			printf("%s %d  %s %d  %s %d  %s %d  %s %d  %s %d\n",kemu[0],dier[0],kemu[1],dier[1],kemu[2],dier[2],kemu[3],dier[3],kemu[4],dier[4],kemu[5],dier[5]); // 列 是成绩
			printf("\n");
            printf("%s 的各科成绩如下:\n",xingming[2]);
			printf("%s %d  %s %d  %s %d  %s %d  %s %d  %s %d\n",kemu[0],disan[0],kemu[1],disan[1],kemu[2],disan[2],kemu[3],disan[3],kemu[4],disan[4],kemu[5],disan[5]); // 列 是成绩
			printf("\n");
            printf("%s 的各科成绩如下:\n",xingming[3]);
			printf("%s %d  %s %d  %s %d  %s %d  %s %d  %s %d\n",kemu[0],disi[0],kemu[1],disi[1],kemu[2],disi[2],kemu[3],disi[3],kemu[4],disi[4],kemu[5],disi[5]); // 列 是成绩
			printf("\n");
            printf("%s 的各科成绩如下:\n",xingming[4]);
			printf("%s %d  %s %d  %s %d  %s %d  %s %d  %s %d\n",kemu[0],diwu[0],kemu[1],diwu[1],kemu[2],diwu[2],kemu[3],diwu[3],kemu[4],diwu[4],kemu[5],diwu[5]); // 列 是成绩
			printf("\n");
            printf("%s 的各科成绩如下:\n",xingming[5]);
			printf("%s %d  %s %d  %s %d  %s %d  %s %d  %s %d\n",kemu[0],diliu[0],kemu[1],diliu[1],kemu[2],diliu[2],kemu[3],diliu[3],kemu[4],diliu[4],kemu[5],diliu[5]); // 列 是成绩

			//*************** 以上 是输出排序前的成绩 *****************************************************************
			
			printf("-------------------------------------------------------------\n");
			printf("                 排序后的成绩单:\n");
		
		for (i=5;i>=0;i--)	                     //第一个学生的成绩排序 
		{
			for(k=1;k<=i;k++)
			{
				if (diyi[k-1]<diyi[k])
				{
					t = diyi[k];
					diyi[k]=diyi[k-1];
					diyi[k-1]=t;
				}
			}
		}
        for (i=5;i>=0;i--)						//第一个学生的成绩排序 
		{
			for(k=1;k<=i;k++)
			{
				if (dier[k-1]<dier[k])
				{
					t = dier[k];
					dier[k]=dier[k-1];
					dier[k-1]=t;
				}
			}
		}
        for (i=5;i>=0;i--)						//第一个学生的成绩排序 
		{
			for(k=1;k<=i;k++)
			{
				if (disan[k-1]<disan[k])
				{
					t = disan[k];
					disan[k]=disan[k-1];
					disan[k-1]=t;
				}
			}
		}
        for (i=5;i>=0;i--)						//第一个学生的成绩排序 
		{
			for(k=1;k<=i;k++)
			{
				if (disi[k-1]<disi[k])
				{
					t = disi[k];
					disi[k]=disi[k-1];
					disi[k-1]=t;
				}
			}
		}
        for (i=5;i>=0;i--)						//第一个学生的成绩排序 
		{
			for(k=1;k<=i;k++)
			{
				if (diwu[k-1]<diwu[k])
				{
					t = diwu[k];
					diwu[k]=diwu[k-1];
					diwu[k-1]=t;
				}
			}
		}
        for (i=5;i>=0;i--)						//第一个学生的成绩排序 
		{
			for(k=1;k<=i;k++)
			{
				if (diliu[k-1]<diliu[k])
				{
					t = diliu[k];
					diliu[k]=diliu[k-1];
					diliu[k-1]=t;
				}
			}
		}

		//-----------------------------------------------------------以上成绩排序-------------------------------	

			for (i=0;i<=5;i++)                         //二层循环 控制排序前的成绩 和 排序前的科目 
			{
				for(j=0;j<=5;j++)                      //三成循环 控制排序后的成绩 和 排序后的科目
				{
					if (diyi[i]==diyi1[j])             //判断 排序后下标2的成绩 是否 等于排序前下标2的成绩 
					{
						strcpy(kemu1[i],kemu[j]);      //如果等于 那么把排序后科目下标2的内容 赋值给 kemu1 下标0的字符数组 
						break;                         //并且退出 三层循环 
					}							       //以上目的就是按照成绩排序的结果 把科目排序一遍  好对应成绩和科目 
				}
			}
				printf("%s 的各科成绩如下:\n",xingming[0]);
				printf("%s %d  %s %d  %s %d  %s %d  %s %d  %s %d\n",kemu1[0],diyi[0],kemu1[1],diyi[1],kemu1[2],diyi[2],kemu1[3],diyi[3],kemu1[4],diyi[4],kemu1[5],diyi[5]); // 列 是成绩
				printf("\n");

			for (i=0;i<=5;i++)
			{
				for(j=0;j<=5;j++)
				{
					if (dier[i]==dier1[j])
					{
						strcpy(kemu1[i],kemu[j]);
						break;
					}
				}
			}
				printf("%s 的各科成绩如下:\n",xingming[1]);
				printf("%s %d  %s %d  %s %d  %s %d  %s %d  %s %d\n",kemu1[0],dier[0],kemu1[1],dier[1],kemu1[2],dier[2],kemu1[3],dier[3],kemu1[4],dier[4],kemu1[5],dier[5]); // 列 是成绩
				printf("\n");

			for (i=0;i<=5;i++)
			{
				for(j=0;j<=5;j++)
				{
					if (disan[i]==disan1[j])
					{
						strcpy(kemu1[i],kemu[j]);
						break;
					}
				}
			}
				printf("%s 的各科成绩如下:\n",xingming[2]);
				printf("%s %d  %s %d  %s %d  %s %d  %s %d  %s %d\n",kemu1[0],disan[0],kemu1[1],disan[1],kemu1[2],disan[2],kemu1[3],disan[3],kemu1[4],disan[4],kemu1[5],disan[5]); // 列 是成绩
				printf("\n");

			for (i=0;i<=5;i++)
			{
				for(j=0;j<=5;j++)
				{
					if (disi[i]==disi1[j])
					{
						strcpy(kemu1[i],kemu[j]);
						break;
					}
				}
			}
				printf("%s 的各科成绩如下:\n",xingming[3]);
				printf("%s %d  %s %d  %s %d  %s %d  %s %d  %s %d\n",kemu1[0],disi[0],kemu1[1],disi[1],kemu1[2],disi[2],kemu1[3],disi[3],kemu1[4],disi[4],kemu1[5],disi[5]); // 列 是成绩
				printf("\n");

			for (i=0;i<=5;i++)
			{
				for(j=0;j<=5;j++)
				{
					if (diwu[i]==diwu1[j])
					{
						strcpy(kemu1[i],kemu[j]);
						break;
					}
				}
			}
				printf("%s 的各科成绩如下:\n",xingming[4]);
				printf("%s %d  %s %d  %s %d  %s %d  %s %d  %s %d\n",kemu1[0],diwu[0],kemu1[1],diwu[1],kemu1[2],diwu[2],kemu1[3],diwu[3],kemu1[4],diwu[4],kemu1[5],diwu[5]); // 列 是成绩
				printf("\n");

			for (i=0;i<=5;i++)
			{
			for(j=0;j<=5;j++)
				{
					if (diliu[i]==diliu1[j])
					{
						strcpy(kemu1[i],kemu[j]);
						break;
					}
				}
			}
				printf("%s 的各科成绩如下:\n",xingming[5]);
				printf("%s %d  %s %d  %s %d  %s %d  %s %d  %s %d\n",kemu1[0],diliu[0],kemu1[1],diliu[1],kemu1[2],diliu[2],kemu1[3],diliu[3],kemu1[4],diliu[4],kemu1[5],diliu[5]); // 列 是成绩
				printf("\n");
				
			printf("\n");
			printf("         返回主菜单请按【1】\n");
            printf("         退出本系统请按【2】\n");
            scanf("%d",&fanhuicaidan); 
			printf("\n");
	
		if (fanhuicaidan==1)
		{
			system("cls"); 		//清除屏幕
			goto zhucaidan;
		}
	
		if (fanhuicaidan==2)
		{
			system("cls");
			printf("\n");
			printf("          感谢您的使用  \n");
			Sleep(2000);
			system("cls");
			printf("\n");
			printf("              再见  \n");
			Sleep(2000);
			system("cls");
			exit(0);
		}
	}
	
	//***************************************************************************************************************
	//                                   第三部分    查找学生的成绩  
	
	if (caidan==2)                                                        //选择排序后 显示按科目排序的成绩表 
	{
		system("cls");
				printf("%s 的各科成绩如下:\n",xingming[0]);
				printf("%s %d  %s %d  %s %d  %s %d  %s %d  %s %d\n",kemu[0],diyi1[0],kemu[1],diyi1[1],kemu[2],diyi1[2],kemu[3],diyi1[3],kemu[4],diyi1[4],kemu[5],diyi1[5]); 
				printf("\n");			// 列 是成绩
				printf("%s 的各科成绩如下:\n",xingming[1]);
				printf("%s %d  %s %d  %s %d  %s %d  %s %d  %s %d\n",kemu[0],dier1[0],kemu[1],dier1[1],kemu[2],dier1[2],kemu[3],dier1[3],kemu[4],dier1[4],kemu[5],dier1[5]); 
				printf("\n");			// 列 是成绩
				printf("%s 的各科成绩如下:\n",xingming[2]);
				printf("%s %d  %s %d  %s %d  %s %d  %s %d  %s %d\n",kemu[0],disan1[0],kemu[1],disan1[1],kemu[2],disan1[2],kemu[3],disan1[3],kemu[4],disan1[4],kemu[5],disan1[5]); 
				printf("\n");			// 列 是成绩
				printf("%s 的各科成绩如下:\n",xingming[3]);
				printf("%s %d  %s %d  %s %d  %s %d  %s %d  %s %d\n",kemu[0],disi1[0],kemu[1],disi1[1],kemu[2],disi1[2],kemu[3],disi1[3],kemu[4],disi1[4],kemu[5],disi1[5]); 
				printf("\n");			// 列 是成绩
				printf("%s 的各科成绩如下:\n",xingming[4]);
				printf("%s %d  %s %d  %s %d  %s %d  %s %d  %s %d\n",kemu[0],diwu1[0],kemu[1],diwu1[1],kemu[2],diwu1[2],kemu[3],diwu1[3],kemu[4],diwu1[4],kemu[5],diwu1[5]); 
				printf("\n");			// 列 是成绩
				printf("%s 的各科成绩如下:\n",xingming[5]);
				printf("%s %d  %s %d  %s %d  %s %d  %s %d  %s %d\n",kemu[0],diliu1[0],kemu[1],diliu1[1],kemu[2],diliu1[2],kemu[3],diliu1[3],kemu[4],diliu1[4],kemu[5],diliu1[5]); 
				printf("\n");			// 列 是成绩
				
		chongxin:                                                          // goto 语句的返回点  【 这句是重新查找的返回点】
				printf("\n");
				printf("          请输入查找关键字（姓名）:  ");
				scanf("%s",&CZguanjianzi1[0]);                             //把查找的关键字放在关键字变量里
				printf("\n");
				printf("          请输入查找关键字（科目）:  ");
				scanf("%s",&CZguanjianzi2[0]);                             //把查找的关键字放在关键字变量里
		
			if(strcmp(CZguanjianzi1[0],xingming[0])==0)                    //如果输入的姓名关键字等于成绩表里的姓名
			{
				for(j=0;j<=5;j++)                                          //那么执行循环  循环变量 j 控制的是科目 
				{
					if (strcmp(CZguanjianzi2[0],kemu[j])==0)               //如果输入的科目关键字等于成绩表里的科目
					{
						printf("\n");                
						printf("           查找结果: %s的%s成绩是%d分\n",CZguanjianzi1[0],CZguanjianzi2[0],diyi1[j]);  // 那么把查找结果输出
						goto label;                                        // goto 语句  如果找到成绩 那么跳转到 label 返回点
					}
				}
			}	  
            if(strcmp(CZguanjianzi1[0],xingming[1])==0)
			{
				for(j=0;j<=5;j++)
				{
					if (strcmp(CZguanjianzi2[0],kemu[j])==0)
					{
						printf("\n");
						printf("           查找结果: %s的%s成绩是%d分\n",CZguanjianzi1[0],CZguanjianzi2[0],dier1[j]);
						goto label;
					}
				}
			}
            if(strcmp(CZguanjianzi1[0],xingming[2])==0)
			{
				for(j=0;j<=5;j++)
				{
					if (strcmp(CZguanjianzi2[0],kemu[j])==0)
					{
						printf("\n");
						printf("           查找结果: %s的%s成绩是%d分\n",CZguanjianzi1[0],CZguanjianzi2[0],disan1[j]);
						goto label;
					}
				}
			}
            if(strcmp(CZguanjianzi1[0],xingming[3])==0)
			{
				for(j=0;j<=5;j++)
				{
					if (strcmp(CZguanjianzi2[0],kemu[j])==0)
					{
						printf("\n"); 
						printf("           查找结果: %s的%s成绩是%d分\n",CZguanjianzi1[0],CZguanjianzi2[0],disi1[j]);
						goto label;
					}
	     		}
	     	}
            if(strcmp(CZguanjianzi1[0],xingming[4])==0)
			{
				for(j=0;j<=5;j++)
				{
					if (strcmp(CZguanjianzi2[0],kemu[j])==0)
					{
						printf("\n");
						printf("           查找结果: %s的%s成绩是%d分\n",CZguanjianzi1[0],CZguanjianzi2[0],diwu1[j]);
						goto label;
					}
				}
			}
            if(strcmp(CZguanjianzi1[0],xingming[5])==0)
			{
				for(j=0;j<=5;j++)
				{
					if (strcmp(CZguanjianzi2[0],kemu[j])==0)
					{
						printf("\n");
						printf("           查找结果: %s的%s成绩是%d分\n",CZguanjianzi1[0],CZguanjianzi2[0],diliu1[j]);
						goto label;
					}
				}
			}
	
            label:                                                  //查到结果正确的 返回点
            printf("\n");    
            printf("         重新查找请按  【1】\n");               // 次菜单
			printf("         返回主菜单请按【2】\n");				// 次菜单
            printf("         退出本系统请按【3】\n");				// 次菜单
            scanf("%d",&fanhuicaidan); 
			printf("\n");

		if (fanhuicaidan==1)
		{
           goto chongxin;                                          //重新查找的 goto 语句 跳转到 chongxin  重新查找的返回点
		}

		if (fanhuicaidan==2)
		{
			goto zhucaidan;										   //重新查找的 goto 语句 跳转到 zhucaidan 主菜单的返回点
		}
	
		if (fanhuicaidan==3)                                                     //退出程序
		{
			goto tuichu;										   //重新查找的 goto 语句 跳转到 tuichu 退出的返回点
		}
      tuichu:                                                      //退出的返回点 以下程序是退出的的代码
		system("cls");
		printf("\n");
		printf("          感谢您的使用  \n");
		Sleep(1500);
		system("cls");
		printf("\n");
		printf("              再见  \n");
		Sleep(1500);
		system("cls");     
		exit(0);
	}
	
	//-------------------------------------------------------------------------------------------------------------------
	//               第四部分  添加科目 和 成绩 
	
	if (caidan==3)
	{
		system("cls");
        printf("\n");
		printf("       请输入添加的位置:");
		scanf("%d",&tianjia);                                     // 添加成绩      在成绩表的哪一列
			for(i=5;i>=tianjia-1;i--)                             // 将成绩从添加位置开始 向后移动一位 
			{
				diyi1[i+1]=diyi1[i];                              
			}
			for(i=5;i>=tianjia-1;i--)
			{
				dier1[i+1]=dier1[i];
			}
			for(i=5;i>=tianjia;i--)
			{
				disan1[i+1]=disan1[i];
			}
			for(i=5;i>=tianjia;i--)
			{
				disi1[i+1]=disi1[i];
			}
			for(i=5;i>=tianjia;i--)
			{
				diwu1[i+1]=diwu1[i];
			}
			for(i=5;i>=tianjia;i--)
			{
				diliu1[i+1]=diliu1[i];
			}
			for(i=5;i>=tianjia-1;i--)
			{
				strcpy(kemu[i+1],kemu[i]);                               //将科目从添加位置开始 向后移动一位 
			}
		
		printf("\n");
		printf("       请输入添加的科目:");
		scanf("%s",&kemu[tianjia-1]);                                    //添加科目     在成绩表的哪一列

			for (i=0;i<=5;i++)
			{
				printf("\n");
				printf("       请输入%s的%s成绩:",xingming[i],kemu[tianjia-1]); //输入新科目的成绩
					if(i==0)
					{ 
						scanf("%d",&diyi1[tianjia-1]);                   //开始将成绩添加进位置里
					}
					if(i==1)
					{
						scanf("%d",&dier1[tianjia-1]);
					}
					if(i==2)
					{
						scanf("%d",&disan1[tianjia-1]);
					}
					if(i==3)
					{
						scanf("%d",&disi1[tianjia-1]);
					}
					if(i==4)
					{
						scanf("%d",&diwu1[tianjia-1]);
					}
					if(i==5)
					{
						scanf("%d",&diliu1[tianjia-1]);
					}
			}
			
			printf("\n");
			printf("%s 的各科成绩如下:\n",xingming[0]);
			printf("%s %d  %s %d  %s %d  %s %d  %s %d  %s %d  %s %d\n",kemu[0],diyi1[0],kemu[1],diyi1[1],kemu[2],diyi1[2],kemu[3],diyi1[3],kemu[4],diyi1[4],kemu[5],diyi1[5],kemu[6],diyi1[6]); // 列 是成绩
			printf("\n");
            printf("%s 的各科成绩如下:\n",xingming[1]);
			printf("%s %d  %s %d  %s %d  %s %d  %s %d  %s %d  %s %d\n",kemu[0],dier1[0],kemu[1],dier1[1],kemu[2],dier1[2],kemu[3],dier1[3],kemu[4],dier1[4],kemu[5],dier1[5],kemu[6],dier1[6]); // 列 是成绩
			printf("\n");
            printf("%s 的各科成绩如下:\n",xingming[2]);
			printf("%s %d  %s %d  %s %d  %s %d  %s %d  %s %d  %s %d\n",kemu[0],disan1[0],kemu[1],disan1[1],kemu[2],disan1[2],kemu[3],disan1[3],kemu[4],disan1[4],kemu[5],disan1[5],kemu[6],disan1[6]); // 列 是成绩
			printf("\n");
            printf("%s 的各科成绩如下:\n",xingming[3]);
			printf("%s %d  %s %d  %s %d  %s %d  %s %d  %s %d  %s %d\n",kemu[0],disi1[0],kemu[1],disi1[1],kemu[2],disi1[2],kemu[3],disi1[3],kemu[4],disi1[4],kemu[5],disi1[5],kemu[6],disi1[6]); // 列 是成绩
			printf("\n");
            printf("%s 的各科成绩如下:\n",xingming[4]);
			printf("%s %d  %s %d  %s %d  %s %d  %s %d  %s %d  %s %d\n",kemu[0],diwu1[0],kemu[1],diwu1[1],kemu[2],diwu1[2],kemu[3],diwu1[3],kemu[4],diwu1[4],kemu[5],diwu1[5],kemu[6],diwu1[6]); // 列 是成绩
			printf("\n");
            printf("%s 的各科成绩如下:\n",xingming[5]);
			printf("%s %d  %s %d  %s %d  %s %d  %s %d  %s %d  %s %d\n",kemu[0],diliu1[0],kemu[1],diliu1[1],kemu[2],diliu1[2],kemu[3],diliu1[3],kemu[4],diliu1[4],kemu[5],diliu1[5],kemu[6],diliu1[6]); // 列 是成绩
			printf("\n");	
		
			printf("\n");
			printf("\n");
			printf("         返回主菜单请按【1】\n");
            printf("         退出本系统请按【2】\n");
            scanf("%d",&fanhuicaidan); 
				if (fanhuicaidan==1)
				{
					goto zhucaidan;
				}
				if (fanhuicaidan==2)
				{
					goto tuichu;
				}
	}
	
	//--------------------------------------------------------------------------------------------------------------------------
	//                第五部分  删除科目
	
	if (caidan==4)
	{
		system("cls");
		printf("\n");
		printf("       请输入您要删除的科目:");
		scanf("%s",&shanchu[0]);                   //要删除的科目存放在 shanchu 字符数组里
        printf("\n");
        printf("\n");
		
		for(j=0;j<=6;j++)
		{
			if (strcmp(kemu[j],shanchu[0])==0)
			{
				for(i=j+1;i<=6;i++)                              // 把删除的科目之后的  成绩和科目   向前移动一位  
				{
					diyi1[i-1]=diyi1[i];
				}
				for(i=j+1;i<=6;i++)
				{
					dier1[i-1]=dier1[i];
				}
				for(i=j+1;i<=6;i++)
				{
					disan1[i-1]=disan1[i];
				}
				for(i=j+1;i<=6;i++)
				{
					disi1[i-1]=disi1[i];
				}
				for(i=j+1;i<=6;i++)
				{
					diwu1[i-1]=diwu1[i];
				}
				for(i=j+1;i<=6;i++)
				{
					diliu1[i-1]=diliu1[i];
				}
				for(i=j+1;i<=6;i++)
				{
					strcpy(kemu[i-1],kemu[i]);
				}
			}
		}
		    printf("\n");
			printf("%s 的各科成绩如下:\n",xingming[0]);
			printf("%s %d  %s %d  %s %d  %s %d  %s %d  %s %d\n",kemu[0],diyi1[0],kemu[1],diyi1[1],kemu[2],diyi1[2],kemu[3],diyi1[3],kemu[4],diyi1[4],kemu[5],diyi1[5]); // 列 是成绩
			printf("\n");
            printf("%s 的各科成绩如下:\n",xingming[1]);
			printf("%s %d  %s %d  %s %d  %s %d  %s %d  %s %d\n",kemu[0],dier1[0],kemu[1],dier1[1],kemu[2],dier1[2],kemu[3],dier1[3],kemu[4],dier1[4],kemu[5],dier1[5]); // 列 是成绩
			printf("\n");
            printf("%s 的各科成绩如下:\n",xingming[2]);
			printf("%s %d  %s %d  %s %d  %s %d  %s %d  %s %d\n",kemu[0],disan1[0],kemu[1],disan1[1],kemu[2],disan1[2],kemu[3],disan1[3],kemu[4],disan1[4],kemu[5],disan1[5]); // 列 是成绩
			printf("\n");
            printf("%s 的各科成绩如下:\n",xingming[3]);
			printf("%s %d  %s %d  %s %d  %s %d  %s %d  %s %d\n",kemu[0],disi1[0],kemu[1],disi1[1],kemu[2],disi1[2],kemu[3],disi1[3],kemu[4],disi1[4],kemu[5],disi1[5]); // 列 是成绩
			printf("\n");
            printf("%s 的各科成绩如下:\n",xingming[4]);
			printf("%s %d  %s %d  %s %d  %s %d  %s %d  %s %d\n",kemu[0],diwu1[0],kemu[1],diwu1[1],kemu[2],diwu1[2],kemu[3],diwu1[3],kemu[4],diwu1[4],kemu[5],diwu1[5]); // 列 是成绩
			printf("\n");
            printf("%s 的各科成绩如下:\n",xingming[5]);
			printf("%s %d  %s %d  %s %d  %s %d  %s %d  %s %d\n",kemu[0],diliu1[0],kemu[1],diliu1[1],kemu[2],diliu1[2],kemu[3],diliu1[3],kemu[4],diliu1[4],kemu[5],diliu1[5]); // 列 是成绩
			printf("\n");
			
			printf("\n");
			printf("\n");
			printf("         退出本系统请按【1】\n");
			scanf("%d",&fanhuicaidan); 
			
			if (fanhuicaidan==1)
			{
				goto tuichu;   
			}
	}
    printf("\n");
	system("pause"); 
}
