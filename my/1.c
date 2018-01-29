#include<stdio.h>
#include<string.h>
#include<string.h>
//#define A 0
//#define ok 0
//#define DATA s[i].name,s[i].number,s[i].level,s[i].sex

struct student{

    char name[10];
    int number;
    int age;
    char level[6];
    char sex[3];
    char building[5];
    char floor[6];
    char room[4];
};

struct student s[100];
int n;//学生总数
int menu();
void add();
int search();
int view();
int delete();
int change();

int num();
int names();
int rooms();
int buildings();
int sta();
int sushe();
int louceng();
int sushe();
void read();

void main(){
     menu();
     } 

int menu(){
    int i;
    while(1){
    printf("请选择您要执行的操作\n");
    printf("1:添加学生住宿信息\n");
    printf("2:修改学生住宿信息\n");
    printf("3:删除学生住宿信息\n");
    printf("4:浏览学生住宿信息\n");
    printf("5:查找学生住宿信息\n");
    printf("6:统计学生住宿信息\n");
    printf("0:退出系统\n");
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
   }  } 
}
void add(){
    int n;
    FILE *fp;
    if((fp=fopen("my.txt","a+"))==NULL) {
	printf("文件打开失败\n");
	return ;
    }
    int i,j;
    int c;
    int b[100];
    int a=0;
    printf("请输入你想输入的人数:");
    scanf("%d",&c);
    for(i=0;i<c;i++){
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
    printf("姓名:%s 学号:%d性别: %s 年级:%d 班级:%s宿舍楼: %s楼层: %s寝室: %s",s[i].name,s[i].number,s[i].sex,s[i].age,s[i].level,s[i].building,s[i].floor,s[i].room);
    n++;
    fwrite(&s,sizeof(struct student),1,fp);}
    //for(i=0;i<n;i++){
    //fwrite(&s[i],sizeof(struct student),1,fp);
   // }
    fclose(fp); 
    printf("写入成功\n");
}
int search(){
    int i,j;
    printf("请输入查找方式:");
    printf("按学号查询:1\n");
    printf("按姓名查询:2\n");
    printf("按宿舍查询:3\n");
    printf("按宿舍楼查询:4\n");
    printf("返回:5\n");
    printf("退出系统:0\n");
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
}

void read(){
    FILE *fp;
    int m;
    if((fp=fopen("my.txt","r"))==NULL) {
	printf("文件打开失败\n");
	return ;}
	while(fread(&s[m],sizeof(struct student),1,fp)==1){
	    m++;}
	    fclose(fp);
	    return;
}
int num(){
   FILE *fp;
 // read();
    int i,a=0;
    int m=0;
    int find;
    printf("请输入你要查询的学生学号:");
    scanf("%d",&find);
    if((fp=fopen("my.txt","r"))==NULL) {
	printf("文件打开失败\n");
	return 0;}
	while(fread(&s[m],sizeof(struct student),1,fp)==1){
	    m++;}
	    printf("%d",m); 
	    for(i=0;i<m;i++){
	    if(s[i].number==find){ 
	printf("学号:%d\n",s[i].number);
	    printf("年龄:%d\n",s[i].age);
	    printf("班级:%s\n",s[i].level);
	    printf("性别:%s\n",s[i].sex);
	    printf("宿舍楼:%s\n",s[i].building);
	    printf("楼层:%s\n",s[i].floor);
	    printf("寝室:%s\n",s[i].room);
	    a=a+1;
	}
    }
    if(a==0){
	printf("不存在该学生\n");
	return 0;
    }
    
}
int names(){
    FILE *fp;
    int i;
    int b=0;
    char find[20];
    fp=fopen("myfile.txt","r");
    printf("请输入你要查询的学生姓名:");
    scanf("%s",&find);
    for(i=0;i<n;i++)
	if(strcmp(s[i].name,find)==0){

	    printf("姓名:%s\n",s[i].name);
	    printf("学号:%d\n",s[i].number);
	    printf("年龄:%d\n",s[i].age);
	    printf("班级:%s\n",s[i].level);
	    printf("性别:%s\n",s[i].sex);
	    printf("宿舍楼:%s\n",s[i].building);
	    printf("楼层:%s\n",s[i].floor);
	    printf("寝室:%s\n",s[i].room);
	    return i;
	    b=1;}
	    if(b==1)
		printf("不存在该学生\n");
	    else{
		fwrite(s,sizeof(struct student)*n,1,fp);
	    fclose(fp);} 
	    return 0;
    
}
int rooms(){
    FILE *fp;
    int m;
    int i,b=0;
    char sushe[10];
    printf("请输入你要查找的寝室号:");
    if((fp=fopen("my.txt","r"))==NULL) {
	printf("文件打开失败\n");
	return 0;}
	while(fread(&s[m],sizeof(struct student),1,fp)==1){
	    m++;}
    scanf("%s",sushe);
    for(i=0;i<m;i++){
	if(strcmp(s[i].room,sushe)==0){
	    printf("姓名:%s\n",s[i].name);
	    printf("学号:%d\n",s[i].number);
	    printf("年龄:%d\n",s[i].age);
	    printf("班级:%s\n",s[i].level);
	    printf("性别:%s\n",s[i].sex);
	    printf("宿舍楼:%s\n",s[i].building);
	    printf("楼层:%s\n",s[i].floor);
	    printf("寝室:%s\n",s[i].room);
	    b=1;
	}
    }
    if(b==0)
	printf("为查到此人");
return 0;
}
int buildings(){
    int i,j=0;
    char B[5];
    printf("请输入你要查找的寝室楼:");
    scanf("%s",&B);
    for(i=0;i<n;i++){
	if(strcmp(s[i].building,B)==0){
	    printf("姓名:%s\n",s[i].name);
	    printf("学号:%d\n",s[i].number);
	    printf("年龄:%d\n",s[i].age);
	    printf("班级:%s\n",s[i].level);
	    printf("性别:%s\n",s[i].sex);
	    printf("宿舍楼:%s\n",s[i].building);
	    printf("楼层:%s\n",s[i].floor);
	    printf("寝室:%s\n",s[i].room);
	j=1;
	}

    }
    if(j==0){
	printf("未查到此宿舍楼\n");
    }
}
int view(){
    FILE *fp;
    if((fp=fopen("my.txt","rb"))==NULL) {
	printf("文件打开失败\n");
	return 0;}
	while(fread(s,sizeof(struct student),1,fp)==1){

	    printf("姓名:%s\n",s->name);
	    printf("学号:%d\n",s->number);
	    printf("年龄:%d\n",s->age);
	    printf("班级:%s\n",s->level);
	    printf("性别:%s\n",s->sex);
	    printf("宿舍楼:%s\n",s->building);
	    printf("楼层:%s\n",s->floor);
	    printf("寝室:%s\n",s->room);
    } 
    fclose(fp);
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
	    printf("姓名:%s\n",s[i].name);
	    printf("学号:%d\n",s[i].number);
	    printf("年龄:%d\n",s[i].age);
	    printf("班级:%s\n",s[i].level);
	    printf("性别:%s\n",s[i].sex);
	    printf("宿舍楼:%s\n",s[i].building);
	    printf("楼层:%s\n",s[i].floor);
	    printf("寝室:%s\n",s[i].room);
	}
	for(j=i;j<n;j++){
	    s[j]=s[j+1];
	}
	n--;
    }

}

int change(){
    char ming[6];
    int i,b=0;
    printf("请输入你要修改的学生姓名:");
    scanf("%s",&ming);
    for(i=0;i<n;i++){
	if(strcmp(s[i].name,ming)==0){
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
    }
    if(b==0)
    printf("该学生不存在\n");
}
int sta(){
    int i,b=0;
    printf("请输入统计方式\n");
    printf("按宿舍统计:1\n");
    printf("按楼层统计:2\n");
    printf("按宿舍楼统计:3\n");
    printf("退出:0\n");
    scanf("%d",&i);
    if(i==0)return 0;
    switch(i){
	case 1: sushe();break;
//	case 2: louceng();break;
//	case 3: sushe();break;
	defult:break;
    }
    return 0;

}
int sushe(){
    int i,j,k=0;
    char a[4];
    char b[1];
    char c;
    printf("请输入需要统计的宿舍:");
    scanf("%s",&a);
    for(i=0;i<n;i++){
	if(strcmp(s[i].room,a)==0)
	    printf("姓名:%s\n",s[i].name);
	    printf("学号:%d\n",s[i].number); 
	    printf("年龄:%d\n",s[i].age);
	    printf("班级:%s\n",s[i].level);
	    printf("性别:%s\n",s[i].sex);
	    printf("宿舍楼:%s\n",s[i].building);
	    printf("楼层:%s\n",s[i].floor);
	    printf("寝室:%s\n",s[i].room);
	    k++;
//	else{
//	    printf("该寝室为空\n");
//	    return 0;
	} 
	printf("该寝室共有%d人\n",k);
	//printf("是否显示寝室个人信息(y/n):");
	//scanf("%s",&b);
	//if(strcmp(b,"y")==0)
    //for(i=0;i<n;i++){
	//if(strcmp(s[i].room,a)==0){
	  //  printf("姓名:%s\n",s[i].name);
	    //printf("学号:%d\n",s[i].number);
	    //printf("年龄:%d\n",s[i].age);
	    //printf("班级:%s\n",s[i].level);
	    //printf("性别:%s\n",s[i].sex);
	    //printf("宿舍楼:%s\n",s[i].building);
	    //printf("楼层:%s\n",s[i].floor);
	    //printf("寝室:%s\n",s[i].room);
	    //printf("\n");
	   // } 
   // }
}  

int save(){
    int i;
    FILE *pk;
    if((pk=fopen("my.txt","wr+"))==NULL) 
    {
	printf("文件打开失败");return 0;
    } for(int i=0;i<n;i++) 
    fprintf(pk,"%s",s[i].name);
     fclose(pk);
}






