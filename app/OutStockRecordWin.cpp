#include"OutStockRecordWin.h"

/******************************
*函数名 OutStockRecordWin()
*函数功能：窗体界面构造函数，对窗体的控件进行初始化
*输入 窗体的坐标和宽度、高度、窗体名字
*输出 无
************************************/
OutStockRecordWin::OutStockRecordWin(int x,int y,int height,int width,char *text,void *data,int winNo)
:CWinBase(x,y,height,width,text,winNo)
{
    this->data=data;
    this->WelcomeLab=new CLabel(this->x+6,this->y+3,2,6,"欢迎:");
    this->DateLab=new CLabel(this->x+this->width-20,this->y+3,2,6,"日期:");
    this->Start=new CLabel(this->x+2,this->y+6,2,6,"开始日期:");
    this->End=new CLabel(this->x+2,this->y+9,2,6,"结束日期:");

    this->OutStockRecTab=new CTable(this->x+6,this->y+11,8,60,this->data,RECORDTABLE);
    this->StartYear=new CEdit(this->x+13,this->y+6,2,10,"",EDIT);
    this->StartMon=new CEdit(this->x+28,this->y+6,2,8,"",EDIT);
    this->StartDay=new CEdit(this->x+43,this->y+6,2,8,"",EDIT);
    this->EndYear=new CEdit(this->x+13,this->y+9,2,10,"",EDIT);
    this->EndMon=new CEdit(this->x+28,this->y+9,2,8,"",EDIT);
    this->EndDay=new CEdit(this->x+43,this->y+9,2,8,"",EDIT);

    this->SearchbyDateBtn=new CButton(this->x+(this->width)-16,this->y+6,2,14,"按出库时间查询");
    this->returnBtn=new CButton(this->x+(this->width)-16,this->y+9,2,4,"返回");
    this->GoodsNoLab=new CLabel(this->x+7,this->y+12,2,6,"商品编号");
    this->GoodsNameLab=new CLabel(this->x+19,this->y+12,2,6,"商品名称");
    this->OutStockDateLab=new CLabel(this->x+31,this->y+12,2,6,"出库日期");
    this->OutStockNumLab=new CLabel(this->x+43,this->y+12,2,6,"出库数量");
    this->LocationNoLab=new CLabel(this->x+55,this->y+12,2,6,"仓位编号");



    this->addControl(this->WelcomeLab);
    this->addControl(this->DateLab);
    this->addControl(this->Start);

    this->addControl(this->OutStockRecTab);
    this->addControl(this->StartYear);//4
    this->addControl(this->StartMon);//5
    this->addControl(this->StartDay);//6
    this->addControl(this->EndYear);//7
    this->addControl(this->EndMon);//8
    this->addControl(this->EndDay);//9
    this->addControl(this->SearchbyDateBtn);
    this->addControl(this->returnBtn);
    this->addControl(this->End);

    this->addControl(this->GoodsNoLab);
    this->addControl(this->GoodsNameLab);
    this->addControl(this->OutStockDateLab);
    this->addControl(this->OutStockNumLab);
    this->addControl(this->LocationNoLab);

}

OutStockRecordWin::~OutStockRecordWin()
{

}

/******************************
*函数名 doAction()
*函数功能：对按键处理结果进行响应
*输入 所需数据，如商品信息，员工信息，出入库信息
*返回 界面号
************************************/
int OutStockRecordWin::doAction(void *data)
{
    int flag=0;//判断是否查找到
    int startDate=0;//整型表示输入的查询日期
    int endDate=0;
    int startYear=0,startMon=0,startDay=0,endYear=0,endMon=0,endDay=0;
    vector<CGoodsStockRecord> *Record=(vector<CGoodsStockRecord>*)data;
    vector<CGoodsStockRecord> *Recordfind=new vector<CGoodsStockRecord>;

    this->OutStockRecTab->setData(data);//先刷一下表格的数据，以免在没有找到后打印乱码
    if(strcmp(this->controls[this->curControl]->getText(),"按出库时间查询")==0)
    {
        if(strlen(this->controls[4]->getText())!=0&&strlen(this->controls[5]->getText())!=0&&strlen(this->controls[6]->getText())!=0&&strlen(this->controls[7]->getText())!=0&&strlen(this->controls[8]->getText())!=0&&strlen(this->controls[9]->getText())!=0)
        {//判断输入框是否都输有数据
            //将输入框数据都转成整数
            sscanf(this->controls[4]->getText(),"%d",&startYear);
            sscanf(this->controls[5]->getText(),"%d",&startMon);
            sscanf(this->controls[6]->getText(),"%d",&startDay);
            sscanf(this->controls[7]->getText(),"%d",&endYear);
            sscanf(this->controls[8]->getText(),"%d",&endMon);
            sscanf(this->controls[9]->getText(),"%d",&endDay);
            startDate=startYear*10000+startMon*100+startDay;
            endDate=endYear*10000+endMon*100+endDay;
            vector<CGoodsStockRecord>::iterator it=Record->begin();
            for(it=Record->begin();it!=Record->end();++it)//此处之前死循环了，因为在main中吧数据传错了。。。。
            {
                if(it->getDate()>=startDate&&it->getDate()<=endDate)
                {//查找到的数据存入链表，再打印出来
                    flag=1;//已经查找到
                    //重新定义一个向量存放找到的数据
                    Recordfind->push_back(CGoodsStockRecord(it->getNo(),it->getName(),it->getDate(),it->getCount(),it->getLocation()));
                }
            }
            if(flag==1)
                this->OutStockRecTab->setData(Recordfind);
            else if(flag==0)
            {
                CTool::gotoxy(20,30);
                cout<<"no find";
                getch();
            }
            //return INSTOCKRECORDWIN;
        }
        else
        {
            CTool::gotoxy(20,30);
            cout<<"input correct date";
            getch();
        }
        //this->data=Recordfind;
        return OUTSTOCKRECORDWIN;//返回入库记录界面
    }
    else if(strcmp(this->controls[this->curControl]->getText(),"返回")==0)
    {
        return OUTSTOCKMENUWIN;
    }
    return OUTSTOCKRECORDWIN;//防止程序崩溃
}

/******************************
*函数名 UpdateControls()
*函数功能：更新窗体控件，主要是登录者的身份和当前日期
*输入 无
*输出 无
************************************/
void OutStockRecordWin::UpdateControls()
{
    char *Date=new char[20];
    CTool::getDate(Date);
    char newLab[25]={0};
    sprintf(newLab,"日期:%s",Date);
    this->DateLab->setLab(newLab);
    if (strcmp(CTool::role,"1")==0)
    {
        this->WelcomeLab->setLab("欢迎:仓库管理员");
    }
    else
    {
        this->WelcomeLab->setLab("欢迎:盘点员");
    }

    delete Date;
    return ;
}
