#include "CGoodsAddWin.h"



/******************************
*函数名 CGoodsAddWin()
*函数功能：窗体界面构造函数，对窗体的控件进行初始化
*输入 窗体的坐标和宽度、高度、窗体名字
*输出 无
************************************/
CGoodsAddWin::CGoodsAddWin(int x,int y,int height,int width,char *text,int winNo)
:CWinBase(x,y,height,width,text,winNo)
{

    this->WelcomeLab=new CLabel(this->x+6,this->y+3,2,6,"欢迎:");
    this->DateLab=new CLabel(this->x+this->width-20,this->y+3,2,6,"日期:");
    this->GoodsNoLab=new CLabel(this->x+8,this->y+5,2,10,"商品编号:");
    this->GoodsNo=new CLabel(this->x+19,this->y+5,2,10,CTool::temp);//(CTool::getTemp())
    this->GoodsNameLab=new CLabel(this->x+8,this->y+8,2,10,"商品名称:");
    this->GoodsNameEdt=new CEdit(this->x+19,this->y+8,2,22,"",CHNEDIT);
    this->GoodsTypeLab=new CLabel(this->x+8,this->y+11,2,10,"商品类型:");
    this->GoodsTypeEdt=new CEdit(this->x+19,this->y+11,2,22,"",CHNEDIT);
    this->GoodsPriceLab=new CLabel(this->x+8,this->y+14,2,10,"商品价格:");
    this->GoodsPriceEdt=new CEdit(this->x+19,this->y+14,2,22,"",CHNEDIT);
    this->GoodsPositionLab=new CLabel(this->x+8,this->y+17,2,10,"仓位编号:");
    this->GoodsPositionEdt=new CEdit(this->x+19,this->y+17,2,22,"",EMPTYEDIT);//此编辑框不被编辑
    this->Enter=new CButton(this->x+14,this->y+21,2,4,"确定");
    this->Esc=new CButton(this->x+this->width-16,this->y+21,2,4,"取消");


    this->addControl(this->WelcomeLab);
    this->addControl(this->DateLab);
    this->addControl(this->GoodsNoLab);
    this->addControl(this->GoodsNo);
    this->addControl(this->GoodsNameLab);
    this->addControl(this->GoodsNameEdt);//商品名字 5
    this->addControl(this->GoodsTypeLab);
    this->addControl(this->GoodsTypeEdt);//商品类型 7
    this->addControl(this->GoodsPriceLab);
    this->addControl(this->GoodsPriceEdt);//商品价格 9
    this->addControl(this->GoodsPositionLab);
    this->addControl(this->GoodsPositionEdt);//仓位编号 11
    this->addControl(this->Enter);
    this->addControl(this->Esc);
}

CGoodsAddWin::~CGoodsAddWin()
{

}
/******************************
*函数名 doAction()
*函数功能：对按键处理结果进行响应
*输入 所需数据，如商品信息，员工信息，出入库信息
*返回 界面号
************************************/
int CGoodsAddWin::doAction(void *data)
{
    int No=0;
    int price=0;
    map<int,CGoods>*Goods=(map<int,CGoods>*)data;
    if(strcmp(this->controls[this->curControl]->getText(),"确定")==0)
    {
        //新建商品节点
        if(strlen(this->controls[5]->getText())==0||strlen(this->controls[7]->getText())==0||strlen(this->controls[9]->getText())==0)
        {
            CTool::gotoxy(28,29);
            cout<<"商品信息未输入完整，请重新输入";
            return GOODSADDWIN;
        }
        else
        {
            sscanf(CTool::temp,"%d",&No);
            sscanf(this->controls[9]->getText(),"%d",&price);
            Goods->insert(map<int,CGoods>::value_type(No,CGoods(No,this->controls[5]->getText(),this->controls[7]->getText(),price,0)));//商品数量初始化为0
            map<int,CGoods>::iterator it;
            it=Goods->find(No);
            CTool::gotoxy(this->x+19,this->y+17);
            cout<<it->second.getLocation();//显示仓位编号
            CFile::Goods_Filewrite("data/Goods.txt",Goods);//写入文件
            CTool::gotoxy(this->x+19,this->y+19);
            cout<<"新增成功!";
            system("pause");
            return INSTOCKWIN;
        }
    }
    else if(strcmp(this->controls[this->curControl]->getText(),"取消")==0)
    {
        return INSTOCKWIN;
    }
}

/******************************
*函数名 UpdateControls()
*函数功能：更新窗体控件，主要是登录者的身份和当前日期
*输入 无
*输出 无
************************************/
void CGoodsAddWin::UpdateControls()
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
