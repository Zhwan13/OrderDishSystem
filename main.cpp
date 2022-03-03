#include <iostream>
#include "core/CButton.h"
#include "core/CEdit.h"
#include "core/CLabel.h"
#include"app/CLoginWin.h"
#include"app/CRegisterWin.h"
#include"app/CStaff.h"
#include"app/CStartWin.h"
#include"app/CGoodSearchWin.h"
#include"app/InStockMenuWin.h"
#include"app/InStockWin.h"
#include"app/InStockRecordWin.h"
#include"app/CTipsWin.h"
#include"app/OutStockMenuWin.h"
#include"app/OutStockWin.h"
#include"app/OutStockRecordWin.h"
#include"app/CCheckMenuWin.h"
#include"app/CCheckCreateWin.h"
#include "app/CCheckReportWin.h"

#include<list>
#include<algorithm>
#include<conio.h>
#include<stdio.h>
#include"app/CFile.h"


using namespace std;

int main()
{
 /***   char *Date;
    Date=new char[20];
    CTool::getNowTime(Date);
    cout<<Date;


//成功读取年月日时分秒
    int date1,date4;
    char Date[20];
    char date2[10];
    char date3[10];
    time_t nowtime=time(NULL);//获取当前系统的时间，单位为秒
    struct tm* t=localtime(&nowtime);//转换成tm类型的结构体
    date1=(t->tm_year+1900)*10000+(t->tm_mon+1)*100+t->tm_mday;//生成日期-long型
    date4=t->tm_hour*10000+t->tm_min*100+t->tm_sec;
    sprintf(date2,"%d",date4);
    if(strlen(date2)<6)//防止中间数据0丢失
    {
        sprintf(date3,"0%s",date2);
        strcpy(date2,date3);
    }
    sprintf(Date,"%d%s",date1,date3);
    cout<<Date;
    ****/

        /****
    list <CStaff>::iterator it=Staff->begin();
    for(it=Staff->begin();it!=Staff->end();++it)
    {
        cout<<it->getID()<<" "<<it->getName()<<" "<<it->getUsername()<<" "<<it->getPwd()<<" "<<it->getRole()<<endl;
    }
    getch();
    ***/
    int ch=0;
    int curWin=0;//当前窗体默认为第0个
	list <CStaff>*Staff;
    Staff=CFile::Staff_init("data/Staff.txt");
    map <int,CGoods>*Goods;
    Goods=CFile::Goods_init("data/Goods.txt");

    vector<CGoodsStockRecord>*InstockRecord;
    InstockRecord=CFile::Record_init("data/InRecord.txt");

    vector<CGoodsStockRecord>*OutstockRecord;
    OutstockRecord=CFile::Record_init("data/OutRecord.txt");

    CStartWin *start=new CStartWin(15,5,17,24,"开始界面",0);//0
    CLoginWin *loginwin=new CLoginWin(10,5,20,40,"用户登录",1);//1
    CRegisterWin *regiswin=new CRegisterWin(10,5,25,40,"用户注册",2);//2
    CadminWin *adminWin=new CadminWin(10,5,20,40,"欢迎使用传一盘点机",3);//3
    CCheckerWin *checkerWin=new CCheckerWin(10,5,20,40,"欢迎使用传一盘点机",4);//4
    CGoodSearchWin *SearchWin=new CGoodSearchWin(10,5,22,80,"欢迎使用传一盘点机",Goods,5);//5

    InStockMenuWin *InStockMenu=new InStockMenuWin(10,5,22,60,"欢迎使用传一盘点机",6);//6
    InStockWin *InStock=new InStockWin(10,5,22,60,"欢迎使用传一盘点机",InstockRecord,7);//7
    CTipsWin *TipsWin=new CTipsWin(30,9,15,20,"",8);//提示框界面8
    CGoodsAddWin *GoodsAddWin=new CGoodsAddWin(10,5,26,50,"欢迎使用传一盘点机",9);//新增商品9
    InStockRecordWin *InstockRecordWin=new InStockRecordWin(10,5,24,70,"欢迎使用传一盘点机",InstockRecord,10);//10

    OutStockMenuWin *OutStockMenu=new OutStockMenuWin(10,5,22,60,"欢迎使用传一盘点机",11);//11
    OutStockWin *OutStock=new OutStockWin(10,5,22,60,"欢迎使用传一盘点机",OutstockRecord,12);//12
    OutStockRecordWin *OutstockRecordWin=new OutStockRecordWin(10,5,24,70,"商品出库记录界面",OutstockRecord,13);//13

    CCheckMenuWin *CheckMenuWin=new CCheckMenuWin(10,5,22,60,"欢迎使用传一盘点机",14);
    CCheckCreateWin *CheckCreateWin=new CCheckCreateWin(10,5,21,60,"欢迎使用传一盘点机",15);
    CCheckReportWin *CheckReportWin=new CCheckReportWin(10,5,22,60,"欢迎使用传一盘点机",OutstockRecord,16);//先为NULL测试界面


    CWinBase *CWin[20]={start,loginwin,regiswin,adminWin,checkerWin,SearchWin,InStockMenu,InStock,TipsWin,GoodsAddWin,InstockRecordWin,OutStockMenu,OutStock,OutstockRecordWin,CheckMenuWin,CheckCreateWin,CheckReportWin};
    while(1)
    {
        //CWin[curWin]->show();
        if(curWin==SEARCHWIN||curWin==INSTOCKWIN||curWin==GOODSADDWIN||curWin==OUTSTOCKWIN||curWin==CHECKMENUWIN||curWin==CHECKWINCREATE)   //当是商品查询窗体和入库、出库窗体时传入的数据时Goods
        {
            curWin=CWin[curWin]->run(Goods);
        }
        else if(curWin==INSTOCKRECORDWIN)
        {
            curWin=CWin[curWin]->run(InstockRecord);
        }
        else if(curWin==OUTSTOCKRECORDWIN)
        {
            curWin=CWin[curWin]->run(OutstockRecord);
        }
        else
        {
            curWin=CWin[curWin]->run(Staff);
        }
        if(curWin==-1)
        {
            break;
        }
    }

    return 0;
}
