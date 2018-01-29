#include<stdio.h> /*I/O函数*/
#include<stdlib.h> /*其它说明*/
#include<string.h> /*字符串函数*/
#include<unistd.h>
#include "a.h"

int main(void)
{
    menuA();
    return 0;
} 
void readfile()/* 建立信息 */
{
    char *p="Student.txt";
    FILE *fp;
    int i=0;
    if ((fp=fopen("Student.txt","r"))==NULL)
    {
        printf("Open file %s error! Strike any key to exit!",p);
        system("pause");
        exit(0);
        }
        while(fscanf(fp,"%s %s %s%d%s%d%d%d",stu[i].code,stu[i].name,stu[i].sex,&stu[i].age,stu[i].class,&stu[i].building,&stu[i].floor,&stu[i].room)==8)
        {
            i++;
            i=i;
        }
        fclose(fp);
        n=i;
        printf("录入完毕！\n");
} 

void seek(void) /*查找*/
{
 //   system("clear");
    int i,item,flag,x,y,z;
    char s1[21]; /* 以姓名和学号最长长度+1为准 */
        while(1)
    {
        system("clear");
    printf("\t    ※※※╰○－－○╯※※※※※※╰○－－ ○╯※※※※※※╰○－－○╯※※※\n");
    printf("\t   ※                 1.按学号查询                ※\n");
    printf("\t  ※                  2.按姓名查询                 ※\n");
    printf("\t ※                   3.按宿舍号查询                ※\n");
    printf("\t※                    4.按楼层号查询                 ※\n");
    printf("\t※                    5.按宿舍楼查询                 ※\n");
    printf("\t ※                   6.按具体宿舍号查询            ※\n");
    printf("\t  ※                  7.返回                     ※\n");
    printf("\t   ※                 0.退出系统                ※\n");
    printf("\t    ※※※╰○－－○╯※※※※※※╰○－－ ○╯※※※※※※╰○－－○╯※※※\n");

        printf("请选择子菜单编号:");
        scanf("%d",&item);
        flag=0;
        switch(item)
        {
            case 1:
                system("clear");
                printf("请输入要查询的学生的学号:");
                scanf("%s",s1);
                printf("学生学号  学生姓名   性别   年龄   班级   宿舍楼   楼层号   宿舍号\n");
                for(i=0;i<n;i++)
                    if(strcmp(stu[i].code,s1)==0)
                    {
                        flag=1;
                        printf("--------------------------------------------------------------------\n");
                         printf("%4s %12s %8s %5d %5s %6d %6d %6d\n",stu[i].code,stu[i].name,&stu[i].sex,stu[i].age,stu[i].class,stu[i].building,stu[i].floor,stu[i].room);
                         printf("--------------------------------------------------------------------\n");
                    }
        
                        printf("\n");
                        printf("\n");
                        if(flag==0)
                            printf("该学号不存在！\n");
                        getchar();
                        printf("任意键返回");
                        getchar();
                        break;
            
            case 2:
                system("clear");
                printf("请输入要查询的学生的姓名:");
                scanf("%s",s1);
                printf("学生学号   学生姓名  性别  年龄  班级  宿舍楼 楼层号 宿舍号\n");
                for(i=0;i<n;i++)
                    if(strcmp(stu[i].name,s1)==0)
                    {
                        flag=1;
                        printf("--------------------------------------------------------------------\n");
                       printf("%4s %12s %8s %5d %5s %6d %6d %6d\n",stu[i].code,stu[i].name,&stu[i].sex,stu[i].age,stu[i].class,stu[i].building,stu[i].floor,stu[i].room);
                        printf("--------------------------------------------------------------------\n");
                        }
                        printf("\n");
                        printf("\n");
                    if(flag==0)
                        printf("该姓名不存在！\n"); 

                  getchar();
                    printf("任意键返回");
                    getchar();
                    break;
            
            case 3:
                system("clear");
                printf("请输入要查询的宿舍号：");
                scanf("%d",&x);
                printf("学生学号   学生姓名  性别  年龄  班级  宿舍楼 楼层号 宿舍号\n");
                for(i=0;i<n;i++)
                    if(stu[i].room == x)
                    {
                        flag=1;
                        printf("--------------------------------------------------------------------\n");
                        printf("%4s %12s %8s %5d %5s %6d %6d %6d\n",stu[i].code,stu[i].name,&stu[i].sex,stu[i].age,stu[i].class,stu[i].building,stu[i].floor,stu[i].room);
                         printf("--------------------------------------------------------------------\n");
                        }
                        printf("\n");
                        printf("\n");
                    if(flag==0)
                        printf("该宿舍不存在！\n"); 
                    getchar();
                    printf("任意键返回");
                    getchar();
                    break;
                    
            case 4:
                system("clear");
                printf("请输入要查询的楼层号：");
                scanf("%d",&x);
                printf("学生学号   学生姓名  性别  年龄  班级  宿舍楼 楼层号 宿舍号\n");
                for(i=0;i<n;i++)
                    if(stu[i].floor == x)
                    {
                        flag=1;
                        printf("--------------------------------------------------------------------\n");
                        printf("%4s %12s %8s %5d %5s %6d %6d %6d\n",stu[i].code,stu[i].name,&stu[i].sex,stu[i].age,stu[i].class,stu[i].building,stu[i].floor,stu[i].room);
                         printf("--------------------------------------------------------------------\n");
                        }
                        printf("\n");
                        printf("\n");
                    if(flag==0)
                        printf("该楼层号不存在！\n");
                    getchar();
                    printf("任意键返回");
                    getchar();
                    break; 
                    
            case 5:
                system("clear");
                printf("请输入要查询的宿舍楼：");
                scanf("%d",&x);
                printf("学生学号   学生姓名  性别  年龄  班级  宿舍楼 楼层号 宿舍号\n");
                for(i=0;i<n;i++)
                    if(stu[i].building == x)
                    {
                        flag=1;
                        printf("--------------------------------------------------------------------\n");
                        printf("%4s %12s %8s %5d %5s %6d %6d %6d\n",stu[i].code,stu[i].name,&stu[i].sex,stu[i].age,stu[i].class,stu[i].building,stu[i].floor,stu[i].room);
                         printf("--------------------------------------------------------------------\n");
                        }
                        printf("\n");
                        printf("\n");
                    if(flag==0)
                        printf("该宿舍楼不存在！\n"); 
                    printf("任意键返回");
                    getchar();
                    getchar();
                    break;        
                    
            
            case 6:
                system("clear");
                printf("请输入要查询的宿舍楼：");
                scanf("%d",&x);
                printf("请输入要查询的楼层号：");
                scanf("%d",&y);
                printf("请输入要查询的宿舍号：");
                scanf("%d",&z);
                printf("学生学号   学生姓名  性别  年龄  班级  宿舍楼 楼层号 宿舍号\n");
                for(i=0;i<n;i++)
                    if(stu[i].building == x)
                        if(stu[i].floor == y)
                            if(stu[i].room == z)
                  {
                        flag=1;
                        printf("--------------------------------------------------------------------\n");
                        printf("%4s %12s %8s %5d %5s %6d %6d %6d\n",stu[i].code,stu[i].name,&stu[i].sex,stu[i].age,stu[i].class,stu[i].building,stu[i].floor,stu[i].room);
                         printf("--------------------------------------------------------------------\n");
                        }
                        printf("\n");
                        printf("\n");
                    if(flag==0)
                        printf("该宿舍楼不存在！\n");
                    getchar();
                    printf("任意键返回");
                    getchar();
                    break;
                    
            case 7: return;
            
            case 0: printf("谢谢使用！\n");exit(0);
            default:printf("请在0-7之间选择\n");
            
        }
        
    }
} 
void modify(void) /*修改信息*/
{
    system("clear");
    int i,item,num;
    char sex1[3],s1[LEN+1],s2[LEN+1]; /* 以姓名和学号最长长度+1为准 */
    printf("请输入要修改的学生的学号:");
    scanf("%s",s1);
    for(i=0;i<n;i++)
        if(strcmp(stu[i].code,s1)==0) /*比较字符串是否相等*/
            num=i;
    printf("\t    ※※※╰○－－○╯※※※※※※╰○－－ ○╯※※※※※※╰○－－○╯※※※\n");
    printf("\t   ※                 1.修改姓名                  ※\n");
    printf("\t  ※                  2.修改年龄                   ※\n");
    printf("\t ※                   3.修改班级                    ※\n");
    printf("\t※                    4.修改宿舍楼                   ※\n");
    printf("\t※                    5.修改楼层号                   ※\n");
    printf("\t ※                   6.修改宿舍号                  ※\n");
    printf("\t  ※                  7.返回                      ※\n");
    printf("\t   ※                 8.退出系统                 ※\n");
    printf("\t    ※※※╰○－－○╯※※※※※※╰○－－ ○╯※※※※※※╰○－－○╯※※※\n");
    printf("友情提示：按9可以重新输入新的学号！\n");
     while(1)
        { 
        printf("请选择子菜单编号:");
        scanf("%d",&item);
        switch(item)
        {  
            case 1:
                printf("请输入新的姓名:");
                scanf("%s",s2);
                strcpy(stu[num].name,s2);
                printf("学生学号  学生姓名   性别   年龄   班级   宿舍楼   楼层号   宿舍号\n");
                printf("--------------------------------------------------------------------\n");
                printf("%4s %12s %8s %5d %5s %6d %6d %6d\n",stu[num].code,stu[num].name,&stu[num].sex,stu[num].age,stu[num].class,stu[num].building,stu[num].floor,stu[num].room);
                printf("--------------------------------------------------------------------\n");
                break;
                
            case 2:
                printf("请输入新的年龄:");
                scanf("%d",&stu[num].age);
                 printf("学生学号  学生姓名   性别   年龄   班级   宿舍楼   楼层号   宿舍号\n");
                printf("--------------------------------------------------------------------\n");
                printf("%4s %12s %8s %5d %5s %6d %6d %6d\n",stu[num].code,stu[num].name,&stu[num].sex,stu[num].age,stu[num].class,stu[num].building,stu[num].floor,stu[num].room);
                printf("--------------------------------------------------------------------\n");
                break;
            
            case 3:
                printf("请输入新的班级:");
                scanf("%s",s2);
                strcpy(stu[num].class,s2);
                 printf("学生学号  学生姓名   性别   年龄   班级   宿舍楼   楼层号   宿舍号\n");
                printf("--------------------------------------------------------------------\n");
                printf("%4s %12s %8s %5d %5s %6d %6d %6d\n",stu[num].code,stu[num].name,&stu[num].sex,stu[num].age,stu[num].class,stu[num].building,stu[num].floor,stu[num].room);
                printf("--------------------------------------------------------------------\n");
                break;
                
            case 4:
                printf("请输入新的宿舍楼:");
                scanf("%d",&stu[num].building);
                 printf("学生学号  学生姓名   性别   年龄   班级   宿舍楼   楼层号   宿舍号\n");
                printf("--------------------------------------------------------------------\n");
                printf("%4s %12s %8s %5d %5s %6d %6d %6d\n",stu[num].code,stu[num].name,&stu[num].sex,stu[num].age,stu[num].class,stu[num].building,stu[num].floor,stu[num].room);
                printf("--------------------------------------------------------------------\n");
                break;
                
            case 5:
                printf("请输入新的楼层号:");
                scanf("%d",&stu[num].floor);
                 printf("学生学号  学生姓名   性别   年龄   班级   宿舍楼   楼层号   宿舍号\n");
                printf("--------------------------------------------------------------------\n");
                printf("%4s %12s %8s %5d %5s %6d %6d %6d\n",stu[num].code,stu[num].name,&stu[num].sex,stu[num].age,stu[num].class,stu[num].building,stu[num].floor,stu[num].room);
                printf("--------------------------------------------------------------------\n");
                break;
                
            case 6:
                printf("请输入新的宿舍号:");
                scanf("%d",&stu[num].room);
                 printf("学生学号  学生姓名   性别   年龄   班级   宿舍楼   楼层号   宿舍号\n");
                printf("--------------------------------------------------------------------\n");
                printf("%4s %12s %8s %5d %5s %6d %6d %6d\n",stu[num].code,stu[num].name,&stu[num].sex,stu[num].age,stu[num].class,stu[num].building,stu[num].floor,stu[num].room);
                printf("--------------------------------------------------------------------\n");
                break;
                
            case 7: return;
            
            case 8: printf("谢谢使用1！\n");exit(0);
            case 9: modify();
        }
    }
} 

void insert(void) /*插入函数*/
{
    system("clear");
    int i=n,j,flag,select;
    char *choice1="男",*choice2="女";
    printf("请输入待增加的学生数:");
    scanf("%d",&m);
    do{
        flag=1;
        while(flag)
        {
            flag=0;
            printf("请输入第 %d 个学生的学号:",i-n+1);
            scanf("%s",stu[i].code);
            for(j=0;j<i;j++)
                if(strcmp(stu[i].code,stu[j].code)==0)
                {
                    printf("已有该学号,请检查后重新录入!");
                    flag=1;
                    break; /*如有重复立即退出该层循环,提高判断速度*/
                }
        }
            printf("请输入第 %d 个学生的姓名:",i-n+1);
            scanf("%s",stu[i].name);
        do{ printf("请输入第 %d 个学生的性别（男/女）:",i-n+1);
            scanf("%s",stu[i].sex);
            if(strcmp(stu[i].sex,choice1)==0||strcmp(stu[i].sex,choice2)==0){break;}
            printf("请重新输入!\n");
        }while(1);
            while(1){printf("请输入第 %d 个学生的年龄:",i-n+1);
            scanf("%d",&stu[i].age);
            if(stu[i].age>6&&stu[i].age<100){break;}
            printf("输入年龄不符！请重新输入！\n");
            }
            printf("请输入第 %d 个学生的班级:",i-n+1);
            scanf("%s",stu[i].class);
            printf("请输入第 %d 个学生的宿舍楼:",i-n+1);
            scanf("%d",&stu[i].building);
            printf("请输入第 %d 个学生的楼层号:",i-n+1);
            scanf("%d",&stu[i].floor);
            printf("请输入第 %d 个学生的宿舍号:",i-n+1);
            scanf("%d",&stu[i].room);
            if(flag==0)
            {
                i=i;
                i++;
                
            }
        
        }while(i<n+m);
    n+=m;
    printf("录入完毕！\n\n");
    getchar();
    printf("任意键返回");
    getchar();

    
} 

void del()
{
    int i,j,select,flag=0;
    char s1[LEN+1];
   do{
    printf("请输入要删除学生的学号:");
    scanf("%s",s1);
    for(i=0;i<n;i++)
        if(strcmp(stu[i].code,s1)==0)
        {
            flag=1;
            for(j=i;j<n-1;j++)
                stu[j]=stu[j+1];
            
        }
        if(flag==0)
            printf("该学号不存在！\n");
        if(flag==1)
        {
            printf("删除成功!\n");
            n--;
            
        }
        printf("请输入1/2（1继续删除/2停止删除）");
        scanf("%d",&select);
       }while(select==1);
} 

void display(void)
{
    system("clear");
    int i;
    printf("所有学生的信息为:\n");
    printf("学生学号   学生姓名  性别  年龄  班级  宿舍楼 楼层号 宿舍号\n");
    printf("--------------------------------------------------------------------\n");
    for(i=0;i<n;i++)
    { 
        printf("%4s %12s %8s %5d %5s %6d %6d %6d\n",stu[i].code,stu[i].name,&stu[i].sex,stu[i].age,stu[i].class,stu[i].building,stu[i].floor,stu[i].room);}
        printf("--------------------------------------------------------------------\n");
        getchar();
        printf("\n");
        printf("输入任意键返回！");
       getchar();
        return;
    } 

void stastic(void)
{
   // system("clear");
    int i,item,flag,x,y,z,p;
     while(1)
    {
        system("clear");
    printf("\t   ※※※╰○－－○╯※※※※※※╰○－－ ○╯※※※※※※╰○－－○╯※※※\n");
    printf("\t  ※                1.按宿舍号统计               ※\n");
    printf("\t ※                 2.按楼层号统计                ※\n");
    printf("\t※                  3.按宿舍楼统计                 ※\n");
    printf("\t※                  4.按具体楼层号统计              ※\n");
    printf("\t※                  5.按具体宿舍号统计              ※\n");
    printf("\t ※                 6.返回                       ※\n");
    printf("\t   ※               7.退出系统                  ※\n");
    printf("\t    ※※※╰○－－○╯※※※※※※╰○－－ ○╯※※※※※※╰○－－○╯※\n");
        printf("请输入子菜单编号：");
        scanf("%d",&item);
        flag=0;
        p=0;
        switch(item)
        {
            case 1:
                system("clear");
                printf("请输入宿舍号：");
                scanf("%d",&x);
                printf("学生学号   学生姓名  性别  年龄  班级  宿舍楼 楼层号 宿舍号\n");
                printf("--------------------------------------------------------------------\n");
                for(i=0;i<n;i++)
                    if(stu[i].room == x)
                         {
                             p++;
                        flag=1;
                        printf("%4s %12s %8s %5d %5s %6d %6d %6d\n",stu[i].code,stu[i].name,&stu[i].sex,stu[i].age,stu[i].class,stu[i].building,stu[i].floor,stu[i].room);
                    
                         }
                        printf("--------------------------------------------------------------------\n");
                   printf("\n总共%d人",p);
                        

                    if(flag==0)
                        printf("该宿舍不存在！\n"); 
                    getchar();
                    printf("\n任意键返回");
                    getchar();
                    break;
              
             case 2: 
                 system("clear");
                 printf("请输入楼层号：");
                scanf("%d",&x);
                printf("学生学号   学生姓名  性别  年龄  班级  宿舍楼 楼层号 宿舍号\n");  printf("--------------------------------------------------------------------\n");
                for(i=0;i<n;i++)
                    if(stu[i].floor == x)
                         {
                             p++;
                        flag=1;
 
                        printf("%4s %12s %8s %5d %5s %6d %6d %6d\n",stu[i].code,stu[i].name,&stu[i].sex,stu[i].age,stu[i].class,stu[i].building,stu[i].floor,stu[i].room);
                         }
                        printf("--------------------------------------------------------------------\n");
                    printf("\n总共%d人",p);
                        
                    if(flag==0)
                        printf("该楼层号不存在！\n");
                    getchar();
                    printf("\n任意键返回");
                    getchar();
                    break;
                    
             case 3:system("clear");
                 printf("请输入宿舍楼：");
                scanf("%d",&x);
                printf("学生学号   学生姓名  性别  年龄  班级  宿舍楼 楼层号 宿舍号\n");
                printf("--------------------------------------------------------------------\n");
                for(i=0;i<n;i++)
                    if(stu[i].building== x)
                         {
                           p++;
                        flag=1;
                        

                        printf("%4s %12s %8s %5d %5s %6d %6d %6d\n",stu[i].code,stu[i].name,&stu[i].sex,stu[i].age,stu[i].class,stu[i].building,stu[i].floor,stu[i].room);
                         }
                        printf("--------------------------------------------------------------------\n");
                    printf("\n总共%d人",p);
                        
                    if(flag==0)
                        printf("该宿舍楼不存在！\n"); 
                    getchar();
                    printf("\n任意键返回");
                    getchar();
                    break;
                    
             case 4:
                 system("clear");
                printf("请输入要查询的宿舍楼：");
                scanf("%d",&x);
                printf("请输入要查询的楼层号：");
                scanf("%d",&y);
                printf("学生学号   学生姓名  性别  年龄  班级  宿舍楼 楼层号 宿舍号\n");
                printf("--------------------------------------------------------------------\n");
                for(i=0;i<n;i++)
                    if(stu[i].building == x)
                        if(stu[i].floor == y)
                             {
                      p++;
                        flag=1;
     
                        printf("%4s %12s %8s %5d %5s %6d %6d %6d\n",stu[i].code,stu[i].name,&stu[i].sex,stu[i].age,stu[i].class,stu[i].building,stu[i].floor,stu[i].room);
                             }
                         printf("--------------------------------------------------------------------\n");
                    
                                        printf("\n总共%d人",p);
                        if(flag==0)
                        printf("该宿舍楼不存在！\n"); 
                    getchar();
                    printf("\n任意键返回");
                    getchar();
                    break;
                   
             case 5:   
                 system("clear");
                printf("请输入要查询的宿舍楼：");
                scanf("%d",&x);
                printf("请输入要查询的楼层号：");
                scanf("%d",&y);
                printf("请输入要查询的宿舍号：");
                scanf("%d",&z);
                printf("学生学号   学生姓名  性别  年龄  班级  宿舍楼 楼层号 宿舍号\n");
                printf("--------------------------------------------------------------------\n");
                for(i=0;i<n;i++)
                    if(stu[i].building == x)
                        if(stu[i].floor == y)
                            if(stu[i].room == z)
                  {
                      p++;
                        flag=1;
                     
                        printf("%4s %12s %8s %5d %5s %6d %6d %6d\n",stu[i].code,stu[i].name,&stu[i].sex,stu[i].age,stu[i].class,stu[i].building,stu[i].floor,stu[i].room);
                  }
                         printf("--------------------------------------------------------------------\n");
                        
                    printf("\n总共%d人",p);
                        if(flag==0)
                        printf("该宿舍楼不存在！\n"); 
                    getchar();
                    printf("\n任意键返回");
                    getchar();
                    break;
               
                        
                    
             case 6: return;
             
             case 7: printf("谢谢使用！");exit(0);
        }
        
    }
}

void save(void)
    {
        int i;
        FILE *fp;
        fp=fopen("Student.txt","w"); /*写入*/
        for(i=0;i<n;i++)
        {
           fprintf(fp,"%s %s %s %d %s %d %d %d\n",stu[i].code,stu[i].name,stu[i].sex,stu[i].age,stu[i].class,stu[i].building,stu[i].floor,stu[i].room); 
        }
        fclose(fp);
        
    } 

void menu(void)/* 界面 */
{
    system("clear");
    int num;
    printf("\n");
    printf("\t      ※※※※※※╰○－－○╯※※※※※※╰○－系统功能菜单－○╯※※※※※※╰○－－ ○╯※※※※※\n");
    printf("\t     ※※※※※※※╰○－－○╯※※※※※※╰○－   － ○╯※※※※※※╰○－－○╯※※※※※※※※※※※※    \n");
    printf("\t    ※                         1.增加学生信息                         ※\n");
    printf("\t   ※                          2.修改学生信息                          ※ \n");    
    printf("\t  ※                           3.删除学生信息                           ※  \n");
    printf("\t ※                            4.浏览学生信息                            ※\n");
    printf("\t※                             5.查找住宿信息                             ※\n");
    printf("\t ※                            6.统计住宿信息                            ※ \n");
    printf("\t  ※                           7.保存当前信息                           ※ \n");
    printf("\t   ※                          8.刷新系统                             ※ \n");
    printf("\t    ※                         0.退出系统                            ※  \n");
    printf("\t     ※※※※※※※╰○－－○╯※※※※※※╰○－  － ○╯※※※※※※╰○－－○╯※※※※※※※※※※※※\n");
    printf("请选择菜单编号(请先选择8读取信息):");
    scanf("%d",&num);
    switch(num)
    { 
        case 1:insert();break;
        case 2:modify();break;
        case 3:del();break;
        case 4:display();break;
        case 5:seek();break;
        case 6:stastic();break;
        case 7: save();break;
        case 8: readfile();break;
        case 0:printf("谢谢使用！\n");exit(0);
        
    }
    return ;
}

void menuA(void){
    system("clear");
    printf("欢迎来到宿舍管理系统！");
    printf("\n");
    getchar();
    int h;
    char* password;
    const char *Password="123456";
    while(1){
        password=getpass("\n请输入管理员密码：");
    if(strcmp(password,Password)==0){
        break;}
    
    printf("\n输入错误！请重新输入！"); 
    printf("\n任意键继续输入(退出请按0):"); 
    scanf("%d",&h);
    if(h==0) exit(0);
    }
    while(k)

    menu();
  
}
        
