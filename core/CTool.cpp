#include"CTool.h"
#include<iostream>
using namespace std;

char *CTool::role=new char[2];
char *role="";
char *CTool::temp=new char[20];
char *temp="";
void CTool::gotoxy(int x,int y)
{
	COORD pos={x,y};
	HANDLE hout=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hout,pos);
}
void CTool::getNowTime(char *Time)
{
    int date1,date4;
    char date2[10];
    char date3[10];
    time_t nowtime=time(NULL);//��ȡ��ǰϵͳ��ʱ�䣬��λΪ��
    struct tm* t=localtime(&nowtime);//ת����tm���͵Ľṹ��
    date1=(t->tm_year+1900)*10000+(t->tm_mon+1)*100+t->tm_mday;//��������-long��
    date4=t->tm_hour*10000+t->tm_min*100+t->tm_sec;
    sprintf(date2,"%d",date4);
    if(strlen(date2)==5)//��ֹ�м�����0��ʧ
    {
        sprintf(date3,"0%s",date2);
        strcpy(date2,date3);
    }
    else if(strlen(date2)==4)//��ֹ�м�����0��ʧ
    {
        sprintf(date3,"00%s",date2);
        strcpy(date2,date3);
    }
    sprintf(Time,"%d%s",date1,date2);
    return ;
}
void CTool::getDate(char *Date)
{
    int date1,date2,date3;
    time_t nowtime=time(NULL);//��ȡ��ǰϵͳ��ʱ�䣬��λΪ��
    struct tm* t=localtime(&nowtime);//ת����tm���͵Ľṹ��
    date1=(t->tm_year+1900);
    date2=(t->tm_mon+1);
    date3=t->tm_mday;//��������-int��
    sprintf(Date,"%d��%d��%d��",date1,date2,date3);
}

void CTool::setTemp(char *data)
{
    temp=data;
}

