#include <stdio.h>    // ��׼���������ͷ�ļ�
#include <windows.h>  // ����ʱ��ͣ��
#include <stdlib.h>
#include "string.h"   //�����ַ�����
main()
{
	int diyi[7],dier[7],disan[7],disi[7],diwu[7],diliu[7];         					//��������ĸ��Ƴɼ�
	int diyi1[7],dier1[7],disan1[7],disi1[7],diwu1[7],diliu1[7];   					//�������ǰ�ĸ��Ƴɼ� 
	int i,j,k;         										      				    // ѭ������ 
	int t;                            							  	 				//�����ݴ����
	int caidan,fanhuicaidan;          							   					//���˵�����   �β˵��������������˵���
	int tianjia;         							               					//��ӳɼ���λ�ñ���  
	char CZguanjianzi1[1][8],CZguanjianzi2[1][12];                 					//���ҹؼ��� ��������     ���ҹؼ��� ����Ŀ��
	char xingming[6][8]={" "," "," "," "," "," "};                 					//���ѧ��������   
	char kemu[7][12]={"Ӣ��","C����","��·����","������Ļ�","����","˼��"};   // ���Ĭ�������Ŀ 
	char kemu1[7][12],shanchu[1][12];                                				//��������Ŀ�Ŀ   ���ɾ���Ŀ�Ŀ����
	
	//--------------------------------------------------------------------------------------------------------------------------
	// ��һ����  ������ϵͳ�Ľ���  

    printf("\n");
	printf("            ��ӭʹ��ѧ���ɼ�����ϵͳ\n");
	Sleep(1000);
	system("cls");
	
    printf("\n");
	printf("            ��ӭʹ��ѧ���ɼ�����ϵͳ\n");    
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("                   ���ڼ���.  \n");
	Sleep(600);
	system("cls");

    printf("\n");
	printf("            ��ӭʹ��ѧ���ɼ�����ϵͳ\n");    
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("                   ���ڼ���..  \n");
	Sleep(600);
	system("cls");
    
    printf("\n");
	printf("            ��ӭʹ��ѧ���ɼ�����ϵͳ\n");    
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("                   ���ڼ���...  \n");
	Sleep(600);
	system("cls");
    
    printf("\n");
	printf("            ��ӭ ʹ��ѧ���ɼ�����ϵͳ\n");    
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("                   ���ڼ���.  \n");
	Sleep(600);
	system("cls");
    
    printf("\n");
	printf("            ��ӭʹ��ѧ���ɼ�����ϵͳ\n");    
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("                   ���ڼ���..  \n");
	Sleep(600);
	system("cls");
    
    printf("\n");
	printf("            ��ӭʹ��ѧ���ɼ�����ϵͳ\n");    
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("                   ���ڼ���...  \n");
	Sleep(600);
	system("cls");
	
	//-------------------------------------------------------------------------------------------------------------------------
	// �ڶ�����  ����ϵͳ���˵�����  ��ʵ������ɼ�  ����ɼ�  ��������	  

	zhucaidan:
        system("cls");
		printf("\n");
		printf("                   ���˵�  \n");
		printf("\n");
		printf("         ����ѧ�������ͳɼ�   �밴 �� 1 �� \n");
		printf("\n");
		printf("         ����ѧ������Ŀ�ɼ�   �밴 �� 2 ��  \n");
		printf("\n");
		printf("         ���ѧ����Ŀ�ɼ�     �밴 �� 3 ��  \n");
		printf("\n");
		printf("         ɾ��ѧ����Ŀ�ɼ�     �밴 �� 4 ��  \n");
		printf("\n");	
	
	scanf("%d",&caidan);                    										    //�˵�ѡ���
	
	if (caidan==1)                              										//ִ��ѡ��˵���
	{
		system("cls");     																//�����Ļ
		for(j=0;j<=5;j++)					   										    //��Ϊ�������6��ѧ�� ����ѭ��6�� 
		{                                                                              
			printf("\n");                                                               //����
			printf("         �������%d��ѧ��������: ",j+1);	                        //��ʾ����ѧ��������
			scanf("%s",&xingming[j]);                                                   //�����ִ���� xingming[]�ַ�������
					for (k=0;k<=5;k++)   		   										    //��ѭ�� ������Ŀ ÿѭ��һ�� ���ѳɼ������ÿ��ѧ���ɼ�������
					{
						printf("         ������%s�ġ�%s���ɼ�: ",xingming[j],kemu[k]);	    //��ʾ����ɼ�
							if (j==0)
							{
								scanf("%d",&diyi[k]);							// diyi[]  ָ���ǵ�һ��ѧ���ĳɼ� 
								diyi1[k]=diyi[k];
							}	
							else if (j==1)
							{
								scanf("%d",&dier[k]); 							// dier[]  ָ���ǵڶ���ѧ���ĳɼ�
								dier1[k]=dier[k];
							}
							else if (j==2)
							{
								scanf("%d",&disan[k]);    						// disan[]  ָ���ǵ�����ѧ���ĳɼ�
								disan1[k]=disan[k];
							}
							else if (j==3)
							{
								scanf("%d",&disi[k]);    						// disi[]  ָ���ǵ��ĸ�ѧ���ĳɼ�
								disi1[k]=disi[k];
							}
							else if (j==4)
							{
								scanf("%d",&diwu[k]);    						// diwu[]  ָ���ǵ����ѧ���ĳɼ�
								diwu1[k]=diwu[k];
							}
							else if (j==5)
							{
								scanf("%d",&diliu[k]);    						// diliu[]  ָ���ǵ�����ѧ���ĳɼ�
								diliu1[k]=diliu[k];
							}
					}	
						system("cls");			                                // �����Ļ
		}
	
			system("cls"); 		//�����Ļ
			printf("-------------------------------------------------------------\n");
			printf("                 ����ǰ�ĳɼ���:\n");
		
			printf("%s �ĸ��Ƴɼ�����:\n",xingming[0]);
			printf("%s %d  %s %d  %s %d  %s %d  %s %d  %s %d\n",kemu[0],diyi[0],kemu[1],diyi[1],kemu[2],diyi[2],kemu[3],diyi[3],kemu[4],diyi[4],kemu[5],diyi[5]); // �� �ǳɼ�
			printf("\n");
            printf("%s �ĸ��Ƴɼ�����:\n",xingming[1]);
			printf("%s %d  %s %d  %s %d  %s %d  %s %d  %s %d\n",kemu[0],dier[0],kemu[1],dier[1],kemu[2],dier[2],kemu[3],dier[3],kemu[4],dier[4],kemu[5],dier[5]); // �� �ǳɼ�
			printf("\n");
            printf("%s �ĸ��Ƴɼ�����:\n",xingming[2]);
			printf("%s %d  %s %d  %s %d  %s %d  %s %d  %s %d\n",kemu[0],disan[0],kemu[1],disan[1],kemu[2],disan[2],kemu[3],disan[3],kemu[4],disan[4],kemu[5],disan[5]); // �� �ǳɼ�
			printf("\n");
            printf("%s �ĸ��Ƴɼ�����:\n",xingming[3]);
			printf("%s %d  %s %d  %s %d  %s %d  %s %d  %s %d\n",kemu[0],disi[0],kemu[1],disi[1],kemu[2],disi[2],kemu[3],disi[3],kemu[4],disi[4],kemu[5],disi[5]); // �� �ǳɼ�
			printf("\n");
            printf("%s �ĸ��Ƴɼ�����:\n",xingming[4]);
			printf("%s %d  %s %d  %s %d  %s %d  %s %d  %s %d\n",kemu[0],diwu[0],kemu[1],diwu[1],kemu[2],diwu[2],kemu[3],diwu[3],kemu[4],diwu[4],kemu[5],diwu[5]); // �� �ǳɼ�
			printf("\n");
            printf("%s �ĸ��Ƴɼ�����:\n",xingming[5]);
			printf("%s %d  %s %d  %s %d  %s %d  %s %d  %s %d\n",kemu[0],diliu[0],kemu[1],diliu[1],kemu[2],diliu[2],kemu[3],diliu[3],kemu[4],diliu[4],kemu[5],diliu[5]); // �� �ǳɼ�

			//*************** ���� ���������ǰ�ĳɼ� *****************************************************************
			
			printf("-------------------------------------------------------------\n");
			printf("                 �����ĳɼ���:\n");
		
		for (i=5;i>=0;i--)	                     //��һ��ѧ���ĳɼ����� 
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
        for (i=5;i>=0;i--)						//��һ��ѧ���ĳɼ����� 
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
        for (i=5;i>=0;i--)						//��һ��ѧ���ĳɼ����� 
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
        for (i=5;i>=0;i--)						//��һ��ѧ���ĳɼ����� 
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
        for (i=5;i>=0;i--)						//��һ��ѧ���ĳɼ����� 
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
        for (i=5;i>=0;i--)						//��һ��ѧ���ĳɼ����� 
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

		//-----------------------------------------------------------���ϳɼ�����-------------------------------	

			for (i=0;i<=5;i++)                         //����ѭ�� ��������ǰ�ĳɼ� �� ����ǰ�Ŀ�Ŀ 
			{
				for(j=0;j<=5;j++)                      //����ѭ�� ���������ĳɼ� �� �����Ŀ�Ŀ
				{
					if (diyi[i]==diyi1[j])             //�ж� ������±�2�ĳɼ� �Ƿ� ��������ǰ�±�2�ĳɼ� 
					{
						strcpy(kemu1[i],kemu[j]);      //������� ��ô��������Ŀ�±�2������ ��ֵ�� kemu1 �±�0���ַ����� 
						break;                         //�����˳� ����ѭ�� 
					}							       //����Ŀ�ľ��ǰ��ճɼ�����Ľ�� �ѿ�Ŀ����һ��  �ö�Ӧ�ɼ��Ϳ�Ŀ 
				}
			}
				printf("%s �ĸ��Ƴɼ�����:\n",xingming[0]);
				printf("%s %d  %s %d  %s %d  %s %d  %s %d  %s %d\n",kemu1[0],diyi[0],kemu1[1],diyi[1],kemu1[2],diyi[2],kemu1[3],diyi[3],kemu1[4],diyi[4],kemu1[5],diyi[5]); // �� �ǳɼ�
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
				printf("%s �ĸ��Ƴɼ�����:\n",xingming[1]);
				printf("%s %d  %s %d  %s %d  %s %d  %s %d  %s %d\n",kemu1[0],dier[0],kemu1[1],dier[1],kemu1[2],dier[2],kemu1[3],dier[3],kemu1[4],dier[4],kemu1[5],dier[5]); // �� �ǳɼ�
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
				printf("%s �ĸ��Ƴɼ�����:\n",xingming[2]);
				printf("%s %d  %s %d  %s %d  %s %d  %s %d  %s %d\n",kemu1[0],disan[0],kemu1[1],disan[1],kemu1[2],disan[2],kemu1[3],disan[3],kemu1[4],disan[4],kemu1[5],disan[5]); // �� �ǳɼ�
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
				printf("%s �ĸ��Ƴɼ�����:\n",xingming[3]);
				printf("%s %d  %s %d  %s %d  %s %d  %s %d  %s %d\n",kemu1[0],disi[0],kemu1[1],disi[1],kemu1[2],disi[2],kemu1[3],disi[3],kemu1[4],disi[4],kemu1[5],disi[5]); // �� �ǳɼ�
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
				printf("%s �ĸ��Ƴɼ�����:\n",xingming[4]);
				printf("%s %d  %s %d  %s %d  %s %d  %s %d  %s %d\n",kemu1[0],diwu[0],kemu1[1],diwu[1],kemu1[2],diwu[2],kemu1[3],diwu[3],kemu1[4],diwu[4],kemu1[5],diwu[5]); // �� �ǳɼ�
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
				printf("%s �ĸ��Ƴɼ�����:\n",xingming[5]);
				printf("%s %d  %s %d  %s %d  %s %d  %s %d  %s %d\n",kemu1[0],diliu[0],kemu1[1],diliu[1],kemu1[2],diliu[2],kemu1[3],diliu[3],kemu1[4],diliu[4],kemu1[5],diliu[5]); // �� �ǳɼ�
				printf("\n");
				
			printf("\n");
			printf("         �������˵��밴��1��\n");
            printf("         �˳���ϵͳ�밴��2��\n");
            scanf("%d",&fanhuicaidan); 
			printf("\n");
	
		if (fanhuicaidan==1)
		{
			system("cls"); 		//�����Ļ
			goto zhucaidan;
		}
	
		if (fanhuicaidan==2)
		{
			system("cls");
			printf("\n");
			printf("          ��л����ʹ��  \n");
			Sleep(2000);
			system("cls");
			printf("\n");
			printf("              �ټ�  \n");
			Sleep(2000);
			system("cls");
			exit(0);
		}
	}
	
	//***************************************************************************************************************
	//                                   ��������    ����ѧ���ĳɼ�  
	
	if (caidan==2)                                                        //ѡ������� ��ʾ����Ŀ����ĳɼ��� 
	{
		system("cls");
				printf("%s �ĸ��Ƴɼ�����:\n",xingming[0]);
				printf("%s %d  %s %d  %s %d  %s %d  %s %d  %s %d\n",kemu[0],diyi1[0],kemu[1],diyi1[1],kemu[2],diyi1[2],kemu[3],diyi1[3],kemu[4],diyi1[4],kemu[5],diyi1[5]); 
				printf("\n");			// �� �ǳɼ�
				printf("%s �ĸ��Ƴɼ�����:\n",xingming[1]);
				printf("%s %d  %s %d  %s %d  %s %d  %s %d  %s %d\n",kemu[0],dier1[0],kemu[1],dier1[1],kemu[2],dier1[2],kemu[3],dier1[3],kemu[4],dier1[4],kemu[5],dier1[5]); 
				printf("\n");			// �� �ǳɼ�
				printf("%s �ĸ��Ƴɼ�����:\n",xingming[2]);
				printf("%s %d  %s %d  %s %d  %s %d  %s %d  %s %d\n",kemu[0],disan1[0],kemu[1],disan1[1],kemu[2],disan1[2],kemu[3],disan1[3],kemu[4],disan1[4],kemu[5],disan1[5]); 
				printf("\n");			// �� �ǳɼ�
				printf("%s �ĸ��Ƴɼ�����:\n",xingming[3]);
				printf("%s %d  %s %d  %s %d  %s %d  %s %d  %s %d\n",kemu[0],disi1[0],kemu[1],disi1[1],kemu[2],disi1[2],kemu[3],disi1[3],kemu[4],disi1[4],kemu[5],disi1[5]); 
				printf("\n");			// �� �ǳɼ�
				printf("%s �ĸ��Ƴɼ�����:\n",xingming[4]);
				printf("%s %d  %s %d  %s %d  %s %d  %s %d  %s %d\n",kemu[0],diwu1[0],kemu[1],diwu1[1],kemu[2],diwu1[2],kemu[3],diwu1[3],kemu[4],diwu1[4],kemu[5],diwu1[5]); 
				printf("\n");			// �� �ǳɼ�
				printf("%s �ĸ��Ƴɼ�����:\n",xingming[5]);
				printf("%s %d  %s %d  %s %d  %s %d  %s %d  %s %d\n",kemu[0],diliu1[0],kemu[1],diliu1[1],kemu[2],diliu1[2],kemu[3],diliu1[3],kemu[4],diliu1[4],kemu[5],diliu1[5]); 
				printf("\n");			// �� �ǳɼ�
				
		chongxin:                                                          // goto ���ķ��ص�  �� ��������²��ҵķ��ص㡿
				printf("\n");
				printf("          ��������ҹؼ��֣�������:  ");
				scanf("%s",&CZguanjianzi1[0]);                             //�Ѳ��ҵĹؼ��ַ��ڹؼ��ֱ�����
				printf("\n");
				printf("          ��������ҹؼ��֣���Ŀ��:  ");
				scanf("%s",&CZguanjianzi2[0]);                             //�Ѳ��ҵĹؼ��ַ��ڹؼ��ֱ�����
		
			if(strcmp(CZguanjianzi1[0],xingming[0])==0)                    //�������������ؼ��ֵ��ڳɼ����������
			{
				for(j=0;j<=5;j++)                                          //��ôִ��ѭ��  ѭ������ j ���Ƶ��ǿ�Ŀ 
				{
					if (strcmp(CZguanjianzi2[0],kemu[j])==0)               //�������Ŀ�Ŀ�ؼ��ֵ��ڳɼ�����Ŀ�Ŀ
					{
						printf("\n");                
						printf("           ���ҽ��: %s��%s�ɼ���%d��\n",CZguanjianzi1[0],CZguanjianzi2[0],diyi1[j]);  // ��ô�Ѳ��ҽ�����
						goto label;                                        // goto ���  ����ҵ��ɼ� ��ô��ת�� label ���ص�
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
						printf("           ���ҽ��: %s��%s�ɼ���%d��\n",CZguanjianzi1[0],CZguanjianzi2[0],dier1[j]);
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
						printf("           ���ҽ��: %s��%s�ɼ���%d��\n",CZguanjianzi1[0],CZguanjianzi2[0],disan1[j]);
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
						printf("           ���ҽ��: %s��%s�ɼ���%d��\n",CZguanjianzi1[0],CZguanjianzi2[0],disi1[j]);
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
						printf("           ���ҽ��: %s��%s�ɼ���%d��\n",CZguanjianzi1[0],CZguanjianzi2[0],diwu1[j]);
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
						printf("           ���ҽ��: %s��%s�ɼ���%d��\n",CZguanjianzi1[0],CZguanjianzi2[0],diliu1[j]);
						goto label;
					}
				}
			}
	
            label:                                                  //�鵽�����ȷ�� ���ص�
            printf("\n");    
            printf("         ���²����밴  ��1��\n");               // �β˵�
			printf("         �������˵��밴��2��\n");				// �β˵�
            printf("         �˳���ϵͳ�밴��3��\n");				// �β˵�
            scanf("%d",&fanhuicaidan); 
			printf("\n");

		if (fanhuicaidan==1)
		{
           goto chongxin;                                          //���²��ҵ� goto ��� ��ת�� chongxin  ���²��ҵķ��ص�
		}

		if (fanhuicaidan==2)
		{
			goto zhucaidan;										   //���²��ҵ� goto ��� ��ת�� zhucaidan ���˵��ķ��ص�
		}
	
		if (fanhuicaidan==3)                                                     //�˳�����
		{
			goto tuichu;										   //���²��ҵ� goto ��� ��ת�� tuichu �˳��ķ��ص�
		}
      tuichu:                                                      //�˳��ķ��ص� ���³������˳��ĵĴ���
		system("cls");
		printf("\n");
		printf("          ��л����ʹ��  \n");
		Sleep(1500);
		system("cls");
		printf("\n");
		printf("              �ټ�  \n");
		Sleep(1500);
		system("cls");     
		exit(0);
	}
	
	//-------------------------------------------------------------------------------------------------------------------
	//               ���Ĳ���  ��ӿ�Ŀ �� �ɼ� 
	
	if (caidan==3)
	{
		system("cls");
        printf("\n");
		printf("       ��������ӵ�λ��:");
		scanf("%d",&tianjia);                                     // ��ӳɼ�      �ڳɼ������һ��
			for(i=5;i>=tianjia-1;i--)                             // ���ɼ������λ�ÿ�ʼ ����ƶ�һλ 
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
				strcpy(kemu[i+1],kemu[i]);                               //����Ŀ�����λ�ÿ�ʼ ����ƶ�һλ 
			}
		
		printf("\n");
		printf("       ��������ӵĿ�Ŀ:");
		scanf("%s",&kemu[tianjia-1]);                                    //��ӿ�Ŀ     �ڳɼ������һ��

			for (i=0;i<=5;i++)
			{
				printf("\n");
				printf("       ������%s��%s�ɼ�:",xingming[i],kemu[tianjia-1]); //�����¿�Ŀ�ĳɼ�
					if(i==0)
					{ 
						scanf("%d",&diyi1[tianjia-1]);                   //��ʼ���ɼ���ӽ�λ����
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
			printf("%s �ĸ��Ƴɼ�����:\n",xingming[0]);
			printf("%s %d  %s %d  %s %d  %s %d  %s %d  %s %d  %s %d\n",kemu[0],diyi1[0],kemu[1],diyi1[1],kemu[2],diyi1[2],kemu[3],diyi1[3],kemu[4],diyi1[4],kemu[5],diyi1[5],kemu[6],diyi1[6]); // �� �ǳɼ�
			printf("\n");
            printf("%s �ĸ��Ƴɼ�����:\n",xingming[1]);
			printf("%s %d  %s %d  %s %d  %s %d  %s %d  %s %d  %s %d\n",kemu[0],dier1[0],kemu[1],dier1[1],kemu[2],dier1[2],kemu[3],dier1[3],kemu[4],dier1[4],kemu[5],dier1[5],kemu[6],dier1[6]); // �� �ǳɼ�
			printf("\n");
            printf("%s �ĸ��Ƴɼ�����:\n",xingming[2]);
			printf("%s %d  %s %d  %s %d  %s %d  %s %d  %s %d  %s %d\n",kemu[0],disan1[0],kemu[1],disan1[1],kemu[2],disan1[2],kemu[3],disan1[3],kemu[4],disan1[4],kemu[5],disan1[5],kemu[6],disan1[6]); // �� �ǳɼ�
			printf("\n");
            printf("%s �ĸ��Ƴɼ�����:\n",xingming[3]);
			printf("%s %d  %s %d  %s %d  %s %d  %s %d  %s %d  %s %d\n",kemu[0],disi1[0],kemu[1],disi1[1],kemu[2],disi1[2],kemu[3],disi1[3],kemu[4],disi1[4],kemu[5],disi1[5],kemu[6],disi1[6]); // �� �ǳɼ�
			printf("\n");
            printf("%s �ĸ��Ƴɼ�����:\n",xingming[4]);
			printf("%s %d  %s %d  %s %d  %s %d  %s %d  %s %d  %s %d\n",kemu[0],diwu1[0],kemu[1],diwu1[1],kemu[2],diwu1[2],kemu[3],diwu1[3],kemu[4],diwu1[4],kemu[5],diwu1[5],kemu[6],diwu1[6]); // �� �ǳɼ�
			printf("\n");
            printf("%s �ĸ��Ƴɼ�����:\n",xingming[5]);
			printf("%s %d  %s %d  %s %d  %s %d  %s %d  %s %d  %s %d\n",kemu[0],diliu1[0],kemu[1],diliu1[1],kemu[2],diliu1[2],kemu[3],diliu1[3],kemu[4],diliu1[4],kemu[5],diliu1[5],kemu[6],diliu1[6]); // �� �ǳɼ�
			printf("\n");	
		
			printf("\n");
			printf("\n");
			printf("         �������˵��밴��1��\n");
            printf("         �˳���ϵͳ�밴��2��\n");
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
	//                ���岿��  ɾ����Ŀ
	
	if (caidan==4)
	{
		system("cls");
		printf("\n");
		printf("       ��������Ҫɾ���Ŀ�Ŀ:");
		scanf("%s",&shanchu[0]);                   //Ҫɾ���Ŀ�Ŀ����� shanchu �ַ�������
        printf("\n");
        printf("\n");
		
		for(j=0;j<=6;j++)
		{
			if (strcmp(kemu[j],shanchu[0])==0)
			{
				for(i=j+1;i<=6;i++)                              // ��ɾ���Ŀ�Ŀ֮���  �ɼ��Ϳ�Ŀ   ��ǰ�ƶ�һλ  
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
			printf("%s �ĸ��Ƴɼ�����:\n",xingming[0]);
			printf("%s %d  %s %d  %s %d  %s %d  %s %d  %s %d\n",kemu[0],diyi1[0],kemu[1],diyi1[1],kemu[2],diyi1[2],kemu[3],diyi1[3],kemu[4],diyi1[4],kemu[5],diyi1[5]); // �� �ǳɼ�
			printf("\n");
            printf("%s �ĸ��Ƴɼ�����:\n",xingming[1]);
			printf("%s %d  %s %d  %s %d  %s %d  %s %d  %s %d\n",kemu[0],dier1[0],kemu[1],dier1[1],kemu[2],dier1[2],kemu[3],dier1[3],kemu[4],dier1[4],kemu[5],dier1[5]); // �� �ǳɼ�
			printf("\n");
            printf("%s �ĸ��Ƴɼ�����:\n",xingming[2]);
			printf("%s %d  %s %d  %s %d  %s %d  %s %d  %s %d\n",kemu[0],disan1[0],kemu[1],disan1[1],kemu[2],disan1[2],kemu[3],disan1[3],kemu[4],disan1[4],kemu[5],disan1[5]); // �� �ǳɼ�
			printf("\n");
            printf("%s �ĸ��Ƴɼ�����:\n",xingming[3]);
			printf("%s %d  %s %d  %s %d  %s %d  %s %d  %s %d\n",kemu[0],disi1[0],kemu[1],disi1[1],kemu[2],disi1[2],kemu[3],disi1[3],kemu[4],disi1[4],kemu[5],disi1[5]); // �� �ǳɼ�
			printf("\n");
            printf("%s �ĸ��Ƴɼ�����:\n",xingming[4]);
			printf("%s %d  %s %d  %s %d  %s %d  %s %d  %s %d\n",kemu[0],diwu1[0],kemu[1],diwu1[1],kemu[2],diwu1[2],kemu[3],diwu1[3],kemu[4],diwu1[4],kemu[5],diwu1[5]); // �� �ǳɼ�
			printf("\n");
            printf("%s �ĸ��Ƴɼ�����:\n",xingming[5]);
			printf("%s %d  %s %d  %s %d  %s %d  %s %d  %s %d\n",kemu[0],diliu1[0],kemu[1],diliu1[1],kemu[2],diliu1[2],kemu[3],diliu1[3],kemu[4],diliu1[4],kemu[5],diliu1[5]); // �� �ǳɼ�
			printf("\n");
			
			printf("\n");
			printf("\n");
			printf("         �˳���ϵͳ�밴��1��\n");
			scanf("%d",&fanhuicaidan); 
			
			if (fanhuicaidan==1)
			{
				goto tuichu;   
			}
	}
    printf("\n");
	system("pause"); 
}
