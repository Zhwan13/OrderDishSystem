#ifndef _CSTAFF_H_
#define _CSTAFF_H_
#include"string.h"
#include<stdlib.h>
#include<stdio.h>
#include<list>
#include<algorithm>


class CStaff
{
public:
    CStaff();
    CStaff(const CStaff &staffs);//拷贝构造
	CStaff(char *name,char *username,char *pwd,char *role);
	CStaff(int ID,char *name,char *username,char *pwd,char *role);
	int getID();
	char *getName();
	char *getUsername();
	char *getPwd();
	char *getRole();
	static void show(void *Staff);//登录成功后显示

	static bool registerCheck(char *name,void *Staff);
	static int loginCheck(char *name,char *pwd,void *Staff);
	static int staff_count;//员工个数

private:
	int ID;
    char *name;
    char *username;
	char *pwd;
	char *role;//用户角色 0-仓库管理员  1-盘点员
};

#endif
