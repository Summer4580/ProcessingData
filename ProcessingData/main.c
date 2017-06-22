//
//  main.c
//  ProcessingData
//
//  Created by Summer on 2017/6/12.
//  Copyright © 2017年 Summer. All rights reserved.
//

#include <stdio.h>
int main()
{
    char a[63];
    char b[63];
    FILE *fp;
    fp=fopen("//Users//20161104580X//Desktop//GPS文档//GPS170510.log","r");
    while(!feof(fp))
    {
        fscanf(fp,"%s",a);
        fscanf(fp,"%s",b);
    }
    printf("GPGGA时间：");
    int i=7;
    while(b[i]!=',')
    {
        printf("%c",b[i]);
        i++;
    }
    printf("\n海拔=");
    i=43;
    while(b[i]!=',')
    {
        printf("%c",b[i]);
        i++;
    }
    printf("\n维度=");
    i=14;
    while(b[i]!=',')
    {
        printf("%c",b[i]);
        i++;
    }
    printf("%c\n",b[i+1]);
    i=i+3;
    printf("经度=");
    while(b[i]!=',')
    {
        printf("%c",b[i]);
        i++;
    }
    printf("%c\n",b[i+1]);
    printf("GPRMC时间:\n");
    i=7;
    while(a[i]!=',')
    {
        printf("%c",a[i]);
        i++;
    }
    printf("\n维度=");
    i=16;
    while(a[i]!=',')
    {
        printf("%c",a[i]);
        i++;
    }
    printf("%c\n",a[i+1]);
    i=i+3;
    printf("经度=");
    while(a[i]!=',')
    {
        printf("%c",a[i]);
        i++;
    }
    printf("%c\n",a[i+1]);

    return 0;
}
