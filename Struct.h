/*包含pragma once 语句的文件只会被编译一次。
表示在编译的时候, 这个文件只被包含(include)一次
这样, 可以减少整个编译过程中打开这个文件的次数*/
#pragma once
typedef struct  //定义一个学生结构体
{
	char name[50];	 //姓名
	char no[5];			//学号
	char sex[10];	     //性别
	int age;				 //年龄
}StuInfo;