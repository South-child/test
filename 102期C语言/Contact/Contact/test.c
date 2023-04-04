#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

void menu()
{
	printf("*********************************\n");
	printf("****  1. add     2. del      ****\n");
	printf("****  3. search  4. modify   ****\n");
	printf("****  5. show    6. sort     ****\n");
	printf("****  0. exit                ****\n");
	printf("*********************************\n");
}

enum Option
{
	EXIT,//退出 0
	ADD,//增加联系人 1
	DEL,//删除联系人 2
	SEARCH,//查找联系人 3
	MODIFY,//修改联系人 4
	SHOW,//打印信息 5
	SORT//排序 6
};

int main()
{
	int input = 0;

	//创建一个通讯录
	struct Contact con;
	
	//初始化通讯录
	InitContact(&con);
	//最多可以放3个人的信息了
	//空间不够可以增容

	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);//增加联系人
			break;
		case DEL:
			DelContact(&con);//删除指定联系人
			break;
		case SEARCH:
			SearchContact(&con);//查找指定联系人
			break;
		case MODIFY:
			ModifyContact(&con);//修改指定联系人
			break;
		case SHOW:
			ShowContact(&con);//显示所有的联系人
			break;
		case EXIT:
			//保存通讯录
			SaveContact(&con);
			//销毁通讯录
			DestroyContact(&con);
			printf("退出通讯录\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
	return 0;
}