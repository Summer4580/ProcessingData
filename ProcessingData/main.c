//
//  main.c
//  ProcessingData
//
//  Created by Summer on 2017/6/12.
//  Copyright © 2017年 Summer. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
typedef struct GPS_type{
    char time[20];
    char date[20];
    char lotd[20];
    char lotdx;
    char latd[20];
    char latdx;
    char hingt[20];
    struct GPS *next;
}GPS;
void GPRMC(char a[],GPS *Temp)
{
//    printf("GPRMC日期:");
    int i=51,j=0;
    while(a[i]!=',')
    {
        Temp->date[j] = a[i];
//        printf("%sdadadasdasdsa",Temp->date);
        i++,j++;
    }
//    printf("\nGPRMC时间:");
//    int p,q;
//    p = (a[7]-'0')*10;
//    q = (a[8]-'0')+8;
//    if(q>24)
//    {
//        p++;
//        q=q-24;
//    }
//    Temp->time[0] = p;
//    Temp->time[1] = q;
    i=7,j=0;
    while(a[i]!=',')
    {
        Temp->time[j] = a[i];
//        printf("%c",a[i]);
        i++,j++;
    }
//    printf("\n维度=");
    i=16,j=0;
    while(a[i]!=',')
    {
        Temp->latd[j] = a[i];
//        printf("%c",a[i]);
        i++,j++;
    }
    Temp->latdx = a[i+1];
//    printf("%c\n",a[i+1]);
    i=i+3,j=0;
//    printf("经度=");
    while(a[i]!=',')
    {
        Temp->lotd[j] = a[i];
//        printf("%c",a[i]);
        i++,j++;
    }
    Temp->lotdx = a[i+1];
//    printf("%c\n",a[i+1]);
}
void GPGGA(char b[],GPS *Temp)
{
//    printf("\n海拔=");
      int i=43,j=0;
    while(b[i]!=',')
    {
    Temp->hingt[j] = b[i];
//        printf("%c",b[i]);
        i++,j++;
    }
}
//void bulid(GPS *p,GPS *a)
//{
//    GPS *temp;
//    temp = p;
//    temp->next = NULL;
//    temp->next = a;
//    temp = a;
//}
int main()
{
    char a[63];
    char b[63];
    FILE *fp;
    FILE *fw;
    fp=fopen("//Users//20161104580X//Desktop//GPS文档//GPS170510.log","r");
    if(fp==NULL)
    {
        printf("打开文件错误!\n");
        return 0;
    }
    fw = fopen("//Users//20161104580X//Desktop//GPS文档//Output.csv","a");
    if(fw==NULL)
    {
        printf("打开文件错误!\n");
        return 0;
    }
    GPS *s;
//    temp = (GPS *)malloc(sizeof(GPS));
//    temp->next = NULL;
    s = (GPS *)malloc(sizeof(GPS));
//    h = (GPS *)malloc(sizeof(GPS));
//    if(head==NULL)
//        printf("空间申请失败\n");
    int i=0;
    while(!feof(fp))
    {
        if(i==0||i==40)
        {
            fprintf(fw,"日期,时间,经度,纬度,海拔\n");
            printf("日期,时间,经度,纬度,海拔\n");
            i=0;
        }
        fscanf(fp,"%s",a);
        GPRMC(a,s);
        fscanf(fp,"%s",b);
        GPGGA(b,s);
        fflush(stdin);
//        bulid(temp,s);
//        printf("%s\n",s->date);
//        printf("%s\n",s->hingt);
//        printf("%s%c\n",s->latd,s->latdx);
        
//        temp->next = NULL;
//        temp->next = s;
//        temp = s;
//        printf("%s\n",temp->date);
//        printf("%s\n",temp->hingt);
//        printf("%s%c\n",temp->latd,temp->latdx);
        fprintf(fw,"%s,%s,%s%c,%s%c,%s\n",s->date,s->time,s->lotd,s->lotdx,s->latd,s->latdx,s->hingt);
        printf("日期:%s\n时间:%s\n经度:%s%c\n维度:%s%c\n海拔:%s\n",s->date,s->time,s->lotd,s->lotdx,s->latd,s->latdx,s->hingt);
        i++;
    }
    fclose(fw);
    fclose(fp);
//    while(temp->next!=NULL)
//    {
//        printf("日期:%s\n时间:%s\n经度:%s%c\n维度:%s%c\n海拔:%s\n",temp->date,temp->time,temp->lotd,temp->lotdx,temp->latd,temp->latdx,temp->hingt);
//        temp = temp->next;
//    }
    return 0;
}
