#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//�ļ�����Ӧ��������ļ����ر��ļ������ļ���дһ���ַ���
int main()
{
    /*
    //�����ļ�ָ������
    FILE*fp;
    //�����ַ����ͣ����ļ���д���ַ�
    char array;
    char a;
    //���ļ�
   if((fp=fopen("E:\\exp01.txt","w"))==NULL)//�ж��ļ��Ƿ�ɹ��򿪣���û�д��ļ������˳�����
    {
        puts("�ļ���ʧ��");
        exit(0);
    }
    //Ϊ�ַ����͸�ֵ
    array=getchar();
    //ʹ��ѭ���������������뵥���ַ���Ҳ��������һ���ַ��ͽ���
    while(array!='#')
    {
        //���ļ���д��һ���ַ�
        fputc(array,fp);//fputcָ��һ���ַ�д�뵽������ȥ
        array=getchar();
    }
    fclose(fp);



    //��ָ�����ļ��ж����ַ�
    fp=fopen("E:\\exp01.txt","r");
    a=fgetc(fp);
    while(a!=EOF)
    {
        putchar(a);
        a=fgetc(fp);
    }

    fclose(fp);*/



    /*
    //����һ���ļ��������ļ���д��һ���ַ��������������
    FILE*fp;//�ļ�ָ�����ǵ�һ����Ҳ�Ǳز����ٵ�һ����û�������޷�����һ���ļ�
    //����һ���ַ����飬�ñ���Ҫд�������
    char array1[20];
    //���ļ�
    if((fp=fopen("E:\\exp02","w"))==NULL)
    {
        printf("�ļ���ʧ��\n");
        exit(0);
    }
    puts("����������");
    gets(array1);
    //���ַ���д���ļ���
    fputs(array1,fp);
    //�ر��ļ�
    fclose(fp);*/


/*
    //�����潨�����ļ��ж���д����ַ���
    //�����ļ�ָ��
    FILE*fp;
    //����һ���ַ����飬���ڱ���Ҫ����������
    char array2[20];
    //���ļ�
    if((fp=fopen("E:\\exp02","r"))==NULL)
    {
         printf("�ļ���ʧ��\n");
         exit(0);
    }
    //���ļ��е����ݶ���,������������ݵĴ�С
    fgets(array2,sizeof(array2),fp);
    //��ӡ�ַ���
    printf("%s",array2);
    //�ر��ļ�
    fclose(fp);
    return 0;
    */




    FILE*fp;//�ļ�ָ��
    char ch[2];
    char str[10];//�������������
    char str1[10];
    //char str3[30];//�����ļ���
    //puts("�������ļ���");
   // scanf("%s",&str3);
    //���ļ����ж��ļ��Ƿ�ɹ���
    if((fp=fopen("E:\\exp04.txt","w"))==NULL)
    {
        printf("�ļ���ʧ��");
        getchar();
        exit(0);
    }
    //getchar();//���ջس���
    printf("������Ҫд����ַ�\n");
    gets(str);//����Ҫд���ļ�������
    fprintf(fp,"%d",str);
    fclose(fp);
    printf("�Ƿ���Ҫ��ӡ�ļ����ݣ�y/n��:");
    scanf("%c",&ch);
   if(strcmp("y",ch)==0||strcmp("Y",ch)==0)//���ַ����ȽϺ������ж��Ƿ���Ҫ��ӡ��Ϣ
    {
        if((fp=fopen("E:\\exp04.txt","r"))==NULL)
        {
            printf("�ļ���ʧ��");
            exit(0);
        }
        fscanf(fp,"%s",&str1);
        fclose(fp);
    }


        printf("%s",str1);

    return 0;
}

/*
    //Ҫ��ʹ���ļ�����ѧ���������Ϣ
    //ʵ�ַ�ʽ1.ʹ�ýṹ�嶨��ѧ������
    //��fread��fwrite,����д�ļ���Ϣ
    //��������

    //�����ṹ��
struct student
{
    int num;//ѧ��
    char name[10];//����
    char tel[15];//�绰
}info[100];

void save(char*name_s,int n)
{
    //�ļ�ָ��
    FILE*fp;
    int i;
    //���ļ������ж�
    if((fp=fopen(name_s,"wb"))==NULL)
    {
        puts("�ļ���ʧ��");
        exit(0);
    }
    //д���ļ�������д��
    for(i=0;i<n;i++)
    {
        //fwrite���������д��ɹ��򷵻�
        if(fwrite(&info[i],sizeof(struct student),1,fp)==0)//�ж���Ϣ�Ƿ�д���ļ�,д��ɹ��򷵻�һ������ֵ�����ɹ�
        {
            puts("д��ʧ��");                              //����һ����ֵ�����ɹ�����ִ����һ����䣬���ɹ��������

        }
    }
    //��֮��д��ɹ���Ȼ��ر��ļ����ȴ���һ�β���
    fclose(fp);
}


void show(char*name_s,int n)
{
    //�ļ�ָ��
    FILE*fp;
    int i;
    //���ļ������ж�
    if((fp=fopen(name_s,"rb"))==NULL)
    {
        puts("�ļ���ʧ��");
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
    FILE*fp;//�ļ�ָ��
    char cf[20]={};//�����ļ���
    int n=0,i=0;//ѧ������
    printf("������ѧ������:");
    scanf("%d",&n);//��������
    puts("�������ļ������Է����ѯ.�����ļ�");
    scanf("%s",&cf);//�����ļ���
    //ʹ��ѭ��Ϊ�ṹ�帳ֵ
    for(i=0;i<n;i++)
    {
        printf("NO%d\n",i+1);
        scanf("%d%s%s",&info[i].num,&info[i].name,&info[i].tel);
        //���ú���д���ļ�
        save(cf,n);
    }
    //���ú��������ļ��е���Ϣ
    show(cf,n);
    return 0;
}
*/



