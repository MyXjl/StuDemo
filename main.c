#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "FileOperate.h"

int main()
{
	//打开文件，并将文件中的数据读入数组中
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
	//如果遇到文件尾，则库函数 feof 返回逻辑真；否则，则返回逻辑假。
	/*注意这边当文件内部位置指针指向文件末尾时，并未立即置位 FILE 结构中的文件结束标记，
	只有再执行一次读文件操作，才会置位结束标志，此后调用 feof 才会返回为真
	请注意下这句话：“只有再执行一次读文件操作，才会置位结束标志”*/

	/*就是说  如果文件里面有数据，假如有一条就会读一条，然后就会置位结束标志，
	此后调用feof就会为真了，就不会进入循环，i的值也是正确的。    
	如果没有数据，还是会进入循环，然后尝试读，
	这时候feof就为真了，i会自增一遍，然后循环结束，所以空文件i的值也会为1
	故进入循环后就判断一下文件是否为空，若为空就直接跳出循环，不让i自增一次*/
	while (!feof(fp))
	{
		//判断文件是否为空
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
//菜单
 void menu()
{
	int item = 0;
	printf("			**********学生信息管理系统**********			\n");
	printf("	                           1.添加学生信息								\n");
	printf("	                           2.删除学生信息								\n");
	printf("	                           3.修改学生信息								\n");
	printf("	                           4.查询学生信息								\n");
	printf("	                           5.显示所有学生信息以及统计信息	\n");
	printf("	                           6.退出系统								\n");
		printf("请选择菜单编号:");
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
			printf("即将退出程序!\n");
			break;
		default:printf("请在1-6之间选择\n");
		}
}
//增
void InputStuInfo()
{
	while (1)
	{
		printf("当前数据库中有%d个学生，请输入第%d个学生的信息\n", StuNum,StuNum + 1);
		printf("输入学号:");
		scanf("%s", &s[StuNum].no);
		for (int i = 0; i < StuNum; i++)
		{
			if ((strcmp(s[i].no, s[StuNum].no)) == 0)
			{
				printf("该学生学号已存在，请确认后重新输入！\n");
				printf("输入学号：");
				scanf("%s", &s[StuNum].no);
			}
		}
		printf("输入姓名:");
		scanf("%s", &s[StuNum].name);
		printf("输入性别:");
		scanf("%s", &s[StuNum].sex);
		printf("输入年龄:");
		scanf("%d", &s[StuNum].age);
		StuNum++;
		RenewStuInfo();
		printf("\n录入成功，继续录入输入y，返回上一级请按任意键(除回车以外)：");
		char flag= getchar();
		while (flag == '\n') 
			flag = getchar();
		//printf("%c...............", flag);
		//输入数据不是y或Y，则返回管理主界面
		if (flag != 'y' && flag != 'Y')
			break;
	}
	printf("\n");
	menu();
}
//删
void DeleteStuInfo()
{
	int flag = 0;
	char DeleteNo[5];
	if (StuNum == 0)
	{
		printf("当前数据库中还没有学生信息！无法删除...\n");
	}
	else
	{
		printf("当前数据库中有%d个学生。\n", StuNum);
		printf("学生学号\t学生姓名\t学生年龄\t学生性别\n");
		for (int j = 0; j < StuNum; j++)
		{
			printf("--------------------------------------------------------------------\n");
			printf("%s\t\t%s\t\t%d\t\t%s\n", s[j].no, s[j].name, s[j].age, s[j].sex);
		}
		printf("请输入要删除的学生学号：");
		scanf("%s", DeleteNo);

		for (int k = 0; k < StuNum; k++)
		{
			if (strcmp(s[k].no, DeleteNo) == 0)  //找到要删除的学生信息
			{
				flag = 1;
				//如果只有一条记录
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
		printf("删除成功！\n");
	}
	else
	{
		printf("该学号不存在，请重新输入！\n");
	}
	/*如果加有system("pause");
       这样在运行到此处时，会显示“Press any key to continue ...”，此时需要按下回车键继续程序；
	   如果加有system("cls");
	   这样在运行到此处时，程序会执行清屏命令*/
	system("pause");
	system("cls");
	menu();
}

//改
void ModifyStuInfo()
{
	char ModifyNo[5];
	printf("请输入要修改的学生学号：");
	scanf("%s", ModifyNo);

	int item = 0; //选项
	char NewName[50];//新姓名
	char NewSex[10];			    //新性别
	int NewAge;				 //新年龄
	int flag = 0;

	for (int i = 0; i < StuNum; i++)
	{
		if ((strcmp(ModifyNo, s[i].no)) == 0)
		{
			printf("------------------\n");
			printf("1.修改姓名\n");
			printf("2.修改性别\n");
			printf("3.修改年龄\n");
			printf("4.退出本菜单\n");
			printf("------------------\n");
			while (item != 4)
			{
				printf("请选择子菜单编号:");
				scanf("%d", &item);
				switch (item)
				{
				case 1:
					printf("请输入新的姓名:");
					scanf("%s", NewName);
					strcpy(s[i].name, NewName);
					flag = 1;
					break;
				case 2:
					printf("请输入新的性别:");
					scanf("%s", NewSex);
					strcpy(s[i].sex, NewSex);
					flag = 1;
					break;
				case 3:
					printf("请输入新的年龄:");
					scanf("%d", &NewAge);
					s[i].age = NewAge;
					flag = 1;
					break;
				case 4:
					break;
				default:printf("请在1-4之间选择\n");
				}
			}
		}// end if 
	}//end for

	if (flag)
	{
		RenewStuInfo();
		printf("修改成功!\n");
	}
	else
	{
		printf("该学号不存在,或未修改任何数据!\n");
	}
	system("pause");
	system("cls");
	menu();
}

//查
void QueryStuInfo()
{
	int item = 0; //选项
	int flag = 0;
	char QueryName[50];	 //姓名
	char QueryNo[5];			//学号

	printf("------------------\n");
	printf("1.根据姓名查询信息\n");
	printf("2.根据学号查询信息\n");
	printf("3.退出本菜单\n");
	printf("------------------\n");
	

	while (item != 3)
	{
		printf("请选择子菜单编号:");
		scanf("%d", &item);
		switch (item)
		{
		case 1:
			printf("请输入要查询信息的学生姓名:");
			scanf("%s", QueryName);
			for (int j = 0; j < StuNum; j++)
			{
				if (strcmp(QueryName, s[j].name) == 0)
				{
					flag = 1;
					printf("学生学号\t学生姓名\t学生年龄\t学生性别\n");
					printf("--------------------------------------------------------------------\n");
					printf("%s\t\t%s\t\t%d\t\t%s\n", s[j].no, s[j].name, s[j].age, s[j].sex);
				}
			}
			if (0 == flag)
				printf("该学生姓名不存在！\n\n");
			flag = 0;
			break;
		case 2:
			printf("请输入要查询信息的学生学号:");
			scanf("%s", QueryNo);
			for (int j = 0; j < StuNum; j++)
			{
				if (strcmp(QueryNo, s[j].no) == 0)
				{
					flag = 1;
					printf("学生学号\t学生姓名\t学生年龄\t学生性别\n");
					printf("--------------------------------------------------------------------\n");
					printf("%s\t\t%s\t\t%d\t\t%s\n", s[j].no, s[j].name, s[j].age, s[j].sex);
				}
			}
			if (0 == flag)
				printf("该学生学号不存在！\n\n");
			flag = 0;
			break;
		case 3:
			break;
		default:printf("请在1-3之间选择\n");
		}
	}//end while
	system("pause");
	system("cls");
	menu();
}


//展示所有学生信息
void Display()
{
	if (StuNum == 0)
	{
		printf("当前数据库中还没有学生信息！\n");
	}
	else
	{
		printf("当前数据库中有%d个学生。\n", StuNum);
		printf("学生学号\t学生姓名\t学生年龄\t学生性别\n");
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
//更新数据库
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

