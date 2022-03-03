#include"CGoodSearchWin.h"


/******************************
*函数名 CGoodSearchWin()
*函数功能：窗体界面构造函数，对窗体的控件进行初始化
*输入 窗体的坐标和宽度、高度、窗体名字
*输出 无
************************************/
CGoodSearchWin::CGoodSearchWin(int x,int y,int height,int width,char *text,void *data,int winNo)
:CWinBase(x,y,height,width,text,winNo)
{
    this->curPage=0;
    this->WelcomeLab=new CLabel(this->x+6,this->y+3,2,6,"欢迎:");
    this->DateLab=new CLabel(this->x+this->width-16,this->y+3,2,6,"日期:");
    this->InputNum=new CLabel(this->x+2,this->y+5,2,16,"请输入商品编号:");
    this->ComInput=new CEdit(this->x+18,this->y+5,2,16,"",EDIT);
    this->GoodsNum=new CLabel(this->x+7,this->y+8,2,6,"商品编号");
    this->GoodsName=new CLabel(this->x+19,this->y+8,2,6,"商品名称");
    this->GoodsType=new CLabel(this->x+31,this->y+8,2,6,"商品类型");
    this->GoodsPrice=new CLabel(this->x+43,this->y+8,2,6,"商品价格");
    this->GoodsCount=new CLabel(this->x+55,this->y+8,2,6,"库存数量");
    this->LocationNum=new CLabel(this->x+67,this->y+8,2,6,"仓位编号");
    this->UpDownPage=new CLabel(this->x+this->width/2-10,this->y+this->height-5,2,20,"<上页          下页>");//10,5,22,80,

    this->SearchBtn=new CButton(this->x+(this->width)-6,this->y+5,2,4,"查询");
    this->ExportBtn=new CButton(this->x+(this->width)/4-1,this->y+this->height-4,2,4,"导出");
    this->ExitBtn=new CButton(this->x+(this->width)*3/4-1,this->y+this->height-4,2,4,"退出");

    this->data=data;
    this->Table=new CTable(16,12,8,70,this->data,GOODSTABLE);

    this->addControl(this->UpDownPage);
    this->addControl(this->Table);
    this->addControl(this->InputNum);//
    this->addControl(this->ComInput);
    this->addControl(this->GoodsNum);
    this->addControl(this->GoodsName);
    this->addControl(this->GoodsType);
    this->addControl(this->GoodsPrice);
    this->addControl(this->GoodsCount);
    this->addControl(this->LocationNum);
    this->addControl(this->SearchBtn);
    this->addControl(this->ExportBtn);
    this->addControl(this->ExitBtn);
    this->addControl(this->WelcomeLab);
	this->addControl(this->DateLab);
}
CGoodSearchWin::~CGoodSearchWin()
{
}
/******************************
*函数名 doAction()
*函数功能：对按键处理结果进行响应
*输入 所需数据，如商品信息，员工信息，出入库信息
*返回 界面号
************************************/
int CGoodSearchWin::doAction(void *data)
{
    //打印表格和数据
    int input=0;
    map<int,CGoods>*Goods=(map<int,CGoods> *)data;
    map<int,CGoods>*newGoods=new map<int,CGoods>;
    if(strcmp(this->controls[this->curControl]->getText(),"查询")==0)
    {
        //此处做查询业务，查到的数据做一个新的map或者链表，再在Table接口函数setdata（自己写一个），将新容器（查到的数据）传进去，再在控件table中show出来
        //用data精确查询，
        sscanf(this->controls[3]->getText(),"%d",&input);
        map<int,CGoods>::iterator it;
        it=Goods->find(input);
        if(it!=Goods->end())
        {//将it迭代器的内容写入到新的map中
            newGoods->insert(map<int,CGoods>::value_type(it->first,CGoods(it->first,it->second.getName(),it->second.getType(),it->second.getPrice(),it->second.getCount(),it->second.getLocation())));
            this->Table->setData(newGoods);//this->data接收查到的数据
        }
        else
        {
            CTool::gotoxy(this->x+(this->width)-16,this->y+4);
            cout<<"no find";
            getch();
        }
        return SEARCHWIN;
    }
    else if(strcmp(this->controls[this->curControl]->getText(),"导出")==0)
    {
        //导出数据
    }
    else if(strcmp(this->controls[this->curControl]->getText(),"退出")==0)
    {
        return ADMINWIN;//退出回到管理员窗口
    }
    return SEARCHWIN;
}

/******************************
*函数名 UpdateControls()
*函数功能：更新窗体控件，主要是登录者的身份和当前日期
*输入 无
*输出 无
************************************/
void CGoodSearchWin::UpdateControls()
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
