#include"InStockWin.h"


/******************************
*函数名 InStockWin()
*函数功能：窗体界面构造函数，对窗体的控件进行初始化
*输入 窗体的坐标和宽度、高度、窗体名字
*输出 无
************************************/
InStockWin::InStockWin(int x,int y,int height,int width,char *text,void *record,int winNo)//这个record是记录文件传进来的
:CWinBase(x,y,height,width,text,winNo)
{
    this->newGoods=new map<int,CGoods>;
    this->WelcomeLab=new CLabel(this->x+6,this->y+3,2,6,"欢迎:");
    this->DateLab=new CLabel(this->x+this->width-20,this->y+3,2,6,"日期:");
    this->NoLab=new CLabel(this->x+2,this->y+6,2,18,"请输入商品编号:");
    this->NoEdt=new CEdit(this->x+22,this->y+6,2,20,"",EDIT);
    this->SearchBtn=new CButton(this->x+this->width-8,this->y+6,2,4,"查询");
    this->GoodsName=new CLabel(this->x+6,this->y+9,2,10,"商品名称:");
    this->GoodsType=new CLabel(this->x+6,this->y+11,2,10,"商品类型:");
    this->GoodsPrice=new CLabel(this->x+6,this->y+13,2,10,"商品价格:");
    this->GoodsCount=new CLabel(this->x+6,this->y+15,2,10,"库存数量:");
    this->LocationNum=new CLabel(this->x+6,this->y+17,2,10,"位置编号:");

    this->Goods_Found=new CGoodsFound(this->x+3,this->y+8,13,28,NULL);
    this->CountLab=new CLabel(this->x+this->width-24,this->y+9,2,25,"请输入入库数量【1-10000】");
    this->CountEdt=new CEdit(this->x+this->width-20,this->y+11,2,18,"",EDIT);
    this->EnterBtn=new CButton(this->x+this->width-20,this->y+16,2,4,"确定");//确定按钮
    this->EscBtn=new CButton(this->x+this->width-12,this->y+16,2,4,"取消");//

    this->addControl(this->WelcomeLab);
    this->addControl(this->DateLab);
    this->addControl(this->NoLab);
    this->addControl(this->NoEdt);
    this->addControl(this->SearchBtn);
    this->addControl(this->Goods_Found);

    this->addControl(this->GoodsName);
    this->addControl(this->GoodsType);
    this->addControl(this->GoodsPrice);
    this->addControl(this->GoodsCount);
    this->addControl(this->LocationNum);

    this->addControl(this->CountLab);
    this->addControl(this->CountEdt);
    this->addControl(this->EnterBtn);
    this->addControl(this->EscBtn);

    this->input=0;
    this->Record=(vector<CGoodsStockRecord>*)record;
}


InStockWin::~InStockWin()
{
    delete this->WelcomeLab;
    delete this->DateLab;
    delete this->NoLab;
    delete this->NoEdt;
    delete this->SearchBtn;
    delete this->GoodsName;
    delete this->GoodsType;
    delete this->GoodsPrice;
    delete this->GoodsCount;
    delete this->LocationNum;
    delete this->Goods_Found;
    delete this->CountLab;
    delete this->CountEdt;
    delete this->EnterBtn;
    delete this->EscBtn;
}

/******************************
*函数名 doAction()
*函数功能：对按键处理结果进行响应
*输入 所需数据，如商品信息，员工信息，出入库信息
*返回 界面号
************************************/
int InStockWin::doAction(void *data)
{
    int nowcount=0,addcount=0;//原来的商品数量、新入库数量
    int date=0;//存放获取的日期，用来写入记录
    map<int,CGoods>*Goods=(map<int,CGoods> *)data;
    sscanf(this->controls[3]->getText(),"%d",&input);//输入的查询商品的编号转成int型，用input存放
    map<int,CGoods>::iterator it;//此句之前有问题--原因在Goods数据有问题--传入数据时传错了
    it=Goods->find(input);
    if(strcmp(this->controls[this->curControl]->getText(),"查询")==0)
    {
        if(it!=Goods->end())//将it迭代器的内容写入到新的map中,新map 中只有一个key_value 对
        {
            //查找到的数据存入属性
            this->newGoods->insert(map<int,CGoods>::value_type(999,CGoods("初始化","例子",1205,"AX0999")));//先初始化一个键值对再删除
            this->newGoods->insert(map<int,CGoods>::value_type(1000,CGoods("初始化","例子",1205,"AX1000")));
            this->newGoods->erase(this->newGoods->begin(),this->newGoods->end());//先初始化两个再重新插入
            this->newGoods->insert(map<int,CGoods>::value_type(it->first,CGoods(it->first,it->second.getName(),it->second.getType(),it->second.getPrice(),it->second.getCount(),it->second.getLocation())));
            this->Goods_Found->setnewGoods(this->newGoods);

        }
        else//写新增商品界面
        {
            CTool::setTemp(this->controls[3]->getText());//传给工具类里的一个静态变量存储，到新增商品界面调用
            return TIPSWIN;//提示窗口
        }
        return INSTOCKWIN;
    }
    if(strcmp(this->controls[this->curControl]->getText(),"确定")==0&&strlen(this->controls[8]->getText())!=0)//确定时有查询到商品信息且输入框有数据才进行操作
    {

        sscanf(this->controls[12]->getText(),"%d",&addcount);//无错
        nowcount=addcount+it->second.getCount();//新入库后的商品数量
        if(nowcount<0||addcount>10000)
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
            CFile::Goods_Filewrite("data/Goods.txt",Goods);
            CTool::gotoxy(this->x+this->width-17,this->y+18);
            cout<<"入库成功!";

            //生成入库信息
            time_t nowtime=time(NULL);//获取当前系统的时间，单位为秒
            struct tm* t=localtime(&nowtime);//转换成tm类型的结构体
            date=(t->tm_year+1900)*10000+(t->tm_mon+1)*100+t->tm_mday;//生成日期-int型
            this->Record->push_back(CGoodsStockRecord(this->input,it->second.getName(),date,addcount,it->second.getLocation()));
            //写入文件
            CFile::Record_Filewrite("data/InRecord.txt",this->Record);
            //cout<<"写入文件成功!";
        }
        getch();
        return INSTOCKWIN;
    }
    else if(strcmp(this->controls[this->curControl]->getText(),"取消")==0)
    {
        this->Goods_Found->setnewGoods(NULL);
        return INSTOCKMENUWIN;//INSTOCKMENUWIN 返回入库菜单界面
    }

    return INSTOCKWIN;
}


void InStockWin::UpdateControls()
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
