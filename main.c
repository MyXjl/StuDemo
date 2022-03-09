#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "FileOperate.h"

int main()
{
	//���ļ��������ļ��е����ݶ���������
	FILE* fp;
	fp = fopen("StudentInfo.txt", "r");
	if (fp == NULL)
	{
		printf("File opening failure!\n");
		exit(-1);
	}
	int i = 0;
	char flag = fgetc(fp);
	rewind(fp);
	//��������ļ�β����⺯�� feof �����߼��棻�����򷵻��߼��١�
	/*ע����ߵ��ļ��ڲ�λ��ָ��ָ���ļ�ĩβʱ����δ������λ FILE �ṹ�е��ļ�������ǣ�
	ֻ����ִ��һ�ζ��ļ��������Ż���λ������־���˺���� feof �Ż᷵��Ϊ��
	��ע������仰����ֻ����ִ��һ�ζ��ļ��������Ż���λ������־��*/

	/*����˵  ����ļ����������ݣ�������һ���ͻ��һ����Ȼ��ͻ���λ������־��
	�˺����feof�ͻ�Ϊ���ˣ��Ͳ������ѭ����i��ֵҲ����ȷ�ġ�    
	���û�����ݣ����ǻ����ѭ����Ȼ���Զ���
	��ʱ��feof��Ϊ���ˣ�i������һ�飬Ȼ��ѭ�����������Կ��ļ�i��ֵҲ��Ϊ1
	�ʽ���ѭ������ж�һ���ļ��Ƿ�Ϊ�գ���Ϊ�վ�ֱ������ѭ��������i����һ��*/
	while (!feof(fp))
	{
		//�ж��ļ��Ƿ�Ϊ��
		if (flag == EOF)
			break;
		fscanf(fp, "%s %s %s %d\n", &s[i].name, &s[i].no, &s[i].sex, &s[i].age);
		i++;
	}

	fclose(fp);
	StuNum = i;
	menu();	
	return 0;
}
//�˵�
 void menu()
{
	int item = 0;
	printf("			**********ѧ����Ϣ����ϵͳ**********			\n");
	printf("	                           1.���ѧ����Ϣ								\n");
	printf("	                           2.ɾ��ѧ����Ϣ								\n");
	printf("	                           3.�޸�ѧ����Ϣ								\n");
	printf("	                           4.��ѯѧ����Ϣ								\n");
	printf("	                           5.��ʾ����ѧ����Ϣ�Լ�ͳ����Ϣ	\n");
	printf("	                           6.�˳�ϵͳ								\n");
		printf("��ѡ��˵����:");
		scanf("%d", &item);
		int n = 0;
		switch (item)
		{
		case 1:
			InputStuInfo();
			break;
		case 2:
			DeleteStuInfo();
			break;
		case 3:
			ModifyStuInfo();
			break;
		case 4:
			QueryStuInfo();
			break;
		case 5:
			Display();
			break;
		case 6:
			printf("�����˳�����!\n");
			break;
		default:printf("����1-6֮��ѡ��\n");
		}
}
//��
void InputStuInfo()
{
	while (1)
	{
		printf("��ǰ���ݿ�����%d��ѧ�����������%d��ѧ������Ϣ\n", StuNum,StuNum + 1);
		printf("����ѧ��:");
		scanf("%s", &s[StuNum].no);
		for (int i = 0; i < StuNum; i++)
		{
			if ((strcmp(s[i].no, s[StuNum].no)) == 0)
			{
				printf("��ѧ��ѧ���Ѵ��ڣ���ȷ�Ϻ��������룡\n");
				printf("����ѧ�ţ�");
				scanf("%s", &s[StuNum].no);
			}
		}
		printf("��������:");
		scanf("%s", &s[StuNum].name);
		printf("�����Ա�:");
		scanf("%s", &s[StuNum].sex);
		printf("��������:");
		scanf("%d", &s[StuNum].age);
		StuNum++;
		RenewStuInfo();
		printf("\n¼��ɹ�������¼������y��������һ���밴�����(���س�����)��");
		char flag= getchar();
		while (flag == '\n') 
			flag = getchar();
		//printf("%c...............", flag);
		//�������ݲ���y��Y���򷵻ع���������
		if (flag != 'y' && flag != 'Y')
			break;
	}
	printf("\n");
	menu();
}
//ɾ
void DeleteStuInfo()
{
	int flag = 0;
	char DeleteNo[5];
	if (StuNum == 0)
	{
		printf("��ǰ���ݿ��л�û��ѧ����Ϣ���޷�ɾ��...\n");
	}
	else
	{
		printf("��ǰ���ݿ�����%d��ѧ����\n", StuNum);
		printf("ѧ��ѧ��\tѧ������\tѧ������\tѧ���Ա�\n");
		for (int j = 0; j < StuNum; j++)
		{
			printf("--------------------------------------------------------------------\n");
			printf("%s\t\t%s\t\t%d\t\t%s\n", s[j].no, s[j].name, s[j].age, s[j].sex);
		}
		printf("������Ҫɾ����ѧ��ѧ�ţ�");
		scanf("%s", DeleteNo);

		for (int k = 0; k < StuNum; k++)
		{
			if (strcmp(s[k].no, DeleteNo) == 0)  //�ҵ�Ҫɾ����ѧ����Ϣ
			{
				flag = 1;
				//���ֻ��һ����¼
				if (StuNum == 1)
				{
					StuNum = 0;
				}
				else
				{
					for (int h = k + 1; k < StuNum; k++)
					{
						s[k].age = s[h].age;
						strcpy(s[k].name, s[h].name);
						strcpy(s[k].sex, s[h].sex);
						strcpy(s[k].no, s[h].no);
					}
					StuNum--;
				}
			}
		}
	}


	if (flag)
	{
		RenewStuInfo();
		printf("ɾ���ɹ���\n");
	}
	else
	{
		printf("��ѧ�Ų����ڣ����������룡\n");
	}
	/*�������system("pause");
       ���������е��˴�ʱ������ʾ��Press any key to continue ...������ʱ��Ҫ���»س�����������
	   �������system("cls");
	   ���������е��˴�ʱ�������ִ����������*/
	system("pause");
	system("cls");
	menu();
}

//��
void ModifyStuInfo()
{
	char ModifyNo[5];
	printf("������Ҫ�޸ĵ�ѧ��ѧ�ţ�");
	scanf("%s", ModifyNo);

	int item = 0; //ѡ��
	char NewName[50];//������
	char NewSex[10];			    //���Ա�
	int NewAge;				 //������
	int flag = 0;

	for (int i = 0; i < StuNum; i++)
	{
		if ((strcmp(ModifyNo, s[i].no)) == 0)
		{
			printf("------------------\n");
			printf("1.�޸�����\n");
			printf("2.�޸��Ա�\n");
			printf("3.�޸�����\n");
			printf("4.�˳����˵�\n");
			printf("------------------\n");
			while (item != 4)
			{
				printf("��ѡ���Ӳ˵����:");
				scanf("%d", &item);
				switch (item)
				{
				case 1:
					printf("�������µ�����:");
					scanf("%s", NewName);
					strcpy(s[i].name, NewName);
					flag = 1;
					break;
				case 2:
					printf("�������µ��Ա�:");
					scanf("%s", NewSex);
					strcpy(s[i].sex, NewSex);
					flag = 1;
					break;
				case 3:
					printf("�������µ�����:");
					scanf("%d", &NewAge);
					s[i].age = NewAge;
					flag = 1;
					break;
				case 4:
					break;
				default:printf("����1-4֮��ѡ��\n");
				}
			}
		}// end if 
	}//end for

	if (flag)
	{
		RenewStuInfo();
		printf("�޸ĳɹ�!\n");
	}
	else
	{
		printf("��ѧ�Ų�����,��δ�޸��κ�����!\n");
	}
	system("pause");
	system("cls");
	menu();
}

//��
void QueryStuInfo()
{
	int item = 0; //ѡ��
	int flag = 0;
	char QueryName[50];	 //����
	char QueryNo[5];			//ѧ��

	printf("------------------\n");
	printf("1.����������ѯ��Ϣ\n");
	printf("2.����ѧ�Ų�ѯ��Ϣ\n");
	printf("3.�˳����˵�\n");
	printf("------------------\n");
	

	while (item != 3)
	{
		printf("��ѡ���Ӳ˵����:");
		scanf("%d", &item);
		switch (item)
		{
		case 1:
			printf("������Ҫ��ѯ��Ϣ��ѧ������:");
			scanf("%s", QueryName);
			for (int j = 0; j < StuNum; j++)
			{
				if (strcmp(QueryName, s[j].name) == 0)
				{
					flag = 1;
					printf("ѧ��ѧ��\tѧ������\tѧ������\tѧ���Ա�\n");
					printf("--------------------------------------------------------------------\n");
					printf("%s\t\t%s\t\t%d\t\t%s\n", s[j].no, s[j].name, s[j].age, s[j].sex);
				}
			}
			if (0 == flag)
				printf("��ѧ�����������ڣ�\n\n");
			flag = 0;
			break;
		case 2:
			printf("������Ҫ��ѯ��Ϣ��ѧ��ѧ��:");
			scanf("%s", QueryNo);
			for (int j = 0; j < StuNum; j++)
			{
				if (strcmp(QueryNo, s[j].no) == 0)
				{
					flag = 1;
					printf("ѧ��ѧ��\tѧ������\tѧ������\tѧ���Ա�\n");
					printf("--------------------------------------------------------------------\n");
					printf("%s\t\t%s\t\t%d\t\t%s\n", s[j].no, s[j].name, s[j].age, s[j].sex);
				}
			}
			if (0 == flag)
				printf("��ѧ��ѧ�Ų����ڣ�\n\n");
			flag = 0;
			break;
		case 3:
			break;
		default:printf("����1-3֮��ѡ��\n");
		}
	}//end while
	system("pause");
	system("cls");
	menu();
}


//չʾ����ѧ����Ϣ
void Display()
{
	if (StuNum == 0)
	{
		printf("��ǰ���ݿ��л�û��ѧ����Ϣ��\n");
	}
	else
	{
		printf("��ǰ���ݿ�����%d��ѧ����\n", StuNum);
		printf("ѧ��ѧ��\tѧ������\tѧ������\tѧ���Ա�\n");
		for (int j = 0; j < StuNum; j++)
		{
			printf("--------------------------------------------------------------------\n");
			printf("%s\t\t%s\t\t%d\t\t%s\n", s[j].no, s[j].name, s[j].age, s[j].sex);
		}
	}
	system("pause");
	system("cls");
	menu();
}
//�������ݿ�
void RenewStuInfo()
{
	FILE* fp;
	fp = fopen("StudentInfo.txt", "w");
	if (fp == NULL)
	{
		printf("File opening failure!\n");
		exit(-1);
	}
	if (StuNum == 0)
	{
		fclose(fp);
		return;
	}
	for (int m = 0; m < StuNum; m++)
		fprintf(fp, "%s %s %s %d\n", s[m].name, s[m].no, s[m].sex, s[m].age);
	fclose(fp);
}

