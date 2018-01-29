

#ifndef a_h

#define a_h

#define BUFLEN 100 /* 缓冲区最大字符数 */

#define LEN 15 /* 学号和姓名最大字符数,实际请更改 */

#define N 100 /* 最大学生人数,实际请更改*/



struct record /*结构体*/

{

char code[LEN+1]; /* 学号 */

char name[LEN+1]; /* 姓名 */

char sex[4]; /* 性别 */

int age; /* 年龄 */

char class[LEN+1]; /* 班级 */

int building; /* 宿舍楼 */

int floor; /* 楼层号 */

int room; /* 宿舍号 */

}stu[N];



int k=1,n,m; /* 定义全局变量 */ 

void readfile(void);/* 函数声明 */

void seek(void);

void modify(void);

void insert(void);

void del(void);

void display(void);

void save(void);

void stastic(void);

void menu(void); 

void menuA(void);



#endif




