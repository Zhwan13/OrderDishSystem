#include"CCheckCreateWin.h"

/******************************
*函数名 CCheckCreateWin()
*函数功能：窗体界面构造函数，对窗体的控件进行初始化
*输入 窗体的坐标和宽度、高度、窗体名字
*输出 无
************************************/
CCheckCreateWin::CCheckCreateWin(int x,int y,int height,int width,char *text,int winNo)
:CWinBase(x,y,height,width,text,winNo)
{
    this->WelcomeLab=new CLabel(this->x+6,this->y+3,2,6,"欢迎:");
    this->DateLab=new CLabel(this->x+this->width-20,this->y+3,2,6,"日期:");
    this->NoLab=new CLabel(this->x+2,this->y+6,2,8,"请输入商品编号:");
    this->NoEdt=new CEdit(this->x+22,this->y+6,2,18,"",EDIT);
    this->SearchBtn=new CButton(this->x+this->width-8,this->y+6,2,4,"查询");
    //this->InformLab=new CLabel(this->x+6,this->y+9,6,30,"商品名称:\n\n\t\t商品类型:\n\n\t\t商品价格:\n\n\t\t库存数量:\n\n\t\t位置编号:");

    this->GoodsName=new CLabel(this->x+6,this->y+9,2,10,"商品名称:");
    this->GoodsType=new CLabel(this->x+6,this->y+11,2,10,"商品类型:");
    this->GoodsPrice=new CLabel(this->x+6,this->y+13,2,10,"商品价格:");
    this->LocationNum=new CLabel(this->x+6,this->y+15,2,10,"位置编号:");

    this->CountLab=new CLabel(this->x+this->width-24,this->y+9,2,25,"请输入盘点数量【1-10000】");
    this->CountEdt=new CEdit(this->x+this->width-20,this->y+11,2,18,"",EDIT);
    this->EnterBtn=new CButton(this->x+this->width-20,this->y+14,2,4,"确定");
    this->EscBtn=new CButton(this->x+this->width-12,this->y+14,2,4,"取消");
    this->ReportBtn=new CButton(this->x+this->width-20,this->y+17,2,10,"生成盘点表");
    this->Goods_Found=new CGoodsFound(this->x+3,this->y+8,10,24,this->newGoods,CHECK_INFO);

    this->addControl(this->WelcomeLab);
    this->addControl(this->DateLab);
    this->addControl(this->NoLab);
    this->addControl(this->NoEdt);
    this->addControl(this->SearchBtn);
    this->addControl(this->Goods_Found);

    this->addControl(this->GoodsName);
    this->addControl(this->GoodsType);
    this->addControl(this->GoodsPrice);
    this->addControl(this->LocationNum);


    this->addControl(this->CountLab);
    this->addControl(this->CountEdt);
    this->addControl(this->EnterBtn);
    this->addControl(this->EscBtn);
    this->addControl(this->ReportBtn);
    this->newGoods=new map<int,CGoods>;
    this->input=0;
}

CCheckCreateWin::~CCheckCreateWin()
{
    delete this->WelcomeLab;
    delete this->DateLab;
    delete this->NoLab;
    delete this->NoEdt;
    delete this->SearchBtn;
    delete this->GoodsName;
    delete this->GoodsType;
    delete this->GoodsPrice;
    delete this->LocationNum;
    delete this->CountLab;
    delete this->CountEdt;
    delete this->EnterBtn;
    delete this->EscBtn;
    delete this->ReportBtn;
    delete this->Goods_Found;

}

/******************************
*函数名 doAction()
*函数功能：对按键处理结果进行响应
*输入 所需数据，如商品信息，员工信息，出入库信息
*返回 界面号
************************************/
int CCheckCreateWin::doAction(void *data)
{

    int nowcount=0;//盘点的数量
    int date1=0,date2=0;//存放获取的日期
    map<int,CGoods>*Goods=(map<int,CGoods> *)data;
    sscanf(this->controls[3]->getText(),"%d",&input);//输入的查询商品的编号转成int型，用input存放
    map<int,CGoods>::iterator it;//此句之前有问题--原因在Goods数据有问题--传入数据时传错了
    it=Goods->find(input);
    if(strcmp(this->controls[this->curControl]->getText(),"查询")==0)
    {
        if(it!=Goods->end())//将it迭代器的内容写入到新的map中,新map 中只能有一个key_value 对
        {
            //查找到的数据存入属性
            this->newGoods->insert(map<int,CGoods>::value_type(999,CGoods("初始化","例子",1205,"AX0999")));//先初始化一个键值对再删除
            this->newGoods->insert(map<int,CGoods>::value_type(1000,CGoods("初始化","例子",1205,"AX1000")));
            this->newGoods->erase(this->newGoods->begin(),this->newGoods->end());//先初始化两个再重新插入
            this->newGoods->insert(map<int,CGoods>::value_type(it->first,CGoods(it->first,it->second.getName(),it->second.getType(),it->second.getPrice(),it->second.getCount(),it->second.getLocation())));
            this->Goods_Found->setnewGoods(this->newGoods);
        }
        else
        {
            cout<<"未找到no find";
            //CTool::setTemp(this->controls[3]->getText());
            //return TIPSWIN;//提示窗口
        }
        return CHECKWINCREATE;
    }
    if(strcmp(this->controls[this->curControl]->getText(),"确定")==0&&strlen(this->controls[8]->getText())!=0)//确定时有查询到商品信息且输入框有数据才进行操作
    {

        sscanf(this->controls[11]->getText(),"%d",&nowcount);
        if(nowcount<0||nowcount>10000)
        {
            cout<<"输入数量有误，请重新输入";
        }
        else
        {
            it->second.setCount(nowcount);//it是指向查找到的商品的迭代器,商品总链表数量修改
            if(this->newGoods!=NULL)//以下几句用来把显示的商品信息更新
            {
                this->newGoods->erase(this->newGoods->begin());
            }
            this->newGoods->insert(map<int,CGoods>::value_type(it->first,CGoods(it->first,it->second.getName(),it->second.getType(),it->second.getPrice(),nowcount,it->second.getLocation())));
            //CFile::Goods_Filewrite("data/Goods.txt",Goods);
            CTool::gotoxy(this->x+this->width-17,this->y+18);
            cout<<"盘点成功!";

            //生成盘点信息
            char *Date;
            Date=new char[20];
            CTool::getNowTime(Date);//获取当前日期

        }
        getch();
        return CHECKWINCREATE;
    }
    else if(strcmp(this->controls[this->curControl]->getText(),"取消")==0)
    {
        this->Goods_Found->setnewGoods(NULL);
        return CHECKMENUWIN;// 返回盘点菜单界面
    }
    else if(strcmp(this->controls[this->curControl]->getText(),"生成盘点表")==0)
    {
        return CHECKREPORTWIN;//盘点表界面
    }

    return CHECKWINCREATE;
}

/******************************
*函数名 UpdateControls()
*函数功能：更新窗体控件，主要是登录者的身份和当前日期
*输入 无
*输出 无
************************************/
void CCheckCreateWin::UpdateControls()
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
