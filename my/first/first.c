#include"mycode.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void regis(){
    int a,b,x;
    printf("         --------欢迎来到学生宿舍管理系统\n");
    printf("         --------1:普通用户登陆\n");
    printf("         --------2:管理员登录\n");
    printf("         --------请你选择用户身份\n");
    scanf("%d",&a);
    while(1){
    if(a==1)
    {
      normal();
      return;
    }
    if(a==2){
	    printf("请输入密码\n");
	    scanf("%d",&b);
	    if(b==2016){
		menu();break;
	    }
	    else{for(x=0;x<3;x++){
		printf("密码输入错误，请重新输入:");
		scanf("%d",&b);
		if(b==2016){
		    menu();break;
		}
		
	    }
    }
}return ; }}  

int normal(){
    system("clear");
    int a;
    printf("         --------欢迎来到学生宿舍管理系统---\n");
    printf("         --------请选择您要执行的操作-------\n");
    printf("         -------1:浏览学生住宿信息----------\n");
    printf("         -------2:查找学生住宿信息----------\n");
    printf("         -------0:退出系统------------------\n");
    scanf("%d",&a);
    if(a==0)return 0;
    while(a){
	switch(a){
	    case 1:view();break;
	    case 2:search();break;
	    default:break;
	}
	return 0;
    }
    }

int menu(){
    system("clear");
    int i;
    while(1){
    printf("         --------欢迎来到学生宿舍管理系统---\n");
    printf("         --------请选择您要执行的操作-------\n");
    printf("         -------1:添加学生住宿信息----------\n");
    printf("         -------2:修改学生住宿信息----------\n");
    printf("         -------3:删除学生住宿信息----------\n");
    printf("         -------4:浏览学生住宿信息----------\n");
    printf("         -------5:查找学生住宿信息----------\n");
    printf("         -------6:统计学生住宿信息----------\n");
    printf("         -------0:退出系统------------------\n");
    printf("请输入您的操作:");
    scanf("%d",&i);
    if(i==0) return 0;
       switch(i){
            case 1:add();break;
	    case 2:change();break;
	    case 3:delete();break;
	    case 4:view();break;
	    case 5:search();break;
	    case 6:sta();break;
	    default:printf("输入错误\n");break;
   }  system("clear");
   } 
}
void add(){
    int n;
    char h;
    int i,j;
    int b[100];
    int c;
    int a=0;
    FILE *fp=NULL;
    fp=fopen("myfile.txt","a+");
    printf("请输入你想输入的人数:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
    printf("\t学生信息为：\n");
    printf("请输入你的名字:");
    scanf("%s",s[i].name);
    printf("请输入你的学号:");
    scanf("%d",&s[i].number);
    printf("请输入你的性别:");
    scanf("%s",s[i].sex);
    printf("请输入你的年龄:");
    scanf("%d",&s[i].age);
    printf("请输入你的班级:");
    scanf("%s",s[i].level);
    printf("请输入你的宿舍楼:");
    scanf("%s",s[i].building);
    printf("请输入你的楼层:");
    scanf("%s",s[i].floor);
    printf("请输入你的寝室:");
    scanf("%s",s[i].room);
    printf("姓名:%s 学号:%d性别: %s 年龄:%d  班级:% s宿舍楼: %s楼层: %s寝室: %s\n",s[i].name,s[i].number,s[i].sex,s[i].age,s[i].level,s[i].building,s[i].floor,s[i].room);
    
    fwrite(&s,sizeof(struct student),1,fp);} 
    fclose(fp);
    printf("写入成功!\n");
    printf("按任意键继续");
    getchar();
    getchar();

}
int search(){
    int i,j;
    printf("请输入查找方式\n");
    printf("1:按学号查询\n");
    printf("2:按姓名查询\n");
    printf("3:按宿舍查询\n");
    printf("4:按宿舍楼查询\n");
    printf("5:返回\n");
    printf("0:退出系统\n");
    scanf("%d",&i);
    if(i==5)return 0;
    else{
	switch(i){
	    case 1:num();break;
	    case 2:names();break;
	    case 3:rooms();break;
	    case 4:buildings();break;
	default:break;
	}
    }
return 0;}
int num(){
    FILE *fp;
    int i,a=0,m;
    int find;
    printf("请输入你要查询的学生学号:");
    scanf("%d",&find);
    if((fp=fopen("my.txt","r"))==NULL){
	printf("文件打开失败");
	return 0;
    }
    while(fread(&s[m],sizeof(struct student),1,fp)==1){
	m++;
    }
    
    for(i=0;i<n;i++){
	if(s[i].number==find){
	   printf("姓名:%s\t",s[i].name);
	   printf("学号:%d\t",s[i].number);
	   printf("年龄:%d\t",s[i].age);
	   printf("班级:%s\t",s[i].level);
	   printf("性别:%s\t",s[i].sex);
	   printf("宿舍楼:%s\t",s[i].building);
	   printf("楼层:%s\t",s[i].floor);
	   printf("寝室:%s\t",s[i].room);
	    a=a+1;
	}
    }
    if(a==0){
	printf("不存在该学生\n");
	return 0;
    }
    printf("按任意键继续");
    getchar();
    getchar();
    
}
int names(){
    int i,m;
    int b=0;
    FILE *fp=NULL;
    char find[20];
    if((fp=fopen("my.txt","r"))==NULL){
	printf("文件打开失败");
	return 0;
    }
    while(fread(&s[m],sizeof(struct student),1,fp)==1){
	m++;} 
    printf("请输入你要查询的学生姓名:");
    scanf("%s",&find);
    for(i=0;i<m;i++)
	if(strcmp(s[i].name,find)==0){

	    printf("姓名:%s\t",s[i].name);
	    printf("学号:%d\t",s[i].number);
	    printf("年龄:%d\t",s[i].age);
	    printf("班级:%s\t",s[i].level);
	    printf("性别:%s\t",s[i].sex);
	    printf("宿舍楼:%s\t",s[i].building);
	    printf("楼层:%s\t",s[i].floor);
	    printf("寝室:%s\t",s[i].room);
	    return i;
	    b=1;}
	    if(b==1)
		printf("不存在该学生\n");
	    else{
		fwrite(s,sizeof(struct student)*n,1,fp);
	 //   fclose(fp);
	 } 
	printf("按任意键继续");
	getchar();
	getchar();
	    return 0;
    
}  
int rooms(){
    int i,b=0;
    char sushe[10];
    printf("请输入你要查找的寝室号:");
    scanf("%s",sushe);
    for(i=0;i<n;i++){
	if(strcmp(s[i].room,sushe)==0){
	    printf("姓名:%s\t",s[i].name);
	    printf("学号:%d\t",s[i].number);
	    printf("年龄:%d\t",s[i].age);
	    printf("班级:%s\t",s[i].level);
	    printf("性别:%s\t",s[i].sex);
	    printf("宿舍楼:%s\t",s[i].building);
	    printf("楼层:%s\t",s[i].floor);
	    printf("寝室:%s\t",s[i].room);
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
	    printf("姓名:%s\t",s[i].name);
	    printf("学号:%d\t",s[i].number);
	    printf("年龄:%d\t",s[i].age);
	    printf("班级:%s\t",s[i].level);
	    printf("性别:%s\t",s[i].sex);
	    printf("宿舍楼:%s\t",s[i].building);
	    printf("楼层:%s\t",s[i].floor);
	    printf("寝室:%s\t",s[i].room);
	j=1;
	}

    }
    if(j==0){
	printf("未查到此宿舍楼\n");
    }
    printf("按任意键继续");
    getchar();
    getchar();
    return 0;
}
int view(){
    int i;
    for(i=0;i<n;i++){
	    printf("姓名:%s\t",s[i].name);
	    printf("学号:%d\t",s[i].number);
	    printf("年龄:%d\t",s[i].age);
	    printf("班级:%s\t",s[i].level);
	    printf("性别:%s\t",s[i].sex);
	    printf("宿舍楼:%s\t",s[i].building);
	    printf("楼层:%s\t",s[i].floor);
	    printf("寝室:%s\t",s[i].room);
	    printf("\n");
    }
    printf("按任意键继续");
    getchar();
    getchar();
    return 0;
}

int delete(){
    int a,i,j;
    int b=0;
    FILE *fp;
    fp=fopen("myfile.txt","wb+");
    printf("请输入要删除的同学的学号:");
    scanf("%d",&a);
    for(i=0;i<n;i++){
	if(s[i].number==a){
	    printf("姓名:%s\t",s[i].name);
	    printf("学号:%d\t",s[i].number);
	    printf("年龄:%d\t",s[i].age);
	    printf("班级:%s\t",s[i].level);
	    printf("性别:%s\t",s[i].sex);
	    printf("宿舍楼:%s\t",s[i].building);
	    printf("楼层:%s\t",s[i].floor);
	    printf("寝室:%s\t",s[i].room);
	}
	for(j=i;j<n;j++){
	    s[j]=s[j+1];
	}
	n--;
	printf("成功删除此人\n");
    }
    printf("按任意键继续");
    getchar();
    getchar();
    return 0;

}

int change(){
    int ming;
    int i,b=0;
    printf("请输入你要修改的学生学号:");
    scanf("%d",&ming);
    for(i=0;i<n;i++){
	if(s[i].number==ming){
	    printf("输入修改信息\n");
	    printf("姓名:\n");
	    scanf("%s",s[i].name);
	    printf("学号:\n");
	    scanf("%d",&s[i].number);
	    printf("年龄:\n");
	    scanf("%d",&s[i].age);
	    printf("班级:\n");
	    scanf("%s",s[i].level);
	    printf("性别:\n");
	    scanf("%s",s[i].sex);
	    printf("宿舍楼:\n");
	    scanf("%s",s[i].building);
	    printf("楼层:\n");
	    scanf("%s",s[i].floor);
	    printf("寝室:\n");
	    scanf("%s",s[i].room);
	    b=1;
	}
	printf("修改成功\n");
    }
    if(b==0)
    printf("该学生不存在\n");
    printf("按任意键继续");
    getchar();
    getchar();
    return 0;
}
int sta(){
    int i,b=0;
    printf("请输入统计方式\n");
    printf("1:按宿舍统计\n");
    printf("2:按楼层统计\n");
    printf("3:按宿舍楼统计\n");
    printf("0:退出\n");
    scanf("%d",&i);
    if(i==0)return 0;
    switch(i){
	case 1: sushe();break;
	case 2: louceng();break;
	case 3: sushelou();break;
	defult:break;
    }
    printf("按任意键继续");
    getchar();
    getchar();
    return 0;

}
int sushe(){
    int i,j,k=0;
    char a[4];
    int b;
    char c;
    printf("请输入需要统计的宿舍:");
    scanf("%s",&a);
    for(i=0;i<n;i++){
	if(strcmp(s[i].room,a)==0)
	    k++;
	} 
	printf("该寝室共有%d人\n",k);
	printf("是否显示寝室个人信息(1/0)):");
	scanf("%d",&b);
	if(b==1)
    for(i=0;i<n;i++){
	if(strcmp(s[i].room,a)==0){
	    printf("姓名:%s\t",s[i].name);
	    printf("学号:%d\t",s[i].number);
	    printf("年龄:%d\t",s[i].age);
	    printf("班级:%s\t",s[i].level);
	    printf("性别:%s\t",s[i].sex);
	    printf("宿舍楼:%s\t",s[i].building);
	    printf("楼层:%s\t",s[i].floor);
	    printf("寝室:%s\t",s[i].room);
	    printf("\n");
	   }  
    }
    printf("按任意键继续");
    getchar();
}   
int louceng(){
    int i,j,k=0;
    char a[4];
    char b[1];
    int c;
    printf("请输入需要统计楼层:");
    scanf("%s",&a);
    for(i=0;i<n;i++){
	if(strcmp(s[i].floor,a)==0)
	    k++;} 
	printf("该楼层共有%d人\n",k);
	printf("是否输出第%s层学生信息（1/0):",a);
	scanf("%d",&c);
	if(c==1){
	    for(i=0;i<n;i++){
		if(strcmp(s[i].room,a)==0){
		printf("姓名:%s\t",s[i].name);
		printf("学号:%d\t",s[i].number);
		printf("年龄:%d\t",s[i].age);
		printf("班级:%s\t",s[i].level);
		printf("性别:%s\t",s[i].sex);
		printf("宿舍楼:%s\t",s[i].building);
		printf("楼层:%s\t",s[i].floor);
		printf("寝室:%s\t",s[i].room);
		printf("\n"); 
	}
	}
	}
	printf("按任意键继续");
		getchar();
		return 0;
}    
int sushelou(){
    int i,j,k=0;
    char a[4];
    char b[1];
    int c;
    printf("请输入需要统计的宿舍楼:");
    scanf("%s",&a);
    for(i=0;i<n;i++){
	if(strcmp(s[i].building,a)==0)
	    k++;} 
	printf("该宿舍楼共有%d人\n",k);
	printf("是否输出%d宿舍楼的信息(1/0):",a);
	scanf("%d",&c);
	if(c==1){
	    for(i=0;i<n;i++){
		if(strcmp(s[i].room,a)==0){
		printf("姓名:%s\t",s[i].name);
		printf("学号:%d\t",s[i].number);
		printf("年龄:%d\t",s[i].age);
		printf("班级:%s\t",s[i].level);
		printf("性别:%s\t",s[i].sex);
		printf("宿舍楼:%s\t",s[i].building);
		printf("楼层:%s\t",s[i].floor);
		printf("寝室:%s\t",s[i].room);
		printf("\n"); 
} }} 
    printf("按任意键继续");
    getchar();
    return 0;
} 










