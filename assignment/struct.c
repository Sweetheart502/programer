/**
 *设某学生管理系统要存储学生的学号姓名性别高数英语政治成绩，要求键盘输入10个学生的信息。
 *1>输出每门课的平均成绩。
 *2>输出每门课的最高成绩。
 *3>输出高数这门课最高分学生信息，并有可能有重复值。
 *4>将所有学生信息按照高数降序输出。
 *5>在4的基础上，若高数成绩相同，在按照英语成绩升序排列。               //未完成
 *6>将所有学生信息按照姓名升序排列。
 */

/*2014.5.8-----assignment*/

#include <stdio.h>
#include <string.h>
#define N 3

typedef struct info{
	int num;
	char name[12];
	char sex;
	int score[3];                     //0--高数  1--英语  3--政治
	double ave[N];
}ST;


void input(ST *a, int n)
{
	int i, sum = 0;
	printf("\nplease input the name:\n");
	gets(a->name);
	printf("\nplease input the num:\n");
	scanf("%d", &a->num);
	getchar();
	printf("\nplease input the score:\n");
	for(i = 0; i < 3; i++) {
		scanf("%d", &a->score[i]);
		sum += a->score[i];
	}
	getchar();
	a->ave[n] = sum / 3.0;
}


void print(ST s[N])
{
	int i;

	printf("num\tname\tmath\teng\tpol\tave\n");
	for(i = 0; i < N; i++) {
		printf("%-d\t%s\t%-d\t%-d\t%-d\t%.3f\n", s[i].num, s[i].name, s[i].score[0], s[i].score[1], s[i].score[2], s[i].ave[i]);
	}
}


void max_score(ST s[])
{
	int i, j, max;
	printf("math\teng\tpol\n");
	for(i = 0; i < 3; i++) {
		max = s[0].score[i];
		for(j = 0; j < N; j++) {
			if(s[j].score[i] > max){
				max = s[j].score[i];
			}
		}
		printf("%d\t", max);
	}
	printf("\n");
}


void max_math(ST s[N])
{
	int i, max;
	for(i = 0; i < N; i++) {
		max = s[0].score[0];
		if(s[i].score[0] > max) {
			max = s[i].score[0];
		}
	}
	printf("\nthe max_math = %d\n", max);
	printf("高数最高分学生信息：\nnum\tname\teng\tpol\tave\n");
	for(i = 0; i < N; i++) {
		if(s[i].score[0] == max) {
			printf("%d\t%s\t%d\t%d\t%.3f\n", s[i].num, s[i].name, s[i].score[1], s[i].score[2], s[i].ave[i]);
		}
	}
}


void math_sort(ST s[])
{
	int i, j, t;

	//冒泡法排序---降序
	for(i = 0; i < N-1; i++) {
		for(j = 0; j < N-i-1; j++) {
			if(s[j].score[0] < s[j+1].score[0]) {
				t = s[j].score[0];
				s[j].score[0] = s[j+1].score[0];
				s[j+1].score[0] = t;
			}
	 	}
	}
}


void name_sort(ST s[])
{
	int i, j;
	char name[12];
	//选择法排序
	for(i = 0; i < N-1; i++) {
		for(j = i+1; j< N; j++) {
			if(strcmp(s[i].name, s[j].name) > 0) {
				strcpy(name, s[i].name);
				strcpy(s[i].name, s[j].name);
				strcpy(s[j].name, name);
			}
		}
	}
}

int main(void)
{
	ST s[N];
	int i;
	
	//输入所需要的学生信息
	printf("\nplease input the message:\n");
	for(i = 0; i < N; i++){
		input(s+i, i);
	}

	//输出所输入的学生信息
	printf("\nplease output the message:\n");
	print(s);

	//输出每门课的最高成绩
	printf("\n输出每门课的最高成绩：\n");
	max_score(s);

	//找出高数最高分学生的信息
	max_math(s);

	//将高数成绩按照降序输出
	printf("\nthe math_sort_H-L :\n");
	math_sort(s);
	print(s);

	//将学生姓名按照升序输出
	printf("\nthe name_sort_L-H :\n");
	name_sort(s);	
	print(s);
	return 0;
}
