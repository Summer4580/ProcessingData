#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct GPS{
    char time[20];
    char date[20];
    char lotd[20];
    char lotdx;
    char latd[20];
    char latdx;
    char hingt[20];
    double carv;
};
void GPRMC(char a[],struct GPS *Temp)
{
//    printf("GPRMC日期:");
    int i,j;
    Temp->date[0] = a[55];
    Temp->date[1] = a[56];
    for(i=51,j=2;i<55;i++,j++)
    {
        Temp->date[j] = a[i];
    }
    int p,q;
    p = (a[7]-'0')*10;
    q = (a[8]-'0')+8;
//    printf("%d\t%d\n",p,q);
    if(p+q>24)
    {
        p= p-2;
        q= q-4;
    }
    a[7] = p+48;
    a[8] = q+48;
//    printf("%c\t%c\n",a[7],a[8]);
    i=7,j=0;
    while(a[i]!=',')
    {
        Temp->time[j] = a[i];
//        printf("%c",a[i]);
        i++,j++;
    }
    i=16,j=0;
    while(a[i]!=',')
    {
        Temp->latd[j] = a[i];
//        printf("\n%c",Temp->latd[j]);
        i++,j++;
    }
    Temp->latdx = a[i+1];
    i=i+3,j=0;
//    printf("经度=");
    while(a[i]!=',')
    {
        Temp->lotd[j] = a[i];
//       printf("%c\t",Temp->lotd[j]);
        i++,j++;
    }
//    printf("%s\nh=%d\n",Temp->lotd,h);
    Temp->lotdx = a[i+1];
//   int l=strlen(Temp->lotd);
//   printf("\n%s\t%d\n",Temp->lotd,l);
     i=39;j=0;
     int h=2;
     while(a[i]!='.')
    {
        Temp->carv += (a[i]-'0')*pow(10,h);
//        printf("----%.3lf----\n",Temp->carv);
        i++,j++,h--;
    }
    i++;
//    printf("----%.3lf----\n",Temp->carv);
    Temp->carv += (a[i]-'0')*0.1;
//  printf("----%.3lf----\n",Temp->carv);
    Temp->carv *=1.852;
//        printf("----%.3lf----\n",Temp->carv);
}
void GPGGA(char b[],struct GPS *Temp)
{
//    printf("\n海拔=");
      int i=43,j=0;
    while(b[i]!=',')
    {
    Temp->hingt[j] = b[i];
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
    fp=fopen("C:\\Users\\18444\\Desktop\\ProcessingData\\GPS170510.txt","r");
    if(fp==NULL)
    {
        printf("打开数据文件错误!\n");
        return 0;
    }
    fw = fopen("C:\\Users\\18444\\Desktop\\ProcessingData\\Output.csv","a+");
    if(fw==NULL)
    {
        printf("打开写入文件错误!\n");
        return 0;
    }
    struct GPS s;
//    temp = (GPS *)malloc(sizeof(GPS));
//    temp->next = NULL;
//    vs = (GPS *)malloc(sizeof(GPS));
//    h = (GPS *)malloc(sizeof(GPS));
//    if(head==NULL)
//        printf("空间申请失败\n");
    int i=0;
    while(!feof(fp))
    {
        memset(&s,0,sizeof(s));
//        printf("日期:%s\n时间:%s\n经度:%s%c\n维度:%s%c\n海拔:%s\n",s.date,s.time,s.lotd,s.lotdx,s.latd,s.latdx,s.hingt);
        if(i==0||i==40)
        {
            fprintf(fw,"日期（年月日）,时间（时分秒）,经度（度分秒),纬度（度分秒),海拔（米）,车速（千米\小时）\n");
//            printf("日期（年\月\日）,时间（时\分\秒）,经度,纬度,海拔（米）\n");
            i=0;
        }
        fscanf(fp,"%s",a);
        GPRMC(a,&s);
        fscanf(fp,"%s",b);
        GPGGA(b,&s);
//        fflush(stdin);
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
        fprintf(fw,"%s,%s,%s%c,%s%c,%s,%.3lf\n",s.date,s.time,s.lotd,s.lotdx,s.latd,s.latdx,s.hingt,s.carv);
//        int l=strlen(s.lotd);
//        printf("长度：%d\t%s\n%c",l,s.lotd,s.lotdx);
        printf("日期:%s\n时间:%s\n经度:%s'%c\n纬度:%s'%c\n海拔:%s米\n车速:%.3lf千米\\小时\n",s.date,s.time,s.lotd,s.lotdx,s.latd,s.latdx,s.hingt,s.carv);
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
