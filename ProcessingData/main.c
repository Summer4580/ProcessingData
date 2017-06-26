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
//        printf("%c",a[i]);
        i++,j++;
    }
//    printf("\nGPRMC时间:");
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
//    while(b[i]!=',')
//    {
    Temp->hingt[j] = b[i];
//        printf("%c",b[i]);
        i++,j++;
//    }

}
int main()
{
    char a[63];
    char b[63];
    FILE *fp;
    fp=fopen("//Users//20161104580X//Desktop//GPS文档//GPS170510.log","r");
    if(fp==NULL)
        printf("打开文件错误!");
    GPS *temp,*head,*s;
    temp = (GPS *)malloc(sizeof(GPS));
    temp->next = NULL;
    s = (GPS *)malloc(sizeof(GPS));
    s->next = NULL;
    head = temp;
    while(!feof(fp))
    {
        fscanf(fp,"%s",a);
        GPRMC(a,s);
        fscanf(fp,"%s",b);
        GPGGA(b,s);
        temp->next = s;
    }
    while(head->next!=NULL)
    {
        printf("日期:%s\n时间:%s\n经度:%s%c\n维度:%s%c\n海拔:%s\n",head->date,head->time,head->lotd,head->lotdx,head->latd,head->latdx,head->hingt);
    }
    return 0;
}
