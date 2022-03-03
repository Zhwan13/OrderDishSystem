#include"OutStockWin.h"
/******************************
*函数名 OutStockWin()
*函数功能：窗体界面构造函数，对窗体的控件进行初始化
*输入 窗体的坐标和宽度、高度、窗体名字
*输出 无
************************************/
OutStockWin::OutStockWin(int x,int y,int height,int width,char *text,void *record,int winNo)
:CWinBase(x,y,height,width,text,winNo)
{
    this->newGoods=new map<int,CGoods>;
    this->WelcomeLab=new CLabel(this->x+6,this->y+4,2,6,"欢迎:");
    this->DateLab=new CLabel(this->x+this->width-20,this->y+4,2,6,"日期:");
    this->NoLab=new CLabel(this->x+2,this->y+6,2,18,"请输入商品编号:");
    this->NoEdt=new CEdit(this->x+22,this->y+6,2,20,"",EDIT);
    this->SearchBtn=new CButton(this->x+this->width-8,this->y+6,2,4,"查询");
    this->Goods_Found=new CGoodsFound(this->x+3,this->y+8,13,28,NULL);

    this->GoodsName=new CLabel(this->x+6,this->y+9,2,10,"商品名称:");
    this->GoodsType=new CLabel(this->x+6,this->y+11,2,10,"商品类型:");
    this->GoodsPrice=new CLabel(this->x+6,this->y+13,2,10,"商品价格:");
    this->GoodsCount=new CLabel(this->x+6,this->y+15,2,10,"库存数量:");
    this->LocationNum=new CLabel(this->x+6,this->y+17,2,10,"位置编号:");

    this->CountLab=new CLabel(this->x+this->width-24,this->y+9,2,25,"请输入出库数量【1-10000】");
    this->CountEdt=new CEdit(this->x+this->width-20,this->y+11,2,16,"",EDIT);
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
    this->addControl(this->CountEdt);//12
    this->addControl(this->EnterBtn);
    this->addControl(this->EscBtn);

    this->input=0;
    this->Record=(vector<CGoodsStockRecord>*)record;
}
OutStockWin::~OutStockWin()
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

int OutStockWin::doAction(void *data)
{
    int nowcount=0,deccount=0;//原来的商品数量、新入库数量
    int date=0;//用来接收时间
    map<int,CGoods>*Goods=(map<int,CGoods> *)data;
    sscanf(this->controls[3]->getText(),"%d",&input);
    map<int,CGoods>::iterator it;//此句之前有问题--原因在Goods数据有问题--传入数据时传错了
    it=Goods->find(input);
    if(strcmp(this->controls[this->curControl]->getText(),"查询")==0)
    {

        if(it!=Goods->end())//将it迭代器的内容写入到新的map中,新map 中只有一个key_value 对
        {
            //查找到的数据存入属性
            //this->newGoods->erase(this->newGoods->begin());//先清除
            this->newGoods->insert(map<int,CGoods>::value_type(999,CGoods("初始化","例子",1205,"1000")));//先初始化一个键值对再删除
            this->newGoods->insert(map<int,CGoods>::value_type(1000,CGoods("初始化","例子",1205,"1002")));

            this->newGoods->erase(this->newGoods->begin(),this->newGoods->end());

            this->newGoods->insert(map<int,CGoods>::value_type(it->first,CGoods(it->first,it->second.getName(),it->second.getType(),it->second.getPrice(),it->second.getCount(),it->second.getLocation())));
            this->Goods_Found->setnewGoods(this->newGoods);
        }
        else//写新增商品界面
        {
            cout<<"未找到该商品，请重新查询";
            getch();
        }
        /***
        map<int,CGoods>::iterator iter2=newGoods->begin();
            for(;iter2!=newGoods->end();++iter2)
            {
                cout<<iter2->first<<" "<<iter2->second.getName()<<" "<<iter2->second.getType()<<" "<<iter2->second.getPrice()<<" "<<iter2->second.getCount()<<" "<<iter2->second.getLocation()<<endl;
            }
            ***/
        return OUTSTOCKWIN;
    }
    if(strcmp(this->controls[this->curControl]->getText(),"确定")==0&&strlen(this->controls[8]->getText())!=0)//确定时有查询到商品信息且输入框有数据才进行操作
    {

        sscanf(this->controls[12]->getText(),"%d",&deccount);//无错
        nowcount=it->second.getCount()-deccount;//新入库后的商品数量
        if(nowcount<0||deccount<(-10000))
        {
            cout<<"输入数量有误，请重新输入";
        }
        else
        {
            it->second.setCount(nowcount);//it是指向查找到的商品的迭代器,商品总链表数量修改
            if(this->newGoods!=NULL)
            {
                this->newGoods->erase(this->newGoods->begin());
            }
            this->newGoods->insert(map<int,CGoods>::value_type(it->first,CGoods(it->first,it->second.getName(),it->second.getType(),it->second.getPrice(),nowcount,it->second.getLocation())));
            //this->Goods_Found->setnewGoods(this->newGoods);
            //Goods[input]=CGoods(input,iter->second.getName(),iter->second.getType(),iter->second.getPrice(),iter->second.getCount(),iter->second.getLocation());
            CFile::Goods_Filewrite("data/Goods.txt",Goods);
            cout<<"出库成功";

            time_t nowtime=time(NULL);//获取当前系统的时间，单位为秒
            struct tm* t=localtime(&nowtime);//转换成tm类型的结构体
            date=(t->tm_year+1900)*10000+(t->tm_mon+1)*100+t->tm_mday;//生成日期-int型
            this->Record->push_back(CGoodsStockRecord(this->input,it->second.getName(),date,deccount,it->second.    getLocation()));
            //写入文件
            CFile::Record_Filewrite("data/OutRecord.txt",this->Record);
            //cout<<"写入文件成功!";

        }
        system("pause");//此处不能用getch()，否则按方向键后会被编辑框接收第二个键值
        return OUTSTOCKWIN;
    }
    else if(strcmp(this->controls[this->curControl]->getText(),"取消")==0)
    {
        this->Goods_Found->setnewGoods(NULL);
        return OUTSTOCKMENUWIN;//INSTOCKMENUWIN 返回入库菜单界面
    }
            return OUTSTOCKWIN;
}

/******************************
*函数名 UpdateControls()
*函数功能：更新窗体控件，主要是登录者的身份和当前日期
*输入 无
*输出 无
************************************/
void OutStockWin::UpdateControls()
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
