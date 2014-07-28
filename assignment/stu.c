/*
 * =====================================================================================
 *
 *       Filename:  stu.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年06月13日 21时00分53秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Sweetheart502, liyingxiao502@gmail.com
 *        Company:  Class 1304 of Software Engineering
 *
 * =====================================================================================
 */

#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MALLOC (ST *)malloc(sizeof(ST))

//生日 年月日
typedef struct birth_info {
	int year;
	int month;
	int day;
}Birth;

//宿舍 楼房间床
typedef struct room_info {
	int build;
	int room;
	int bed;
}Room;

//学生信息
typedef struct node {
	int num;
	char name[20];
	char sex;
	Birth birth;
	Room room;
	struct node *next;
}ST;

/*
//创建单向链表函数声明
ST *creatlink ();
//文件函数声明
void write_to_file (ST *);
void read_file (ST *);
//查找函数声明
void find_info (ST *);
//插入函数声明
void insert_info (ST *);
void insert_num (ST *, ST *);
void insert_head (ST *, ST *);
void insert_tail (ST *, ST *);
//删除函数声明
void delete_info (ST *);
void delete_num (ST *);
void delete_name (ST *);
void delete_room (ST *);
//修改函数声明
void change_info (ST *);
//显示函数声明
void print (ST *);
*/

//存储学生信息
void write_to_file (ST *head)
{
	FILE  *fp;                             //文件指针
	ST *p = head->next;                    //使p指向第一个有数据的结点

	fp = fopen ("stu.txt", "wt");          //以写入的方式打开文件

	if (fp == NULL) {
		printf ("Cannot open the file!\n");
		exit (0);
	}

	while (p != NULL) {
		//将链表信息写入文件
		fprintf (fp, "%d\t%s\t%c\t%d\t%d\t%d\t%d\t%d\t%d\n", p->num, p->name, p->sex, p->birth.year, p->birth.month, p->birth.day, p->room.build, p->room.room, p->room.bed); 
		//使p遍历整个链表
		p = p->next;
	}

	fclose (fp);                           //关闭文件
}


//读取文件信息
void read_file (ST *head)
{
	ST *p, *q;
	FILE *fp;

	fp = fopen ("stu.txt", "rt");

	if (fp == NULL) {
		printf ("Cannot ioen the file!\n");
		exit (0);
	}

	p = head;
	q = MALLOC;

	while (fscanf (fp, "%d %s %c %d %d %d %d %d %d", &q->num, q->name, &q->sex, &q->birth.year, &q->birth.month, &q->birth.day, &q->room.build, &q->room.room, &q->room.bed) != EOF) {
		p = p->next = q;         //挂链挪尾指针
		q = MALLOC;
	}
	
	p->next = NULL;
	free (q);

	fclose (fp);
}


//创建单向链表
ST *creatlink ()
{
	ST *head, *p, *q;
	char choice;

	//创建头结点
	head = p = MALLOC;

	do {
		q = MALLOC;
		scanf ("%d %s %c %d %d %d %d %d %d", &q->num, q->name, &q->sex, &q->birth.year, &q->birth.month, &q->birth.day, &q->room.build, &q->room.room, &q->room.bed);

	/*	
		printf ("\nplease input the num:\n");
		scanf ("%d", &q->num);

		printf ("\nplease input the name:\n");
		scanf ("%s", q->name);

		printf ("\nplease input the sex:\n");
		getchar ();
		scanf ("%c", &q->sex);

		printf ("\nplease input the birth(year month day):\n");
		scanf ("%d %d %d", &q->birth.year,  &q->birth.month, &q->birth.day);
		
		printf ("\nplease input the room(build room bed):\n");
		scanf ("%d %d %d", &q->room.build, &q->room.room, &q->room.bed);
	*/
		//挂链挪指针
		p->next = q;
		p = q;

		printf ("\nDo you want to continue? (Y/N)\n");
		getchar ();
		scanf ("%c", &choice);
	} while (choice == 'Y' || choice == 'y');
	p->next = NULL;	//尾结点指针域赋值为NULL

	write_to_file (head);	//调用存储函数，将学生信息存储在文件中
	
	return head;
}


//输出函数
void print_info (ST *head)
{
	ST *p = head->next;

	read_file (head);

	if (p == NULL) {
		printf ("该链表是一个空链表！\n");
	}

	else {
		printf ("\nnum\tname\tsex\tyear month day build room bed\n");
		while (p) {
			//将链表信息输出显示
			printf ("%d\t%-18s%c\t%5d%5d%5d%5d%5d%5d\n", p->num, p->name, p->sex, p->birth.year, p->birth.month, p->birth.day, p->room.build, p->room.room, p->room.bed);
			//使p遍历整个链表
			p = p->next;
		}
	}
}


//查找学生信息
void find_info (ST *head)
{
	ST *p = head->next;
	char choice[10];                       //查找方式

	//读取数据信息
	read_file (head);

	//选择查找方式
	printf ("\n欢迎进入学生宿舍管理系统\n");
	printf ("\n请输入您所要进行的查找方式:\n");
	getchar ();
	scanf ("%s", choice);

	//学号查询
	if (strcmp (choice, "num") == 0) {
		int num;
		printf ("\n请输入您所要查找的学号：\n");
		scanf ("%d", &num);

		while (p != NULL) {
			if (p->num == num) {
				printf ("成功找到您所查找的学生信息！信息如下：\n");
				printf ("%d\t%-18s%c\t%5d%5d%5d%5d%5d%5d\n", p->num, p->name, p->sex, p->birth.year, p->birth.month, p->birth.day, p->room.build, p->room.room, p->room.bed);
				break;
			}
			p = p->next;
		}

		if (p == NULL) {
			printf ("抱歉没有找到您所要查找的学生信息！\n");
		}
	}

	//姓名查询
	if (strcmp (choice, "name") == 0) {
		char name[20];
		printf ("\n请输入您所要查找的姓名：\n");
		scanf ("%s", name);

		while (p != NULL) {
			if (strcmp (p->name, name) == 0) {
				//成功找到
				printf ("成功找到您所查找的学生信息！信息如下：\n");
				//输出所找学生信息
				printf ("num\tname\tsex\tyear month day  build room bed\n");
				printf ("%d\t%-18s%c\t%5d%5d%5d%5d%5d%5d\n", p->num, p->name, p->sex, p->birth.year, p->birth.month, p->birth.day, p->room.build, p->room.room, p->room.bed);
				break;
			}
			p = p->next;
		}

		if (p == NULL) {
			printf ("抱歉没有找到您所要查找的学生信息！\n");
		}
	}
	write_to_file (head);
}
//插入在某学号学生之后
void insert_num (ST *head, ST *q)
{
	ST *p = head->next;
	int num;

	printf ("输入您所要插入的学生学号:\n");
	scanf ("%d", &num);

	while (p != NULL) {
		if (p->num == num) {
			printf ("成功插入！\n");
			q->next = p->next;
			p->next = q;
			break;
		}
		p = p->next;
	}

	if (p == NULL) {
		printf ("学生信息中没有您所输入学号的学生信息。\n");
	}

	write_to_file (head);
}


//头插法
void insert_head (ST *head, ST *q)
{
	q = head->next;
	head->next = q;
}

//尾插法
void insert_tail (ST *head, ST *q)
{
	ST *p = head;


	//将p指向尾结点位置
	while (p->next != NULL) {
		p = p->next;
	}

	//将q插入在p之后，作为新的尾结点
	q->next = p->next;
	p->next = q;
}


//插入学生信息
void insert_info (ST *head)
{
	ST *q;                               //插入的结点信息
	int choice;                          //查找方式序号

	//读取文件信息
	read_file (head);


	//插入学生信息
	printf ("\n欢迎进入学生宿舍管理系统\n");
	printf ("\n请输入您所要插入学生的信息:\n");
	q = MALLOC;
	printf ("num name sex year month day build room bed\n");
	scanf ("%d %s %c %d %d %d %d %d %d", &q->num, q->name, &q->sex, &q->birth.year, &q->birth.month, &q->birth.day, &q->room.build, &q->room.room, &q->room.bed);

	//选择插入方式
	printf ("\n请根据提示选择您所要选择的插入方式(1/2/3)：\n");
	printf ("1:insert_num(插入在某学号学生之后)\n2:insert_head(插入头结点之后)\n3:insert_tail(插入在尾结点之后)\n");
	scanf ("%d", &choice);

	//根据选择方式 调用不同的函数
	switch (choice) {
		case 1:
			insert_num (head, q);   break;
		case 2:
			insert_head (head, q);    break;
		case 3:
			insert_tail (head, q);    break;
	}

	write_to_file (head);
}




//根据学号进行删除操作
void delete_num (ST *head)
{
	ST *p = head->next, *q = head;
	int num;

	printf ("请输入您所要删除的学号信息：\n");
	scanf ("%d", &num);
	while (p != NULL) {
		if (p->num == num) {	//满足条件则找到该学生

			printf ("成功删除该学生信息。\n");
			q->next = p->next;
			free (p);
			break;
		}
		//p = p->next;	//不满足条件则继续往后跑，遍历整个链表	
		q = p;          //q始终要在p的前去借点上指着    
		p = p->next;
	}
	if (p == NULL) {
		printf ("抱歉没有找到您做要删除的学生信息。\n");
	}
}


//根据姓名进行删除操作
void delete_name (ST *head) 
{
	ST *p = head->next, *q = head;
	char name[20];

	printf ("请输入你所要删除的姓名信息：\n");
	scanf ("%s", name);	
	
	while (p != NULL) {
		if (strcmp (p->name, name) == 0) {	//满足条件则找到该学生

			printf ("成功删除该学生信息。\n");
			q->next = p->next;
			free (p);
			break;
		}
		//p = p->next;	//不满足条件则继续往后跑，遍历整个链表
		q = p;
		p = p->next;
	}
	if (p == NULL) {
		printf ("抱歉没有找到您所要删除的学生信息。\n");
	}
}



//根据宿舍信息进行删除操作
void delete_room (ST *head)
{
	ST *p = head->next, *q = head;
	int build, room, bed;

	printf ("请输入您所要删除的宿舍信息：\n");
	scanf ("%d %d %d", &build, &room, &bed);

	while (p != NULL) {
		if (p->room.build == build && p->room.room == room && p->room.bed == bed) {	//满足条件则找到该学生

			printf ("成功删除该学生信息。\n");
			q->next = p->next;
			free (p);
			break;
		}
		//p = p->next;      //不满足条件则继续往后跑，遍历整个链表
		q = p;
		p = p->next;
	}
	if (p == NULL) {
		printf ("抱歉没有找到您所要删除的学生信息。\n");
	}
}


//删除函数
void delete_info (ST *head)
{
	char choice[12];                 //删除方式

	//读取数据信息
	read_file (head);

	//选择删除方式
	printf ("\n欢迎进入学生宿舍管理系统\n");
	printf ("\n请输入您所要进行的删除方式(num/name/room):\n");
	getchar ();
	scanf ("%s", choice);

	if (strcmp (choice, "num") == 0) {	//根据学号信息进行删除操作

		delete_num (head);
	}
	if (strcmp (choice, "name") == 0) {	//根据姓名信息进行删除操作

		delete_name (head);
	}
	if (strcmp(choice, "room") == 0) {	//根据宿舍信息进行删除操作

		delete_room (head);
	}

	write_to_file (head);
}


void change_num (ST *head) 
{
	ST *p = head->next;
	int num;

	printf ("请输入您所要修改的学生学号：\n");
	scanf ("%d", &num);

	while (p != NULL) {
		if (p->num == num) {
			scanf ("%d %s %c %d %d %d %d %d %d", &p->num, p->name, &p->sex, &p->birth.year, &p->birth.month, &p->birth.day, &p->room.build, &p->room.room, &p->room.bed);
			break;
		}
		p = p->next;
	}
}


void change_name (ST *head)
{
	ST *p = head->next;
	char name[20];

	printf ("请输入您所要修改的学生姓名：\n");
	scanf ("%s", name);

	while (p != NULL) {
		if (strcmp (p->name, name) == 0) {
			scanf ("%d %s %c %d %d %d %d %d %d", &p->num, p->name, &p->sex, &p->birth.year, &p->birth.month, &p->birth.day, &p->room.build, &p->room.room, &p->room.bed);
		}
		p = p->next;
	}
}

//修改函数
void change_info (ST *head)
{
	ST *p = head->next;
	char choice[20];

	//读取数据信息
	read_file (head);

	//选择删除方式
	printf ("\n欢迎进入学生宿舍管理系统\n");
	printf ("\n请输入您所要进行的修改方式(num/name/room):\n");
	getchar ();
	scanf ("%s", choice);

	if (strcmp (choice, "num") == 0) {	//根据学号信息进行修改操作

		change_num (head);
	}
	if (strcmp (choice, "name") == 0) {	//根据姓名信息进行修改操作

		change_name (head);
	}

	write_to_file (head);
}


//排序函数
void sort_info (ST *head)
{
	ST *p = head->next;
}


//统计函数
void count_info (ST *head)
{

}

//主菜单
void menu () 
{
	ST *head;
	int choice;
	char ch;

	//只有当用户执行退出系统这一操作时，才会退出系统，否则进行完某一操作之后，继续选择操作。
	while (1) {
		printf ("\n\t\t**********欢迎登陆西安邮电大学学生宿舍管理系统**********\n");
		printf ("\n\t\t**********************  主 菜 单  **********************\n");
		printf ("\n\t\t*|  1:\t\t录入学生信息\n");
		printf ("\n\t\t*|  2:\t\t查找学生信息\n");
		printf ("\n\t\t*|  3:\t\t插入学生信息\n");
		printf ("\n\t\t*|  4:\t\t删除学生信息\n");
		printf ("\n\t\t*|  5:\t\t修改学生信息\n");
		printf ("\n\t\t*|  6:\t\t排序学生信息\n");
		printf ("\n\t\t*|  7:\t\t统计学生信息\n");
		printf ("\n\t\t*|  8:\t\t显示学生信息\n");
		printf ("\n\t\t*|  9:\t\t退出学生系统\n");

	
		printf ("\n\t\t请根据系统提示完成操作。\n");
		printf ("\n\t\t输入您所要执行操作的序号：\n");
		scanf ("%d", &choice);

		switch (choice) {
			case 1:
				head = creatlink (head);   break;
			case 2:
				find_info (head);          break;
			case 3:
				insert_info (head);        break;
			case 4:
				delete_info (head);        break;
			case 5:
				change_info (head);        break;
			case 6:
				sort_info (head);          break;
			case 7:
				count_info (head);         break;
			case 8:
				print_info (head);         break;
			case 9:
				printf ("Do you want to exit the system?(Y/N)\n");
				getchar ();
				scanf ("%c", &ch);

				if (ch == 'Y' || ch == 'y') {
					printf ("您已成功退出系统.\n");
					exit (0);
				}
					

				if (ch == 'N' || ch == 'n') {
				}
		}
	}
}

	
//主函数
int main(int argc, char *argv[])
{
	menu ();

	return EXIT_SUCCESS;
}

