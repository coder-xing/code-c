#include"mycode.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
int n;
int N=0;
void Save()
{
    FILE *fp;
    int i;
    if((fp=fopen("my.txt","wb"))==NULL){
        printf("Open failed!\n");
        return;
    }
    if(fwrite(&N,sizeof(int),1,fp)!=1){
        printf("Write in failed!\n");
    }
    for (i=0;i<N;i++){
        if(fwrite(&s[i],sizeof(struct student),1,fp)!=1){
          printf("Write in failed!\n");
	}
    }
    fclose(fp);
    return;
}
void Read() 
{
    FILE *fp;
    int i;

    if((fp=fopen("my.txt","rb"))==NULL){
        printf("Open failed!\n");
        return;
    }
    if(fread(&N,sizeof(int),1,fp)!=1){
        N=-1;
    }else{
        for(i=0;i<N;i++){
            fread(&s[i],sizeof(struct student),1,fp);
        }
    }
    fclose(fp);
    return;
}                                 

void regis()
{
    char *password,*password2;
    const char*Password="2016";
    const char*Password2="2017";
	system("clear");
    int a,b,x;
    printf("\t ******************************\n");
    printf("\t *    欢迎来到学生宿舍管理系统  *\n");
    printf("\n");
    printf("\t *    1:普通用户登陆            *\n");
    printf("\n");
    printf("\t *    2:管理员登录              *\n");
    printf("\n");
    printf("\t *    请你选择用户身份          *\n");
    printf("\t *****************************\n");
    scanf("%d",&a);
    if(a==1)
    {
	password=getpass( "请输入密码");
	if(strcmp(password,Password)==0)
	    normal();
	else{for(x=0;x<3;x++){
	    printf("密码错误,请重新输入\n");
	    password=getpass( "请输入密码");
	   if(strcmp(password,Password)==0)
	    normal();
	    return;
	}
	return;
    }
    } 
    if(a==2)
    {
	password2=getpass("请输入密码\n");
	if(strcmp(password2,Password2)==0){
	    menu();}
	else{for(x=0;x<3;x++){
	    printf("密码错误,请重新输入\n");
	    password=getpass( "请输入密码");
	   if(strcmp(password2,Password2)==0)
	    menu();
	    return;

    }}return;}  
    if(a!=1&&a!=3){
	printf("\e[33m\e[1%s\e[0m","无效数字");
	getchar();} 
    if(a==0)
	return;

    }


int normal(){
    while(1){
    system("clear");
    int a;
    printf("\t **********************************  \n");
    printf("\t *     欢迎来到学生宿舍管理系统   *\n\n");
    printf("\t *     请选择您要执行的操作       *\n\n");
    printf("\t *     1:浏览学生住宿信息         *\n\n");
    printf("\t *     2:查找学生住宿信息         *\n\n");
    printf("\t *     0:退出系统                 *\n");
    printf("\t **********************************\n");
    scanf("%d",&a);
    if(a==0)exit(0);
    else{
	switch(a){
	    case 1:view();break;
	    case 2:search();break;
	    default:break;
	}} 
    }
    return 0;
    } 

int menu(){
    //system("clear");
    int i;
    while(1){
    system("clear");
    printf("\t ***********************************  \n");
    printf("\t *     欢迎来到学生宿舍管理系统    *\n\n");
    printf("\t *     请选择您要执行的操作        *\n\n");
    printf("\t *     1:添加学生住宿信息          *\n\n");
    printf("\t *     2:修改学生住宿信息          *\n\n");
    printf("\t *     3:删除学生住宿信息          *\n\n");
    printf("\t *     4:浏览学生住宿信息          *\n\n");
    printf("\t *     5:查找学生住宿信息          *\n\n");
    printf("\t *     6:统计学生住宿信息          *\n\n");
    printf("\t *     0:退出系统                  *\n");
    printf("\t ***********************************\n");
    printf("请输入您的操作:");
    scanf("%d",&i);
       switch(i){
            case 1:add();break;
	    case 2:change();break;
	    case 3:delete();break;
	    case 4:view();break;
	    case 5:search();break;
	    case 6:sta();break;
	    case 0:exit(0);
	    default:printf("\e[33m\e[1%s\e[0m","输入错误\n");break;
   }  system("clear");
   } 
}
void add(){
    char h;
    int i,c,j;
    int a=0;
    char choice;
    printf("请输入你想输入的人数:");
    scanf("%d",&c);
    for(i=0;i<c;i++){
    printf("学生信息为：\n");
    printf("请输入你的名字:");
    scanf("%s",s[N].name);
    printf("请输入你的学号:");
    scanf("%d",&s[N].number);
    for(j=0;j<N;j++){
	if(s[j].number==s[N].number)
	{
	    printf("该学号已存在,是否重新输入(y/n):");
	    printf("\n");
	    getchar();
	    scanf("%c",&choice);
	    if(choice=='y'){
		printf("请输入你的学号:");
		scanf("%d",&s[i].number);
		} 
	    else return;
	}} 
    printf("请输入你的性别:");
    scanf("%s",&s[N].sex);
    if(strcmp(s[N].sex,"男")!=0)
    {
	if(strcmp(s[N].sex,"女")!=0)
	for(int arr=0;arr<3;arr++){
	printf("非法输入");
	printf("请重新输入");
	scanf("%s",&s[N].sex);
	if(strcmp(s[N].sex,"男")==0||strcmp(s[N].sex,"女")==0)
	    break;
	;
    }
	}

    printf("请输入你的年龄:");
    scanf("%d",&s[N].age);
    printf("请输入你的班级:");
    scanf("%s",s[N].level);
    printf("请输入你的宿舍楼:");
    scanf("%s",s[N].building);
    printf("请输入你的楼层:");
    scanf("%s",s[N].floor);
    printf("请输入你的寝室:");
    scanf("%s",s[N].room);
    printf("姓名:%-4s 学号:%-12d性别: %-4s 年级:%-4d 班级:%-6s宿舍楼: %-4s楼层: %-4s寝室: %s\n",s[N].name,s[N].number,s[N].sex,s[N].age,s[N].level,s[N].building,s[N].floor,s[N].room);
    N++;
    }
    Save();
    printf("写入成功!\n");
    printf("按任意键继续");
    getchar();
    getchar();

}
int search(){
    while(1){
    system("clear");
    int i,j;
    Read();
    printf("\t ********************************* \n");
    printf("\t *     请输入查找方式            *\n\n");
    printf("\t *     1:按学号查询              *\n\n");
    printf("\t *     2:按姓名查询              *\n\n");
    printf("\t *     3:按宿舍查询              *\n\n");
    printf("\t *     4:按宿舍楼查询            *\n\n");
    printf("\t *     5:返回                    *\n\n");
    printf("\t *     0:退出系统                *\n");
    printf("\t ********************************* \n");
    scanf("%d",&i);
	switch(i){
	    case 0:exit(0);
	    case 1:num();break;
	    case 2:names();break;
	    case 3:rooms();break;
	    case 4:buildings();break;
	    case 5:return 0;
	default:break;
	}
    }} 
int num(){
    Read();
    int i,a=0;
    int find;
    printf("请输入你要查询的学生学号:");
    scanf("%d",&find);
    for(i=0;i<N;i++){
	if(s[i].number==find){
    	   printf("姓名:%s 学号:%d性别: %s 年级:%d 班级:%s宿舍楼: %s楼层: %s寝室: %s\n",s[i].name,s[i].number,s[i].sex,s[i].age,s[i].level,s[i].building,s[i].floor,s[i].room);
	    a=a+1;
	}
    }
    if(a==0){
	printf("\e[33m\e[1%s\e[0m","不存在该学生\n");
	return 0;
    }
    printf("按任意键继续");
    
    getchar();
    getchar();
    
}
int names(){
    Read();
    int i;
    int b=0;
    char find[20];
    printf("请输入你要查询的学生姓名:");
    scanf("%s",&find);
    for(i=0;i<N;i++)
	if(strcmp(s[i].name,find)==0){
    	   printf("姓名:%s 学号:%d性别: %s 年级:%d 班级:%s宿舍楼: %s楼层: %s寝室: %s\n",s[i].name,s[i].number,s[i].sex,s[i].age,s[i].level,s[i].building,s[i].floor,s[i].room);
	    b=1;}
	    if(b==1)
		printf("不存在该学生\n");
	printf("按任意键继续");
	getchar();
	getchar();
	    return 0;
}
int rooms(){
    Read();
    int i,b=0;
    char sushe[10];
    printf("请输入你要查找的寝室号:");
    scanf("%s",sushe);
    for(i=0;i<N;i++){
	if(strcmp(s[i].room,sushe)==0){
    	   printf("姓名:%s 学号:%d性别: %s 年级:%d 班级:%s宿舍楼: %s楼层: %s寝室: %s\n",s[i].name,s[i].number,s[i].sex,s[i].age,s[i].level,s[i].building,s[i].floor,s[i].room);
	    b=1;
	}
    }
    if(b==0)
	printf("未查到此人");
	printf("按任意键继续");
	getchar();
	getchar();
return 0;
}
int buildings(){
    int i,j=0;
    char B[5];
    printf("请输入你要查找的寝室楼:");
    scanf("%s",&B);
    for(i=0;i<n;i++){
	if(strcmp(s[i].building,B)==0){
    	   printf("姓名:%s 学号:%d性别: %s 年级:%d 班级:%s宿舍楼: %s楼层: %s寝室: %s\n",s[i].name,s[i].number,s[i].sex,s[i].age,s[i].level,s[i].building,s[i].floor,s[i].room);
	j=1;
	}
    }
    if(j==0){
	printf("\e[33m\e[1%s\e[0m","未查到此宿舍楼\n");
    }
    printf("按任意键继续");
    getchar();
    getchar();
    return 0;
}
int view(){
    Read();
    int i;
    for(i=0;i<N;i++){
    	   printf("姓名:%6s 学号:%-12d性别:%-4s年级:%-6d 班级:%-4s宿舍楼:%-4s楼层:%-4s寝室:%-4s\n",s[i].name,s[i].number,s[i].sex,s[i].age,s[i].level,s[i].building,s[i].floor,s[i].room);
	    printf("\n");
    }
    printf("按任意键继续");
    getchar();
    getchar();
    return 0;
}
int delete(){
    Read();
    int a,i,j;
    int b=0;
    printf("请输入要删除的同学的学号:");
    scanf("%d",&a);
    for(i=0;i<N;i++){
	if(s[i].number==a){
    	   printf("姓名:%-4s 学号:%-12d性别: %-4s 年级:%-4d 班级:%-6s宿舍楼: %-4s楼层: %-4s寝室: %-4s\n",s[i].name,s[i].number,s[i].sex,s[i].age,s[i].level,s[i].building,s[i].floor,s[i].room);
	for(j=i;j=N-1;j++){
	    s[j]=s[j+1];
	}} 
	N--;
	printf("\e[33m\e[1%s\e[0m"," 成功删除此人\n");
    }
    printf("按任意键继续");
    Save();
    getchar();
    getchar();
    return 0;

}
int change(){
    while(1){
    system("clear");
    Read();
    int h;
    int ming;
    char ch[3];
    int i,b=0;
    int choice;
    printf("请输入你要修改的学生学号:");
    scanf("%d",&ming);
    for(i=0;i<N;i++){
	if(s[i].number==ming){
    	   printf("姓名:%-4s 学号:%-12d性别: %-4s 年级:%-6d 班级:%-4s宿舍楼: %-4s楼层: %-4s寝室: %-4s\n",s[i].name,s[i].number,s[i].sex,s[i].age,s[i].level,s[i].building,s[i].floor,s[i].room);
	   printf("输入你想修改的信息\n");
	   printf("1:姓名\n");
	   printf("2:学号\n");
	   printf("3:年龄\n");
	   printf("4:班级\n");
	   printf("5:性别\n");
	   printf("6:宿舍楼\n"); 
	   printf("7:楼层\n");
	   printf("8:寝室\n");
	   printf("0:退出修改\n");
	   scanf("%d",&choice); 
	    switch(choice){
		case 1:printf("姓名:");scanf("%s",&s[i].name);break;
		case 2:printf("学号:");scanf("%d",&s[i].number);break;
		case 3:printf("年龄:");scanf("%d",&s[i].age);break;
		case 4:printf("班级:");scanf("%s",&s[i].level);break;
		case 5:printf("性别:");scanf("%s",&s[i].sex);break;
		case 6:printf("宿舍楼:");scanf("%s",&s[i].building);break;
		case 7:printf("楼层:");scanf("%s",&s[i].floor);break;
		case 8:printf("寝室:");scanf("%s",&s[i].room);break;
		case 0:return 0;
		default:break;
	    }
	    b++;
    	   printf("姓名:%-4s 学号:%-12d性别: %-4s 年级:%-6d 班级:%-4s宿舍楼: %-4s楼层: %-4s寝室: %-4s\n",s[i].name,s[i].number,s[i].sex,s[i].age,s[i].level,s[i].building,s[i].floor,s[i].room);
	}
	}
    Save();
    if(b==0)
    printf("该学生不存在\n");
    printf("是否继续修改(y/n)");
    scanf("%s",&ch);
    if(strcmp(ch,"y")==0||strcmp(ch,"Y")==0)
	 h=1;
    if(strcmp(ch,"n")==0||strcmp(ch,"N")==0)
	return 0;
 } return 0;} 
int sta(){
    while(1){
    system("clear");
    int i,b=0;
    printf("\t **************************\n\n");
    printf("\t *     请输入统计方式     *\n\n");
    printf("\t *     1:按宿舍统计       *\n\n");
    printf("\t *     2:按楼层统计       *\n\n");
    printf("\t *     3:按宿舍楼统计     *\n\n");
    printf("\t *     4:返回             *\n\n");
    printf("\t *     0:退出系统         *\n");
    printf("\t **************************\n");
    scanf("%d",&i);
    switch(i){
	case 1: sushe();break;
	case 2: louceng();break;
	case 3: sushelou();break;
	case 4: return 0;
	case 0: exit(0);
	defult:break;
    }} 
}
int sushe(){
    Read();
    int i,j,k=0;
    char a[4];
    int b;
    char c;
    printf("请输入需要统计的宿舍:");
    scanf("%s",&a);
    for(i=0;i<N;i++){
	if(strcmp(s[i].room,a)==0)
	    k++;
	} 
	printf("该寝室共有%d人\n",k);
	printf("是否显示寝室个人信息(1/0)):");
	scanf("%d",&b);
	if(b==1)
    for(i=0;i<N;i++){
	if(strcmp(s[i].room,a)==0){
    	   printf("姓名:%-4s 学号:%-12d性别: %-4s 年级:%-6d 班级:%-4s宿舍楼: %-4s楼层: %-4s寝室: %-4s\n",s[i].name,s[i].number,s[i].sex,s[i].age,s[i].level,s[i].building,s[i].floor,s[i].room);
	    printf("\n");
	   }  
    }
    printf("按任意键继续");
    getchar();
    getchar();
}   
int louceng(){
    Read();
    int i,j,k=0;
    char a[4];
    char b[3];
    int c;
    printf("请输入需要统计楼层:");
    scanf("%s",&a);
    for(i=0;i<N;i++){
	if(strcmp(s[i].floor,a)==0)
	    k++;} 
	printf("该楼层共有%d人\n",k);
	printf("是否输出第%s层学生信息（1/0):",a);
	scanf("%d",&c);
	if(c==1){
	    for(i=0;i<N;i++){
    	   printf("姓名:%-4s 学号:%-12d性别: %-4s 年级:%-6d 班级:%-4s宿舍楼: %-4s楼层: %-4s寝室: %-4s\n",s[i].name,s[i].number,s[i].sex,s[i].age,s[i].level,s[i].building,s[i].floor,s[i].room);
		printf("\n"); 
	}
	}
	printf("按任意键继续");
	getchar();
	getchar();
	return 0;
}
    
int sushelou(){
    Read();
    int i,j,k=0;
    char a[4];
    char b[3];
    int c;
    printf("请输入需要统计的宿舍楼:");
    scanf("%s",&a);
    for(i=0;i<N;i++){
	if(strcmp(s[i].building,a)==0)
	    k++;} 
	printf("该宿舍楼共有%d人\n",k);
	printf("是否输出%d宿舍楼的信息(1/0):",k);
	scanf("%d",&c);
	if(c==1){
	    for(i=0;i<N;i++){
		if(strcmp(s[i].room,a)==0){
    	   printf("姓名:%-4s 学号:%-12d性别: %-4s 年级:%-6d 班级:%-4s宿舍楼: %-4s楼层: %-4s寝室: %-4s\n",s[i].name,s[i].number,s[i].sex,s[i].age,s[i].level,s[i].building,s[i].floor,s[i].room);
		printf("\n"); 
} }} 
    printf("按任意键继续");
    getchar();
    getchar();
    return 0;
} 










