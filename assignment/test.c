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

	head = tail = (ST *)malloc(sizeof(ST));

	for(i = 0; i < N; i++) {
		p = (ST *)malloc(sizeof(ST));
		p->data = a[i];
		tail = tail->next = p;
	}
	p->next = NULL;

	return head;
}


//排序函数
void sort (head)
{
	ST *p = head->next, *q = p->next;

	for (; p->next != NULL; p = p->next) {
		for (; q != NULL; q = q->next) {
			if (p->data > q->data) {
					
			}
		}
	}
}

//输出函数
void print(ST *head)
{
	ST *p = head->next;
	
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
	
	sort (head);

	print(head);

	return 0;
}
