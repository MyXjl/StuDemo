#pragma once
#include "Struct.h"
//ѧ����Ϣ��¼50��
#define STUDENT_SIZE 50

//ѧ����Ϣ�������鷽ʽ��֯���ݣ�ȫ������
StuInfo s[STUDENT_SIZE];
int StuNum = 0;  //��¼ѧ������

//��������

/*ѧ����Ϣ����������*/
void menu();
/*����ѧ����Ϣ*/
void InputStuInfo();
/*ɾ��ѧ����Ϣ*/
void DeleteStuInfo();
/*�޸�ѧ����Ϣ*/
void ModifyStuInfo();
/*��ѯѧ����Ϣ*/
void QueryStuInfo();
/*��ʾ����ѧ����Ϣ*/
void Display();
/*�������ݿ�*/
void RenewStuInfo();

