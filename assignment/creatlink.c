/**
 *	HOMEWORK
 *	Topic: 设head指向一个非空单向链表,要求:输出单向链表数据域值为奇数的结点个数;输出单向链表数据域的最大值;逆向输出单向链表数据域的值.
 *	Data : 2014.6.6   Friday  16:29
 *	Name : 李映霄
 */


#include <stdio.h>
#include <stdlib.h>
#define N 3


typedef struct node {
	int data;
	struct node *next;
}ST;


//创建链表
ST *creatlink1(int a[])
{
	ST *head, *tail, *p;
	int i;

	for(i = 0; i < N; i++) {
		p = (ST *)malloc(sizeof(ST));
		p->data = a[i];
		p->next = NULL;
		if(i == 0) {
			head = tail = p;
		}
		else 
			tail = tail->next = p;
	}

	/*
	head = tail = (ST *)malloc(sizeof(ST));
	head->data = a[0];
	head->next = NULL;
	
	for(i = 1; i < N; i++) {
		p = (ST *)malloc(sizeof(ST));
		p->data = a[i];
		p->next = NULL;
		tail->next = p;
		tail = p;
	}
	*/
	

	return head;
}


/*
ST *creatlink(int a[])
{
	ST *head, *p;
	head = NULL
	int i;

	for(i = N-1; i >= 0; i--) {
		p = (ST *)malloc(sizeof(ST));
		p->data = a[i];
		p->next = head;
		head = p;
	}

	return head;
}
*/



/*
//统计数据域奇数的数量
int count(ST *head)
{
	int number = 0;
	ST *p = head;

	while(p != NULL) {
		number = number + p->data % 2;
	
	//	if(p->data % 2 != 0) {
	//		number++;
	//	}
		p = p->next;
	}

	return number;
}
*/


/*
//输出数据域最大值
ST *max(ST *head)
{
	ST *p = head, *pmax = head;

	while(p != NULL) {
		if(p->data > pmax->data) {
			pmax = p;
		}
		p = p->next;
	}

	return pmax;
}
*/


/*
//链表的销毁
ST * destory(ST *head)
{
	ST *p = head, *q = p->next;

	while(q != NULL) {
		free(p);
		p = q;
		q = p->next;
	}

	printf("链表已经成功销毁.\n");

	return q;
}
*/


//链表的逆置
ST *inverse(ST *head)
{
	ST *p, *q, *t;
	
	p = head;
	q = p->next;
	p->next = NULL;
	t = NULL;

	while(q != NULL) {
		t = q->next;
		q->next = p;
		p = q;
		q = t;
	}

	return p;
}


/*
//将尾结点作为单向链表的头结点
ST *tail_to_head (ST *head)
{
	ST *p, *q;

	//将p指向尾结点，将q指向p的前驱结点
	for (p = head; p->next; q = p, p = p->next);
	p->next = head;
	q->next = NULL;

	return p;
}
*/


/*
//最大值结点作为新的尾结点
ST *max_to_tail (ST *head)
{
	ST *p, *q, *pmax;

	//找到最大结点的地址
	pmax = max (head);
	
	if (pmax == head) {
		//先将p指向尾结点
		for (p = head; p->next; p = p->next);
		//将最大值结点作为尾结点
		p = p->next = pmax;
		//将head指向第二个结点
		head = head->next;
		//在进行挪了头指针之后再进行置尾结点next域为NULL
		p->next = NULL;
	}	printf ("\n欢迎进入学生宿舍管理系统\n");

	else if (pmax->next != NULL) {
		//先找到最大结点的前驱结点
		for(q = head; q->next != pmax; q = q->next);
		//挂链
		q->next = pmax->next;
		//使p指向尾结点
		for (p = head; p->next; p = p->next);
		//挂链，使最大值结点作为尾结点
		p->next = pmax;
		pmax->next = NULL;
	}
	//返回头指针
	return head;
}
*/

/*
//删除链表中的最大值结点
ST *delete(ST *head)
{
	ST *p, *q, *pmax;

	pmax = max(head);

	for (p = head; p && p->data != pmax->data; q = p, p = p->next);
	if (!p)
	      printf("Not found!\n");
	else {
		if (p == head)
		      head = head->next;
		else 
		      q->next = p->next;
		free (p);
	}

	return head;
}
*/

/*
//思路不清楚，未解决
//数据域的值含有重复值且升序排列，删除值为key的值
ST *find_repeate_key (ST *head, int key)
{
	ST *p, q;

	for (p = head->next; p; p = p->next) {
		if (p->data == key) 
		      delete (head, p);
	}
}
*/

//输出函数
void print(ST *head)
{
	ST *p = head;
	
	while(p != NULL) {
		printf("%4d", p->data);
		p = p->next;
	}

	printf("\n");
}


//主函数
int main(void)
{
	ST *head, *p;
	int a[N], i;
	int key;

	for(i = 0; i < N; i++) {
		scanf("%d", a + i);
	}

	head = creatlink1(a);

	printf("数据域的值输出表示为:\n");
	print(head);
	
	//printf("the ODD_number is:\n");
	//printf("%d\n", count(head));
	
	//p = max(head);
	//printf("the max is %d\n", p->data);
	
	//链表逆置
	head = inverse(head);
	
	//尾结点作为头结点
	//head = tail_to_head (head);

	//删除最大值结点
	//head = delete(head);
	
	//将最大值结点作为尾结点
	//head = max_to_tail (head);

	//删除数据域值为key的结点
	//head = delete_repeate_key (head, key);
	
	//head = destory(head);
	//printf("链表数据域的值逆向输出表示为:\n");
	print(head);

	return 0;
}
