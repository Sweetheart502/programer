#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N sizeof(struct stud)
#define PT "学号:%ld 姓名:%-10s 成绩:%6.1f \n",p->num,p->name,p->score

struct stud {
	long num;
	char name[12];
	float score;
	struct stud *next;
};


void *creat()
{
	struct stud *head, *p, *q;

	head = p = (struct stud *)malloc(N);
	printf("please input num  name  score(学号输入0则结束输入)\n");
	q = (struct stud *)malloc(N);
	scanf("%ld %s %f", &q->num, q->name, &q->score);

	while(q->num  != 0) {
		p->next = q;
		p = q;
		q = (struct stud *)malloc(N);
		scanf("%ld %s %f", &q->num, q->name, &q->score);
	}
	p->next = NULL;
	free(q);

	return head;
}


void print(struct stud *p)
{
	p = p->next;

	while(p != NULL) {
		printf(PT);
		p = p->next;
	}
}

/*
struct stud *find(struct stud *p)
{
	long num;
	scanf("%ld", &num);

	while(p->next != NULL) {
		p = p->next;
		if(p->num == num) {
			return p;
		}
	}

	return NULL;
}


int delete(struct stud *p)
{
	struct stud *q;
	long num;
	scanf("%ld", &num);
	q = p->next;

	while(q != NULL) {
		if(q->num == num) {
			p->next = q->next;
			free(q);
			return 1;
		}
		p = q;
		q = p->next;
	}

	return 0;
}


int insert(struct stud *p)
{
	struct stud *q;

	q = (struct stud *)malloc(N);

	printf("input\n");
	scanf("%ld %s %f", &q->num, q->name, &q->score);

	while(p->next != NULL && q->num > p->next->num) {
		p = p->next;
	}
	if(p->next != NULL && p->next->num == q->num) {
		printf("this num has been.\n");
		free(q);
		return 0;
	}
	q->next = p->next;
	p->next = q;
	return 1;
}
*/

int main(void)
{
	struct stud *head, *p;
	head = creat();

	print(head);

//	p = find(head);

//	if(p != NULL) {
//		printf("find:\n");
//		printf("%-10ld%-10s%6.1f\n", p->num, p->name, p->score);
//	}
//	else {
//		printf("not found!\n");
//	}

//	if(delete(head)) {
//		printf("成功删除！\n");
//		print(head);
//	}
//	else {
//		printf("not found!\n");
//	}

//	if(insert(head) == 1) {
//		printf("成功插入！\n");
//		print(head);
//	}
//	else {
//		printf("插入失败！\n");
//	}

	return 0;
}
