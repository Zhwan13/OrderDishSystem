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


//�ɹ���ȡ������ʱ����
    int date1,date4;
    char Date[20];
    char date2[10];
    char date3[10];
    time_t nowtime=time(NULL);//��ȡ��ǰϵͳ��ʱ�䣬��λΪ��
    struct tm* t=localtime(&nowtime);//ת����tm���͵Ľṹ��
    date1=(t->tm_year+1900)*10000+(t->tm_mon+1)*100+t->tm_mday;//��������-long��
    date4=t->tm_hour*10000+t->tm_min*100+t->tm_sec;
    sprintf(date2,"%d",date4);
    if(strlen(date2)<6)//��ֹ�м�����0��ʧ
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
    int curWin=0;//��ǰ����Ĭ��Ϊ��0��
	list <CStaff>*Staff;
    Staff=CFile::Staff_init("data/Staff.txt");
    map <int,CGoods>*Goods;
    Goods=CFile::Goods_init("data/Goods.txt");

    vector<CGoodsStockRecord>*InstockRecord;
    InstockRecord=CFile::Record_init("data/InRecord.txt");

    vector<CGoodsStockRecord>*OutstockRecord;
    OutstockRecord=CFile::Record_init("data/OutRecord.txt");

    CStartWin *start=new CStartWin(15,5,17,24,"��ʼ����",0);//0
    CLoginWin *loginwin=new CLoginWin(10,5,20,40,"�û���¼",1);//1
    CRegisterWin *regiswin=new CRegisterWin(10,5,25,40,"�û�ע��",2);//2
    CadminWin *adminWin=new CadminWin(10,5,20,40,"��ӭʹ�ô�һ�̵��",3);//3
    CCheckerWin *checkerWin=new CCheckerWin(10,5,20,40,"��ӭʹ�ô�һ�̵��",4);//4
    CGoodSearchWin *SearchWin=new CGoodSearchWin(10,5,22,80,"��ӭʹ�ô�һ�̵��",Goods,5);//5

    InStockMenuWin *InStockMenu=new InStockMenuWin(10,5,22,60,"��ӭʹ�ô�һ�̵��",6);//6
    InStockWin *InStock=new InStockWin(10,5,22,60,"��ӭʹ�ô�һ�̵��",InstockRecord,7);//7
    CTipsWin *TipsWin=new CTipsWin(30,9,15,20,"",8);//��ʾ�����8
    CGoodsAddWin *GoodsAddWin=new CGoodsAddWin(10,5,26,50,"��ӭʹ�ô�һ�̵��",9);//������Ʒ9
    InStockRecordWin *InstockRecordWin=new InStockRecordWin(10,5,24,70,"��ӭʹ�ô�һ�̵��",InstockRecord,10);//10

    OutStockMenuWin *OutStockMenu=new OutStockMenuWin(10,5,22,60,"��ӭʹ�ô�һ�̵��",11);//11
    OutStockWin *OutStock=new OutStockWin(10,5,22,60,"��ӭʹ�ô�һ�̵��",OutstockRecord,12);//12
    OutStockRecordWin *OutstockRecordWin=new OutStockRecordWin(10,5,24,70,"��Ʒ�����¼����",OutstockRecord,13);//13

    CCheckMenuWin *CheckMenuWin=new CCheckMenuWin(10,5,22,60,"��ӭʹ�ô�һ�̵��",14);
    CCheckCreateWin *CheckCreateWin=new CCheckCreateWin(10,5,21,60,"��ӭʹ�ô�һ�̵��",15);
    CCheckReportWin *CheckReportWin=new CCheckReportWin(10,5,22,60,"��ӭʹ�ô�һ�̵��",OutstockRecord,16);//��ΪNULL���Խ���


    CWinBase *CWin[20]={start,loginwin,regiswin,adminWin,checkerWin,SearchWin,InStockMenu,InStock,TipsWin,GoodsAddWin,InstockRecordWin,OutStockMenu,OutStock,OutstockRecordWin,CheckMenuWin,CheckCreateWin,CheckReportWin};
    while(1)
    {
        //CWin[curWin]->show();
        if(curWin==SEARCHWIN||curWin==INSTOCKWIN||curWin==GOODSADDWIN||curWin==OUTSTOCKWIN||curWin==CHECKMENUWIN||curWin==CHECKWINCREATE)   //������Ʒ��ѯ�������⡢���ⴰ��ʱ���������ʱGoods
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
