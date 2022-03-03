#include"CStaff.h"
#include<iostream>
using namespace std;

int CStaff::staff_count=0;
CStaff::CStaff()
{
}

CStaff::CStaff(const CStaff &staffs)//深拷贝
{
    this->ID=staffs.ID;
    this->name=new char[10];
    this->username=new char[20];//输入中文
    this->pwd=new char[10];
    this->role=new char[2];
    strcpy(this->name,staffs.name);//！！！这里用strcpy();不能用=！！
    strcpy(this->username,staffs.username);
    strcpy(this->pwd,staffs.pwd);
    strcpy(this->role,staffs.role);
}

CStaff::CStaff(char *name,char *username,char *pwd,char *role)
{
	staff_count++;
	this->ID=1000+staff_count;
	this->name=new char[10];
	this->username=new char[20];//输入中文
	this->pwd=new char[10];
	this->role=new char[2];
	strcpy(this->name,name);
	strcpy(this->username,username);
	strcpy(this->pwd,pwd);
	strcpy(this->role,role);
}
CStaff::CStaff(int ID,char *name,char *username,char *pwd,char *role)
{
	staff_count++;
	this->ID=ID;
	this->name=new char[10];
	this->username=new char[20];//输入中文
	this->pwd=new char[10];
	this->role=new char[2];
	strcpy(this->name,name);
	strcpy(this->username,username);
	strcpy(this->pwd,pwd);
	strcpy(this->role,role);
}

int CStaff::getID()
{
    return this->ID;
}

char *CStaff::getName()
{
    return this->name;
}

char *CStaff::getUsername()
{
    return this->username;
}

char *CStaff::getPwd()
{
    return this->pwd;
}

char *CStaff::getRole()
{
    return this->role;
}
/**
//登录成功后显示员工
void CStaff::show(void *Staff)
{
    int i=0;
    list<CStaff> *ptemp=(list <CStaff>*)Staff;
    system("CLS");
    list<CStaff>::iterator it=ptemp->begin();
    for(it=ptemp->begin();it!=ptemp->end();++it)
    {
        cout<<it->getID()<<"\t"<<it->getName()<<"\t"<<it->getPwd()<<"\t"<<it->getRole()<<endl;
    }
    //cout<<ptemp->size()<<endl;//显示个数
    system("pause");
    return ;
}
**/

bool CStaff::registerCheck(char *name,void *Staff)
{
    list<CStaff> *ptemp=(list <CStaff>*)Staff;
    list<CStaff>::iterator it=ptemp->begin();
    for(it=ptemp->begin();it!=ptemp->end();it++)
    {
        if(strcmp(it->getName(),name)==0)
        {
            return true;
        }
    }
    return false;
}

int CStaff::loginCheck(char *ID,char *pwd,void *Staff)
{
	int i=0;//作为是否登录成功的标志位
	char id[10]={0};
    list<CStaff> *ptemp=(list <CStaff>*)Staff;
    list<CStaff>::iterator it=ptemp->begin();
    for(it=ptemp->begin();it!=ptemp->end();++it)
    {
        sprintf(id,"%d",it->getID());
        if(strcmp(id,ID)==0&&strcmp(it->getPwd(),pwd)==0)
        {
            i=1;
            if(strcmp(it->getRole(),"1")==0)
            {
                return 1;//验证是管理员
            }
            else if(strcmp(it->getRole(),"0")==0)
            {
                return 2;//验证是盘点员
            }
        }
    }
    if(i==0)//登录失败
    {
    }
	return 0;
}
