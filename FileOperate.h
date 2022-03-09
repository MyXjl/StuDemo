#pragma once
#include "Struct.h"
//学生信息记录50条
#define STUDENT_SIZE 50

//学生信息，以数组方式组织数据，全局数据
StuInfo s[STUDENT_SIZE];
int StuNum = 0;  //记录学生个数

//函数声明

/*学生信息管理主界面*/
void menu();
/*输入学生信息*/
void InputStuInfo();
/*删除学生信息*/
void DeleteStuInfo();
/*修改学生信息*/
void ModifyStuInfo();
/*查询学生信息*/
void QueryStuInfo();
/*显示所有学生信息*/
void Display();
/*更新数据库*/
void RenewStuInfo();

