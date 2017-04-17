#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//文件的相应操作如打开文件，关闭文件，向文件读写一个字符等
int main()
{
    /*
    //定义文件指针类型
    FILE*fp;
    //定义字符类型，向文件中写入字符
    char array;
    char a;
    //打开文件
   if((fp=fopen("E:\\exp01.txt","w"))==NULL)//判断文件是否成功打开，如没有打开文件，则退出程序
    {
        puts("文件打开失败");
        exit(0);
    }
    //为字符类型赋值
    array=getchar();
    //使用循环可以连续的输入单个字符，也可以输入一个字符就结束
    while(array!='#')
    {
        //在文件中写入一个字符
        fputc(array,fp);//fputc指把一个字符写入到磁盘中去
        array=getchar();
    }
    fclose(fp);



    //从指定的文件中读出字符
    fp=fopen("E:\\exp01.txt","r");
    a=fgetc(fp);
    while(a!=EOF)
    {
        putchar(a);
        a=fgetc(fp);
    }

    fclose(fp);*/



    /*
    //建立一个文件，并向文件中写入一个字符串，并将其读出
    FILE*fp;//文件指针这是第一步，也是必不可少的一步，没有它将无法建立一个文件
    //声明一个字符数组，用保存要写入的数据
    char array1[20];
    //打开文件
    if((fp=fopen("E:\\exp02","w"))==NULL)
    {
        printf("文件打开失败\n");
        exit(0);
    }
    puts("请输入内容");
    gets(array1);
    //将字符串写入文件中
    fputs(array1,fp);
    //关闭文件
    fclose(fp);*/


/*
    //从上面建立的文件中读出写入的字符串
    //建立文件指针
    FILE*fp;
    //声明一个字符数组，用于保存要读出的数据
    char array2[20];
    //打开文件
    if((fp=fopen("E:\\exp02","r"))==NULL)
    {
         printf("文件打开失败\n");
         exit(0);
    }
    //将文件中的数据读出,并计算读出数据的大小
    fgets(array2,sizeof(array2),fp);
    //打印字符串
    printf("%s",array2);
    //关闭文件
    fclose(fp);
    return 0;
    */




    FILE*fp;//文件指针
    char ch[2];
    char str[10];//保存输入的数据
    char str1[10];
    //char str3[30];//保存文件名
    //puts("请输入文件名");
   // scanf("%s",&str3);
    //打开文件并判断文件是否成功打开
    if((fp=fopen("E:\\exp04.txt","w"))==NULL)
    {
        printf("文件打开失败");
        getchar();
        exit(0);
    }
    //getchar();//接收回车符
    printf("请输入要写入的字符\n");
    gets(str);//输入要写入文件的内容
    fprintf(fp,"%d",str);
    fclose(fp);
    printf("是否需要打印文件内容（y/n）:");
    scanf("%c",&ch);
   if(strcmp("y",ch)==0||strcmp("Y",ch)==0)//用字符串比较函数来判断是否需要打印信息
    {
        if((fp=fopen("E:\\exp04.txt","r"))==NULL)
        {
            printf("文件打开失败");
            exit(0);
        }
        fscanf(fp,"%s",&str1);
        fclose(fp);
    }


        printf("%s",str1);

    return 0;
}

/*
    //要求：使用文件保存学生的相关信息
    //实现方式1.使用结构体定义学生变量
    //用fread和fwrite,来读写文件信息
    //程序如下

    //申明结构体
struct student
{
    int num;//学号
    char name[10];//姓名
    char tel[15];//电话
}info[100];

void save(char*name_s,int n)
{
    //文件指针
    FILE*fp;
    int i;
    //打开文件，并判断
    if((fp=fopen(name_s,"wb"))==NULL)
    {
        puts("文件打开失败");
        exit(0);
    }
    //写入文件，单个写入
    for(i=0;i<n;i++)
    {
        //fwrite函数，如果写入成功则返回
        if(fwrite(&info[i],sizeof(struct student),1,fp)==0)//判断信息是否写入文件,写入成功则返回一个非零值，不成功
        {
            puts("写入失败");                              //返回一个零值，（成功跳过执行下一条语句，不成功输出错误

        }
    }
    //反之则写入成功，然后关闭文件，等待下一次操作
    fclose(fp);
}


void show(char*name_s,int n)
{
    //文件指针
    FILE*fp;
    int i;
    //打开文件，并判断
    if((fp=fopen(name_s,"rb"))==NULL)
    {
        puts("文件打开失败");
        exit(0);
    }
    for(i=0;i<n;i++)
    {
        fread(&info[i],sizeof(struct student),1,fp);
        printf("%5d,%5s,%5s\n",info[i].num,info[i].name,info[i].tel);
    }
    fclose(fp);
}



int main()
{
    FILE*fp;//文件指针
    char cf[20]={};//保存文件名
    int n=0,i=0;//学生人数
    printf("请输入学生人数:");
    scanf("%d",&n);//输入数字
    puts("请输入文件名，以方便查询.保存文件");
    scanf("%s",&cf);//输入文件名
    //使用循环为结构体赋值
    for(i=0;i<n;i++)
    {
        printf("NO%d\n",i+1);
        scanf("%d%s%s",&info[i].num,&info[i].name,&info[i].tel);
        //调用函数写入文件
        save(cf,n);
    }
    //调用函数读出文件中的信息
    show(cf,n);
    return 0;
}
*/



